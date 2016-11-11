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

    void say_my_name() { std::cout << "Hello, my name is " << blob->name << std::endl; }

private:
    Widget(const Widget& o);                // same effect as =deleter
    Widget& operator=(const Widget& o);     // (pre-C++11 way)
};


int main(int, const char *[])
{
    Widget w;
    Widget w2 = w;      // error: 'Widget::Widget(const Widget&)' is private within this context
    w.say_my_name();
    return 0;
}
