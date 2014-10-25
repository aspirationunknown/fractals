#include "structs.h"

void Polygon::close()
{
    // adds the first point as the final to close off the polygon
    this->addPoint(this->points[0]);
}

void Polygon::addPoint(Point point)
{
    this->points[this->length] = point;
    this->length++;
}

void Polygon::addPoint(int x, int y)
{
    Point point;
    point.x = x;
    point.y = y;

    this->addPoint(point);
}
