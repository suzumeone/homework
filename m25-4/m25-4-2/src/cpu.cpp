#include "cpu.h"
#include "ram.h"
#include <iostream>

void compute() {
    int sum = 0;
    int* buffer = read();
    for (int i = 0; i < 8; ++i)
        sum += buffer[i];
    std::cout << "Result: " << sum << std::endl;
}