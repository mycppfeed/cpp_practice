#include <iostream>
#include <chrono>

void test_0() {
    /**
     *
     * Duration
     *  A duration consists of a span of time, defined as some number of ticks of some time unit.
     *  For example, "42 seconds" could be represented by a duration consisting of 42 ticks of a 1-second time unit.
     *
     * template<
     *    class Rep,
     *    class Period = std::ratio<1>
     *   > class duration;
     *
     *  It consists of a count of ticks of type Rep and a tick period.
     *  Rep:
     *      The only data stored in a duration is a tick count of type Rep.
     *      If Rep is floating point, then the duration can represent fractions of ticks.
     *
     *  Period:
     *      The tick period is a compile-time rational constant, representing the number of seconds from one tick to the next.
     *      Period is included as part of the duration's type, and is only used when converting between different durations.

     */

    auto PrintNanoSeconds = [](std::chrono::nanoseconds ns) {
        std::cout << "  " << ns.count() << " Nano Seconds\n";
    };

    std::chrono::seconds s1;
    std::chrono::seconds s2(10);
    PrintNanoSeconds(s1);
    PrintNanoSeconds(s2);

//    std::chrono::seconds s3{10};

}

void test_1() {
    constexpr auto year = 31556952ll; // seconds in average Gregorian year
    using shakes = std::chrono::duration<int, std::ratio<1, 100000000>>;
    using jiffies = std::chrono::duration<int, std::centi>;
    using microfortnights = std::chrono::duration<float, std::ratio<14*24*60*60, 1000000>>;
    using nanocenturies = std::chrono::duration<float, std::ratio<100*year, 1000000000>>;

    std::chrono::seconds sec(1);

    std::cout << "1 second is:\n";

    // integer scale conversion with no precision loss: no cast
    std::cout << std::chrono::microseconds(sec).count() << " microseconds\n"
              << shakes(sec).count() << " shakes\n"
              << jiffies(sec).count() << " jiffies\n";

    // integer scale conversion with precision loss: requires a cast
    std::cout << std::chrono::duration_cast<std::chrono::minutes>(sec).count()
              << " minutes\n";

    // floating-point scale conversion: no cast
    std::cout << microfortnights(sec).count() << " microfortnights\n"
              << nanocenturies(sec).count() << " nanocenturies\n";
}

int main() {
    test_0();
    test_1();
    return 0;
}
