#include <iostream>

using namespace std;

void bubbleSort(float arr[], int n) 
{
	bool swapped;
	for (int i = 0; i < n - 1; i++) 
	{
		swapped = false;
		for (int j = 0; j < n - i - 1; j++) 
		{
			if (arr[j] > arr[j + 1]) 
			{
				std::swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}


int main()
{
	float arr[] = { 1.2f, 2.3f, 1.11f, 3.4f, 5.5f, 5.4f, 5.3f, 5.1f, 1.5f, 1.25f, 5.41f, 5.31f, 5.11f, 1.51f, 1.251f };
	for (int i = 0; i < sizeof(arr) / sizeof(float); i++)
	{
		cout << arr[i] << '\t';
	}

	cout << endl;

	bubbleSort(arr, sizeof(arr) / sizeof(float));

	for (int i = 0; i < sizeof(arr) / sizeof(float); i++)
	{
		cout << arr[i] << '\t';
	}
	
}