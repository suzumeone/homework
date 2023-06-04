#include <iostream>
#include <fstream>
#include <random>

const int MAX_BILLS = 1000;
const int NUM_BILLS = 5;
const int BILL_DENOMINATIONS[NUM_BILLS] = { 5000, 1000, 500, 200, 100 };

void saveStateToFile(const int* bills)
{
    std::ofstream file("atm_state.bin", std::ios::binary);
    file.write(reinterpret_cast<const char*>(bills), MAX_BILLS * sizeof(int));
    file.close();
}

void loadStateFromFile(int* bills)
{
    std::ifstream file("atm_state.bin", std::ios::binary);
    file.read(reinterpret_cast<char*>(bills), MAX_BILLS * sizeof(int));
    file.close();
}

void refillATM(int* bills)
{
    for (int i = 0; i < 1000; i++)
    {
        if (bills[i] == 0)
            bills[i] = BILL_DENOMINATIONS[std::rand() % 5];
    }
}

void withdrawMoney(int* bills, int amount)
{
    int sum = 0;
    for (int i = 0; i < MAX_BILLS; ++i) 
        sum += bills[i];
    if (sum < amount) 
    {
        std::cout << "Operation is not possible. There is not enough money in the ATM." << std::endl;
        return;
    }

    int withdrawnAmount = 0;
    for (int i = 0; i < MAX_BILLS; ++i) 
    {
        if (bills[i] != 0) 
        {
            withdrawnAmount += bills[i];
            bills[i] = 0;
            if (withdrawnAmount >= amount) 
                break;
        }
    }

    std::cout << "Sum " << amount << " rubles successfully withdrawn." << std::endl;
}

int main()
{
    int bills[MAX_BILLS] = { 0 };

    char operation;
    std::cout << "Enter '+' for fill the ATM or '-' for withdrawal:";
    std::cin >> operation;

    if (operation == '+') 
    {
        refillATM(bills);
        std::cout << "The ATM was successfully refilled." << std::endl;
    }
    else if (operation == '-') 
    {
        loadStateFromFile(bills);
        int amount;
        std::cout << "Enter the amount to withdraw (with an accuracy of 100 rubles): ";
        std::cin >> amount;
        withdrawMoney(bills, amount);
    }
    else 
    {
        std::cout << "Incorrect operation." << std::endl;
        return 0;
    }

    saveStateToFile(bills);

    return 0;
}
