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
};


int main(int, const char *[])
{
    Widget w;
    w.say_my_name();
    return 0;
}
