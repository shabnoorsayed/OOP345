#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace sdds {

	class Reservation {

		string rId;
		string rName;
		string rEmail;
		int rPartySize;
		int rDay;
		int rHour;

	public:
		Reservation();
		Reservation(const string& res);
		friend ostream& operator<<(ostream& os, const Reservation& res);
		~Reservation();
	};

}