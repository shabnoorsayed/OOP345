#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <chrono>
#include "TimedEvents.h"

using namespace std::chrono;
using namespace std;

namespace sdds 
{
	TimedEvents::TimedEvents()
	{
		t_recorded = 0;
		for (int i = 0; i < MAX_RECORDS; i++)
		{
			event[i].msg = "";
			event[i].units = "";
		}
	}

	void TimedEvents::startClock()
	{
		ts = steady_clock::now();
	}

	void TimedEvents::stopClock()
	{
		te = steady_clock::now();
	}

	void TimedEvents::recordEvent(const char* msgs)
	{
		auto td = std::chrono::duration_cast<std::chrono::nanoseconds>(te - ts);
		if (t_recorded < MAX_RECORDS)
		{
			event[t_recorded].msg = msgs;
			event[t_recorded].units = "nanoseconds";
			event[t_recorded].duration = td;
			t_recorded++;
		}
	}

	TimedEvents::~TimedEvents()
	{
		for (int i = 0; i < MAX_RECORDS; i++)
		{
			event[i].msg = "";
		}
	}

	ostream& operator<<(std::ostream& os, const TimedEvents& event)
	{
		os << "--------------------------" << endl;
		os << "Execution Times:" << endl;
		os << "--------------------------" << endl;

		for (int i = 0; i < event.t_recorded; i++)
			os << std::setw(20) << std::left
			<< event.event[i].msg << ' ' << std::setw(12) << std::right
			<< event.event[i].duration.count() << ' '
			<< event.event[i].units << endl;
		os << "--------------------------" << endl;
		return os;
	}
}