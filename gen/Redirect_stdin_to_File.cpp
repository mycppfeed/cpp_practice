#include <iostream>

using namespace std;

int main() {
    freopen("/Users/user/in.txt", "r", stdin); // redirects standard input
    freopen("/Users/user/out.txt", "w", stdout); // redirects standard output

    std::string x;
    cin >> x; // reads from input.txt
    
    cout << x << endl; // writes to output.txt
}
