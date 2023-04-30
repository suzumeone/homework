#include "utils.h"

int main()
{
	char bw[12][12]; //bubble wrap;

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			bw[i][j] = 'o';
		}
	}
	printM(bw);

	int popCtr = 0;

	while (popCtr < 144)
	{
		int sX, sY, eX, eY;
		std::cout << "Input start position X (1-12): ";
		std::cin >> sX;
		std::cout << "Input start position Y (1-12): ";
		std::cin >> sY;
		std::cout << "Input end position X (1-12): ";
		std::cin >> eX;
		std::cout << "Input end position Y (1-12): ";
		std::cin >> eY;
		if (sX <= 12 && sY <= 12 && eX <= 12 && eY <= 12)
		{
			popCtr += burstRange(bw, sX, sY, eX, eY);
			printM(bw);
		}
		else
		{
			std::cout << "Incorrect input!" << std::endl;
			break;
		}
	}
}