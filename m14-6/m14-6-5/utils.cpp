#include "utils.h"

int popCtr = 0;

void printM(char matrix[][12])
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int burstRange(char bw[][12], int startIndex, int endIndex)
{
	int sI = startIndex / 12;
	int srI = startIndex % 12;
	
	int r = endIndex - startIndex;

	for (int i = sI; ; i++)
	{
		for (int j = srI-1; ; j++)
		{
			if (r >= 0)
			{
				bw[i][j] = 'x';
				popCtr++;
				std::cout << "x" << popCtr << " Pop!" << std::endl;
				r--;
				
			}
			else
			{
				return popCtr;
			}
				
		}
	}
}