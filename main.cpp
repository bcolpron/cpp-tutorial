#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cassert>

struct NimporteQuoi
{
    NimporteQuoi() {}
    NimporteQuoi(std::string n, double v): name(std::move(n)), value(v) {}
    
    std::string name;
    double value;
};

int main(int, const char*[])
{
    std::vector<NimporteQuoi> v(10);  // pre-filled vector of 10 default-constructed elements

    NimporteQuoi pi {"pi", 3.1416};
    v.push_back(pi);

    v.push_back(NimporteQuoi{"e",  2.7183});

    v.emplace_back("golden ration", 1.6180);

    return 0;
}