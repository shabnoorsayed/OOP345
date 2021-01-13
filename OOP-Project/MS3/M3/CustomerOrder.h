//NAME: Shabnoor Sayed
//Student ID: 133649194
//Date: 11/28/2020
//MS3
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include <iostream>
#include "Station.h"

using namespace std;

struct Item
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};

//NAME: Shabnoor Sayed
//Student ID: 133649194
//Date: 11/21/2020
//MS2
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

class CustomerOrder 
{
	string m_name;
	string m_product;
	unsigned int m_cntItem;
	Item** m_lstItem;
	static size_t m_widthField;
public:
	CustomerOrder();
	CustomerOrder(string&);
	CustomerOrder(CustomerOrder&);
	CustomerOrder& operator=(CustomerOrder&)= delete;
	CustomerOrder(CustomerOrder&&) noexcept;
	CustomerOrder& operator=(CustomerOrder&&) noexcept;
	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;
	~CustomerOrder();
};