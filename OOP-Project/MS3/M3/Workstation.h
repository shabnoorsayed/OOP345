//NAME: Shabnoor Sayed
//Student ID: 133649194
//Date: 11/28/2020
//MS3
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include <iostream>
#include <deque>
#include <string>
#include "CustomerOrder.h"
#include "Station.h"
#include "Utilities.h"

using namespace std;

class Workstation: public Station {
	deque<CustomerOrder> m_orders;
	Workstation* m_pNextStation;
public:
	Workstation(const string& str);
	Workstation(const Workstation& src)= delete;
	Workstation& operator=(const Workstation& src)= delete;
	Workstation(Workstation&& src)noexcept = delete;
	Workstation& operator=(Workstation&& src)noexcept = delete;
	void runProcess(std::ostream&);
	bool moveOrder();
	void setNextStation(Station& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream&) const;
	Workstation& operator+=(CustomerOrder&&);
};