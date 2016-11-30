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

    v.insert(v.begin(), 1); // equivalent of "push_front()" (with some cost penalty!)

    return 0;
}