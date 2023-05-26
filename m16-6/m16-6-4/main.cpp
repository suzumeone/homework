#include <iostream>

enum note
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int main() 
{
    int melody[12];
    std::string notes[] = { "DO", "RE", "MI", "FA", "SOL", "LA", "SI" };
    std::string melodyString;

    for (int i = 0; i < 12; ++i) 
    {
        std::cout << "Notes: ";
        std::cin >> melody[i];
    }

    std::cout << "Melody: ";
    for (int i = 0; i < 12; ++i) 
    {
        for (int j = 0; j < 7; ++j) 
        {
            if (melody[i] & (1 << j)) 
            {
                std::cout << notes[j] << " ";
                melodyString += notes[j] + " ";
            }
        }
    }
    std::cout << std::endl;

    return 0;
}