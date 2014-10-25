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


//functions
void rotate(Polygon poly[]);
void rotatePoints(/*add params*/);
void scale(Polygon  poly[]);
void scalePoints(/*add params*/);
void translate(Polygon  poly[]);
void translatePoints(/*add params*/);



