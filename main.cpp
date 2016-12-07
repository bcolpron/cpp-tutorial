#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

void print(const std::vector<int>& v)
{
    std::for_each(begin(v), end(v), [] (int i)
    {
        std::cout << i << " ";
    });
    std::cout << std::endl;
}

int main(int, const char*[])
{
    std::vector<int> v = {23, 42, 4, 8};
    v.push_back(15);
    v.push_back(16);

    // Pass vector to a function
    print(v);

    return 0;
}