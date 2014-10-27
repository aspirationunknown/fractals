#include "fractal.h"

void drawLine(Point first, Point second, const float color[])
{
    glColor3fv(color);
    glBegin(GL_LINES);
        glVertex2i(first.x, first.y);
        glVertex2i(second.x, second.y);
    glEnd();
    glFlush();
}

void drawPolygon(Polygon poly[], int size, const float color[])
{
    int i;

    for(i = 0; i < poly.length; ++i)
    {
        //draw a line between each pair of points
        drawLine(poly[i], poly[(i+1)%poly.length], color);
    }

}

void drawField(int screen_height, int screen_width)
{
    Point poly[4];

    poly[0].x = 5;
    poly[0].y = screen_height;

    poly[1].x = -5;
    poly[1].y = screen_height;

    poly[2].x = -5;
    poly[2].y = -screen_height;

    poly[3].x = 5;
    poly[3].y = -screen_height;

    drawLine(poly[0], poly[1]);
    drawLine(poly[1], poly[2]);
    drawLine(poly[2], poly[3]);
    drawLine(poly[3], poly[0]);
    
}

void drawText(char* text, int x)
{
    drawBitmapString(text, x, 0, Yellow);
}

//function to replace a line with the generator pattern


 /***************************************************************************//**
 * DrawBitmapString
 * Authors - Dr. John Weiss
 *
 * Draws a stroke string for a game menu
 * Parameters -
    string - the string to draw
    x - the x location to draw the string on the screen
    y - the y location to draw the string on the screen
    color -the color the draw the string, stored in a 3-element array
 ******************************************************************************/
void drawBitmapString( const char *string, float x, float y, float color[] )
{
    glColor3f( color[0], color[1], color[2] );
    glRasterPos2f( x, y );
    // while ( *string ) glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, *string++ );
    glutBitmapString( GLUT_BITMAP_HELVETICA_18, (const unsigned char *)string );
}




