#include <iostream>
#include <memory>

bool is_local(const std::string& ) {return false;} 



/// Abstract interface
struct IConnection
{
    virtual void execute_command(int code) = 0;
};

// convenience typedef (modern way)
using IConnectionPtr = std::unique_ptr<IConnection>;


/// First Concrete implementation
struct KromadaryConnection: IConnection
{
    /* lot of details goes here */
    virtual void execute_command(int code) override;
};

/// Alternate concrete implementation
struct LocalConnection: IConnection
{
    /* lot of details goes here */
    virtual void execute_command(int code) override;
};

/// Abstract factory interface
struct IConnectionFactory
{
    virtual IConnectionPtr create(const std::string& address) = 0;
};

/// Concrete factory implementation
struct KromadoryConnectionFactory: IConnectionFactory
{
    IConnectionPtr create(const std::string& address) override
    {
        if (is_local(address))
        {
            return std::make_unique<LocalConnection>(local_sys_mgr);
        }
        else
        {
            auto c = std::make_unique<KromadaryConnection>(sys_mgr);
            c->set_credentials("username", "fancy-password");
            c->activate_omega_13();
            return c;
        }
    }
    /* lot of details omitted */
};

class HighLevelBusinessLogic
{
public:
    explicit HighLevelBusinessLogic(std::shared_ptr<IConnectionFactory> f): factory(f) {}

    void do_something()
    {
        auto connection = factory->create("192.168.0.42");
        connection->execute_command(0b11101110111010000010101000111011);
    }
private:
    std::shared_ptr<IConnectionFactory> factory;
};


// "Factory" design patterns

int main(int, const char*[])
{
    
    std::cout << "hello" << std::endl;
    return 0;
}


