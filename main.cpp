#include <iostream>
#include <string>
#include <string_view>
#include <any>

using namespace std::chrono_literals;

namespace foo::bar
{
	struct Event
	{
		std::string name;
		std::any data;
	};

	class EventServiceConnection
	{
	public:
		EventServiceConnection(std::string_view url); // connect to remote service

		void submit_event(Event e); // push a new event to service

		std::optional<Event> get_next_event(); // non-blocking request for event
	};
}

void main_loop()
{
	foo::bar::EventServiceConnection service("somewhere://over-the-rainbow");

	service.submit_event({"ready", std::pair(123, "demo-client") });

	while (true)
	{
		if (auto e = service.get_next_event(); e != std::nullopt)
		{
			std::cout << e->name << std::any_cast<double>(e->data) << std::endl;
		}
		else
		{
			std::this_thread::sleep_for(1s);
		}
	}
}
