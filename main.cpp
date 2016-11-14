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
    auto blob = factory.create_blob();

    // convert for sharing
    auto shared_blob = std::shared_ptr<IBlob>(std::move(blob));

    return 0;
}
