#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>
//NAME: Shabnoor Sayed
//Student ID: 133649194
//Date: 11/14/2020
//MS1
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

using namespace std;

char Utilities::m_delimiter = ',';

void Utilities::setFieldWidth(size_t newWidth)
{
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const
{
	return m_widthField;
}

string Utilities::extractToken(const string& str, size_t& next_pos, bool& more)
{
	string temp = "";
	size_t pos = next_pos;
	next_pos = str.find(getDelimiter(), pos);

	if (next_pos == string::npos) {
		temp = str.substr(pos);
		m_widthField = max(temp.length(), getFieldWidth());
		more = true;
	}
	else if (pos == next_pos)
	{
		more = false;
		throw "No token between delimiters";
	}
	else {
		temp = str.substr(pos, next_pos - pos);
		m_widthField = max(temp.length(), getFieldWidth());
		more = true;
	}
	next_pos++;
	return temp;
}

void Utilities::setDelimiter(char newDelimiter)
{
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter()
{
	return m_delimiter;
}
