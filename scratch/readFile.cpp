#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <fstream>

struct Line
{
    std::string lineData;

    operator std::string() const
    {
        return lineData;
    }
};
std::istream& operator>>(std::istream& str,Line& data)
{
    std::getline(str,data.lineData);
    return str;
}

int main(int argc, char *argv[])
{
    std::ifstream inputFile(argv[1]);
     std::vector<std::string>    lines((std::istream_iterator<Line>(inputFile)),
                                       std::istream_iterator<Line>());

    for (auto line : lines) {
        std::cout << line << "\n";
    }
}
