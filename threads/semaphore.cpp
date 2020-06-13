#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>

class Semaphore {
    using Lock = std::unique_lock<std::mutex>;

    Semaphore(const Semaphore&);
    Semaphore& operator=(const Semaphore&);

public:
    explicit Semaphore(unsigned int count = 0) : _count(count) {}

    void Signal() {
        (Lock(_mtx), _count++);
        _cv.notify_one();
    }

    template<typename Duration>
    bool Wait(Duration dur) {
        Lock lock(_mtx);

        if (_count > 0 || _cv.wait_for(lock, dur, [=] { return _count > 0; })) {
            _count--;
            return true;
        }
        return false;
    }

private:
    std::mutex _mtx;
    std::condition_variable _cv;
    unsigned int _count;
};

class Example {
    std::thread _worker;
    std::mutex _mtx;
    Semaphore _sem;

    std::atomic_bool _active {true};

    void Work() {
        auto tid = std::this_thread::get_id();
        while (_active) {
            std::cout << " TID: " << tid << " Sleep inside Work\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << " TID: " << tid << " Woken from Work\n";
            _sem.Wait(std::chrono::seconds(2));
        }
    }
public:
    Example() {
        std::cout << __PRETTY_FUNCTION__ << "\n";
        _worker = std::thread(&Example::Work, this);
    }

    ~Example() {
        std::cout << __PRETTY_FUNCTION__ << "\n";
        _active = false;
        _sem.Signal();

        if (_worker.joinable()) _worker.join();
    }
};

int main() {
    Example e1;
    Example e2;
    return 0;
}
