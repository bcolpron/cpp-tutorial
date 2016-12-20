#include <iostream>
#include <memory>
#include <vector>

struct File;
struct Folder;

struct Visitor
{
    virtual void visit(File& e) = 0;
    virtual void visit(Folder& e) = 0;
};

struct Element
{
    virtual ~Element() {}

    std::string name() const;

    virtual void accept(Visitor& v)=0;
};

struct File: Element
{
    std::size_t size() const; // File size in bytes

    void accept(Visitor& v) override {v.visit(*this);}
};

struct Folder: Element
{
    std::vector<std::shared_ptr<Element>> children() const;
    
    void accept(Visitor& v) override {v.visit(*this);}
};  

struct SpaceCalculator: Visitor
{
    void visit(File& e) override
    {
        total_size += e.size();
    }
    void visit(Folder& e) override
    {
        for(auto&& child : e.children())
        {
            child->accept(*this);
        }
    };

    std::size_t total_size;
};

int main(int, const char*[])
{
    std::vector<std::shared_ptr<Element>> root; // obtained somehow

    SpaceCalculator visitor;
    for(auto&& item: root) item->accept(visitor);

    std::cout << "Total size: " << visitor.total_size << " bytes." << std::endl;
    return 0;
}