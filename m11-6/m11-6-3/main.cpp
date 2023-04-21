#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;



int get_address_part(string ip, int octet)
{
    string octet_str = "";
    int dotCtr =  0;

    for (int i = 0; i < ip.length(); i++)
    {
        if ((char)ip[i] == '.')
        {
            dotCtr++;
            continue;
        }

        if (octet == 1 && dotCtr == 0)
            octet_str += ip[i];
        else if (octet == 2 && dotCtr == 1)
            octet_str += ip[i];
        else if ((octet == 3 && dotCtr == 2))
            octet_str += ip[i];
        else if ((octet == 4 && dotCtr == 3))
            octet_str += ip[i];
        else
            continue;
    }
    int numericOctet = stoi(octet_str);
    if (dotCtr == 4)
        return -1;
    if (numericOctet >= 0 && numericOctet <= 255)
        return numericOctet;
    else
        return -1;
}



bool is_valid(string ip)
{
    bool valid = true;
    for (int i = 0; i < ip.length(); i++)
    {
        if (ip[i] == ' ')
        {
            valid = false;
            break;
        }
        else if (isalpha(ip[i]))
        {
            valid = false;
            break;
        }
        else if (isalnum(ip[i]) || (ip[i] == '.' && ip[i + 1] != '.'))
        {
            if (ip[i] == '0' && i != 0 && ip[i - 1] == '.' && ip[i+1] != '.')
            {
                valid = false;
                break;
            }
            else
                valid = true;
        }
        else
        {
            valid = false;
            break;
        }
    }
    return valid;
}

bool checkAddress(string ip)
{
    if (!is_valid(ip))
        return false;
    bool valid = true;
    for (int i = 1; i < 5; i++)
    {
        if (get_address_part(ip, i) != -1)
            valid = true;
        else
        {
            valid = false;
            break;
        }
    }

    return valid;
}

int main()
{
    while (true)
    {
        string ip;
        cout << "IP: ";
        std::getline(cin, ip);

        if (checkAddress(ip))
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

}
