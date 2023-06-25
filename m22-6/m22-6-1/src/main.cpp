#include "utils.h"
#include <vector>

int main()
{
    std::map<std::string, std::string> nts; // Number To Surname;
    std::map<std::string, std::vector<std::string>> stn; // Surname To Number;

    std::string data, number, surname;

    while(true)
    {
        std::cout << ">>> ";
        std::getline(std::cin, data);

        if(data == "q" || data == "Q")
            break;

        if(!SeparateData(data, number, surname))
        {
            std::cout << "Incorrect input." << std::endl;
            clean(data, number, surname);
            continue;
        }

        if(number != "\0" && surname != "\0")
        {
            nts[number] = surname;
            stn[surname].push_back(number);
            std::cout << "Added to list." << std::endl;
        }
        else if(number != "\0")
        {
            auto it = nts.find(number);
            if(it != nts.end())
                std::cout << "Surname linked to number: " << it->second << std::endl;
            else
                std::cout << "Surname not found." << std::endl;
        }
        else if(surname != "\0")
        {
            auto it = stn.find(surname);
            if(it != stn.end())
            {
                if(it->second.size() > 1)
                {
                    std::cout << "Numbers linked to surname: " << std::endl;
                    for(auto number : it->second)
                        std::cout << "\t" << number << std::endl;
                }
                else
                    std::cout << "Number linked to surname: " << it->second[0] << std::endl;
            }
        }
        clean(data, number, surname);
    }

    return 0;
}