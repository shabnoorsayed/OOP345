//NAME: Shabnoor Sayed
//Student ID: 133649194
//Date: 11/14/2020
//MS1
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include "Utilities.h"
#include "Station.h"

using namespace std;

size_t Station::m_widthField = 0;
int Station::id_generator = 0;


Station::Station(const string& str)
{
	

	Utilities token;
	size_t next_pos = 0;
	bool more = true;

	if (str.empty()) {
		itemName = "";
		nextSNo = 0;
		numStock = 0;
		itemDesc = "";
	}
	else {
	
		itemName = token.extractToken(str, next_pos, more);
		nextSNo = stoi(token.extractToken(str, next_pos, more));
		numStock = stoi(token.extractToken(str, next_pos, more));
		m_widthField = max(token.getFieldWidth(), m_widthField);
		itemDesc = token.extractToken(str, next_pos, more);
	}
	sId = ++id_generator;
}

const string& Station::getItemName() const
{
	return itemName;
}

unsigned int Station::getNextSerialNumber()
{
	nextSNo++;
	return nextSNo - 1;
}

unsigned int Station::getQuantity() const
{
	return numStock;
}

void Station::updateQuantity()
{
	numStock--;
	if (numStock < 0) {
		numStock = 0;
	}
}

void Station::display(std::ostream& os, bool full) const
{
	os << '[' << setw(3) << setfill('0') << right << sId
		<< "] Item: " << setw(m_widthField) << setfill(' ') << left << itemName
		<< " [" << setw(6) << setfill('0') << right << nextSNo << "]" << setfill(' ') << left;
	if (full) {
		os << " Quantity: " << setw(m_widthField) << numStock
			<< " Description: " << itemDesc;
	}
	os << endl;
}
