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

    l.assign(6, 9);
    std::cout << "After Assign n: " << l << "\n";

    l.clear();
    std::cout << "After clear   : " << l << "\n";

    for (auto i = 0; i < 10; i++) l.push_back(i);
    std::cout << "After Reinit  : " << l << "\n";

    // Note, list position is indexed with 0
    auto it = l.begin();
    std::advance(it, 4);
    std::cout << "Data at pos 5 : " << *it << "\n";

    // Note, list iterator is bidirectional.
    // So, it wraps to pos 0 when end is reached.
    it = l.begin();
    std::advance(it, l.size() + 2);
    std::cout << "Data at pos 2 : " << *it << "\n";

    return 0;
}
