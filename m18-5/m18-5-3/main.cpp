#include <iostream>

int countWays(int n, int k = 3) 
{
    if (n <= 1)
        return 1;
    int ways = 0;
    for (int i = 1; i <= k && i <= n; i++)
        ways += countWays(n - i, k);
    
    return ways;
}

int main()
{
    printf("%d\n", countWays(3, 2));
    return 0;
}