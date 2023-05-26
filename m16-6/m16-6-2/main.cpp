#include <iostream>
#include <string>

int main()
{
	std::string integer, factorial;
	printf("Input Integer: ");
	std::cin >> integer;
	printf("Input Factorial: ");
	std::cin >> factorial;
	std::string n = integer + "." + factorial;
	double i = std::stod(n);
	printf("%f", i);
	return 0;
}
