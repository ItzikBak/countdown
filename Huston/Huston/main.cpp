#include <iostream>
#include <chrono>
#include <thread>

#define TAKEOFF_TIMER 12
#define BLINK_TIMER 5

void cleanLastLine()
{
	std::cout << '\r'; // clean last line
	std::cout << "                            ";
	std::cout << '\r'; // clean last line;
}

/*
Count to 0 from 12, and blink 'Takeoff!' to screen when to counter is 0.
*/
int main()
{
	using namespace std::chrono_literals;
	int timer = TAKEOFF_TIMER;
	std::cout << "Time until takeoff: ";

	while(timer >= 1)
	{
		std::cout << timer;

		std::this_thread::sleep_for(1s);

		std::cout << '\b';
		if(timer > 10)
		{
			std::cout << '\b';
		}
		else if(timer == 10)
		{
			std::cout << ' ';
			std::cout << '\b' << '\b';
		}

		timer--;
	}

	// print blinking 'Takeoff'
	cleanLastLine();

	timer = BLINK_TIMER;
	while(timer >= 1)
	{
		std::cout << "Takeoff";
		std::this_thread::sleep_for(0.5s);
		cleanLastLine();
		std::this_thread::sleep_for(0.5s);
		timer--;
	}
}