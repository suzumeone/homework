#include "utils.h"

bool checkNumber(std::string& number)
{
    if (stoi(number.substr(0, 2)) >= 0 && stoi(number.substr(0, 2)) <= 99)
    {
        if (stoi(number.substr(3, 2)) >= 0 && stoi(number.substr(3, 2)) <= 99)
        {
            if (stoi(number.substr(6, 2)) >= 0 && stoi(number.substr(6, 2)) <= 99)
                return true;
        }
    }
    
    return false;
}

bool checkSurname(std::string& surname)
{
    if (surname != "\0")
    {
        for (char c : surname)
        {
            if (!isalpha(c))
                return false;
        }
        return true;
    }
    else
        return false;

}

bool SeparateData(std::string& data, std::string& number, std::string& surname)
{
    bool num = true;

    for (char c : data)
    {
        if (c == ' ')
            num = false;
        if (num && isdigit(c) || c == '-')
            number += c;
        else if (isalpha(c))
            surname += c;
    }

    if (number.length() != NUMBER_LENGHT)
    {
        if (!checkSurname(surname))
        {
            std::cout << "Invalid input." << std::endl;
            data = "";
            number = "\0";
            surname = "\0";
            return false;
        }

    }
    else if (number.length() == NUMBER_LENGHT)
    {
        if (!checkNumber(number))
        {
            std::cout << "Invalid input." << std::endl;
            data = "";
            number = "\0";
            surname = "\0";
            return false;
        }
        if (surname.length() > 1)
        {
            if (!checkSurname(surname))
            {
                std::cout << "Invalid input." << std::endl;
                data = "";
                number = "\0";
                surname = "\0";
                return false;
            }
        }
    }

    return true;

}