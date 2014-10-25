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

bool Polygon::normalize()
{
    // transforms an open polygon so the first and last points are on (0, 0) and (1, 0)
    if (this->points[0].x == this -> points[this->length-1].x && this->points[0].y == this -> points[this->length-1].y)
        return false;
}
