#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <chrono>
#include <fstream>
#include "RecordSet.h"

using namespace std;

namespace sdds
{
	RecordSet::RecordSet()
	{
		str = nullptr;
		numOfStr = 0;
	}

	RecordSet::RecordSet(char* strin)
	{
		int i = 0;
		string c;
		ifstream file;
		file.open(strin);
		
		if (file.is_open())
		{
			while (!file.eof())
			{
				getline(file, c, ' ');
				++i;
			}
			
			str = new string[i + 1];
			c = {};
			file.close();
		}

		file.open(strin);
		i = 0;
		if (file.is_open())
		{
			while (getline(file, c, ' '))
			{
				str[i] = c;
				++i;
			}
		}

		numOfStr = i;
	}

	RecordSet::RecordSet(const RecordSet& obj)
	{
		*this = obj;
	}

	RecordSet& RecordSet::operator=(const RecordSet& obj)
	{
		numOfStr = obj.numOfStr;
		str = new string[obj.numOfStr];

		for (int i = 0; i < numOfStr; i++)
		{
			str[i] = obj.str[i];
		}

		return *this;
	}

	RecordSet::RecordSet(RecordSet&& m_obj)
	{
		*this = move(m_obj);
	}

	RecordSet& RecordSet::operator=(RecordSet&& m_obj)
	{
		if (m_obj.str != nullptr)
		{
			numOfStr = m_obj.numOfStr;
			str = new string[m_obj.numOfStr];

			for (int i = 0; i < numOfStr; ++i)
			{
				str[i] = m_obj.str[i];
			}
			delete[] m_obj.str;
			m_obj.str = nullptr;
		}
		return *this;
	}

	size_t RecordSet::size()
	{
		return numOfStr;
	}

	string RecordSet::getRecord(size_t index)
	{
		if (str != nullptr)
		{
			return str[index];
		}
		else
		{
			return "";
		}
	}

	RecordSet::~RecordSet()
	{
		delete[] str;
		str = nullptr;
	}
}