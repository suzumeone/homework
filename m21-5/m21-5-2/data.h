#pragma once
#include <vector>
#include <iostream>

enum RoomType
{
	BedRoom,
	LivingRoom,
	Kitchen,
	BathRoom,
	ChildRoom
};

enum BuildingType
{
	House,
	Sauna,
	Garage,
	Storage
};

struct Rooms
{
	int room_area;
	RoomType type;
};

struct Floors
{
	int room_count;
	std::vector<Rooms> rooms;
};

struct Buildings
{
	BuildingType type;
	bool hasPipe;
	double area;
	int floorCout;
	std::vector<Floors> floors;
};

struct Sectors
{
	int id;
	double area;
	std::vector<Buildings> buildings;
};

struct Village
{
	std::vector<Sectors>sectors;
	double area;
};





