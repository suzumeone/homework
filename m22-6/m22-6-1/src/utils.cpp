#include "utils.h"

void clean(std::string& data, std::string& number, std::string& surname)
{
        data = "\0"; 
        number = "\0";
        surname = "\0";
}

bool checkNumber(std::string& number)
{
    if (stoi(number.substr(0, 2)) >= 0 && stoi(number.substr(0, 2)) <= 99 && number.substr(2, 1) == "-")
    {
        if (stoi(number.substr(3, 2)) >= 0 && stoi(number.substr(3, 2)) <= 99 && number.substr(5,1) == "-")
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
    for (char c : data)
    {
        if (c == ' ')
            continue;
        else if (isdigit(c) || c == '-')
            number += c;
        else if (isalpha(c))
            surname += c;
        else
            return false;
    }
    if (number != "" && surname != "")
    {
        if (checkNumber(number) && checkSurname(surname))
            return true;
    }
    else if (number != "")
    {
        if (checkNumber(number))
            return true;
    }
    else if (surname != "")
    {
        if (checkSurname(surname))
            return true;
    }

    return false;
}