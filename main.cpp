#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

extern "C"
{
    void legacy_function(int* pData, size_t size) {}
}

int main(int, const char*[])
{
    std::vector<int> v = {23, 42, 4, 8};
    v.push_back(15);
    v.push_back(16);

    return 0;
}