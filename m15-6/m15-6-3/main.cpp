#include <iostream>

void insertIntoArray(int array[], int size, int number) 
{
    int index = size - 1;

    while (index >= 0 && array[index] > number) 
    {
        array[index + 1] = array[index];
        index--;
    }

    array[index + 1] = number;
}

int main() {
    const int ARRAY_SZ = 5;
    int numbers[ARRAY_SZ] = { 0 };
    int count = 0;

    while (true)
    {
        int input;
        std::cin >> input;

        if (input == -2)
        {
            break;
        }
        else if (input == -1)
        {
            if (count >= 5)
            {
                std::cout << "Fifth number:" << numbers[4] << std::endl;
            }
            else
            {
                std::cout << "There are not enough numbers to display the fifth number." << std::endl;
            }
        }
        else 
        {
            if (count < 5)
            {
                insertIntoArray(numbers, count, input);
                count++;
            }
            else if (input < numbers[ARRAY_SZ - 1])
            {
                insertIntoArray(numbers, ARRAY_SZ - 1, input);
            }
        }
    }

    return 0;
}