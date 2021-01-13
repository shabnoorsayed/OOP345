#ifndef SICT_RECORDSET_H
#define SICT_RECORDSET_H

#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <chrono>
#include <fstream>

using namespace std;

namespace sdds
{
	class RecordSet
	{
		string *str;
		int numOfStr;

	public:
		RecordSet();
		RecordSet(char*);
		RecordSet(const RecordSet&);
		RecordSet& operator=(const RecordSet&);
		size_t size();
		string getRecord(size_t);
		RecordSet(RecordSet&&);
		RecordSet& operator=(RecordSet&&);
		~RecordSet();
	};
}

#endif