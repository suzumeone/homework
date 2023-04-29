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
		std::cout << "Input start index to burst (1-143): ";
		int start, end;
		std::cin >> start;
		std::cout << "Input end index to burst (" << start << "-144): ";
		std::cin >> end;
		if ((start >= 1 && start <= 143) && (end > start && end <= 144))
		{
			popCtr += burstRange(bw, start, end);
			printM(bw);
		}
		else
		{
			std::cout << "Incorrect input!" << std::endl;
			break;
		}
	}
}