#include <iostream>
#include <string>
#include <map>

 struct A
 {
     std::string name;
     int age;

     // introduced for logging purposes only
     A(){ std::cout << "Default ctor. "; }

     //explicit
     A(std::string const& s, int x):name(s), age(x){
         std::cout << "Ctor. ";
     }

     A(A const& a):name(a.name),age(a.age){
         std::cout << "Copy ctor. ";
     }

     A(A && a) noexcept :name(std::move(a.name)),age(std::move(a.age)){
         std::cout << "Move ctor. ";
     }

     A& operator=(A const& a){
         std::cout << "Copy assign. ";
         name = a.name, age = a.age;
         return *this;
     }

     A& operator=(A && a) noexcept {
         std::cout << "Move assign. ";
         name = std::move(a.name), age = std::move(a.age);
         return *this;
     }

     ~A() noexcept { std::cout << "Dtor. "; }
 };

int main() {
#if 0
//     C++03 style
//    std::map<int, std::string> m03_0;
//    m03_0[1] = "Ann";

//     C++03 style
    std::map<int, std::string> m03_1;
//     Error: No matching member function call to insert.
//     We need m.insert( std::make_pair() )
//    m.insert(1, "Ann");
    m03_1.insert(std::make_pair(1, "Ann"));


    // Ctor. Default ctor. Move assign. Dtor. Dtor.
    auto m11_0 = std::map<int, A> {};
    auto a = A("Ann", 63);
    m11_0[1] = a;

    // Ctor. Move ctor. Move ctor. Dtor. Dtor. Dtor.
    auto m11_1 = std::map<int, A> {};
    m11_1.insert({1, a});
#endif
    auto m = std::map<int, A> {};

    // (1) Ctor. Copy ctor. Move ctor. Dtor. Dtor. Dtor.
    m.insert({1, {"Ann", 63}});
    std::cout << "\n\n\n";

    // (2) Ctor. Move ctor. Move ctor. Dtor. Dtor. Dtor.
    m.insert(std::make_pair(1, A("Ann", 63)));
    std::cout << "\n\n\n";

    // (3) Ctor. Move ctor. Move ctor. Dtor. Dtor. Dtor.
    m.insert({1, A("Ann", 63)});
    std::cout << "\n\n\n";

    // (4) Ctor. Move ctor. Move ctor. Dtor. Dtor. Dtor.
    m.emplace(std::make_pair(1, A("Ann", 63)));
    std::cout << "\n\n\n";

    // (5) Ctor. Move ctor. Dtor. Dtor.
    m.emplace(1, A("Ann", 63));
    std::cout << "\n\n\n";

    // (6) Doesn't compile. That is why try_emplace of C++17 is of interest
    // m.emplace(1, "Ann", 63);

    // (7) Ctor. Dtor.
    m.emplace(std::piecewise_construct,
    std::forward_as_tuple(1),
    std::forward_as_tuple("Ann", 63));
    std::cout << "\n\n\n";

    return 0;
}
