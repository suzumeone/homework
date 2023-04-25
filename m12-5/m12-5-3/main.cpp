#include <iostream>
#include <cassert>

float travelTime(float distance, float speed)
{
	assert(speed > 0);
	return distance / speed;
}

int main()
{

	//Assertion failed : speed > 0, file D : main.cpp, line 6
	std::cout << travelTime(100, 0) << std::endl;
}