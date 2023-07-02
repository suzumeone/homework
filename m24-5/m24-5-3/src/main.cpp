#include <iostream>
#include <sstream>
#include <cstring>
#include <chrono>
#include <thread>
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
    std::tm tm{0};
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
        ss >> std::get_time(&tm, "%M:%S");
        while (tm.tm_min > 0 || tm.tm_sec > 0)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(999));
            if (tm.tm_sec == 0)
            {
                tm.tm_min--;
                tm.tm_sec = 60;
            }
            tm.tm_sec--;
            Clear();
            std::cout << "Timer: MM:SS" << std::endl;
            std::cout << std::put_time(&tm, "%M:%S") << std::endl;

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