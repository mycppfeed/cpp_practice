#include <stdio.h>
#include <iostream>
#include <map>

using Numbers = std::map<int, std::string>;

std::ostream& operator<<(std::ostream& os, const Numbers& n) {
    os << "[ Size : " << n.size() << " ]\n\t [ ";

    // The following is a standard way
    // for(const auto& e : n) { std::cout << "\n\t\t { " << e.first << ", " << e.second << " }, "; }

    // The following is using structure bindings
    for(auto const& [digit, word]  : n) { std::cout << "\n\t\t { " << digit << ", " << word << " }, "; }

    os << "\n\t ]\n\n";
    return os;
}

void printString(const Numbers& n, int num) {
    // error: no viable overloaded operator[] for type 'const Numbers'
    // std::cout << " The number 5 is called as " << n[5] << "\n";

    // auto const& [digit, word] = n.find(5);
    auto it = n.find(num);
    if (it == n.end()) {
        std::cout << " The number " << num << " is not available in map\n\n";
        return;
    }
    else  std::cout << " The number " << num << " is called as " << it->second << "\n";
}
void test_1() {
    Numbers numbers;
    std::cout << "Empty numbers Map : " << numbers;

    numbers[1] = "One";
    numbers[2] = "Two";
    numbers[4] = "Four";

    std::cout << "After inserting into Map : " << numbers;

    numbers.insert({3, "Three"});
    std::cout << "After inserting via insert : " << numbers;

    numbers.insert(std::make_pair(5, "Five"));
    std::cout << "After inserting via make_pair : " << numbers;

    printString(numbers, 5);
    printString(numbers, 6);
}

int main() {
    test_1();
}
