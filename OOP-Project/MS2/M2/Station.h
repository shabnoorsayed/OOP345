//NAME: Shabnoor Sayed
//Student ID: 133649194
//Date: 11/14/2020
//MS1
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include <iostream>

using namespace std;

class Station {

	int sId;
	string itemName;
	string itemDesc;
	int nextSNo;
	int numStock;

	static size_t m_widthField;
	static int id_generator;

public:
	Station(const string&);
	const string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};
