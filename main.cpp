#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cassert>

int main(int, const char*[])
{
    std::vector<int> v = {23, 42, 4, 8};
    v.push_back(15);
    v.push_back(16);

    // Other vector goodies

    // vector is copy-able
    std::vector<int> v2 = v;

    // vectors are comparable
    assert(v == v2);

    return 0;
}