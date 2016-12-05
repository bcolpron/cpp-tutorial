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

using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

struct Timer
{
    bool report_progress(float percent)
    {
        auto elapsed
            = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now() - start);

        std::cout << percent << "% elapsed in " << elapsed.count() << "ms" << std::endl;

        return true;
    }

private:
    TimePoint start = std::chrono::system_clock::now();
};


int main(int, const char*[])
{
    Timer timer;
    long_running_task([&](float progress)
    {
        return timer.report_progress(progress);
    });
    return 0;
}