#include <iostream>
#include <vector>

int main()
{
	std::vector<int> db(20);

	for (int i = 0; i < db.size()+1; i++)
	{
		int num;
		std::cout << "input number: ";
		std::cin >> num;
		if (num != -1)
		{
			if (i == db.size())
			{
				db.push_back(num);
				db.erase(db.begin(), db.begin() + 1);
				i--;
			}
			else
				db.at(i) = num;
			
		}
		else 
		{
			std::cout << "output: ";


			for (int j = 0; j < i; j++)
				std::cout << db.at(j) << " ";
			std::cout << std::endl;
			i--;
		}
	}
}