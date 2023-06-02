#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::fstream file("words.txt");

	std::string word;
	std::string wordToFind = "Lorem"; //4
	
	int ctr = 0;

	while (file >> word)
	{
		if (word == wordToFind)
			ctr++;
	}

	file.close();

	std::cout << "Word \"" << wordToFind << "\": " << ctr << " times" << std::endl;

	return 0;
}
