#include <iostream>

template<size_t S>
class FixedString {
public:
 FixedString(const char* s=nullptr) {
   // set first and last bytes to null ('\0')
   str_[0] = str_[S] = 0;
   if (s) std::strncpy(str_, s, sizeof str_ - 1);
 }

 // conversion operator
 // user-defined conversion function
 operator const char* () {
   return str_;
 }

private:
 // keep an extra char for null
 char str_[S + 1];
};

int main() {
    FixedString<4> s1("Hey");

    std::cout << "s1 " << s1 << " " << std::endl;

    const char* cool = "Cool";
    s1 = cool;
    auto s2 = s1;
    std::cout << "s1 " << s1 << " " << std::endl;
    std::cout << "s1 ? " << (s1 ? "True " : "False ") << std::endl;
    std::cout << "s1 == cool ? " << (s1 == cool ? "True " : "False ") << std::endl;
    std::cout << "strcmp(s1, cool) ? " << (strcmp(s1,cool) == 0 ? "True " : "False ") << std::endl;
}
