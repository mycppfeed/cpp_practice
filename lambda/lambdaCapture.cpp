#include <cstdio>
#include <string>

int main()
{
    std::string s1 = "";
    std::string s2 = "Suffix";

    auto ret = std::equal(s2.rbegin(), s2.rend(), s1.rbegin());
    assert(ret);
}
