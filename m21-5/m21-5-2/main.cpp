#include "filling.h"
#include "utils.h"

int main()
{
	Village village;
	village.area = getArea();
	village.sectors.push_back(FillSector());

	if (village.sectors[0].buildings[0].type == House)
		std::cout << "Area of first room on first floor is: " << village.sectors[0].buildings[0].floors[0].rooms[0].room_area << std::endl;

	return 0;
}