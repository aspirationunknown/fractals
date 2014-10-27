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

//transform functions
void rotate(Polygon poly, double angle)
{
    rotatePoints(poly.points, poly.length, angle);
}

void rotatePoints(Point* points, int size, double angle)
{
    Point current;
    int i;

    for(i = 0; i < size; ++i)
    {
        current = points[i];
        points[i].x = current.x * cos(angle) - current.y * sin(angle);
        points[i].y = current.x * sin(angle) - current.y * cos(angle);
    }
}

void scale(Polygon poly)
{
    scalePoints(poly.points, poly.length);
}
void scalePoints(Point* points, int size)
{
    Point begin, end; //points where generator pattern begins and ends
    double distance; //distance between begin and end
    int i;

    begin = points[0];
    end = points[size-1]; 

    distance = sqrt((end.x - begin.x)*(end.x - begin.x) + (end.y - begin.y) * (end.y - begin.y));

    for(i = 0; i < size; ++i)
    {
        points[i].x *= (1.0 / distance);
        points[i].y *= (1.0 / distance);
    }
}

void translate(Polygon poly)
{
    translatePoints(poly.points, poly.length);
}

void translatePoints(Point* points, int size)
{
    int delta_x, delta_y, i;

    delta_x = -points[0].x;
    delta_y = -points[0].y;

    for(i = 0; i < size; ++i)
    {
        points[i].x += delta_x;
        points[i].y += delta_y;
    }
}


