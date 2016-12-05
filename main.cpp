#include <iostream>
#include <functional>
#include <chrono>

// Decorator pattern!
template<class F>
auto decorate(F f)
{
    return [f{std::move(f)}] (auto... args)
    {
        std::cout << "before call" << std::endl;
        f(args...);
        std::cout << "after call" << std::endl;
    };
}


void my_func()
{
    std::cout << "allo" << std::endl;
};

int main(int, const char*[])
{
    auto decorated = decorate(my_func);

    decorated();

    return 0;
}
