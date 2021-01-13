#pragma once

#include "Reservation.h"

namespace sdds {

	class Restaurant
	{
	
		Reservation *restoRes;
		int r_cnt;

	public:
		Restaurant();
		~Restaurant();
		Restaurant(Reservation* reservations[], int cnt);
		Restaurant(const Restaurant& src);
		Restaurant& operator=(const Restaurant& src);
		Restaurant(Restaurant&& src);
		int size() const;

		friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);

	};

}