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

    auto found = std::find(begin(v), end(v), 42);
    if (found != v.end())
    {
        std::cout << "Found!" << std::endl;
    }
    else
    {
        std::cout << "Not found :(" << std::endl;
    }
    
    return 0;
}