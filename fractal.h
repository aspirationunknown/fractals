#include <iostream>
#include <GL/freeglut.h>

//keys
const int EscapeKey = 27;

//screens
enum screen {INITIATOR_SHAPE, GENERATOR_PATTERN, FRACTAL};

//function prototypes
void DrawScreen(screen current, point[] initiator, point[] generator, point[] fractal);
void DrawBitmapString( const char *string, float x, float y, float color[] );
void DrawLine( float x1, float y1, float x2, float y2, const float color[] );
void DrawFilledEllipse( float x, float y, float xRadius, float yRadius, float color[] );
void DrawFilledRectangle( float x1, float y1, float x2, float y2, float color[] );
void DrawPolygon(point[] poly);
