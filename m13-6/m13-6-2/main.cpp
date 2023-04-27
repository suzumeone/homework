#include <iostream>
#include <vector>

int main()
{
	std::vector<float> prices{ 2.5, 4.25, 3.0, 10.0 };
	std::vector<int> items{ 1, 1, 0, 3 };
	float sum = 0.f;

	for (int i = 0; i < items.size(); i++)
	{
		if (items[i] < prices.size())
			sum += prices[items[i]];
		else
			std::cout << "We don't have product with index " << items[i] << ", skip" << std::endl;
	}
	std::cout << "Produts total cost: " << sum;
}