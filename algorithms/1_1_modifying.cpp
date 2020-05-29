
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>
#include <iterator>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v) {
    os << " [ Size : " << v.size() << " ] [ ";
    for (auto e : v) { std::cout << e << ", "; }
    os << " ]\n\n";
    return os;
}

using IntVector = std::vector<int>;

auto print_line = [](){ std::cout << "\n===========================================================\n"; };
auto print_int = [](const int i) { std::cout << i << ", ";};
auto IsEven = [](const int i) { return !(i%2); };
auto IsOdd = [](const int i) { return (i%2); };

void test_1() {
    IntVector v1(10);

    // std::copy requires memory to be preallocated
    // IntVector v2;
    IntVector v2(10);
    IntVector v3(10);

    std::iota(v1.begin(), v1.end(), 0);

    std::cout << " Initial Vector v1 : " << v1;
    std::cout << " Initial Vector v2 : " << v2;
    std::cout << " Initial Vector v3 : " << v3;

    /**
     * OutputIt copy( InputIt first, InputIt last, OutputIt d_first );
     *
     *  Copies the elements in the range, defined by [first, last), to another range beginning at d_first.
     */
    std::copy(v1.begin(), v1.end(), v2.begin());
    std::cout << " Vector v2, After copying v1, using copy : " << v2;

    std::copy_if(v1.begin(), v1.end(), v3.begin(), IsEven);
    std::cout << " Vector v3, After copying Even number using copy_if : " << v3;

    auto noOfOdds = std::count_if(v1.begin(), v1.end(), IsOdd);
    IntVector v4(noOfOdds);
    std::cout << " Vector 4, After allocating mmemory for Odd numbers : " << v4;

    std::copy_if(v1.begin(), v1.end(), v4.begin(), IsOdd);
    std::cout << " Vector 4, After copying Odd numbers using copy_if : " << v4;

    IntVector v5(5);
    std::cout << " Initial Vector 5" << v5;
    std::copy_n(v1.begin(), 5, v5.begin());
    std::cout << " Vector 5, after copying 5 elements using copy_n: " << v5;

    std::copy_backward(v1.begin(), v1.end() - 1, v1.end());
    std::cout << " Vector 1, after using copy_backward (v1.begin(), v1.end() - 1, v1.end()): " << v1;

    /**
     * Moves the elements in the range [first, last), to another range
     * beginning at d_first, starting from first and proceeding to last - 1.
     *
     * After this operation the elements in the moved-from range will still
     * contain valid values of the appropriate type, but not necessarily the
     * same values as before the move.
     */
    IntVector v6;
    v6 = std::move(v1);

    std::cout << " Vector v6, After moving v1, using move : " << v6;
    std::cout << " Vector v1, After moving v1, using move : " << v1;

    // v1.reserve(v6.size());
    // The above will cause access out of bound, because reserving memory
    // doesnt automatically resize the size and hence the iterators
    // Use resize() instead, as below

    /**
     * std::vector::reserve will allocate the memory but will not resize your vector, which will have a logical size the same as it was before.
     * std::vector::resize will actually modify the size of your vector and will fill any space with objects in their default state. If they are ints, they will all be zero.
     **/

    v1.resize(v6.size());
    std::move(v6.begin(), v6.end(), v1.begin());

    std::cout << " Vector v6, After moving v1, using move : " << v6;
    std::cout << " Vector v1, After moving v1, using move : " << v1;

    std::move_backward(v1.begin(), v1.end() - 1, v1.end());

    std::cout << " Vector v1, After moving v1, using move_backeards : " << v1;

    std::fill(v6.begin(), v6.end(), -8);
    std::cout << " Vector 6 after filling with -8, using std::fill() : " << v6;

    std::fill_n(v6.begin(), 5, 8);
    std::cout << " Vector 6 after filling first 5 position with 8, using std::fill_n() : " << v6;

    auto AddNine = [](int i) { return i + 9; };
    auto Add = [](int i, int j) { return i + j; };
    std::transform(v6.begin(), v6.end(), v6.begin(), AddNine);
    std::cout << " Vector 6 after adding 9 to evey element, using std::transform() : " << v6;

    std::transform(v6.begin(), v6.end(), v1.begin(), v6.begin(), Add);
    std::cout << " Vector 6 after adding elements in Vector 1, using std::transform() : " << v6;

#if 0
    // The following will crash, because of different in size b/w two containers
    v1.resize(v1.size() - 1);
    std::cout << " Vector v1, After reducing the size by 1 : " << v1;

    std::transform(v6.begin(), v6.end(), v1.begin(), v6.begin(), Add);
    std::cout << " Vector 6 after adding elements in Vector 1, using std::transform() : " << v6;
#endif

    auto my_rand = []() { return rand() % 10; };
    auto RetOne = []() { return 1; };
    auto RetInc = []() { static int i = 0; return i++; };

    std::generate(v6.begin(), v6.end(), my_rand);
    std::cout << " Vector 6 after assigning random elements, using std::generate() : " << v6;

    std::generate_n(v6.begin(), 5, RetOne);
    std::cout << " Vector 6 after replacing to first five elements with 1, using std::generate_n() : " << v6;

    std::remove(v6.begin(), v6.end(), 1);
    std::cout << " Vector 6 after removing all occurances of 1, using std::remove() : " << v6;
    std::cout << " .=> Note, in previous line, std::remove didnt change size of vector\n\n";

    std::generate_n(v6.begin(), 5, RetOne);
    std::cout << " Vector 6 after replacing to first five elements with 1, using std::generate_n() : " << v6;

    v6.erase(std::remove(v6.begin(), v6.end(), 1), v6.end());
    std::cout << " Vector 6 after removing all occurances of 1, using std::remove() and erase using v6.errase() : " << v6;

    v1.erase(std::remove_if(v1.begin(), v1.end(), IsOdd), v1.end());
    std::cout << " Vector 1 after removing all Odd numbers, using std::remove() and erase using v1.errase() : " << v1;
    print_line();

    v1.clear();
    v1.resize(10);
    std::generate(v1.begin(), v1.end(), my_rand);

    auto ChangeToNine = [](int i) { return 9; };
    std::transform(v1.begin() + 2, v1.begin() + 5 , v1.begin() + 2, ChangeToNine);

    std::cout << " Vector 1, generated random data and inserting 9 : " << v1;
    std::cout << " Vector 3, before use in next Operation : " << v3;

    std::remove_copy(v1.begin(), v1.end(), v3.begin(), 9);
    std::cout << " Vector 3, After copying V1 except 9, using std::remove_copy : " << v3;
    std::cout << " .=> Note, there are remaining data in Vector 3. Can be erased using returned iterator\n\n";

    std::replace(v1.begin(), v1.end(), 9, 8);
    std::cout << " Vector 1, After replacing every 9 with 8, using std::replace : " << v1;

    std::replace_if(v1.begin(), v1.end(), IsEven, 11);
    std::cout << " Vector 1, After replacing all Even numbers with 11, using std::replace_if : " << v1;

    std::replace_copy(v1.begin(), v1.end(), v3.begin(), 11, 13);
    std::cout << " Vector 3, After copying from Vector 1, replacing all 11 with 13, using std::replace_copy : " << v3;

    std::generate_n(v3.begin(), 5, RetInc);
    std::cout << " Vector 3, before use in next Operation - Use generate_n : " << v3;

    std::replace_copy_if(v3.begin(), v3.end(), v3.begin(), IsOdd, 7);
    std::cout << " Vector 3, After copying from Vector 3 (self), replacing all odd elements with 7, using std::replace_copy_if : " << v3;

    print_line();
    std::cout << " Vector 1, Before swap (complete) : " << v1;
    std::cout << " Vector 3, Before swap (complete) : " << v3;

    std::swap(v1, v3);

    std::cout << " Vector 1, After swap (complete) : " << v1;
    std::cout << " Vector 3, After swap (complete) : " << v3;

    print_line();
    std::swap_ranges(v1.begin(), v1.begin() + 5, v3.begin());

    std::cout << " Vector 1, After swap_range( 5 ) : " << v1;
    std::cout << " Vector 3, After swap_range( 5 ) : " << v3;

    print_line();
    std::iter_swap(v1.begin(), v3.begin());
    std::cout << " Vector 1, After std::iter_swap(begin) : " << v1;
    std::cout << " Vector 3, After std::iter_swap(begin) : " << v3;

    print_line();
    std::reverse(v1.begin(), v1.end());
    std::cout << " Vector 1, After std::reverse() : " << v1;

    print_line();
    std::reverse_copy(v1.begin(), v1.end(), v3.begin());
    std::cout << " Vector 1, After std::reverse_copy() : " << v1;
    std::cout << " Vector 3, After std::reverse_copy() : " << v3;

    print_line();
    std::rotate(v1.begin(), v1.begin() + 3, v1.end());
    std::cout << " Vector 1, After std::rotate( 3 ) : " << v1;

#if 0
    // deprecated in C++14  and removed in C++17
    print_line();
    std::random_shuffle(v1.begin(), v1.end());
    std::cout << " Vector 1, After std::random_shuffle() : " << v1;
#endif
    print_line();

    std::generate(v3.begin(), v3.end(), RetInc);
    std::cout << " Vector 3, After std::generate(RetInc) : " << v3;

    std::random_device d;
    std::mt19937 mt(std::random_device{}());

    // std::shuffle(v3.begin(), v3.end(), mt);

    std::shuffle(v3.begin(), v3.end(), std::mt19937{std::random_device{}()});
    std::cout << " Vector 3, After std::shuffle() : " << v3;

    print_line();
    IntVector v7(5);
    std::sample(v3.begin(), v3.end(), v7.begin(), v7.size(), mt);
    std::cout << " Vector 7, After sampling " << v7.size() << " elements from v3, using std::sample() : " << v7;

    print_line();
    v1.erase(std::unique(v1.begin(), v1.end()), v1.end());
    std::cout << " Vector 1, After std::unique() and erase: " << v1;

    print_line();
    std::string s1 = "The      string    with many       spaces!";
    std::cout << " String to operate on : " << s1 << '\n';

    std::string s2;
    std::unique_copy(s1.begin(), s1.end(), std::back_inserter(s2),
                    [](char c1, char c2){ return c1 == ' ' && c2 == ' '; });

    std::cout << " String after std::unique() with back_iterator over S2 and custom predicate : " << s2 << '\n';

    print_line();
}

int main() {
    test_1();
    return 0;
}
