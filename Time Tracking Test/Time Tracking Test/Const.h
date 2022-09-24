#pragma once
#include <string>
#include <array>

struct PInfo
{
	std::string Name, Email, Department, Position, Project, Task, Date, Hours;
};

struct MInfo
{
	std::string Name, Month;
		int Year, Hours;
};

const char divi = ';';
const char endDivi = '"';
const char yearDivi = '-';

const std::array < std::string, 12> months = { "January","February","March","April","May","June","July","August","September","October","November","December" };