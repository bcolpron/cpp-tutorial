// In AddressBook.h  /////////////////////////////////

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

// In AddressBook.cpp ////////////////////////////////

ContactId AddressBook::add(Contact c)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_contacts[m_sequence] = std::move(c);
    return m_sequence++;
}

const Contact& AddressBook::get(ContactId id) const
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_contacts[id];
}

/* ... */

// Ce code est-il valide (i.e. exempt de bug) ?



