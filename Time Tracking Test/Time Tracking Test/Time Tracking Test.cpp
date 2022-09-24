
#include <iostream>
#include "File.h"

int main()
{
    try {
        std::string path;
        std::cout << "Enter log file path: ";
        getline(std::cin, path);
        File file(path, std::ios::in | std::ios::out | std::ios::app);

        file.Read();

        std::string month;
        std::cout << "Enter selected month: ";
        getline(std::cin, month);

        file.MonthlyStatistic(month);
    }
    catch (std::exception& ex)
    {
        std::cout << "Exeption: " << ex.what() << std::endl;
    }
    
    getchar();
    return 0;
}