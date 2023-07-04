#pragma once
struct Point
{
    double x;
    double y;

};

void scalpel(const Point& start, const Point& end);
void hemostat(const Point& point);
void tweezers(const Point& point);
void suture(const Point& start, const Point& end);