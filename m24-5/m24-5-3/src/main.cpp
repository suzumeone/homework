#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>

void Clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

int main()
{
    std::string time;
    std::cout << "Timer: MM:SS" << std::endl;
    std::cin >> time;
    size_t sPos = time.find(":");
    std::stringstream ss(time);
    if (sPos != std::string::npos)
    {
        int left = 0, right = 0;

        try
        {
            left = stoi(time.substr(0, sPos));
            right = stoi(time.substr(sPos + 1, strlen(time.c_str())));
        }
        catch (...)
        {
            std::cout << "Incorret time format." << std::endl;
            return 1;
        }

        if (left >= 0 && left <= 59 && right >= 0 && right <= 59);

        std::time_t now = std::time(nullptr);
        std::tm now_tm = *std::localtime(&now);
        std::time_t end = std::time(nullptr);
        end += left * 60 + right;
        std::tm end_tm = *std::localtime(&end);
        while (now < end)
        {
            //TODO
            break;
        }
        std::cout << "DING! DING! DING!" << std::endl;
    }
    else
    {
        std::cout << "Incorret time format." << std::endl;
        return 1;
    }

    return 0;
}