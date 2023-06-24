#include "utils.h"

int main()
{
    std::map<std::string, std::string> mp;
    std::string data, number = "\0", surname = "\0";
    std::map<std::string, std::string>::iterator it1, it2;


    while(true)
    {
        std::cout << ">>> ";
        std::getline(std::cin, data);

        if (data == "q" || data == "Q")
            break;

        SeparateData(data, number, surname);

        if (number != "\0" && surname != "\0")
        {
            mp.insert(std::pair<std::string, std::string>(number, surname));
            std::cout << "Added to list." << std::endl;
        }


        else if(number != "\0")
        {
            for (const auto& it : mp)
            {
                if (it.first == number)
                {
                    std::cout << "Surname: " << it.second << "\t\t" << "Number: " << it.first << std::endl;
                    break;
                }
            }
        }

        else if (surname != "\0")
        {
            for (const auto& it : mp)
            {
                if (it.second == surname)
                    std::cout << "Surname: " << it.second << "\t\t" << "Number: " << it.first << std::endl;
            }

        }

        data = "";
        number = "\0";
        surname = "\0";
    }

    return 0;
}