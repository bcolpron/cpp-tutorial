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
    
    Widget(const Widget& o) = delete;
    Widget& operator=(const Widget& o) = delete;

    void say_my_name() { std::cout << "Hello, my name is " << blob->name << std::endl; }
};


int main(int, const char *[])
{
    Widget w;
    Widget w2 = w;      // error: use of deleted function 'Widget::Widget(const Widget&)'
    w.say_my_name();
    return 0;
}
