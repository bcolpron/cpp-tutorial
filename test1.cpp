#include <iostream>
#include <future>

struct Blob { /*a stuff here */ };

class Widget
{
    Blob* blob;
public:
    Widget()
    {
        blob = new Blob();
    }
    ~Widget()
    {
        delete blob;
    }
};


int main(int, const char *[])
{
    Widget w;

    return 0;
}