#include <iostream>

int main() 
{
    int arr[] = { -100, -50, -5, 1, 10, 15 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int left = 0;
    while (left < n && arr[left] < 0) 
        left++;

    int right = left;

    if (right == n)
        right--;

    else
    {
        while (right < n && arr[right] >= 0)
            right++;
        right--;
    }

    while (left >= 0 && right < n)
    {
        if (abs(arr[left]) <= arr[right])
        {
            std::cout << arr[left] << " ";
            left--;
        }
        else 
        {
            std::cout << arr[right] << " ";
            right++;
        }
    }

    while (left >= 0)
    {
        std::cout << arr[left] << " ";
        left--;
    }

    while (right < n)
    {
        std::cout << arr[right] << " ";
        right++;
    }

    return 0;
}