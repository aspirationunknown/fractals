#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "structs.h"
#include <GL/freeglut.h>

//keys
const int EscapeKey = 27;

//screens
enum screen {INITIATOR_SHAPE, GENERATOR_PATTERN, FRACTAL};

//function prototypes
void drawScreen(screen current, Point initiator[], Point generator[], Point fractal[]);
void drawBitmapString( const char *string, float x, float y, const float color[] );
void drawLine(Point first, Point second, const float color[]);
void drawFilledEllipse( float x, float y, float xRadius, float yRadius, float color[] );
void drawFilledRectangle( float x1, float y1, float x2, float y2, float color[] );
void drawPolygon(Polygon poly, const float color[], bool drawPoints);
void drawText(char* text, int x);
void drawCircle(Point point);
Polygon fitPattern(Polygon poly, Point start, Point end);
const char* itoa(int num);
