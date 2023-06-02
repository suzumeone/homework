#include <iostream>
#include <fstream>
#include <string>

int main() 
{
    const int totalSectors = 13;
    int currentPlayer = 0;
    int playerScore = 0;
    int audienceScore = 0;

    std::ifstream sectorsFile("sectors.txt");
    std::ifstream answersFile("answers.txt");

    if (!sectorsFile || !answersFile) 
    {
        std::cerr << "Files not found." << std::endl;
        return 1;
    }

    std::string sectorNames[totalSectors];
    std::string answers[totalSectors];

    for (int i = 0; i < totalSectors; ++i) 
    {
        sectorsFile >> sectorNames[i];
        answersFile >> answers[i];
    }

    sectorsFile.close();
    answersFile.close();

    int currentPlayerScore = 0;
    int currentAudienceScore = 0;

    while (currentPlayerScore < 6 && currentAudienceScore < 6) 
    {
        std::cout << "Player " << currentPlayer + 1 << ", enter offset: ";
        int offset;
        std::cin >> offset;

        int currentSector = (currentPlayerScore + offset) % totalSectors;
        while (!sectorNames[currentSector].empty()) 
        {
            std::cout << "Sector: " << sectorNames[currentSector] << std::endl;
            std::cout << "Enter your answer: ";
            std::string playerAnswer;
            std::cin >> playerAnswer;

            if (playerAnswer == answers[currentSector]) 
            {
                std::cout << "Correct answer! You get 1 point." << std::endl;
                currentPlayerScore++;
                currentAudienceScore = 0;
            }
            else 
            {
                std::cout << "Incorrect answer! The score goes to the viewers." << std::endl;
                currentAudienceScore++;
                currentPlayer = (currentPlayer + 1) % 2;
            }

            if (currentPlayerScore == 6 || currentAudienceScore == 6)
                break;

            currentSector = (currentSector + 1) % totalSectors;
        }
    }

    std::cout << "Player " << (currentPlayerScore == 6 ? currentPlayer + 1 : 3 - currentPlayer) << " wins!" << std::endl;

    return 0;
}