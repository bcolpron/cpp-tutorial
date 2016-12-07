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
    // Do this instead
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());
    animals.push_back(std::make_unique<Cow>());

    for(const auto& i : animals) std::cout << i->sound() << std::endl;

    return 0;
}
