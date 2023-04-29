#include <iostream>

int checkMatrices(int a[][4], int b[][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] != b[i][j])
			{
				std::cout << "Matrices are not equal" << std::endl;
				return -1;
			}
		}
	}
	return 0;
}

void createDiagonal(int matrix[][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i != j)
				matrix[i][j] = 0; 
		}
	}
}

void printMatrix(int matrix[][4])
{
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

int main()
{
	int a[4][4];
	int b[4][4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << "A [" << i + 1 << "][" << j + 1 << "]: ";
			std::cin >> a[i][j];
		} 
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << "B [" << i + 1 << "][" << j + 1 << "]: ";
			std::cin >> b[i][j];
		}
	}

	if (checkMatrices(a, b) != -1)
	{
		createDiagonal(a);
		printMatrix(a);
	}

	return 0;
}