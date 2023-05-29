#include <iostream>

void evendigits(long long n, int& ans)
{
    if (n == 0)
        return;
    if (n % 2 == 0)
        ans++;
    evendigits(n / 10, ans);
}

int main()
{
    int ans = 0;
    evendigits(9223372036854775806, ans);
    printf("Number of even digits: %d", ans);
    return 0;
}