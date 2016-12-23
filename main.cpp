#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

struct Object    // Generic 'Object' type definition
{
    virtual ~Object() {}
    virtual std::string to_string()const=0;
};
using ObjectPtr = std::shared_ptr<Object>;

template<class T>  
struct ObjectImpl: Object  // Concrete implementation
{
    template<class... Args> ObjectImpl(Args&&... args): m_value(args...) {}

    std::string to_string() const override
    {
        std::stringstream s;
        s << m_value;
        return s.str();
    }
private:
    T m_value;
};

template<class T, class... Args>
auto make_object(Args&&... args)  // helper function to build 'Object' instances
{
    return std::make_shared<ObjectImpl<T>>(args...);
}

int main(int, const char*[])
{
    std::vector<ObjectPtr> my_list = {   
        make_object<int>(42),
        make_object<double>(1.1),
        make_object<std::string>("hello")
    };

    for (auto&& i : my_list)
    {
        std::cout << i->to_string() << std::endl;
    }
    return 0;
}

// Java in C++ !