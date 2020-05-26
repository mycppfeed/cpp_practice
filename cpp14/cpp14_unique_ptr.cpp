#include <iostream>
#include <memory>

class X {
public:
    X() {
        instance_count++;
        instance_id = instance_count;
        printf("[ %2d ] X's Constructor\n", instance_id);
    }

    ~X() {
        printf("[ %2d ] X's Destructor\n", instance_id);
    }

    void SayHi() {
        printf("[ %2d ] Hi from X\n", instance_id);
    }

private:
    static int instance_count;
    int instance_id;
};

int X::instance_count = 0;

void print_line() {
    std::cout << "----------------------------------------------------------\n"; return;
}

void test_with_raw_ptr() {
    print_line();

    X *x = new X{};
    x->SayHi();

    print_line();
    return;
}

// Example on how to return a unique_ptr;
// Here, Move semantics come into play.
// Ref: https://stackoverflow.com/questions/9827183/why-am-i-allowed-to-copy-unique-ptr
auto getXsUniquePtr() {
    auto x = std::make_unique<X>();

    // The following line is equivalent to return std::move(x)
    return x;
}

void test_with_uniq_ptr() {
    print_line();

    auto x = std::make_unique<X>();
    x->SayHi();
    print_line();

    // Unique Ptr cannot be copied.
    // auto y = x;

    // Reason:
    //  unique_ptr(const unique_ptr&) = delete;
    //  unique_ptr& operator=(const unique_ptr&) = delete;

    // Example on how to return a unique_ptr;
    // Here, Move semantics come into play.
    // Ref: https://stackoverflow.com/questions/9827183/why-am-i-allowed-to-copy-unique-ptr
    auto z = getXsUniquePtr();
    x->SayHi();
    print_line();

    return;
}

int main() {

    test_with_raw_ptr();
    test_with_uniq_ptr();

    return 0;
}