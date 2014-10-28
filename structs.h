#include <cmath>

// colors {R, G, B}
const float Black[]	= { 0.0, 0.0, 0.0 };
const float Red[]	= { 1.0, 0.0, 0.0 };
const float Green[]	= { 0.0, 1.0, 0.0 };
const float Blue[]	= { 0.0, 0.0, 1.0 };
const float Magenta[]	= { 1.0, 0.0, 1.0 };
const float Cyan[]	= { 0.0, 1.0, 1.0 };
const float Yellow[]	= { 1.0, 1.0, 0.0 };
const float White[]	= { 1.0, 1.0, 1.0 };


struct Point
{
    int x;
    int y;
};

struct Polygon
{
    Point* points;
    unsigned long length = 0;   // the number of points  

    void close();
    void addPoint( Point point );
    void addPoint( int x, int y );
    bool normalize();
};


//transform functions
void rotate(Polygon poly, double angle);
void scale(Polygon poly, double scalar);
void translate(Polygon poly, int x, int y);


