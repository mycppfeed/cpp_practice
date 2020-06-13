#include <iostream>
#include <thread>
#include <chrono>

/**
 *  Constants
 */
namespace ConstVals {
    uint64_t start = 0;
    uint64_t end = 10;
//    uint64_t end = 1900000000;
}

/**
 * Global Data Variable
 */
uint64_t GEvens = 0, GOdds = 0;

/**
 * Free Lambdas
 */
auto PrintLine = [](std::string fn_name = "") {
    std::cout << "\n=========================================\n\n";
    if (! fn_name.empty()) std::cout << fn_name << ":\n\n";
};

auto PrintSums = [](uint64_t evens, uint64_t odds) {
    std::cout << "Evens sum : " << evens << "\n";
    std::cout << "Odds sum  : " << odds << "\n\n";
};

auto LRefAddEvens = [](uint64_t start, uint64_t end, uint64_t& sum) {
    std::cout <<" TID : " << std::thread::id() << "\t" << std::this_thread::get_id() << "\n";
    for(uint64_t i = start; i <= end; i++) if (!(i & 1)) sum += i;
};

auto LRefAddOdds = [](uint64_t start, uint64_t end, uint64_t& sum) {
    std::cout <<" TID : " << std::thread::id() << "\t" << std::this_thread::get_id() << "\n";
    for(uint64_t i = start; i <= end; i++) if (i & 1) sum += i;
};


auto L_Global_AddEvens = [](uint64_t start, uint64_t end) {
    std::cout <<" TID : " << std::thread::id() << "\t" << std::this_thread::get_id() << "\n";
    for(uint64_t i = start; i <= end; i++) if (!(i & 1)) GEvens += i;
};

auto L_Global_AddOdds = [](uint64_t start, uint64_t end) {
    std::cout <<" TID : " << std::thread::id() << "\t" << std::this_thread::get_id() << "\n";
    for(uint64_t i = start; i <= end; i++) if (i & 1) GOdds += i;
};


/**
 * Free Functions
 */
void Fn_AddEvens_Ref(uint64_t start, uint64_t end, uint64_t& sum) {
    std::cout <<" TID : " << std::thread::id() << "\t" << std::this_thread::get_id() << "\n";
    for(uint64_t i = start; i <= end; i++) if (!(i & 1)) sum += i;
};

void Fn_AddOdds_Ref(uint64_t start, uint64_t end, uint64_t& sum) {
    std::cout <<" TID : " << std::thread::id() << "\t" << std::this_thread::get_id() << "\n";
    for(uint64_t i = start; i <= end; i++) if (i & 1) sum += i;
};

void Fn_AddEvens_Global(uint64_t start, uint64_t end) {
    std::cout <<" TID : " << std::thread::id() << "\t" << std::this_thread::get_id() << "\n";
    for(uint64_t i = start; i <= end; i++) if (!(i & 1)) GEvens += i;
};

void Fn_AddOdds_Global(uint64_t start, uint64_t end) {
    std::cout <<" TID : " << std::thread::id() << "\t" << std::this_thread::get_id() << "\n";
    for(uint64_t i = start; i <= end; i++) if (i & 1) GOdds += i;
};


/**
 * Tests
 */
void ThreadWithLambda_Global() {
    PrintLine(__PRETTY_FUNCTION__);
    auto TStart = std::chrono::high_resolution_clock::now();

    std::thread threadEven(L_Global_AddEvens, ConstVals::start, ConstVals::end);
    std::thread threadOdd(L_Global_AddOdds, ConstVals::start, ConstVals::end);

    threadOdd.join();
    threadEven.join();

    auto TEnd = std::chrono::high_resolution_clock::now();
    auto TDiff = std::chrono::duration_cast<std::chrono::microseconds>(TEnd - TStart);

    PrintSums(GEvens, GOdds);

    std::cout << "Total time taken: [ " << TDiff.count() / 1000000 << " ] "
              << TDiff.count() << " microseconds" << "\n\n";
    PrintLine();
}


