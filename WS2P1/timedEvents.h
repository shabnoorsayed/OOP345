#ifndef SICT_TIMEDEVENTS_H
#define SICT_TIMEDEVENTS_H

#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <chrono>

using namespace std::chrono;
using namespace std;

namespace sdds
{
	const int MAX_RECORDS = 7;
	class TimedEvents
	{
		int t_recorded{0};
		steady_clock::time_point ts;
		steady_clock::time_point te;

		struct
		{
			string msg{};
			string units{};
			steady_clock::duration duration{};
		} event[MAX_RECORDS];

	public:
		TimedEvents();
		~TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char*);
		friend std::ostream& operator<<(std::ostream& out, const TimedEvents& events);
	};
}
#endif