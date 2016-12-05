#include <iostream>
#include <functional>
#include <chrono>

/////////////////////////////////////////////
// API 
/////////////////////////////////////////////

typedef std::function<bool(float)> Progress;

void long_running_task(Progress callback);

/////////////////////////////////////////////
/////////////////////////////////////////////

int main(int, const char*[])
{
    auto start = std::chrono::system_clock::now();

    long_running_task([=](float percent)
    {
        auto elapsed
            = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now() - start);

        std::cout << percent << "% elapsed in " << elapsed.count() << "ms" << std::endl;

        return true;
    });

    return 0;
}
