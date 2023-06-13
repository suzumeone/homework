#include "data.h"

int main()
{
	std::cout << "Commands: \n\tList\n\tAdd\n\tQ for Exit\n" << std::endl;
	std::string choice;
	listing lists;
	while (true)
	{
		printf(">>> ");
		std::cin >> choice;
		if (choice == "q" || choice == "Q")
			return 0;
		else if (choice == "List" || choice == "list")
			list("data.txt", lists);
		else if (choice == "Add" || choice == "add")
			add("data.txt", lists);
		else
			printf("Invalid input.\n");
		
	}
}

