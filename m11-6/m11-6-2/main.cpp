#include "main.h"

int main()
{
	bool run = true;
	cout << "Email Checker | For quit press \'q\'" << endl;
	while (run)
	{
		string input;
		cout << "Email: ";
		std::getline(cin, input);
		if (input == "q")
			run = false;
		else
			cout << emailCheck(input) << endl;
	}

	return 0;
}

bool leftSideCheck(string email)
{
	bool valid = true;
	if (email.length() > 64)
		return false;

	for (int i = 0; i < email.length(); i++)
	{
		if (valid)
		{
			if (isalnum(email[i]) || isalpha(email[i]))
				valid = true;
			else
			{
				string allowed = "!#$%&'*+-/=?^_`{|}~.";
				int mCtr = 0;
				for (int j = 0; j < allowed.length(); j++)
				{
					if (email[i] == allowed[j])
					{
						if (email[i + 1] != email[i])
						{
							mCtr++;
							valid = true;
							break;
						}
						else
						{
							valid = false;
							break;
						}
					}
				}
				if (mCtr != 0)
				{
					valid = true;
					mCtr = 0;
				}
				else
				{
					valid = false;
					break;
				}
			}
		}
		else
			break;
	}
	return valid;
}

bool rightSideCheck(string email)
{
	bool valid = true;

	if (email.length() > 64)
		return false;

	for (int i = 0; i < email.length(); i++)
	{
		if (valid)
		{
			if (isalnum(email[i]) || isalpha(email[i]))
				valid = true;
			else
			{
				string allowed = ".-";
				int mCtr = 0;
				for (int j = 0; j < allowed.length(); j++)
				{
					if (email[i] == allowed[j])
					{
						if (email[i + 1] != email[i])
						{
							mCtr++;
							valid = true;
							break;
						}
						else
						{
							valid = false;
							break;
						}
					}
				}
				if (mCtr != 0)
				{
					valid = true;
					mCtr = 0;
				}
				else
				{
					valid = false;
					break;
				}
			}
		}
		else
			break;
	}
	return valid;
}

string emailCheck(string email)
{
	bool valid = true;
	int aIndex = 0;
	for (int i = 0, aCtr = 0; i < email.length(); i++)
	{
		if (email[i] == '@')
		{
			aCtr++;
			if (aCtr >= 2)
			{
				valid = false;
				break;
			}
			aIndex += i;
		}
	}
	if (aIndex == 0)
		valid = false;
	if (valid)
	{
		string rightSide = email.substr(aIndex + 1);
		string leftSide = email.erase(aIndex, email.length());

		if (leftSideCheck(leftSide) && rightSideCheck(rightSide))
			return "Yes";
		else
			return "No";
	}
	else
		return "No";
}