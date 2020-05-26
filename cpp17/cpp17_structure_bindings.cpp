// cpp17_structure_bindings.cpp

#include <stdio.h>
#include <map>
#include <string>

using MyMap = std::map<std::string, std::string>;

int main() {
    MyMap myMap{
        {"casa",   "home"},
        {"gatto",  "cat"},
        {"tavola", "table"}
    };

    auto [pos, success] = myMap.insert({"sedia", "chair"});

    if (success) printf("Sucessfully inserted\n");
    else printf("Insertion failed\n");

    for (const auto& [italian, english] : myMap) {
        printf("Italian : %10s\t English : %10s\n", italian.c_str(), english.c_str());
    }

    return 0;
}