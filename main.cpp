#include <iostream>
#include <memory>
#include <string>
#include <map>

class IBackend
{
public:
	virtual ~IBackend() {}

	virtual void reboot_device(const std::string& id) = 0;
};

class WebServiceImpl
{
	std::unique_ptr<IBackend> backend;
public:

	typedef unsigned short HttpStatusCode;
	typedef std::map<std::string, std::string> Params;

	/* a lot more of mission-specific code here */

	// One of many URI dispatched request handler
	HttpStatusCode reboot_device(const Params& params)
	{
		backend->reboot_device(params.at("device-id"));
		return 200;
	}
};

class RemoteServerBackend: public IBackend
{
	~RemoteServerBackend() override {}

	void reboot_device(const std::string& id) override
	{
	}
};

int main(int, const char*[])
{
    return 0;
}