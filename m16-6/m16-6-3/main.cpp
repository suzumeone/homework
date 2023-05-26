#include <iostream>
#include <string>

int main()
{
	std::string buffer;
	printf(">>");
	std::cin >> buffer;

	std::string s_right = "";
	std::string s_left = "";

	bool right = false;
	char sign = '0';

	for (char c : buffer)
	{
		if (!isalpha(c) && !isalnum(c) && c != EOF)
		{
			sign = c;
			right = true;
		}
		if (isalnum(c))
		{
			if (right)
			{
				s_right += c;
			}
			else
			{
				s_left += c;
			}
		}
	}

	double a = std::stod(s_left);
	double b = std::stod(s_right);
	double result = 0;

	switch (sign)
	{
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			result = a / b;
			break;
		default:
			break;
	}

	printf("Result: %.2f", result);
	return 0;
}