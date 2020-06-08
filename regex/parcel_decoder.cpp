#include <iostream>
#include <string>
#include <regex>

// ^\s*0x[a-f0-9]*: ([a-f0-9]{8}) ([a-f0-9]{8}) ([a-f0-9]{8}) ([a-f0-9]{8})
// [a-f0-9]{8}\s

// C  O  N  N  E  C  T  E  D
// 43 4f 4e 4e 45 43 54 45 44 00
// 4f 43 4e 4e 43 45 45 54 00 44

 /*
  *
  * 00490057   00490046
  *
  * 0049 0057  0049 0046
  *
  * // Stripping
  * 49 57   49 46
  * I  W    I  F
  *
  * // EXchange
  * 57 49   46 49
  * W  I    F  I
  **/

static std::string mobileData = "Result: Parcel( \n"
    "    0x00000000: 00000000 00000001 00000000 00000000  '................'\n"
    "    0x00000010: 00000006 004f004d 00490042 0045004c  '................'\n"
    "    0x00000020: 00000000 00000000 00000000 0000000c  '................'\n"
    "    0x00000030: 00490044 00430053 004e004f 0045004e  '................'\n"
    "    0x00000040: 00540043 00440045 00000000 0000000c  '................'\n"
    "    0x00000050: 00490044 00430053 004e004f 0045004e  '................'\n"
    "    0x00000060: 00540043 00440045 00000000 00000000  '................'\n"
    "    0x00000070: 00000001 00000000 ffffffff ffffffff  '................'\n"
    "    0x00000080: 00000000 00000000 00000000 00000000  '................'\n"
    "    0x00000090: 00000000 00000000 00000000 00000000  '................'\n"
    "    0x000000a0: 00000000 00000000 00000000 00000000  '................'\n"
    "    0x000000b0: 00000000                             '....            ')\n";

static std::string wifiData = "Result: Parcel( \n"
    "    0x00000000: 00000000 00000001 00000001 00000000  '................'\n"
    "    0x00000010: 00000004 00490057 00490046 00000000  '................'\n"
    "    0x00000020: 00000000 00000000 00000009 004f0043  '................'\n"
    "    0x00000030: 004e004e 00430045 00450054 00000044  '................'\n"
    "    0x00000040: 00000009 004f0043 004e004e 00430045  '................'\n"
    "    0x00000050: 00450054 00000044 00000000 00000001  '................'\n"
    "    0x00000060: 00540043 00440045 00000000 00000000  '................'\n"
    "    0x00000070: 00000000 ffffffff ffffffff 00000000  '................'\n"
    "    0x00000080: 00000000 00000000 00000000 00000000  '................'\n"
    "    0x00000090: 00000000 00000000 00000000 00000000  '................'\n"
    "    0x000000a0: 00000000 00000000 00000000 00000000  '................')\n";

int main() {

    auto GetLength = [](std::sregex_iterator& it) {
        return std::stoul((*it++).str(), nullptr, 16);
    };

    auto ExtractString = [](const std::sregex_iterator& it, std::string& result) {
        auto str = (*it).str();
        std::rotate(str.begin(), str.begin()+4, str.end());
        result += stoul(str.substr(0,4), nullptr, 16);
        result += stoul(str.substr(4,8), nullptr, 16);
    };

    auto ExtractStringAndAdvance = [GetLength, ExtractString]
    (std::sregex_iterator& it, std::string& result) {
        size_t len = GetLength(it);
        auto start = it;
        std::advance(it, (len / 2) + 1);

        for (auto i = start; i != it; i++)
            ExtractString(i, result);
    };

    auto CheckStatus = [ExtractStringAndAdvance](const std::string& blob) {
        std::regex reg("\\b[a-f0-9]{8}\\b");
        auto rgxIt = std::sregex_iterator(blob.begin(), blob.end(), reg);
        std::advance(rgxIt, 4);
        std::string Name;
        ExtractStringAndAdvance(rgxIt, Name);

        std::advance(rgxIt, 2);
        std::string status;
        ExtractStringAndAdvance(rgxIt, status);

        std::cout << " [ " << Name << " ] : " << status << "\n\n";
    };

    CheckStatus(mobileData);
    CheckStatus(wifiData);

    return 0;
}
