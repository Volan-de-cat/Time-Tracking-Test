#pragma once

#include"Const.h"

class Person
{
public:
	Person();

	void SetName(std::string Name);
	void SetEmail(std::string Email);
	void SetDepartment(std::string Department);
	void SetPosition(std::string Position);
	void SetProject(std::string Project);
	void SetTask(std::string Task);
	void SetDate(std::string Date);
	void SetHours(std::string Hours);

	std::string GetName();
	std::string GetMonth();
	int GetYear();
	int GetHours();

private:
	PInfo _person;
	char dateDivide;
	int _year;
	std::string _month;
};

