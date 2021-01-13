#include <iostream>
#include <string>
#include <iomanip>

#include "Reservation.h"

namespace sdds {

	Reservation::Reservation()
	{

		rId = "";
		rName = "";
		rEmail = "";
		rPartySize = 0;
		rDay = 0;
		rHour = 0;

	}

	Reservation::Reservation(const string& res)
	{
	
		string id, name, email, partySize, day, hour;
		string s = res;

		id = s.substr(0, s.find(':'));

		s.erase(0, s.find(':') + 1);
		name = s.substr(0, s.find(','));

		s.erase(0, s.find(',') + 1);
		email = s.substr(0, s.find(','));

		s.erase(0, s.find(',') + 1);
		partySize = s.substr(0, s.find(','));

		s.erase(0, s.find(',') + 1);
		day = s.substr(0, s.find(','));

		s.erase(0, s.find(',') + 1);
		hour = s.substr(0, s.find(','));

		id.erase(id.find_last_not_of(' ') + 1);
		id.erase(0, id.find_first_not_of(' '));

		name.erase(name.find_last_not_of(' ') + 1);
		name.erase(0, name.find_first_not_of(' '));

		email.erase(email.find_last_not_of(' ') + 1);
		email.erase(0, email.find_first_not_of(' '));

		email = "<" + email + ">";

		rId = id;
		rName = name;
		rEmail = email;
		rPartySize = stoi(partySize);
		rDay = stoi(day);
		rHour = stoi(hour);
	}

	ostream& operator<<(ostream& os, const Reservation& res)
	{
		os << "Reservation " << res.rId << ": "
			<< setw(10) << right << res.rName << "  "
			<< setw(20) << left << res.rEmail << right << "    ";
	
		if (res.rHour >= 6 && res.rHour <= 9)
		{

			os << "Breakfast on day " << res.rDay << " @ " << res.rHour << ":00 for " << res.rPartySize << " people.";

		}
		else if (res.rHour >= 11 && res.rHour <= 15)
		{

			os << "Lunch on day " << res.rDay << " @ " << res.rHour << ":00 for " << res.rPartySize << " people.";

		}
		else if (res.rHour >= 17 && res.rHour <= 21)
		{

			os << "Dinner on day " << res.rDay << " @ " << res.rHour << ":00 for " << res.rPartySize << " people.";

		}
		else
		{

			os << "Drinks on day " << res.rDay << " @ " << res.rHour << ":00 for " << res.rPartySize << " people.";

		}
		os << endl;

		return os;
	
	}

	Reservation::~Reservation()
	{
		rId = "";
		rName = "";
		rEmail = "";
	}
}