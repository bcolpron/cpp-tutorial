#include <iostream>
#include <memory>
#include <string>
#include <thread>

struct Blob
{
    std::string name = "Inigo Montoya";

    void some_lenghty_process();
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

void grab_and_spin(const std::shared_ptr<Blob>& blob)
{
    std::thread([=]
    {
        blob->some_lenghty_process();
    }).detach();
}

int main(int, const char *[])
{
    Widget w;
    Widget w2 = w;      // OK! (shallow copy of blob)
    w.say_my_name();

    auto b = w.get_blob();
    grab_and_spin(b);

    return 0;
}
