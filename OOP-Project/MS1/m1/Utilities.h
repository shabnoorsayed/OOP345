//NAME: Shabnoor Sayed
//Student ID: 133649194
//Date: 11/14/2020
//MS1
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include <iostream>


using namespace std;

class Utilities {
	size_t m_widthField = 0;
	static char m_delimiter;
public:
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(char newDelimiter);
	static char getDelimiter();
};
