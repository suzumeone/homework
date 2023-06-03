#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

const int MAX_NOTES = 1000;

void refillATM() 
{
    std::ofstream file("banknotes.bin", std::ios::binary);

    int banknotes[MAX_NOTES];

    for (int i = 0; i < MAX_NOTES; ++i)
        banknotes[i] = (std::rand() % 50 + 1) * 100;
 

    file.write(reinterpret_cast<char*>(banknotes), sizeof(banknotes));

    file.close();

    std::cout << "The ATM has been successfully filled." << std::endl;
}

void withdrawFromATM(int amount) 
{
    std::ifstream file("banknotes.bin", std::ios::binary);

    if (!file)
    {
        std::cout << "Error: Banknote file not found." << std::endl;
        return;
    }

    int banknotes[MAX_NOTES];
    file.read(reinterpret_cast<char*>(banknotes), sizeof(banknotes));

    file.close();

    int remainingAmount = amount;
    int withdrawnAmount = 0;
    int withdrawnNotes[MAX_NOTES];
    int numWithdrawnNotes = 0;

    for (int i = 0; i < MAX_NOTES && remainingAmount > 0; ++i) 
    {
        if (banknotes[i] != 0 && banknotes[i] <= remainingAmount) 
        {
            withdrawnNotes[numWithdrawnNotes] = banknotes[i];
            numWithdrawnNotes++;
            withdrawnAmount += banknotes[i];
            remainingAmount -= banknotes[i];
            banknotes[i] = 0;
        }
    }

    if (withdrawnAmount < amount) 
    {
        std::cout << "Error: The operation is not possible. There are not enough suitable banknotes in the ATM." << std::endl;
        return;
    }

    std::ofstream outFile("banknotes.bin", std::ios::binary);
    outFile.write(reinterpret_cast<char*>(banknotes), sizeof(banknotes));
    outFile.close();

    std::cout << "Sum " << amount << " rubles successfully withdrawn. Banknotes: ";
    for (int i = 0; i < numWithdrawnNotes; ++i)
        std::cout << withdrawnNotes[i] << " ";
    std::cout << std::endl;
}

int main() 
{
    std::srand(std::time(nullptr));

    char operation;
    std::cout << "Enter the operation (+ for filling, - for withdrawing): ";
    std::cin >> operation;

    if (operation == '+')
        refillATM();
    else if (operation == '-') 
    {
        int amount;
        std::cout << "Enter amount to withdraw: ";
        std::cin >> amount;

        withdrawFromATM(amount);
    }
    else
        std::cout << "Error: Invalid operation." << std::endl;

    return EXIT_SUCCESS;
}
