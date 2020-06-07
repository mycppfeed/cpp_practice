#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

auto PrintLine = [] () { std::cout << "==============================================\n"; };

int global = -1;

void test_3() {
    PrintLine();
    auto LambdaWithException = [] () { // If 'noexcept' is added, then the exception wont be caught
        throw std::runtime_error("ExampleException");
    };

    try {
        std::cout << "LambdaWithException:\n";
        LambdaWithException();
    } catch (std::runtime_error & e) {
        std::cout << "Exception from lambda: " << e.what() << "\n\n";
    }
    PrintLine();
}

void test_2() {
//    int local_1 = 0;
    static int static_local_1 = 0;
    constexpr auto contexpr_local = 10;

    PrintLine();
    // error: 'static_local_1' cannot be captured because it does not have automatic storage duration
    // auto CaptureStaticWithoutCapture = [static_local_1] {

    // error: 'global' cannot be captured because it does not have automatic storage duration
    // auto CaptureGlobalByValue = [ global ] {

    // auto CaptureStaticWithoutCapture = [ = ] { // is equal to
    // auto CaptureStaticWithoutCapture = [ & ] { // is equal to
     auto CaptureStaticWithoutCapture = [] {
        std::cout << " Global value in lambda : " << global << "\n";
        std::cout << " Static Local value in lambda : " << static_local_1 << "\n";
        std::cout << " contexpr_local value in lambda : " << contexpr_local << "\n\n";

        global++;
        static_local_1++;

        std::cout << " Global value in lambda after increment : " << global << "\n";
        std::cout << " Static Local value in lambda after increment : " << static_local_1 << "\n\n";
    };

    std::cout << "CaptureStaticWithoutCapture :\n";
    std::cout << " Global value in func before lambda : " << global << "\n";
    std::cout << " Static Local value in func before lambda : " << static_local_1 << "\n\n";

    CaptureStaticWithoutCapture();

    std::cout << " Global value in func after lambda : " << global << "\n";
    std::cout << " Static Local value in func after lambda : " << static_local_1 << "\n\n";
}

void test_1() {
    PrintLine();

    auto simple = []{ std::cout << " This is a simple lambda\n\n"; };
    simple();

    PrintLine();

    int local = 0;
    std::cout << "DefaultLambda:\n";
    std::cout << " Global Value in func   : " << global << "\n";
    auto DefaultLambda = []{
        std::cout << " Global Value in lambda : " << global << "\n";
        global++;
        std::cout << " Global Value in lambda : " << global << "\n";

        // error: variable 'local' cannot be implicitly captured in a lambda with no capture-default specified
        // std::cout << " Local Value in func    : " << local << "\n";
    };
    DefaultLambda();
    std::cout << " Global Value in func   : " << global << "\n\n";

    PrintLine();
    std::cout << "CaptureAllByValue:\n";
    std::cout << " Global Value in func   : " << global << "\n";
    std::cout << " Local  Value in func   : " << local << "\n\n";
    // error: 'global' cannot be captured because it does not have automatic storage duration
    // auto CaptureGlobalByValue = [ global ] {
    auto CaptureAllByValue = [ = ]{
        global++;

        // error: cannot assign to a variable captured by copy in a non-mutable lambda
        // local++;
        std::cout << " Global Value in lambda : " << global << "\n";
        std::cout << " Local  Value in lambda : " << global << "\n\n";
    };
    CaptureAllByValue();
    std::cout << " Global Value in func   : " << global << "\n";
    std::cout << " Local  Value in func   : " << local << "\n\n";

    PrintLine();
    std::cout << "CaptureAllByRef:\n";
    std::cout << " Global Value in func   : " << global << "\n";
    std::cout << " Local  Value in func   : " << local << "\n\n";
    auto CaptureAllByRef = [ & ] {
        global++;
        local++;
        std::cout << " Global Value in lambda : " << global << "\n";
        std::cout << " Local  Value in lambda : " << local << "\n\n";
    };
    CaptureAllByRef();
    std::cout << " Global Value in func   : " << global << "\n";
    std::cout << " Local  Value in func   : " << local << "\n\n";

    PrintLine();
    int local2 = 0;
    std::cout << "CaptureBothByRefAndValue:\n";
    std::cout << " Global Value in func   : " << global << "\n";
    std::cout << " Local  Value in func   : " << local << "\n";
    std::cout << " Local-2 Value in func  : " << local2 << "\n\n";
    auto CaptureBothByRefAndValue = [ &, local2 ]{
        global++;
        local++;
        // local2++;
        std::cout << " Global Value in lambda : " << global << "\n";
        std::cout << " Local  Value in lambda : " << local << "\n";
        std::cout << " Local-2 Value in lambda: " << local2 << "\n\n";
    };
    CaptureBothByRefAndValue();
    std::cout << " Global Value in func   : " << global << "\n";
    std::cout << " Local  Value in func   : " << local << "\n";
    std::cout << " Local-2 Value in func  : " << local2 << "\n\n";

    PrintLine();
    std::cout << "MutableLambda: allows body to modify the objects captured by copy, and to call their non-const member functions \n";
    std::cout << " Global Value in func   : " << global << "\n";
    std::cout << " Local  Value in func   : " << local << "\n";
    std::cout << " Local-2 Value in func  : " << local2 << "\n\n";
    auto MutableLambda = [ = ] () mutable {
        global++;
        local++;
        local2++;
        std::cout << " Global Value in lambda : " << global << "\n";
        std::cout << " Local  Value in lambda : " << local << "\n";
        std::cout << " Local-2 Value in lambda: " << local2 << "\n\n";
    };
    MutableLambda();
    std::cout << " Global Value in func   : " << global << "\n";
    std::cout << " Local  Value in func   : " << local << "\n";
    std::cout << " Local-2 Value in func  : " << local2 << "\n\n";

    PrintLine();
    std::cout << "Alias Capture:\n";
    auto AliasCapture = [n = 10] {
        std::cout << " Alias Captured n = " << n << "\n\n";
    };
    AliasCapture();

    PrintLine();
}

int main(){
    test_1();
    test_2();
    test_3();

    return 0;
}
