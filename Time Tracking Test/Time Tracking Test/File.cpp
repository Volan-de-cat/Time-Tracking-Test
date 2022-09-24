#include "File.h"
#include <iostream>

File::File()
{
}

File::File(const std::string& fileName, int mode)
{
    _mFile.open(fileName, mode);
}

File::~File()
{
    if (_mFile)
    {
        _mFile.close();
    }
}

void File::Read()
{
    if (_mFile) {

        std::string line = "0";
        divide = divi;
        end = endDivi;
        int c = 0;

        while (!line.empty())
        {
            getline(_mFile, line);
            if (!line.empty())
            {
                Split(line);
            }

        }
    }
}

void File::Split(std::string& s)
{
    std::string elem ="";
    int count = 0;
    Person log;

    for (int i = 1; i <= s.size()-1; i++)
    {
        elem += s[i];
        if (s[i + 1] == divide || s[i + 1] == end)
        {
            count++;
            switch (count)
            {
            case 1:
                log.SetName(elem);
                _name.insert(elem);
                break;
            case 2:
                log.SetEmail(elem);
                break;
            case 3:
                log.SetDepartment(elem);
                break;
            case 4:
                log.SetPosition(elem);
                break;
            case 5:
                log.SetProject(elem);
                break;
            case 6:
                log.SetTask(elem);
                break;
            case 7:
                log.SetDate(elem);
                break;
            case 8:
                log.SetHours(elem);
                break;
            default:
                break;
            }
            elem = "";
            i++;
        }
    }
    _logs.push_back(log);
}

void File::Write(std::list<MInfo> statistics)
{
    if (_mFile.is_open()) 
    {

        std::string path;
        std::cout << "Enter log file path: ";
        getline(std::cin, path);

        _eFile.open(path,std::ios::out | std::ios::app);
        for (auto statistic : statistics)
        {
            _eFile << statistic.Name << ";" << statistic.Year << " " << statistic.Month << ";" << statistic.Hours << ";" << std::endl;
            std::cout << statistic.Name << ";" << statistic.Year << " " << statistic.Month << ";" << statistic.Hours << ";" << std::endl;
        }
    }
    else
    {
        throw std::exception("File not open");
    }
}

void File::MonthlyStatistic(std::string month)
{
    std::list<MInfo> statistics;
    for (auto name : _name)
    {
        MInfo statistic;
        statistic.Name = "";
        statistic.Month = "";
        statistic.Year = 0;
        statistic.Hours =0;
        for (auto log : _logs)
        {
            if (name == log.GetName())
            {
                statistic.Name = name;
                if (month == log.GetMonth())
                {
                    statistic.Month = month;
                    statistic.Year = log.GetYear();
                    statistic.Hours += log.GetHours();
                }
            }
        }
        if (!statistic.Name.empty()) 
        {
            statistics.push_back(statistic);
        }
    }
    Write(statistics);
}
