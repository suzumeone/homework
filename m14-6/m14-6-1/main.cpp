#include <iostream>

int main()
{
	int a[12][12];
	int ctr = 0;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			a[i][j] = ctr++;
		}
	}

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			std::cout << a[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}