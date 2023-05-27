#include <iostream>

void swap(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

int main()
{
	int a = 10;
	int b = 3;
	printf("A: %d B: %d\n", a, b);
	swap(a, b);
	printf("A: %d B: %d", a, b);
}
