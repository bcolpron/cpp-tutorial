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
		explicit EventServiceConnection(std::string_view url); // connect to remote service 

		void submit_event(Event e);                            // push a new event to the service

		std::optional<Event> get_next_event();                 // non-blocking query for available event
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

//            ** HAPPY NEW Standard C++17 YEAR **
//
// Question #1: Can you spot the 6 C++17 novelties in this code?
//  (Hint: 3 new language features, 3 new standard library features)
// Question #2: Can you spot the potential problem?
