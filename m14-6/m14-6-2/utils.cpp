#include "utils.h"

void printTable(char table[][3])
{
	system("cls");
	std::cout << " +-----+-----+-----+ " << std::endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << " | ";
			std::cout << " " << table[i][j] << " ";
			if (j == 2)
				std::cout << " | ";
		}
		std::cout << std::endl;
		std::cout << " +-----+-----+-----+ ";
		std::cout << std::endl;
	}
	std::cout << "=====================" << std::endl;
}

char checkTable(char table[][3])
{
	//checking rows
	for (int i = 0; i < 3; i++)
	{
		if (table[i][0] == table[i][1] && table[i][1] == table[i][2])
			return table[i][0];
	}

	for (int i = 0; i < 3; i++)
	{
		if (table[0][i] == table[1][i] && table[1][i] == table[2][i])
			return table[i][i];
	}

	if (table[0][0] == table[1][1] && table[1][1] == table[2][2])
		return table[1][1];
	if (table[0][2] == table[1][1] && table[1][1] == table[2][0])
		return table[1][1];
	
	return 'c';
}

bool is_empty(int row, int column, char table[][3])
{
	return true;
}