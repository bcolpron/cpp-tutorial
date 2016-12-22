#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

struct Object
{
    virtual ~Object() {}
    virtual std::string to_string()const=0;
};

template<class T>
struct ObjectImpl: Object
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
std::unique_ptr<ObjectImpl<T>> make_object(Args&&... args)
{
    return std::make_unique<ObjectImpl<T>>(args...);
}

int main(int, const char*[])
{
    std::vector<std::unique_ptr<Object>> my_list;

    my_list.push_back(make_object<int>(42));
    my_list.push_back(make_object<double>(1.1));
    my_list.push_back(make_object<std::string>("hello"));

    for (auto&& i : my_list)
    {
        std::cout << i->to_string() << std::endl;
    }
    return 0;
}

// Java in C++ !