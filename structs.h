#include <cmath>

struct Point
{
    int x;
    int y;
};

struct Polygon
{
    Point* points;
    int length = 0;   // the number of points  

    void close();
    void addPoint( Point point );
    void addPoint( int x, int y );
};
