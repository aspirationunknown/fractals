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
void drawField(int screen_height, int screen_width);
void drawFilledEllipse( float x, float y, float xRadius, float yRadius, float color[] );
void drawFilledRectangle( float x1, float y1, float x2, float y2, float color[] );
void drawPolygon(Polygon poly, const float color[], bool drawPoints);
void drawText(char* text, int x);
void drawCircle(Point point);
void fitPattern(Polygon poly, Point start, Point end, Polygon result);
const char* itoa(int num);
