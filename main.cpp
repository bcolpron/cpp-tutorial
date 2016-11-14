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
    std::shared_ptr<Blob> blob;
public:
    Widget()
    {
        blob = std::make_shared<Blob>();
    }

    void say_my_name() { std::cout << "Hello, my name is " << blob->name << std::endl; }

    std::shared_ptr<Blob> get_blob() { return blob; }
};


int main(int, const char *[])
{
    Widget w;
    Widget w2 = w;      // OK! (shallow copy of blob)
    w.say_my_name();

    auto b = w.get_blob();

    return 0;
}
