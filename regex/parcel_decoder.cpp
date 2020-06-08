#include <iostream>
#include <string>
#include <regex>

// ^\s*0x[a-f0-9]*: ([a-f0-9]{8}) ([a-f0-9]{8}) ([a-f0-9]{8}) ([a-f0-9]{8})
// [a-f0-9]{8}\s

// C  O  N  N  E  C  T  E  D
// 43 4f 4e 4e 45 43 54 45 44 00
// 4f 43 4e 4e 43 45 45 54 00 44

/*
 * 00000000   00000001   00000001   00000000
 *
 * 0000 0000  0000 0001  0000 0001  0000 0000
 *
 *
 * // Interchange
 * 0000 0000  0001 0000  0001 0000  0000 0000
 *
 * // Stripping
 * 0000 0001   0001 0000
 *
 * // stripping
 * 00   00    00   01    00   01    00   00
 *
 * // Interchange
 * 00   00    01  00     01   00    00   00
 */

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

std::string wifiData = "Result: Parcel( \n\
    0x00000000: 00000000 00000001 00000001 00000000  '................'\n\
    0x00000010: 00000004 00490057 00490046 00000000  '................'\n\
    0x00000020: 00000000 00000000 00000009 004f0043  '................'\n\
    0x00000030: 004e004e 00430045 00450054 00000044  '................'\n\
    0x00000040: 00000009 004f0043 004e004e 00430045  '................'\n\
    0x00000050: 00450054 00000044 00000000 00000001  '................'\n\
    0x00000060: 00540043 00440045 00000000 00000000  '................'\n\
    0x00000070: 00000000 ffffffff ffffffff 00000000  '................'\n\
    0x00000080: 00000000 00000000 00000000 00000000  '................'\n\
    0x00000090: 00000000 00000000 00000000 00000000  '................'\n\
    0x000000a0: 00000000 00000000 00000000 00000000  '................')\n";

int main() {
    std::regex eightHexDigits_pattern("\\b[a-f0-9]{8}\\b");
//    auto rgx_itr_end = std::sregex_iterator();

    auto eightHex_start = std::sregex_iterator(wifiData.begin(), wifiData.end(), eightHexDigits_pattern);

    std::advance(eightHex_start, 4);
    std::smatch typeName_match = *eightHex_start;
    int typeName_len = std::stoul(typeName_match.str(), nullptr, 16);

    auto GetTwoChars = [](std::string& str, std::string& result) {
        std::rotate(str.begin(), str.begin()+4, str.end());
        result += stoul(str.substr(0,4), nullptr, 16);
        result += stoul(str.substr(4,8), nullptr, 16);
    };

    auto ExtractString = [GetTwoChars](const std::smatch& match, std::string& result) {
        auto match_str = match.str();
        GetTwoChars(match_str, result);
    };

    auto typeName_start = ++eightHex_start;
    auto typeName_end = typeName_start;
    std::advance(typeName_end, (typeName_len/2)+1);
    std::string typeName;
    
    for (auto i = typeName_start; i != typeName_end; i++) {
        auto match = *i;
        ExtractString(match, typeName);
    }
    std::cout << "TypeName : " << typeName << "\n\n";

    
    
    eightHex_start = typeName_end;
    std::advance(eightHex_start, 2);

    std::smatch status_match = *eightHex_start;
    int status_len = std::stoul(status_match.str(), nullptr, 16);
    
    auto status_start = ++eightHex_start;
    auto status_end = status_start;
    std::advance(status_end, (status_len/2)+1);
    std::string status;
    
    for (auto i = status_start; i != status_end; i++) {
        auto match = *i;
        ExtractString(match, status);
    }
    std::cout << "status : " << status << "\n\n";

    return 0;
}
