#include <thread>
#include <iostream>

class TestMutex {

public:
    TestMutex() {
        Init(1000000);

        IncrementData(_data[0], None);
        IncrementData(_data[0], None);
        printData(_data[0]);

        std::thread t1(&TestMutex::IncrementData, this, std::ref(_data[1]), None);
        std::thread t2(&TestMutex::IncrementData, this, std::ref(_data[1]), None);
        t1.join();
        t2.join();
        printData(_data[1]);

        std::thread t3(&TestMutex::IncrementData, this, std::ref(_data[2]), RegularMutex);
        std::thread t4(&TestMutex::IncrementData, this, std::ref(_data[2]), RegularMutex);
        t3.join();
        t4.join();
        printData(_data[2]);

        std::thread t7(&TestMutex::IncrementDataLockGuard, this, std::ref(_data[3]));
        std::thread t8(&TestMutex::IncrementDataLockGuard, this, std::ref(_data[3]));
        t7.join();
        t8.join();
        printData(_data[3]);
    }
    
    void Init(uint64_t count) { _count = count; }
    void printData(uint64_t data) { std::cout << "TID : " << std::this_thread::get_id() << " Data: " << data << "\n\n"; }

private:
    enum MutexType { None = 0, RegularMutex = 1, LockGuard = 2 };

    uint64_t _count = 0;
    uint64_t _data[5];
    
    std::mutex myMtx;
    void IncrementData(uint64_t& data, MutexType mType) {
        if (mType == RegularMutex) myMtx.lock();
        for(size_t i = 0; i < _count; i++) data++;
        if (mType == RegularMutex) myMtx.unlock();
    }
    
    void IncrementDataLockGuard(uint64_t& data) {
        std::lock_guard<std::mutex> lock(myMtx);
        for(size_t i = 0; i < _count; i++) data++;
    }

};

int main() {
    TestMutex t1;
    return 0;
}
