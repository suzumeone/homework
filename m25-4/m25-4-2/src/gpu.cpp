#include "gpu.h"
#include "ram.h"
#include <iostream>

void display() 
{
    int* buffer = read();
    for (int i = 0; i < 8; ++i)
        std::cout << buffer[i] << " ";
    std::cout << std::endl;
}