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
        try
        {
		    backend->reboot_device(params.at("device-id"));
		    return 200;
        }
        catch(const DeviceNotFound& e)
        {
            return 404;
        }
        catch(const std::exception& e)  // catches all of the previous exceptions
        {
            std::cerr << "Exception in reboot_device: " << e.what() << std::endl;
            return 500;
        }
	}
};

class RemoteServerBackend: public IBackend
{
	~RemoteServerBackend() override {}

	void reboot_device(const std::string& id) override
	{
		ServerConnection("192.168.42.103")
			.get_device_manager()
			.find_device(id)
			.perform_action("reboot");
	}
};

int main(int, const char*[])
{
    return 0;
}