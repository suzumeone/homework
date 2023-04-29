#include <iostream>
#include <vector>

using std::vector;

int main()
{
	int a[4][4];
	vector<int> vec;
	vector<int> vResult;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << "A [" << i + 1 << "][" << j + 1 << "]: ";
			std::cin >> a[i][j];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int n;
		std::cout << "vec[" << i+1 << "]: ";
		std::cin >> n;
		vec.push_back(n);
	}

	for (int i = 0; i < 4; i++)
	{
		int rowResult = 0;
		for (int j = 0; j < 4; j++)
		{
			rowResult += a[i][j] * vec.at(j);
		}
		vResult.push_back(rowResult);
		rowResult = 0;
	}

	std::cout << "Result: " << std::endl;
	for (int i = 0; i < vResult.size(); i++)
	{
		std::cout << "Row " << i+1 << ": " << vResult.at(i) << std::endl;
	}
	
}