//NAME: Shabnoor Sayed
//Student ID: 133649194
//Date: 11/28/2020
//MS3
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include <cstring>
#include <iostream>
#include <vector>
#include "Workstation.h"

using namespace std;

class LineManager {
	std::vector<Workstation*> AssemblyLine;
	std::vector<Workstation*> assemblySorted;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;
public:
	LineManager(const string&, vector<Workstation*>&, vector<CustomerOrder>&);
	bool run(std::ostream& os);
	void displayCompletedOrders(std::ostream& os) const;
	void displayStations() const;
	void displayStationsSorted() const;
};
