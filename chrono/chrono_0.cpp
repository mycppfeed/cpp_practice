#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

int main() {
//    for (size_t i = 0; i < 10; i++) {
//        auto tmp = std::chrono::steady_clock::now();
//        auto dur = tmp.time_since_epoch();
//        std::cout << dur.count() << "\n\n";
//        std::this_thread::sleep_for(std::chrono::seconds(1));
//    }

    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t t_c = std::chrono::system_clock::to_time_t(now - std::chrono::hours(24));
    std::cout << "24 hours ago, the time was "
              << std::put_time(std::localtime(&t_c), "%F %T") << '\n';

    std::cout << "\n\n\n";

    return 0;
}
//951949378437991
//951640965240214 secs

// 15862.6 mins
// 660.941666666666667 days
