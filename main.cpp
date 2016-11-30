#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

// The pre-C++11 way
void twice(std::vector<int>& v)
{
    for (int& i : v)
    {
        i *= 2;
    }
}

std::vector<int> returns_a_vector();

int main(int, const char*[])
{
    std::vector<int> v = {23, 42, 4, 8};
    v.push_back(15);
    v.push_back(16);

    // mutating function
    twice(v);
    twice(v);
    twice(v);   // cannot chain calls!

    // Cannot pass a temporary
    twice(returns_a_vector());  // ERROR: initialization of non-const reference

    // Solution: declare a local variable
    var v2 = returns_a_vector();
    twice(v2);

    return 0;
}