#pragma once

#include "Person.h"
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <set>

class Person;

class File
{
public:

	File();
	File(const std::string& fileName, int mode);;

	~File();

	void Read();
	void Split(std::string& s);
	void Write(std::list<MInfo> statistics);

	void MonthlyStatistic(std::string month);

private:
	std::fstream _mFile;
	std::fstream _eFile;
	char divide;
	char end;
	std::list<Person> _logs;
	std::set<std::string> _name;
	std::list<MInfo> _statistics;
};

