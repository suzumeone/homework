#include <iostream>

int main()
{
	int a[] = {2, 7, 11, 15};
	int r = 9;

	for (int i = 0; i < sizeof(a) / sizeof(int)-1; i++)
	{
		for (int j = 0; j < sizeof(a) / sizeof(int); j++)
		{
			if (a[i] + a[j] == r)
			{
				std::cout << a[i] << " " << a[j] << std::endl;
				return 0;
			}
		}
	}
}