#include <iostream>
#include <memory>
#include <string>
#include <map>

enum class ErrorCode
{
    OK,
    DEVICE_NOT_FOUND,
    CONNECTION_ERROR,
    SERVICE_UNAVAILABLE,
    UNKNOWN_ERROR
};

class IBackend
{
public:
	virtual ~IBackend() {}

	virtual ErrorCode reboot_device(const std::string& id) = 0;
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
        auto ec = backend->reboot_device(params.at("device-id"));
        if (ec == ErrorCode::OK)
        {
		    return 200;
        }
        else if (ec == ErrorCode::DEVICE_NOT_FOUND)
        {
            return 404;
        }
        else
        {
            std::cerr << "Failed with error code " << ec << std::endl;
            return 500;
        }
	}
};

class RemoteServerBackend: public IBackend
{
	~RemoteServerBackend() override {}

	ErrorCode reboot_device(const std::string& id) override
	{
        ServerConnection conn;
		FooResult e = conn.connect("192.168.42.103");
        if (e != FOO_SUCCESS)
        {
            return ErrorCode::CONNECTION_ERROR;
        }

        DeviceManager* dm = conn.get_device_manager();
        if (!dm)
        {
            if (conn.get_last_error() == FOO_SERVICE_UNAVAILABLE)
            {
                return ErrorCode::SERVICE_UNAVAILABLE;
            }
            else
            {
                return ErrorCode::UNKNOWN_ERROR;
            }
        }

        Device* dev = dm->find_device(id);
        if (!dev)
        {
            return ErrorCode::DEVICE_NOT_FOUND;
        }

		Command result = dev.perform_action("reboot");
        if (e != COMMAND_SUCCESS)
        {
            return convert_to_backend_error_code(result);
        }

        return ErrorCode::OK;   // finally
	}
};

int main(int, const char*[])
{
    return 0;
}