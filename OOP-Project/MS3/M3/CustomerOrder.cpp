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
#include <list>
#include "Utilities.h"
#include "Station.h"
#include "CustomerOrder.h"

using namespace std;

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder()
{
	m_cntItem = 0;
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(string& str)
{
	Utilities token;
	size_t next_pos = 0;
	bool more = true;
	Item* list[1000];
	m_cntItem = 0;
	m_lstItem = nullptr;

	if (str.empty()) {
		m_name = "";
		m_product = "";
		m_cntItem = 0;
		m_lstItem = nullptr;
	}
	else {
		m_name = token.extractToken(str, next_pos, more);
		m_product = token.extractToken(str, next_pos, more);
		string temp;
		while (more) {
			temp = token.extractToken(str, next_pos, more);
			list[m_cntItem] = new Item(temp);
			m_cntItem++;
		}

		m_lstItem = new Item * [m_cntItem];

		for (size_t i = 0; i < m_cntItem; i++) {
			m_lstItem[i] = list[i];
		}

		m_widthField = max(token.getFieldWidth(), m_widthField);
	}
}

CustomerOrder::CustomerOrder(CustomerOrder& src)
{
	throw "no copying allowed!";
}

CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
{
	m_cntItem = 0;
	m_lstItem = nullptr;
	*this = move(src);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
{
	if (&src == this)
		return *this;
	if (m_lstItem == nullptr) {
	}
	else {
		for (size_t i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}

	delete[] m_lstItem;
	m_name = src.m_name;
	m_product = src.m_product;
	m_lstItem = src.m_lstItem;
	m_cntItem = src.m_cntItem;
	src.m_cntItem = 0;
	src.m_lstItem = nullptr;
	return *this;
}

bool CustomerOrder::isOrderFilled() const
{
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_isFilled == false) {
			return false;
		}
	}
	return true;
} 

bool CustomerOrder::isItemFilled(const std::string& itemName) const
{
	bool flag = true;
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName.compare(itemName) == 0) {
			return m_lstItem[i]->m_isFilled;
		}
	}
	return flag;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os)
{
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName.compare(station.getItemName()) == 0) {
			if (station.getQuantity() > 0) {
				station.updateQuantity();
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;
				os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
			}
			else {
				os << "    Unable to fill NAME, PRODUCT " << m_lstItem[i]->m_itemName << endl;
			}
		}
	}
}

void CustomerOrder::display(std::ostream& os) const
{
	if (m_lstItem) {
		os << m_name << " - " << m_product << endl;
		for (size_t i = 0; i < m_cntItem; i++) {
			os << "[" << setfill('0') << right << setw(6) << m_lstItem[i]->m_serialNumber << "]" << " ";

			os << setfill(' ') << left << setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
			os << (m_lstItem[i]->m_isFilled ? "FILLED" : "MISSING") << endl;
		}
	}
}

CustomerOrder::~CustomerOrder()
{
	if (m_lstItem == nullptr) {
		return;
	}
	for (size_t i = 0; i < m_cntItem; i++) {
		delete m_lstItem[i];
	}
	delete[] m_lstItem;
}