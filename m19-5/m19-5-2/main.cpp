#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string file_path;
	printf("Path to file: ");

	std::getline(std::cin, file_path);

	std::fstream file(file_path);

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
			std::cout << line << std::endl;
	}
	else
		printf("File not found\n");

	file.close();

	return 0;
}
