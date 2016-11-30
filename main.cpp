#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

void print(const std::vector<int>& v)
{
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
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