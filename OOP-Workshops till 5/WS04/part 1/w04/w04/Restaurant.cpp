#include "Restaurant.h"

namespace sdds {

	Restaurant::Restaurant()
	{
	
		restoRes = nullptr;
		r_cnt = 0;
	
	}

	Restaurant::Restaurant(Reservation* reservations[], int cnt)
	{
	
		r_cnt = cnt;
		restoRes = new Reservation[cnt];
		for (int i = 0; i < cnt; i++)
		{
			this->restoRes[i] = *reservations[i];
		}

	}

	Restaurant::Restaurant(const Restaurant& src)
	{
	
		*this = src;
	
	}

	Restaurant& Restaurant::operator=(const Restaurant& src)
	{
	
		if (src.restoRes != nullptr)
		{
			r_cnt = src.r_cnt;
			restoRes = new Reservation[src.size() + 1];
			for (int i = 0; i < src.r_cnt; i++)
			{
				this->restoRes[i] = src.restoRes[i];
			}
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& src)
	{
		
		if (src.restoRes != nullptr)
		{
			swap(restoRes, src.restoRes);
			r_cnt = src.r_cnt;
			src.r_cnt = 0;
			src.restoRes = nullptr;
		}
	
	}

	int Restaurant::size() const
	{
	
		return r_cnt;

	}

	Restaurant::~Restaurant()
	{
	
		delete[] restoRes;
		restoRes = nullptr;

	}

	ostream& operator<<(std::ostream& os, const Restaurant& res)
	{
		os << "--------------------------" << endl;
		os << "Fancy Restaurant" << endl;
		os << "--------------------------" << endl;
		if (res.r_cnt <= 0)
		{
			os << "The object is empty!" << endl;
			os << "--------------------------" << endl;
		}
		else
		{
			for (int i = 0; i < res.r_cnt; i++)
			{
				os << res.restoRes[i];
			}
			os << "--------------------------" << endl;
		}
		return os;
	
	}

}