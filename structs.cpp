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
    int delta_x, delta_y;
    double distance, theta;

    // transforms an open polygon so the first and last points are on (0, 0) and (1, 0)
    if (this->points[0].x == this -> points[this->length-1].x && this->points[0].y == this -> points[this->length-1].y)
        return false;

    //scale to length 1
    delta_x = this->points[this->length-1].x - this->points[0].x;
    delta_y = this->points[this->length-1].y - this->points[0].y;
    distance = sqrt((delta_x*delta_x) + (delta_y * delta_y));
    scale(*this, (1.0 / distance));

    //rotate so first and last points are on x-axis
    theta = atan(delta_y / delta_x);
    rotate(*this, -theta);

}

 /***************************************************************************//**
 * Rotate
 * Authors - Derek Stotz, Charles Parsons
 *
 * Rotates the points of a given polygon by a given angle.
 ******************************************************************************/
void rotate(Polygon poly, double angle)
{
    Point current;
    int i, size;

    size = poly.length;

    for(i = 0; i < size; ++i)
    {
        current.x = poly.points[i].x;
        current.y = poly.points[i].y;
        poly.points[i].x = current.x * cos(angle) - current.y * sin(angle);
        poly.points[i].y = current.x * sin(angle) - current.y * cos(angle);
    }
}

 /***************************************************************************//**
 * Scale
 * Authors - Derek Stotz, Charles Parsons
 *
 * Scales a given polygon by a given scalar value.
 ******************************************************************************/
void scale(Polygon poly, double scalar)
{
    int i, size;

    size = poly.length;

    for(i = 0; i < size; ++i)
    {
        poly.points[i].x *= scalar;
        poly.points[i].y *= scalar;
    }
}

 /***************************************************************************//**
 * Translate
 * Authors - Derek Stotz, Charles Parsons
 *
 * Translates a given polygon to a given point.
 ******************************************************************************/
void translate(Polygon poly, int x, int y)
{

    int i, size;
    
    size = poly.length;

    for(i = 0; i < size; ++i)
    {
        poly.points[i].x += x;
        poly.points[i].y += y;
    }
}


