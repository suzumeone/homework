#include <iostream>
#include <string>

int main()
{
	std::string flats[10];

	for (int i = 0; i < sizeof(flats)/sizeof(std::string); i++)
	{
		std::cout << i+1 << " | <- ";
		std::getline(std::cin, flats[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		int flatId;
		std::cout << "<- ";
		std::cin >> flatId;
		if (flatId > 0 && flatId < sizeof(flats) / sizeof(std::string) + 1)
			std::cout << flats[flatId - 1] << std::endl;
		else
			std::cout << "X | Index must be from 1 to 10" << std::endl;

	}


}