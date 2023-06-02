#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main()
{
	std::string name, maxPayoutName, surname, date;
	int payout = 0;
	int maxPayout  = 0;
	

	std::fstream data("data.txt");

	if (data.is_open())
	{
		std::string line;
		while (std::getline(data, line))
		{
			std::stringstream ss(line);
			ss >> name >> surname >> payout >> date;
			if (payout > maxPayout)
			{
				maxPayout = payout;
				maxPayoutName = name;
			}

			std::cout << "Name: " << name << "\tPayout: " << payout << "$" << "\tDate: //" << date << std::endl;
		}

		std::cout << "\tMax payout:\n" << "Name: " << maxPayoutName << "\tPayout: " << maxPayout << "$" << std::endl;
	}
	
	else
		printf("File not found.\n");
	return 0;
}