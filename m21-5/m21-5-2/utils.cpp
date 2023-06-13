#include "data.h"

bool isValidChar(char c)
{
	if (c == 'Y' || c == 'y' || c == 'N' || c == 'n')
		return true;
	else
		return false;
}

double getArea()
{
	double area;
	std::cout << "Enter area: ";
	std::cin >> area;

	if (area < 0 || area > 100000)
	{
		std::cout << "Incorrect value." << std::endl;
		getArea();
	}
	else
		return area;
}

bool checkPipe(std::string bType)
{
	char c;
	while (true)
	{
		std::cout << "Is there a pipe in the "+ bType + "?: ";
		std::cout << "Y\\N: ";
		std::cin >> c;
		if (isValidChar(c) && c == 'y' || c == 'Y')
		{
			return true;
		}
		else if (isValidChar(c) && c == 'n' || c == 'N')
		{
			return false;
		}
		else
			std::cout << "Incorrect input." << std::endl;
	}
}