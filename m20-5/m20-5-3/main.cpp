#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define RIVER 0
#define BASKET  1

bool addToBasket(const char* fish)
{
	std::ofstream basket("basket.txt", std::ios::app);

	if (basket.is_open())
	{
		basket.write(fish, strlen(fish));
		basket.write("\n", 1);
	}

	else
		return false;

	basket.close();
	return true;
}

std::vector<std::string> getFish(int n)
{
	std::vector<std::string> names;
	if (n == BASKET)
	{
		std::ifstream basket("basket.txt");
		std::string fish;

		if (basket.is_open())
		{
			printf("You have: \n");
			while (std::getline(basket, fish))
				std::cout << fish << std::endl;

			std::cout << std::endl;
		}
		else
			printf("Can't find your basket.\n");

		return names;
	}
	else if (n == RIVER)
	{
		std::ifstream river("river.txt");
		std::string fish;
		int ctr = 1;

		if (river.is_open())
		{
			while (std::getline(river, fish))
			{
				std::cout << ctr << ". " << fish << std::endl;
				names.push_back(fish);
				ctr++;
			}
		}
		else
			std::cout << "There is no river." << std::endl;

		river.close();
	}
}

int main()
{
	std::vector<std::string> river = getFish(RIVER);
	std::string fish;
	
	
	while (fish != "q" || fish == "Q")
	{
		CATCH:
		printf("What kind of fish do you want to catch?\n\t\"S\" to show your basket \"Q\" to exit.\n>>");
		std::cin >> fish;
		int i = 0;
		if (fish == "s" || fish == "S")
		{
			getFish(BASKET);
			continue;
		}


		for (; i < river.size(); i++)
		{
			if (fish == river[i])
			{
				if (addToBasket(fish.c_str()))
					printf("You catch the fish.\n");
				else
					printf("Can't add fish to the basket.\n");
				break;
			}
			else if (fish != river[i])
				continue;
		}

		if (i == river.size())
			printf("You miss the fish!\n");

	}


}