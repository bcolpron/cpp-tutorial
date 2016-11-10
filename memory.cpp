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
    Widget(const Widget& o)
    {
        blob = new Blob(*o.blob);
    }
    Widget& operator=(const Widget& o)
    {
        *blob = *o.blob;
    }
};


int main(int, const char *[])
{
    Widget w;
    Widget w2 = w;  // deep-copy (as intended)
    return 0;
}