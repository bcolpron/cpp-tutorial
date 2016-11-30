#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

// The post-C++11 way (with move semantic)
std::vector<int> twice(std::vector<int> v)
{
    for (int& i : v)
    {
        i *= 2;
    }
    return v;
}

std::vector<int> returns_a_vector();

int main(int, const char*[])
{
    std::vector<int> v = {23, 42, 4, 8};
    v.push_back(15);
    v.push_back(16);

    // mutating function

    // Ah...
    v = twice(twice(twice(std::move(v))));

    // handles temporary
    twice(returns_a_vector());

    return 0;
}