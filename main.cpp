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
    IBlob* create_blob() { return new Blob(); }
};

BlobFactory factory;

int main(int, const char *[])
{
    factory.create_blob();      // ALERT! Memory leak

    return 0;
}
