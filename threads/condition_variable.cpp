#include <thread>
#include <iostream>
#include <chrono>

uint64_t balance;
std::mutex myMtx;
std::condition_variable cv;
void Deposit(uint64_t amount) {
    std::cout << "TID : " << std::this_thread::get_id() << " " << __PRETTY_FUNCTION__ << "\n";
    std::cout << "TID : " << std::this_thread::get_id() << " " << "Try to get lock on mutex\n";
    std::lock_guard<std::mutex> lock(myMtx);
    std::cout << "TID : " << std::this_thread::get_id() << " " << "Got lock on mutex\n";
    std::cout << "TID : " << std::this_thread::get_id() << " " << "Deposit amount " << amount << "\n";
    
    balance += amount;
    std::cout << "TID : " << std::this_thread::get_id() << " " << "Notify conditional variable\n";
    cv.notify_all();
}

void Withdraw(uint64_t amount) {
    std::cout << "TID : " << std::this_thread::get_id() << " " << __PRETTY_FUNCTION__ << "\n";
    std::cout << "TID : " << std::this_thread::get_id() << " " << "Try to get unique lock on mutex\n";
    std::unique_lock<std::mutex> lock(myMtx);
    std::cout << "TID : " << std::this_thread::get_id() << " " << "Got unique lock on mutex\n";

    std::cout << "TID : " << std::this_thread::get_id() << " " << "Conditional variable waiting on balance > 0\n";
    cv.wait(lock, []() { return balance > 0; });
    std::cout << "TID : " << std::this_thread::get_id() << " " << "Conditional variable succeded on balance > 0\n";
    
    if (balance < amount) {
        std::cout << "TID : " << std::this_thread::get_id() << " " << "Error: Balance [ " << balance << " ] is less than " << amount << "\n";
    }
    else {
        std::cout << "TID : " << std::this_thread::get_id() << " " << "Success: Withdrawn " << amount << " from balance [ " << balance << " ] \n";
        balance -= amount;
    }
    return;
}

int main() {
    std::thread t1(Withdraw, 500);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::thread t2(Deposit, 500);

    t1.join();
    t2.join();

    return 0;
}
