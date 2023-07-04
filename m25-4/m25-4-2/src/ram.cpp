#include "ram.h"
#include <iostream>

int buffer[8] = {0};

int* read() 
{
    return buffer;
}

void write(int* newBuffer) 
{
    for (int i = 0; i < 8; ++i)
        buffer[i] = newBuffer[i];
}