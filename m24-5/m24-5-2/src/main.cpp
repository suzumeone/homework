#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <map>

int main()
{
    //YY/MM/DD
    std::map<std::time_t, std::vector<std::string>> birthdays;
    std::time_t t = std::time(nullptr);
    std::tm today = *std::localtime(&t);

    std::cout << "Valid input example: Name YYYY/MM/DD." << std::endl;
    
    std::string input;
    while(true)
    {
        std::cout << ">>> ";
        std::getline(std::cin, input);
        if(input == "end")
            break;

        size_t sPos = input.find(' ');
        if(sPos != std::string::npos)
        {
            std::tm bd{0};
            std::string name = input.substr(0,sPos);
            std::string date = input.substr(sPos+1, strlen(input.c_str()));
            std::time_t sec{0};
            std::stringstream ss(date);
            ss >> std::get_time(&bd, "%Y/%m/%d");
            sec = mktime(&bd);
            birthdays[sec].push_back(name);
            std::cout << "Birthday added." << std::endl;
        }
        else
            std::cout << "Invalid input." << std::endl << "Valid input example: Name YYYY/MM/DD." << std::endl;
    }
    int ctr = 0;

    for (const auto& day : birthdays)
    {
        std::tm bday = *std::localtime(&day.first);
        if (today.tm_mday == bday.tm_mday && today.tm_mon == bday.tm_mon)
        {
            if (day.second.size() > 1)
                std::cout << "Happy birthdays";
            else
                std::cout << "Happy birthday";
            for (auto name : day.second)
                std::cout << ", " << name;
            std::cout << "!" << std::endl;
        }
        else 
        {
            if (bday.tm_mon <= today.tm_mon)
            {
                if (bday.tm_mday < today.tm_mday)
                    continue;
            }
            else
            {
                std::cout << "Date: " << bday.tm_mon + 1 << "/" << bday.tm_mday;
                if (day.second.size() > 1)
                    std::cout << " Birthdays: ";
                else
                    std::cout << " Birthday: ";
                for (auto name : day.second)
                    std::cout << name << " ";
                std::cout << std::endl;
            }        
        }
    }
}