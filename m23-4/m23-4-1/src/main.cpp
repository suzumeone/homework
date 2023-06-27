#include <iostream>

#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7

#define FIRST_DAY "Monday"
#define SECOND_DAY "Tuesday"
#define THIRD_DAY "Wednesday"
#define FOURTH_DAY "Thursday"
#define FIFTH_DAY "Friday"
#define SIXTH_DAY "Saturday"
#define SEVENTH_DAY "Sunday"

#define ERROR_MSG "Unknown day"

int main()
{
    int day;
    while(std::cin >> day)
    {
        switch (day)
        {
            case MONDAY:
                std::cout << FIRST_DAY << std::endl;
                break;
            case TUESDAY:
                std::cout << SECOND_DAY << std::endl;
                break;
            case WEDNESDAY:
                std::cout << THIRD_DAY << std::endl;
                break;
            case THURSDAY:
                std::cout << FOURTH_DAY << std::endl;
                break;
            case FRIDAY:
                std::cout << FIFTH_DAY << std::endl;
                break;
            case SATURDAY:
                std::cout << SIXTH_DAY << std::endl;
                break;
            case SUNDAY:
                std::cout << SEVENTH_DAY << std::endl;
                break;
            default:
                std::cout << ERROR_MSG << std::endl;
                break;
        }
    }
    return 0;
}