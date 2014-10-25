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
    int length = 0;   // the number of points  

    void close();
    void addPoint( Point point );
    void addPoint( int x, int y );
    bool normalize();
};


//functions
void rotate(Polygon poly);
void rotatePoints(/*add params*/);
void scale(Polygon  poly);
void scalePoints(/*add params*/);
void translate(Polygon  poly);
void translatePoints(/*add params*/);


