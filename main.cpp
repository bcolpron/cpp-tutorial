#include <iostream>
#include <string>
#include <map>
#include <thread>

struct Contact
{
    std::string name;
    std::string phone;
};

using ContactId = unsigned int;

class AddressBook
{
public:
    ContactId add(Contact c);
    const Contact& get(ContactId id) const;
    void update(ContactId id, Contact c);
    bool remove(ContactId id);
private:
    std::map<ContactId, Contact> m_contacts;
    ContactId m_sequence = 1;
    mutable std::mutex m_mutex;
};
