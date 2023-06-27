#include <iostream>

//#define SPRING "Spring"
//#define SUMMER "Summer"
//#define SPRING "Spring"
#define WINTER "Winter"

#if defined(SPRING)
int main()
{
    std::cout << SPRING << std::endl;
    return 0;
}
#endif

#if defined(SUMMER)
int main()
{
    std::cout << SUMMER << std::endl;
    return 0;
}
#endif

#ifdef AUTUMN
int main()
{
    std::cout << SPRING << std::endl;
    retunr 0;
}
#endif

#ifdef WINTER
int main()
{
    std::cout << WINTER << std::endl;
    return 0;
}
#endif