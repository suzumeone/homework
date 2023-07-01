#include <iostream>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <map>

int main()
{
    std::map<std::tm, std::string> birthdays;
    std::time_t t = std::time(nullptr);
    std::tm now = *localtime(&t);
    
    std::cout << "Date: " << now.tm_mon << "/" << now.tm_mday << "/" << now.tm_year << std::endl;

    std::string input;
    while(true)
    {
        if(input == "end")
            break;

        size_t sPos = input.find('/');
        if(sPos != std::string::npos)
        {
            std::tm bd{0};
            std::string name = input.substr(0,sPos-3);
            std::string date = input.substr(sPos-2, strlen(input.c_str()));
            std::get_time(&bd, "%m/%d/%Y");
            birthdays.insert(std::pair<std::tm, std::string>(bd, name));
            std::cout << "Birthday added." << std::endl;
        }
        else
        {
            std::cout << "Invalid input." << std::endl;
            std::cout << "Valid input example: Name mon/day/year." << std::endl;
        }

    }
}