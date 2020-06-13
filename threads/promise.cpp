#include <iostream>
#include <thread>
#include <chrono>
#include <future>

/****************************************************************************************
* Basic std::async
****************************************************************************************/

int taskReturn100() {
    std::cout << "\n\nTID : " << std::this_thread::get_id() << " " << __PRETTY_FUNCTION__ << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 100;
}

void BasicAsync() {
    std::cout << "TID : " << std::this_thread::get_id() << " " << __PRETTY_FUNCTION__ << "\n";
    std::future<int> tmp = std::async(std::launch::async, taskReturn100);
    std::cout << "TID : " << std::this_thread::get_id() << " " << " Waiting for the future to return\n";
    std::cout << "TID : " << std::this_thread::get_id() << " " << " Future returned " << tmp.get() << "\n";
    std::cout << "\n\n\n\n";
}
/****************************************************************************************
 * Basic Future promise
 ****************************************************************************************/
void taskSetPromise100(std::promise<int>&& promise) {
    std::cout << "\n\nTID : " << std::this_thread::get_id() << " " << __PRETTY_FUNCTION__ << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    promise.set_value(100);
}

void BasicPromiseFuture() {
    std::cout << "TID : " << std::this_thread::get_id() << " " << __PRETTY_FUNCTION__ << "\n";
    std::promise<int> myPromise;
    std::future<int> myFuture = myPromise.get_future();
    
    std::thread t1(taskSetPromise100, std::move(myPromise));

    std::cout << "TID : " << std::this_thread::get_id() << " " << " Waiting for the future to return\n";
    std::cout << "TID : " << std::this_thread::get_id() << " " << " Future returned " << myFuture.get() << "\n";

    t1.join();
    std::cout << "\n\n\n\n";
}

int main() {
    BasicPromiseFuture();
    BasicAsync();
    return 0;
}
