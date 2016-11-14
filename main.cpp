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
    void remove(ContactId id);
};

int main(int, const char*[])
{
    AddressBook book;

    auto id = book.add(Contact{"Verbal Kint", "514-555-1234"});

    auto guy = book.get(id);
    assert(guy.name == "Verbal Kint");

    guy.name = "Keyser Soze";
    book.update(id, guy);

    book.remove(id);

    return 0;
}