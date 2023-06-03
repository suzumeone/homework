#include <iostream>
#include <fstream>
#include <string>

bool isValidd(std::string& date)
{
	for (char c : date)
	{
		if (c == '.')
			continue;
		if (!isalnum(c))
			return false;
	}
	if (std::stoi(date.substr(3, 2)) <= 12 && std::stoi(date.substr(3, 2)) >= 1)
		return true;

	return false;
}

bool isValidp(std::string pay)
{
	for (char c : pay)
	{
		if (!isalnum(c))
			return false;
	}
	return true;
}

int main()
{
	std::string name, surname, payout, date;


	std::ofstream data("data.txt", std::ios_base::app);

	if (data.is_open())
	{
		printf("Name: ");
		std::cin >> name;

		printf("Surname: ");
		std::cin >> surname;

		LOOP:
		printf("Payout: ");
		std::cin >> payout;

		printf("Date: ");
		std::cin >> date;

		if (isValidd(date) && isValidp(payout))
		{
			std::string temp = name + " " + surname + " " + payout + "$ " + date + '\n';
			data.write(temp.c_str(), strlen(temp.c_str()));
			printf("Successfully added to document.\n");
		}
		else
		{
			printf("Invalid date or payout.\n");
			goto LOOP;
		}
	}
	else
		printf("File not found.\n");

	data.close();

	return 0;
}