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

int main(int, const char*[])
{
    std::vector<int> v = {23, 42, 4, 8};
    v.push_back(15);
    v.push_back(16);

    // mutating function
    twice(v);

    return 0;
}