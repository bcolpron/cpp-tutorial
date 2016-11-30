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

    // Removing elements off the vector

    v.erase(v.begin()+3);   // erase the 4th element

    v.clear();  // erase everything (preserves capacity)

    return 0;
}