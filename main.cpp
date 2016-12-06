#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cassert>

struct NimporteQuoi
{
    std::string name;
    double value;
};

int main(int, const char*[])
{
    std::vector<NimporteQuoi> v(10);  // pre-filled vector of 10 default-constructed elements

    return 0;
}