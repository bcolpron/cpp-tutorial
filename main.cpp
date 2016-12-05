#include <iostream>

/////////////////////////////////////////////
// API 
/////////////////////////////////////////////

typedef bool (*Progress) (float percent);

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