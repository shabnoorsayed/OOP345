//NAME: Shabnoor Sayed
//Student ID: 133649194
//Date: 11/28/2020
//MS3
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Utilities.h"
#include "Station.h"
#include "Workstation.h"

using namespace std;


Workstation::Workstation(const std::string& str) :Station(str) {
	m_pNextStation = nullptr;
}

void Workstation::runProcess(std::ostream& src) {
	if (m_orders.empty()) {
		return;
	}

	m_orders.front().fillItem(*this, src);
}

bool Workstation::moveOrder() 
{
	bool flag = false;
	if (!m_orders.empty() && m_orders.front().isItemFilled(getItemName()) && m_pNextStation)
	{
		*m_pNextStation += move(m_orders.front());
		m_orders.pop_front();
		flag = true;
	}
	return flag;
}
void Workstation::setNextStation(Station& station) {
	m_pNextStation = (Workstation*)&station;
}

const Workstation* Workstation::getNextStation() const {
	return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order) {
	bool flag = false;
	if (!m_orders.empty() && m_orders.front().isOrderFilled()) {
		order = move(m_orders.front());
		m_orders.pop_front();
		flag = true;
	}
	return flag;
}

void Workstation::display(std::ostream& os) const {

	if (m_pNextStation == nullptr)
		os << getItemName() << " --> END OF LINE" << endl;
	else
		os << getItemName() << " --> " << m_pNextStation->getItemName() << endl;
}


Workstation& Workstation::operator+=(CustomerOrder&& src) 
{

	m_orders.push_back(std::move(src));
	return *this;
}