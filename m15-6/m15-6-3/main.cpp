#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& vec) {
	int n = vec.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (vec[j] > vec[j + 1]) {
				std::swap(vec[j], vec[j+1]);
			}
		}
	}
}

void printV(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec.at(i) << " ";
}

std::vector<int> unicNums(std::vector<int> osv)//originalSortedVector
{
	std::vector<int> unicVec;
	int prevNum = osv[0];

	for (int i = 1; i < osv.size(); i++)
	{
		if (prevNum != osv[i])
		{
			unicVec.push_back(prevNum);
			prevNum = osv[i];
		}
	}
	unicVec.push_back(prevNum);
	return unicVec;
}

int main()
{
	std::vector<int> vec;
	int input = 0;
	for(;;)
	{
		for (;;)
		{
			std::cout << "Input: ";
			std::cin >> input;
			if (input == -1)
				break;
			if (input == -2)
				return 0;
			vec.push_back(input);
		}

		std::cout << "Output: ";
		bubbleSort(vec);
		std::cout << unicNums(vec)[4] << " (Sorted array preview: { ";
		printV(vec);
		std::cout << "})" << std::endl;
	}

	return 0;
}