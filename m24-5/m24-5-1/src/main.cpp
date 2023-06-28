#include <iostream>

int main()
{
    std::string input;
    std::string currentTaks = "\0";

    while(true)
    {
        if(input == "exit" || input == "EXIT" || input == "e" || input == "E")
            break;
        
        if(input == "begin" || input == "Begin" || input == "BEGIN")
        {

        }
        else if(input == "end" || input == "End" || input == "END")
        {

        }
        else if(input == "status" || input == "Status" || input == "STATUS")
        {

        }
        else
            std::cout << "Incorrect input." << std::endl;
    }
}