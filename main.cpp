#include <iostream>
#include <memory>
#include <string>
#include <thread>

struct IBlob
{
    virtual ~IBlob() {};
};

struct Blob: IBlob
{
    ~Blob() override {}

    std::string name = "Inigo Montoya";
    /* More stuff here */
};

struct BlobFactory
{
    std::unique_ptr<IBlob> create_blob() { return std::make_unique<Blob>(); }
};

BlobFactory factory;

int main(int, const char *[])
{
    std::shared_ptr<IBlob> shared_blob(factory.create_blob());

    return 0;
}
