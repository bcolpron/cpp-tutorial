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
    std::unique_ptr<Blob> blob;
public:
    Widget()
    {
        blob = std::make_unique<Blob>();
    }

    void say_my_name() { std::cout << "Hello, my name is " << blob->name << std::endl; }
};


int main(int, const char *[])
{
    Widget w;
    Widget w2 = w;      // error: use of deleted function 'Widget::Widget(const Widget&)'
    w.say_my_name();
    return 0;
}
