#include <iostream>

void printA(int array[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << array[i] << "\t";
	std::cout << std::endl;
}

int main()
{
	int arr[] = { -100,-50, -5, 1, 10, 15 };
	int n = sizeof(arr) / sizeof(int);

	printA(arr, n);

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (abs(arr[j]) > abs(arr[j + 1])) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}

	printA(arr, n);
	return 0;
	
}