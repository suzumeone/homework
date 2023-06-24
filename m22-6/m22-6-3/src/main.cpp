#include <iostream>
#include <map>
#include <string>

bool isAnagram(const std::string& str1, const std::string& str2) 
{
    if (str1.length() != str2.length()) 
        return false;

    std::map<char, int> charCount;

    for (char c : str1)
        charCount[c]++;

    for (char c : str2)
    {
        if (charCount[c] == 0)
            return false;
        charCount[c]--;
    }

    for (const auto& pair : charCount) 
    {
        if (pair.second != 0)
            return false;
    }

    return true;
}

int main() 
{
    std::string str1, str2;
    std::cout << "Input first string: ";
    std::getline(std::cin, str1);
    std::cout << "Input second string: ";
    std::getline(std::cin, str2);

    if (isAnagram(str1, str2))
        std::cout << "The strings are anagrams." << std::endl;
    else
        std::cout << "The strings are not anagrams." << std::endl;

    return 0;
}