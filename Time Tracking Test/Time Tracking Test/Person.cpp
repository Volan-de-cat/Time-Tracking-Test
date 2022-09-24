#include "Person.h"
#include <iostream>

Person::Person()
{
}

void Person::SetName(std::string Name)
{
	_person.Name = Name;
}

void Person::SetEmail(std::string Email)
{
	_person.Email = Email;
}

void Person::SetDepartment(std::string Department)
{
	_person.Department = Department;
}

void Person::SetPosition(std::string Position)
{
	_person.Position = Position;
}

void Person::SetProject(std::string Project)
{
	_person.Project = Project;
}

void Person::SetTask(std::string Task)
{
	_person.Task = Task;
}

void Person::SetDate(std::string Date)
{
	_person.Date = Date;
	std::string num = "";
	int count = 0;
	dateDivide = yearDivi;
	for (int i = 0; i < Date.size(); i++)
	{
		num += Date[i];
		if (Date[i+1] == dateDivide)
		{
			count++;
			switch (count)
			{
			case 1:
				_year = stoi(num);
				break;
			case 2:
				_month = months[stoi(num)-1];
				break;
			case 3:
				break;
			default:
				break;
			}
			num = "";
			i++;
		}
	}
}

void Person::SetHours(std::string Hours)
{
	_person.Hours = Hours;
}

std::string Person::GetName()
{
	return _person.Name;
}

std::string Person::GetMonth()
{
	return _month;
}

int Person::GetYear()
{
	return _year;
}

int Person::GetHours()
{
	return stoi(_person.Hours);
}
