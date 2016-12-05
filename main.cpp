#include <iostream>
#include <functional>

/////////////////////////////////////////////
// API 
/////////////////////////////////////////////

typedef std::function<bool(float)> Progress;

void long_running_task(Progress callback);

/////////////////////////////////////////////
/////////////////////////////////////////////

bool my_callback(float percent)
{
    std::cout << percent << std::endl;
    return true;
}

int main(int, const char*[])
{
    long_running_task(&my_callback);
    return 0;
}