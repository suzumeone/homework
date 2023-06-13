#include "data.h"

/*   Date Validation   */
bool isValidDate(std::string& date)
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

/*   Salary Validation   */
bool isValidSalary(std::string salary)
{
	for (char c : salary)
	{
		if (!isalnum(c))
			return false;
	}
	return true;
}

void fillStruct(listing& person)
{
	printf("Name: ");
	std::cin >> person.s_name;
	printf("Surname: ");
	std::cin >> person.s_surname;

	while (true)
	{
		printf("Salary: ");
		std::cin >> person.salary;
		printf("Date: ");
		std::cin >> person.date;

		if (isValidDate(person.date) && isValidSalary(person.salary))
			break;
		else
			printf("Invalid date or salary.\n");
	}
}

void add(std::string path, listing& person)
{
	std::fstream file(path, std::ios_base::app);
	if (file.is_open())
	{
		fillStruct(person);
		std::string temp = person.s_name + " " + person.s_surname + " " + person.salary + "$ " + person.date + '\n';
		file.write(temp.c_str(), strlen(temp.c_str()));
		printf("Successfully added to document.\n");
	}
	else
		printf("File not found.\n");
}

void list(std::string path, listing& person)
{
	std::fstream file(path);

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			std::stringstream ss(line);
			ss >> person.s_name >> person.s_surname >> person.salary >> person.date;
			std::cout << "Name: " << person.s_name << "\tPayout: " << person.salary << "$" << "\tDate: //" << person.date << std::endl;
		}
	}
}
