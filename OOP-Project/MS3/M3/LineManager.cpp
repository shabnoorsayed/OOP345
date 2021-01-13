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
#include <fstream>
#include "Utilities.h"
#include "Station.h"
#include "LineManager.h"

using namespace std;

LineManager::LineManager(const string& src, vector<Workstation*>& Wobj, vector<CustomerOrder>& Oobj) {
	ifstream file(src);
	if (!file)
		throw std::string("Unable to open [") + src + "] file.";

	string record;
	string current = "";
	string next = "";
	Utilities utility;
	size_t next_pos = 0;
	bool more = true;

	while (!file.eof())
	{
		std::getline(file, record);
		current = utility.extractToken(record, next_pos, more);
		if (more) {
			next = utility.extractToken(record, next_pos, more);
		}
		else {
			next = "";
		}
		for (size_t i = 0; i < Wobj.size(); i++)
		{
			if (Wobj[i]->getItemName() == current)
			{
				for (size_t j = 0; j < Wobj.size(); j++)
				{
					if (Wobj[j]->getItemName() == next)
					{
						Wobj[i]->setNextStation(*Wobj[j]);
						break;
					}
				}

				assemblySorted.push_back(Wobj[i]);

			}
		}
	}
	for (size_t i = 0; i < Oobj.size(); ++i) {
		ToBeFilled.push_back(std::move(Oobj[i]));
	}

	for (size_t i = 0; i < Wobj.size(); ++i) {
		AssemblyLine.push_back(Wobj[i]);
	}
	m_cntCustomerOrder = Oobj.size();
}

bool LineManager::run(std::ostream& os)
{
	static size_t count = 1;
	os << "Line Manager Iteration: " << count << endl;
	count++;
	if (!ToBeFilled.empty()) {
		*(assemblySorted[0]) += move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}
	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->runProcess(os);
	}

	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		if (AssemblyLine[i]->getNextStation() == nullptr)
		{
			CustomerOrder temp;
			if (AssemblyLine[i]->getIfCompleted(temp)) {
				Completed.push_back(std::move(temp));
			}
		}
		else {
			AssemblyLine[i]->moveOrder();
		}
	}
	if (Completed.size() == m_cntCustomerOrder) {
		return true;
	}
	else
		return false;
}

void LineManager::displayCompletedOrders(std::ostream& os) const
{
	for (size_t i = 0; i < Completed.size(); i++) {
		Completed[i].display(os);
	}
}

void LineManager::displayStations() const
{
	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->display(cout);
	}
}

void LineManager::displayStationsSorted() const
{
	for (auto i : assemblySorted) {
		i->display(cout);
	}
}