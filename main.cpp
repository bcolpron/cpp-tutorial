#include <iostream>
#include <memory>
#include <string>

struct Blob
{
    std::string name = "Inigo Montoya"; 
    /* More stuff here */
};

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
    Widget(const Widget& o)     // copy constructor
    {
        blob = new Blob(*o.blob);
    }
    Widget& operator=(const Widget& o)  // copy assignment operator
    {
        *blob = *o.blob;
    }

    void say_my_name() { std::cout << "Hello, my name is " << blob->name << std::endl; }
};


int main(int, const char *[])
{
    Widget w;
    Widget w2 = w;      // deep-copy (as intended)
    w.say_my_name();
    return 0;
}
