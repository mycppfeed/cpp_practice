#include <iostream>
#include <filesystem>

auto PrintLine = [](){ std::cout << "=======================================\n"; };
auto PrintX = [](){ std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"; };
auto PrintY = [](){ std::cout << "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\n"; };
auto PrintMsg = [](const std::string& msg) { PrintLine(); std::cout << msg <<"\n"; PrintLine();};

template<typename Func>
void TryExec(Func f) {
    PrintX();
    try { f(); }
    catch(std::exception& e) { std::cout << __LINE__ << " Exception : " << e.what() << "\n"; }
    PrintY(); std::cout <<"\n\n";
};

void test_1(const std::string& file_path) {
    PrintLine();

    auto t1 = [=](){
        std::cout << __LINE__ << " std::filesystem::exists( " << file_path << " ):\n\t";
        std::cout << (std::filesystem::exists(file_path)? "Exists" : "Doesn't Exists") << "\n"; };
    TryExec(t1);

    auto t2 = [=]() {
        std::cout << __LINE__ << " std::filesystem::is_empty( " << file_path << " ):\n\t";
        std::cout << ( (std::filesystem::exists(file_path) == 0)? "Empty" : "Not Empty") << "\n"; };
    TryExec(t2);

    auto t3 = [=]() {
        std::cout << __LINE__ << " std::filesystem::file_size( " << file_path << " ):\n\t";
        std::cout << std::filesystem::file_size(file_path) << "\n"; };
    TryExec(t3);

    auto t4 = [=]() {
        std::cout << __LINE__ << " std::filesystem::absolute( " << file_path << " ):\n\t";
        std::cout << std::filesystem::absolute(file_path) << "\n"; };
    TryExec(t4);

    auto t5 = [=]() {
        std::cout << __LINE__ << " std::filesystem::canonical( " << file_path << " ):\n\t";
        std::cout << std::filesystem::canonical(file_path) << "\n"; };
    TryExec(t5);

    auto t6 = [=]() {
        std::cout << __LINE__ << " std::filesystem::hash_value( " << file_path << " ):\n\t";
        std::cout << std::filesystem::hash_value(file_path) << "\n"; };
    TryExec(t6);

    auto t7 = [=]() {
        std::cout << __LINE__ << " std::filesystem::relative( " << file_path << " ):\n\t";
        std::cout << std::filesystem::relative(file_path) << "\n"; };
    TryExec(t7);

    auto t8 = [=]() {
        std::cout << __LINE__ << " std::filesystem::create_directories( sandbox/1/2/a ):\n";
        std::filesystem::create_directories("sandbox/1/2/a");

        std::cout << __LINE__ << " std::filesystem::create_directory( sandbox/1/2/b ):\n";
        std::filesystem::create_directory("sandbox/1/2/b");

        std::cout << __LINE__ << " std::filesystem::permissions( sandbox/1/2/b, fs::perms::others_all, fs::perm_options::remove ):\n";
        std::filesystem::permissions("sandbox/1/2/b", std::filesystem::perms::others_all, std::filesystem::perm_options::remove);

        std::cout << __LINE__ << " std::filesystem::create_directory( sandbox/1/2/c, sandbox/1/2/b ):\n";
        std::filesystem::create_directory("sandbox/1/2/c", "sandbox/1/2/b");

        std::cout << __LINE__ << " std::system( ls -l sandbox/1/2 ):\n";
        std::system("ls -l sandbox/1/2");

        std::cout << __LINE__ << " std::filesystem::remove_all( sandbox ):\n";
        std::filesystem::remove_all("sandbox");
    };
    TryExec(t8);

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
