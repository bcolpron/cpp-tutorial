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

    // Inserting many elements
    v.reserve(106);
    for(auto i=0; i < 100; ++i)
    {
        v.push_back(i);
    }

    return 0;
}