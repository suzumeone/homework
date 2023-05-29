#include <iostream>

int countWays(int n) 
{
    if (n <= 1)
        return 1;
    else if (n == 2)
        return 2;
    else if (n == 3)
        return 4;
    else
        return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
}

int main()
{
    printf("%d\n", countWays(3));
    return 0;
}