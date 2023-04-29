#include "utils.h"

int main() 
{
	char player = 'X';
	int place = 0, row = 0, column = 0;

	char table[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			table[i][j] = ' ';
	}

	bool is_filled[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			is_filled[i][j] = false;
	}

	printTable(table);

	int i = 0;
	for (; i < 3 * 3; i++)
	{
		std::cout << player << " your turn (1-9): ";
		std::cin >> place;
		if (place <= 3)
		{
			row = 0;
			column = place-1;
		}
		else if (place <= 6)
		{
			row = 1;
			column = place - 1 - 3;
		}
		else if (place <= 9)
		{
			row = 2;
			column = place - 1 - 6;
		}
		else
		{
			i--;
			continue;
		}


		if (table[row][column] == 'X' || table[row][column] == 'O')
		{
			std::cout << "This place is not empty!" << std::endl;
			system("pause");
			i--;
			continue;
		}
		else
			table[row][column] = player;

		char key = checkTable(table);

		if (key == 'X' || key == 'O')
		{
			printTable(table);
			std::cout << key << " player won" << std::endl;
			break;
		}

		if (player == 'X')
			player = 'O';
		else
			player = 'X';
		printTable(table);
	}

	if (i == 9)
	{
		printTable(table);
		std::cout << " Tie" << std::endl;
	}


}