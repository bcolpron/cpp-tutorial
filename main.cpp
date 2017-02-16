#include <iostream>
#include <memory>
#include <vector>

struct File;
struct Folder;

/// Visitor interface
struct Visitor
{
    virtual void visit(File& e) = 0;
    virtual void visit(Folder& e) = 0;
};

/// Base class for all 'FileSystem' elements 
struct Element
{
    virtual ~Element() {}
    virtual void accept(Visitor& v)=0;

    std::string name() const;   // name of file/folder
};

/// Stripped-down file/document interface   
struct File: Element
{
    void accept(Visitor& v) override {v.visit(*this);}

    std::size_t size() const; // File size in bytes
};

/// Folder is a mere collection of 'Element's
struct Folder: Element
{
    void accept(Visitor& v) override {v.visit(*this);}

    std::vector<std::shared_ptr<Element>> children() const;
};  

/// One particular purpose operation...
struct SizeCalculator: Visitor
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

    std::size_t total_size = 0;
};

int main(int, const char*[])
{
    std::vector<std::shared_ptr<Element>> root; // obtained somehow

    SizeCalculator visitor;
    for(auto&& item: root)
    {
        item->accept(visitor);
    }

    std::cout << "Total size: " << visitor.total_size << " bytes." << std::endl;
    return 0;
}


// The Visitor Pattern - Is this good OO design/implementation?

