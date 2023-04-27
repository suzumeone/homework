#include <iostream>
#include <vector>

int main()
{
	std::vector<int> db(20);

	int ci = 0; // curren index
	for (;;)
	{
		int num;
		std::cout << "input number: ";
		std::cin >> num;
		if (num != -1)
		{
			db.at(ci) = num;
			ci++;
			if (ci == 20) ci = 0;
		}
		else
		{
			for (int i = ci; i < db.size(); i++)
				std::cout << db.at(i) << " ";
			for (int j = 0; j < ci; j++)
				std::cout << db.at(j) << " ";
			std::cout << std::endl;
		}
	}
}