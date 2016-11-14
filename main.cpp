#include <iostream>
#include <cassert>
#include <map>
#include <thread>

struct Contact
{
    std::string name;
    std::string phone;
};

typedef unsigned int ContactId; 

class AddressBook
{
public:
    ContactId add(const Contact& c);
    Contact get(ContactId id) const;
    void update(ContactId id, const Contact& c);
    void delete(ContactId id);
};

int main(int, const char*[])
{
    AddressBook book;

    return 0;
}