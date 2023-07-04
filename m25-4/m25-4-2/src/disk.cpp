#include "disk.h"
#include "ram.h"
#include <fstream>
#include <iostream>

void save() 
{
    std::ofstream file("data.txt");
    int* buffer = read();
    for (int i = 0; i < 8; ++i)
        file << buffer[i] << std::endl;
    file.close();
    std::cout << "The data is saved to the hard drive." << std::endl;
}

void load() 
{
    std::ifstream file("data.txt");
    int* buffer = read();
    for (int i = 0; i < 8; ++i)
        file >> buffer[i];
    file.close();
    std::cout << "The data is loaded from the hard drive." << std::endl;
}