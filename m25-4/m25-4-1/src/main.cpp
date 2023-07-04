#include <iostream>
#include "tools.h"

int main()
{
    Point start, end;
    std::cout << "Enter the start point of the cut: ";
    std::cin >> start.x >> start.y;
    
    std::cout << "Enter the end point of the cut: ";
    std::cin >> end.x >> end.y;
    
    scalpel(start, end);
    
    Point clamp;
    std::cout << "Enter point to clamp: ";
    std::cin >> clamp.x >> clamp.y;
    
    hemostat(clamp);
    tweezers(clamp);
    
    std::cout << "Enter the start point of the seam: ";
    std::cin >> start.x >> start.y;
    
    std::cout << "Enter the end point of the seam: ";
    std::cin >> end.x >> end.y;
    
    suture(start, end);
    return 0;
}

void scalpel(const Point& start, const Point& end) 
{
    std::cout << "Cut between points (" << start.x << ", " << start.y << ") & (" << end.x << ", " << end.y << ")" << std::endl;
}

void hemostat(const Point& point) 
{
    std::cout << "Clamp in point (" << point.x << ", " << point.y << ")" << std::endl;
}

void tweezers(const Point& point) 
{
    std::cout << "Tweezers at the point (" << point.x << ", " << point.y << ")" << std::endl;
}

void suture(const Point& start, const Point& end) 
{
    std::cout << "Seam between dots (" << start.x << ", " << start.y << ") & (" << end.x << ", " << end.y << ")" << std::endl;
}