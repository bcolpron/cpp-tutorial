#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

int main(int, const char*[])
{
    std::vector<int> v = {23, 42, 4, 8};
    v.push_back(15);
    v.push_back(16);

    // Let's talk about STL

    std::sort(begin(v), end(v)); // meh

    return 0;
}