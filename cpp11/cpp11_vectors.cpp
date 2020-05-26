// cpp11_vectors.cpp

#include <stdio.h>
#include <vector>

void test_1() {
    std::vector<int> myIntVect{0, 1, 2, 3};

    for (auto i : myIntVect) {
        printf("%d\n", i);
    }
}

class MyIntVector {
public:
    MyIntVector() {
        _instance_count++;
        _instance_id = _instance_count;
    }

    void printInfo() {
        printf("Info of MyIntVector\n");
        printf("\t Capacity / Size : [ %zu / %zu ]\n", _v.capacity(), _v.size());
        printf("\t        Elements : ");
        for (auto i : _v) printf("%2d, ", i);
        printf("\n");
    }

    //  Member functions
    void assign(size_t count, int val)       { return _v.assign(count, val); }

    //  Element access
    int at(size_t pos) { return at(pos); }
    int operator[](size_t pos) { return _v[pos]; }
    int front(size_t pos) { return _v.front(); }
    int back(size_t pos) { return _v.back(); }
    int* data(size_t pos) { return _v.data(); }

    const int at(size_t pos) const { return at(pos); }
    const int operator[](size_t pos) const { return _v[pos]; }
    const int front(size_t pos) const { return _v.front(); }
    const int back(size_t pos) const { return _v.back(); }
    const int* data(size_t pos) const { return _v.data(); }

    void push_back(int i) { return _v.push_back(i); }
    void pop_back()       { return _v.pop_back(); }
    void erase_all()      { _v.erase(_v.begin(), _v.end()); }

    size_t size()         { return _v.size(); }
    size_t capacity()     { return _v.capacity(); }

private:
    static int _instance_count;
    int _instance_id;
    std::vector<int> _v;
};
int MyIntVector::_instance_count = 0;

void test_2() {
    MyIntVector myIntVector;
    myIntVector.printInfo();

    for (auto i = 0; i < 10; i++) {
        myIntVector.push_back(10 - i);
        myIntVector.printInfo();
    }
    return;
}

void printInfo(std::vector<int> _v) {
    printf("Info of MyIntVector\n");
    printf("\t Capacity / Size : [ %zu / %zu ]\n", _v.capacity(), _v.size());
    printf("\t        Elements : ");
    for (auto i : _v) printf("%2d, ", i);
    printf("\n");
}


void test_3() {
    std::vector<int> myIntVector;
    printInfo(myIntVector);

    for (auto i = 0; i < 10; i++) {
        myIntVector.push_back(10 - i);
        printInfo(myIntVector);
    }

    myIntVector.erase(myIntVector.begin(), myIntVector.end());
    printInfo(myIntVector);
    return;
}

int main() {
    test_1();
    test_2();
    test_3();
    return 0;
}