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

    // Print element #4 of v... 
    std::cout << v[3] << std::endl;
    std::cout << v.at(3) << std::endl;  // does bound checking!
    std::cout << *(v.begin() + 3) << std::endl;
    std::cout << *(begin(v) + 3) << std::endl;
    std::cout << *(v.data() + 3) << std::endl;  // pointer arithmetic

    return 0;
}