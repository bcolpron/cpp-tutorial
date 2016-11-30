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

    auto found = std::find_if(begin(v), end(v), [](int val) {
        return val > 10;
    });

    if (found != v.end())
    {
        std::cout << "I found a value larger than 10: " << *found << std::endl;
    }
    
    return 0;
}