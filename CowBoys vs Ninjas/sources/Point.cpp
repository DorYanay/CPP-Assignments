#include "Point.hpp"
using namespace std;

Point::Point(double AxisX, double AxisY) : AxisX(AxisX), AxisY(AxisY) {}
double Point::distance(const Point &other)
{
    return sqrt(pow(AxisX - other.AxisX, 2) + pow(AxisY - other.AxisY, 2));
}
string Point::print()
{
    return "(" + to_string(this->AxisX) + "," + to_string(this->AxisY) + ")";
}

Point Point::moveTowards(Point src, Point dst, double distance)
{
    if (distance == 0)
    {
        return src;
    }
    else if (distance < 0)
    {
        throw invalid_argument("distance cannot be zero\n");
    }

    double totalDistance = src.distance(dst);

    if (totalDistance <= distance)
    {
        // The destination is within reach, return it
        return dst;
    }
    else
    {
        // Calculate the ratio of the distance to move
        double ratio = distance / totalDistance;

        // Calculate the new point coordinates
        double newX = src.AxisX + ratio * (dst.AxisX - src.AxisX);
        double newY = src.AxisY + ratio * (dst.AxisY - src.AxisY);

        // Return the new point
        return Point(newX, newY);
    }
}
