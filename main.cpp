#include <iostream>
#include <cassert>
#include <map>
#include <thread>
#include <iostream>
#include <optional>

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
    bool remove(ContactId id);

    void addOrUpdate(ContactId id, const Contact& c);
    std::optional<Contact> find(ContactId id) const;

private:
    std::map<ContactId, Contact> m_contacts;
    ContactId m_sequence = 1;
    mutable std::mutex m_mutex;
};

ContactId AddressBook::add(const Contact& c)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_contacts[m_sequence] = c;
    return m_sequence++;
}

Contact AddressBook::get(ContactId id) const
{
    std::lock_guard<std::mutex> lock(m_mutex);
    auto found = m_contacts.find(id);
    if (found != m_contacts.end())
        return found->second;
    else
        throw std::out_of_range("not found");
}

void AddressBook::update(ContactId id, const Contact& c)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    auto found = m_contacts.find(id);
    if (found != m_contacts.end())
        found->second = c;
    else
        throw std::out_of_range("not found");
}

bool AddressBook::remove(ContactId id)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_contacts.erase(id) > 0;
}

void AddressBook::addOrUpdate(ContactId id, const Contact& c)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    auto found = m_contacts.insert(std::make_pair(id, c));
    if (found.second)
        ; // inserted!
    else
        found.first->second = c;
}

std::optional<Contact> AddressBook::find(ContactId id) const
{
    std::lock_guard<std::mutex> lock(m_mutex);
    auto found = m_contacts.find(id);
    if (found != m_contacts.end())
        return found->second;
    else
        return {};
}

int main(int, const char*[])
{
    AddressBook book;

    auto id = book.add(Contact{"Verbal Kint", "514-555-1234"});

    auto guy = book.get(id);
    assert(guy.name == "Verbal Kint");

    guy.name = "Keyser Soze";
    book.update(id, guy);

    book.remove(id);

    auto found = book.find(id);
    if (found) {
        std::cout << "Found " << found->name << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }

    return 0;
}