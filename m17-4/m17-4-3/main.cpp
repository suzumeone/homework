#include <iostream>

bool substr(const char* str, const char* substr)
{
    int strLength = strlen(str);
    int substrLength = strlen(substr);

    for (int i = 0; i <= strLength - substrLength; i++)
    {
        int j;
        for (j = 0; j < substrLength; j++)
        {
            if (str[i + j] != substr[j])
                break;
        }

        if (j == substrLength)
            return true;
    }

    return false;
}

int main()
{
	const char* a = "Hello world";

	const char* b = "11r";

	const char* c = "banana";

	printf("%s\t%s", substr(a, b) ? "true" : "false", substr(a, c) ? "true" : "false");

	return 0;
}