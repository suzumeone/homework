#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> removeNum(std::vector<int> nums, int numToDelete)
{
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums.at(i) == numToDelete)
		{
			nums.resize(nums.size() + 1);
			std::swap(nums.at(i), nums.back());
			nums.pop_back();
			for (int j = i, k = i + 1; j < nums.size() - 1; j++)
			{
				std::swap(nums.at(j), nums.at(k));
				k++;
			}
			i--;
			nums.pop_back();
		}
	}

	return nums;
}

void printV(std::vector<int> _vector)
{
	for (int i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}

std::vector<int> fillVector(int _vectorSZ)
{
	vector<int> vec(_vectorSZ);

	cout << "Input numbers: ";

	for (int i = 0; i < vec.size(); i++)
		cin >> vec[i];

	return vec;
}


int main()
{
	int vecSZ, numToDelete;

	cout << "Input vector size: ";
	cin >> vecSZ;

	vector<int> nums = fillVector(vecSZ);

	cout << "Input number to delete: ";
	cin >> numToDelete;

	cout << "Result: ";
	printV(removeNum(nums, numToDelete));

	return 0;
}