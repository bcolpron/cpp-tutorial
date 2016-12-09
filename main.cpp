#include <iostream>
#include <thread>
#include <memory>

struct Alice
{
    void hello() const { std::cout << "hello" << std::endl; }
};

struct Bob
{
    explicit Bob(const std::shared_ptr<Alice>& a) { this.alice = a; }

    void greetings() { alice->hello(); }

private:
    std::shared_ptr<Alice> alice;
};

void foobar()
{
    std::shared_ptr<Alice> alice(new Alice());

    Bob bob(alice);

    std::thread([=]
    {
        alice->hello();
    }).detach();

    alice = nullptr;

    bob.greetings();
}

// Questions:
// - Ce programme est-il valide (i.e. exempt de bug) ?
// - Que peut-on dire du cycle de vie de "Alice" ?



