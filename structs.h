#include <cmath>

struct Point
{
    int x;
    int y;
};

<<<<<<< HEAD
//functions
void rotate(Points poly[]);
void rotatePoints(/*add params*/);
void scale(Points poly[]);
void scalePoints(/*add params*/);
void translate(Points poly[]);
void translatePoints(/*add params*/);

=======
struct Polygon
{
    Point* points;
    int length = 0;   // the number of points  
>>>>>>> cc593631123f2a5cf5da7eeb5ad0347c0b2bcae2

    void close();
    void addPoint( Point point );
    void addPoint( int x, int y );
};
