#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string encrypt_caesar(string str, int key)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]))
        {
            if (islower(str[i]))
                str[i] = (str[i] + key - 'a') % 26 + 'a';
            else
                str[i] = (str[i] + key - 'A') % 26 + 'A';
        }
        else
            continue;
    }

    return str;
}

string decrypt_caesar(string str, int key)
{
    return encrypt_caesar(str, 26 - key);
}

int main()
{
    string str;
    int key;
    cout << "Message: ";
    getline(cin, str);

    cout << "Key: ";
    cin >> key;
    cout << "ENC: " << encrypt_caesar(str, key) << endl;
    cout << "DEC: " << decrypt_caesar(encrypt_caesar(str, key), key) << endl;

    return 0;
}

