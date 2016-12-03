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
		backend->reboot_device(params.at("device-id"));   //  at() can throw!
		return 200;
	}	// no response is sent if handler call results in an exception thrown!
};

class RemoteServerBackend: public IBackend
{
	~RemoteServerBackend() override {}

	void reboot_device(const std::string& id) override
	{
		ServerConnection("192.168.42.103")                // can throw
			.get_device_manager()                         // can throw
			.find_device(id)                              // can throw
			.perform_action("reboot");                    // can throw
	}
};

int main(int, const char*[])
{
    return 0;
}