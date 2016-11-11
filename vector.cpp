#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

extern "C"
{
    void legacy_function(int* pData, size_t size) {}
}

void print(const std::vector<int>& v)
{
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

std::vector<int> twice(std::vector<int> v)
{
    for (auto&& i : v) i *= 2;
    return v;
}

int main(int, const char*[])
{
    std::vector<int> v = {23, 42, 4, 8};

    v.push_back(15);
    v.push_back(16);
    v.insert(v.end(), 16);
    
    legacy_function(v.data(), v.size());
    legacy_function(&v[0], v.size());

    std::sort(v.begin(), v.end());
    v = twice(std::move(v));
    print(v);

    std::cout << v[3] << std::endl;
    std::cout << v.at(3) << std::endl;
    std::cout << *(v.begin() + 3) << std::endl;
    std::cout << *(begin(v) + 3) << std::endl;
    std::cout << *(v.data() + 3) << std::endl;

    v.erase(v.begin()+3);
    print(v);

    std::cin.get();
    return 0;
}