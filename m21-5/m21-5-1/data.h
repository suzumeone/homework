#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

struct listing
{
	std::string s_name;
	std::string s_surname;
	std::string salary;
	std::string date;
};

bool isValidDate(std::string& date);
bool isValidSalary(std::string salary);
void add(std::string path, listing& person);
void list(std::string path, listing& person);
