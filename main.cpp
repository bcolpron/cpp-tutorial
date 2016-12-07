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
    std::vector<std::shared_ptr<Animal>> animals;
    animals.push_back(std::make_shared<Dog>());
    animals.push_back(std::make_shared<Cat>());
    animals.push_back(std::make_shared<Cow>());

    for(const auto& i : animals) std::cout << i->sound() << std::endl;

    // copy allowed!
    std::vector<std::shared_ptr<Animal>> animals2 = animals;

    return 0;
}
