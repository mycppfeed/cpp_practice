
#include <iostream>
#include <boost/filesystem.hpp>

auto PrintLine = [](){ std::cout << "=======================================\n"; };
auto PrintMsg = [](const std::string& msg) { PrintLine(); std::cout << msg <<"\n"; PrintLine();};

template<typename Func>
void TryExec(Func f) {
    try { f(); }
    catch(std::exception& e) { std::cout << __LINE__ << " Exception : " << e.what() << "\n"; }
};

void test_1(const std::string& file_path) {
    PrintLine();

    auto t1 = [=](){
        if ( boost::filesystem::exists(file_path) ) std::cout << __LINE__ << " " << file_path <<" Exists\n";
        else std::cout << __LINE__ << " " << file_path <<" Doesnt Exists\n";
    };
    TryExec(t1);

    auto t2 = [=]() {
        if ( boost::filesystem::is_empty(file_path) ) std::cout << __LINE__ << "\t Is empty\n";
        else std::cout << __LINE__ << "\t Is not empty\n";
    };
    TryExec(t2);

    auto t3 = [=]() { std::cout << __LINE__ << "\t Size = " << boost::filesystem::file_size(file_path) << "\n"; };
    TryExec(t3);
    auto t4 = [=]() { std::cout << __LINE__ << " Absolute path of " << file_path << " is " << boost::filesystem::absolute(file_path) << "\n"; };
    TryExec(t4);
    auto t5 = [=]() { std::cout << __LINE__ << " Canonical => " << boost::filesystem::canonical(file_path) << "\n"; };
    TryExec(t5);
    auto t6 = [=]() { std::cout << __LINE__ << " Canonical => " << boost::filesystem::canonical(file_path, "/tmp") << "\n"; };

#if __cplusplus >= 201703L
    TryExec(t6);
    auto t7 = [=]() { std::cout << __LINE__ << " Hash => " << std::filesystem::hash_value(file_path) << "\n"; };
    TryExec(t7);
//    auto t8 = [=]() { std::cout << __LINE__ << " Hash => " << boost::filesystem::hash_value(file_path) << "\n"; };
//    TryExec(t8);
#endif

    PrintLine();
}


int main(int argc, char* argv[])
{
    std::string fpath;

    std::cout << __LINE__ << " argc = " << argc << "\n";
    if (argc >= 2) fpath = argv[1];

    test_1(fpath);

    return 0;
}
