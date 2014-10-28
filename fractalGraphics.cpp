#include "fractal.h"

 /***************************************************************************//**
 * Draw Line
 * Authors - Derek Stotz, Charles Parsons
 *
 * Draws a colored line on the viewport.
 ******************************************************************************/
void drawLine(Point first, Point second, const float color[])
{
    glColor3fv(color);
    glBegin(GL_LINES);
        glVertex2i(first.x, first.y);
        glVertex2i(second.x, second.y);
    glEnd();
    glFlush();
}

 /***************************************************************************//**
 * Draw Polygon
 * Authors - Derek Stotz, Charles Parsons
 *
 * Draws a given polygon in a given color.
 ******************************************************************************/
void drawPolygon(Polygon poly, const float color[])
{
    int i, size;

    size = poly.length;

    for(i = 0; i < size - 1; ++i)
    {
        //draw a line between each pair of points
        drawLine(poly.points[i], poly.points[i+1], color);
    }

}

 /***************************************************************************//**
 * Draw Field
 * Authors - Derek Stotz, Charles Parsons
 *
 * Draws a white box in the middle of viewport to separate starting shape and
 * generator pattern.
 ******************************************************************************/
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

    drawLine(poly[0], poly[1], White);
    drawLine(poly[1], poly[2], White);
    drawLine(poly[2], poly[3], White);
    drawLine(poly[3], poly[0], White);
    
}

 /***************************************************************************//**
 * Draw Text
 * Authors - Derek Stotz, Charles Parsons
 *
 * Draws specified text in a specified area of the viewport.
 ******************************************************************************/
void drawText(char* text, int x)
{
    drawBitmapString(text, x, 0, Yellow);
}

 /***************************************************************************//**
 * Fit Pattern
 * Authors - Derek Stotz, Charles Parsons
 *
 * Determines the angle of the line to be replaced, scales the pattern to the 
 * length of that line, rotates the pattern to the proper angle, and translates
 * the pattern to the location of the original line.
 ******************************************************************************/
Polygon fitPattern(Polygon poly, Point start, Point end)
{
    int delta_x, delta_y;
    double distance = 0.0;
    double theta = 0.0;

    //given a pattern at (0,0), where distance from P0 to Pn = 1
    //find theta between angle at P1 and P2
    delta_x = end.x - start.x;
    delta_y = end.y - start.y;
    theta = atan(delta_y / delta_x);

    //scale by distance fit P1 to fit P2
    distance = sqrt((delta_x * delta_x) + (delta_y * delta_y));
    scale(poly, distance);

    //rotate by theta
    rotate(poly, theta);

    //translate by fit P1x and fit P1y
    translate(poly, start.x, start.y);

    return poly;
}

 /***************************************************************************//**
 * itoa
 * Authors - Derek Stotz, Charles Parsons
 *
 * Converts an integer to a character string.
 ******************************************************************************/
const char* itoa(int num)
{
    std::string str;
    
    str = std::to_string(num);

    return str.c_str();
    
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
void drawBitmapString( const char *string, float x, float y, const float color[] )
{
    glColor3f( color[0], color[1], color[2] );
    glRasterPos2f( x, y );
    // while ( *string ) glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, *string++ );
    glutBitmapString( GLUT_BITMAP_HELVETICA_18, (const unsigned char *)string );
}