void ThreadWithLambda_Ref() {
    PrintLine(__PRETTY_FUNCTION__);
    auto TStart = std::chrono::high_resolution_clock::now();

    uint64_t EvenSum = 0, OddSum = 0;
    std::thread threadEven(LRefAddEvens, ConstVals::start, ConstVals::end, std::ref(EvenSum));
    std::thread threadOdd(LRefAddOdds, ConstVals::start, ConstVals::end, std::ref(OddSum));

    threadOdd.join();
    threadEven.join();

    auto TEnd = std::chrono::high_resolution_clock::now();
    auto TDiff = std::chrono::duration_cast<std::chrono::microseconds>(TEnd - TStart);

    PrintSums(EvenSum, OddSum);

    std::cout << "Total time taken: [ " << TDiff.count() / 1000000 << " ] "
              << TDiff.count() << " microseconds" << "\n\n";
    PrintLine();
}


void ThreadWithFunction_Global() {
    PrintLine(__PRETTY_FUNCTION__);
    auto TStart = std::chrono::high_resolution_clock::now();

    std::thread threadEven(Fn_AddEvens_Global, ConstVals::start, ConstVals::end);
    std::thread threadOdd(Fn_AddOdds_Global, ConstVals::start, ConstVals::end);

    threadOdd.join();
    threadEven.join();

    auto TEnd = std::chrono::high_resolution_clock::now();
    auto TDiff = std::chrono::duration_cast<std::chrono::microseconds>(TEnd - TStart);

    PrintSums(GEvens, GOdds);

    std::cout << "Total time taken: [ " << TDiff.count() / 1000000 << " ] "
              << TDiff.count() << " microseconds" << "\n\n";
    PrintLine();
}


void ThreadWithFunction_Ref() {
    PrintLine(__PRETTY_FUNCTION__);
    auto TStart = std::chrono::high_resolution_clock::now();

    uint64_t EvenSum = 0, OddSum = 0;
    std::thread threadEven(Fn_AddEvens_Ref, ConstVals::start, ConstVals::end, std::ref(EvenSum));
    std::thread threadOdd(Fn_AddOdds_Ref, ConstVals::start, ConstVals::end, std::ref(OddSum));

    threadOdd.join();
    threadEven.join();

    auto TEnd = std::chrono::high_resolution_clock::now();
    auto TDiff = std::chrono::duration_cast<std::chrono::microseconds>(TEnd - TStart);

    PrintSums(EvenSum, OddSum);

    std::cout << "Total time taken: [ " << TDiff.count() / 1000000 << " ] "
              << TDiff.count() << " microseconds" << "\n\n";
    PrintLine();
}


void noThread() {
    PrintLine(__PRETTY_FUNCTION__);
    auto TStart = std::chrono::high_resolution_clock::now();

    uint64_t EvenSum = 0, OddSum = 0;
    Fn_AddEvens_Ref(ConstVals::start, ConstVals::end, EvenSum);
    Fn_AddOdds_Ref(ConstVals::start, ConstVals::end, OddSum);

    auto TEnd = std::chrono::high_resolution_clock::now();
    auto TDiff = std::chrono::duration_cast<std::chrono::microseconds>(TEnd - TStart);

    PrintSums(EvenSum, OddSum);

    std::cout << "Total time taken: [ " << TDiff.count() / 1000000 << " ] "
              << TDiff.count() << " microseconds" << "\n\n";
    PrintLine();
}

void ThreadJoinErrors() {
    std::thread t1;
    try {
        t1.join();
    } catch (std::exception& e) {
        std::cout << "Exception : " << e.what() << "\n\n";
    }
}

int main() {
    ThreadJoinErrors();
    noThread();
    ThreadWithFunction_Ref();
    ThreadWithFunction_Global();
    ThreadWithLambda_Ref();
    ThreadWithLambda_Global();
    return 0;
}
