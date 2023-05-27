#include <iostream>

void reverse(int *arr, int sz)
{
	for (int i = 0, t; i < sz / 2; i++)
	{
		arr[i] = arr[sz - i - 1] + arr[i];
		arr[sz - i - 1] = arr[i] - arr[sz - i - 1];
		arr[i] = arr[i] - arr[sz - i - 1];
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	//before
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");

	//---
	reverse(arr,sz);
	//---

	//after
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	
	return 0;
}