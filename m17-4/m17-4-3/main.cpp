#include <iostream>

bool substr(const char* str, const char* substr)
{
	for (int i = 0; i < strlen(str) - strlen(substr)+1; i++)
	{
		for (int j = 0; j < strlen(substr); j++)
		{
			if (j == strlen(substr) - 1 && str[i + j] == substr[j])
				return true;
		}
	}
	return false;
}

int main()
{
	const char* a = "Hello world";

	const char* b = "wor";

	const char* c = "banana";

	printf("%s\t%s", substr(a, b) ? "true" : "false", substr(a, c) ? "true" : "false");

	return 0;
}