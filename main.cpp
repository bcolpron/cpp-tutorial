#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Animal
{
    virtual ~Animal() {};
    virtual std::string sound() = 0; 
};

struct Dog: Animal
{
    std::string sound() override {return "barl";}
};

struct Cat: Animal
{
    std::string sound() override {return "meow";}
};

struct Cow: Animal
{
    std::string sound() override {return "moo";}
};


int main(int, const char *[])
{
    // Gaaah! For goodness sake, never, ever do this!!
    std::vector<Animal*> animals;
    animals.push_back(new Dog);
    animals.push_back(new Cat);
    animals.push_back(new Cow);

    for(auto i : animals) std::cout << i->sound() << std::endl;

    for(auto i : animals) delete i;

    return 0;
}
