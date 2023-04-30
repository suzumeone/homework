#include "utils.h"

int popCtr = 0;

void printM(char matrix[][12])
{
	std::cout << "  " << " Y " << std::endl;
	std::cout << "  " << " ^ " << std::endl;
	for (int i = 0; i < 12; i++)
	{
		if(i < 9)
			std::cout << " " << i + 1 << " | ";
		else
			std::cout << i + 1 << " | ";
		
		for (int j = 0; j < 12; j++)
		{
				std::cout << matrix[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	std::cout << "----------------------------------------> X" <<std::endl;
	std::cout << "     1  2  3  4  5  6  7  8  9  10 11 12" <<std::endl;
}

int burstRange(char bw[][12], int startX,int startY, int endX, int endY)
{
	int startIndex = startY * 12 + startX;
	int endIndex = endY * 12 + endX;
	int r = endIndex - startIndex;

	for (int i = startY -1; ; i++)
	{
		for (int j = startX - 1; ; j++)
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