#include <stdio.h>
#include <iostream>
#include <list>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& l) {
    os << "[ size : " << l.size() << " ] : [ ";
    for (auto e : l) os << e << ", ";
    os << " ]";
    return os;
}

int main() {
    std::list<int> l;

    std::cout << "Empty List    : " << l << "\n";
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    std::cout << "Inital List   : " << l << "\n";

    l.reverse();
    std::cout << "Reversed List : " << l << "\n";

    l.sort();
    std::cout << "Sorted List   : " << l << "\n";

    l.push_back(3);
    std::cout << "Add duplicate : " << l << "\n";

    l.unique();
    std::cout << "After Unique  : " << l << "\n";
    
    l.assign(1, 99);
    std::cout << "After Assign  : " << l << "\n";

    return 0;
}
