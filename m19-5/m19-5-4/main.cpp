#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string file_path;
	printf("Path to file: ");

	std::string PNG = "";

	std::getline(std::cin, file_path);

	std::ifstream file(file_path, std::ios::binary);

	if (!file)
	{
		printf("File not found\n");
		return 1;
	}

	char bytes[4];
	file.read(bytes, sizeof(bytes));
	for (int i = 1; i < sizeof(bytes); i++)
		PNG += bytes[i];

	if (PNG == "PNG")
		std::cout << "File is real PNG." << std::endl;
	else
		std::cout << "File is not PNG." << std::endl;

	file.close();

	return 0;
}