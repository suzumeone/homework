#include "data.h"
#include "utils.h"
#include "filling.h"

Sectors FillSector()
{
	Sectors sector;
	int id;
	std::cout << "Sector ID: ";
	std::cin >> id;
	sector.id = id;

	double area;
	std::cout << "Sector area: ";
	std::cin >> area;
	sector.area = area;

	int bctr = 1;
	do
	{
		std::cout << "How many buildings on sector?: ";
		std::cin >> bctr;

	} while (bctr < 0 || bctr > 4);

	for (int i = 0; i < bctr; i++)
	{
		int type = 0;
		while (true)
		{
			std::cout << "Enter building type: \n1. House\n2. Sauna\n3. Garage\n4. Storage\n>> ";
			std::cin >> type;
			if (type >= 1 && type <= 4)
				break;
			else
				std::cout << "Invalid building type." << std::endl << std::endl;
		}
		sector.buildings.push_back(FIllBuilding(static_cast<BuildingType>(type-1)));
	}

	return sector;
}

Buildings FIllBuilding(BuildingType type)
{
	Buildings building;

	switch (type)
	{
	case House:
		building.type = type;
		building.area = getArea();
		building.hasPipe = checkPipe("house");

		int fc;

		while (true)
		{
			std::cout << "how many floors are there in the house?: ";
			std::cin >> fc;
			if (fc >= 1 || fc <= 3)
				break;
		}
		building.floorCout = fc;
		for (int i = 0; i < fc; i++)
		{
			building.floors.push_back(FillFloor());
		}

		break;
	case Sauna:
		building.type = type;
		building.area = getArea();
		building.hasPipe = checkPipe("house");
		break;
	case Garage:
		building.type = type;
		building.area = getArea();
		break;
	case Storage:
		building.type = type;
		building.area = getArea();
		break;
	default:
		break;
	}

	return building;
}

Floors FillFloor()
{
	int rooms;
	Floors floor;

	while (true)
	{
		std::cout << "How many rooms per floor?: ";
		std::cin >> rooms;
		if (rooms >= 2 && rooms <= 4)
			break;
	}

	floor.room_count = rooms;

	for (int i = 0; i < rooms; i++)
	{
		int t = 0;
		while (true)
		{
			std::cout << "Enter id of RoomType: \n1. Bedroom\n2. LivingRoom\n3. Kitchen\n4. BathRoom\n5. ChildRoom\n>> ";
			std::cin >> t;
			if (t >= 1 && t <= 5)
				break;
		}
		floor.rooms.push_back(FillRoom(static_cast<RoomType>(t-1)));
	}

	return floor;
}

Rooms FillRoom(RoomType type)
{
	Rooms room;
	switch (type)
	{
		case BedRoom:
			room.type = type;
			room.room_area = getArea();
			break;
		case LivingRoom:
			room.type = type;
			room.room_area = getArea();
			break;
		case Kitchen:
			room.type = type;
			room.room_area = getArea();
			break;
		case BathRoom:
			room.type = type;
			room.room_area = getArea();
			break;
		case ChildRoom:
			room.type = type;
			room.room_area = getArea();
			break;
	}
	return room;
}




