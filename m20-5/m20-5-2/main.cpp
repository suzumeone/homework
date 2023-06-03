#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string> 

int main()
{
	std::srand(std::time(nullptr));

	int x, y;

	printf("X Y: ");

	std::cin >> x >> y;

	std::ofstream pic("pic.txt");

	std::string picture;

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
			picture += std::to_string(rand() % 2);
		picture += "\n";
	}

	pic.write(picture.c_str(), strlen(picture.c_str()));

	pic.close();

	return EXIT_SUCCESS;
}