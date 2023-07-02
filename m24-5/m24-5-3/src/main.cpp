#include <iostream>
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
    std::cin >> std::get_time(&tm, "%M:%S");
    while(tm.tm_min > 0 || tm.tm_sec > 0)
    {
        if(tm.tm_sec == 0)
        {
            tm.tm_min--;
            tm.tm_sec = 60;
        }
        tm.tm_sec--;
        Clear();
        std::cout << "Timer: MM:SS" << std::endl;
        std::cout << std::put_time(&tm, "%M:%S") << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(999));
    }
    std::cout << "DING! DING! DING!" << std::endl;
}