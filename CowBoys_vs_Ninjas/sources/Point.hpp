#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Point
{

    double AxisX;
    double AxisY;

public:
    Point(double AxisX, double AxisY);
    double distance(const Point &);
    string print();
    static Point moveTowards(Point, Point, double);
};
