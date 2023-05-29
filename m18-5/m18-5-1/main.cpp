#include <iostream>
#include <vector>

void swapvec(std::vector<int>&vec, int* arr)
{
	for (int i = 0; i < vec.size(); i++)
		std::swap(vec[i], arr[i]);
}

int main()
{
	std::vector<int> a = { 1,2,3,4 };

	int b[] = { 2,4,6,8 };

	swapvec(a, b);

	for (int i = 0; i < a.size(); i++)
		printf("%d ", a[i]);
	printf("\n");
	for (int i = 0; i < a.size(); i++)
		printf("%d ", b[i]);
	printf("\n");

	return 0;
}