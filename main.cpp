#include <iostream>
#include <memory>
#include <string>
#include <map>

class IBackend;

class WebServiceImpl
{
	std::unique_ptr<IBackend> backend;
public:

	typedef unsigned short HttpStatusCode;
	typedef std::map<std::string, std::string> Params;

	/* a lot more of mission-specific code here */

	// One of many URI dispatched request handler
	HttpStatusCode reboot_device(const Params& params);
};


int main(int, const char*[])
{
    return 0;
}