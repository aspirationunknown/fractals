/***************************************************************************//**
 * fractals.cpp
 *
 * Assignment - PA 2 - Fractals
 *
 * Authors - Derek Stotz, Charles Parsons
 *
 * Date - October 27, 2014
 *
 * Instructor - Dr. Weiss
 *
 * Course - CSC 433
 *
 * Location - McLaury - Room 313
 *
 *
 * Usage - 
            To Compile: make
            To Run: ./pong

            This application is a fractal generator which requries the user
            to draw an initiator shape and a generator pattern with a series of
            line segments.  After asking the user for a number of iterations, the
            application draws the fractal by replacing each line segment with the
            generator pattern.  Each iteration replaces the line segments in the
            current shape with a scaled down replication of the original generator pattern.

            Authors: Derek Stotz & Charles Parsons


            Controls:

            Mode: Draw Initiator Shape

             - Click to create endpoints
             - Right click to close the shape

            Mode: Draw Generator Pattern
            
             - Click to create endpoints
             - After two or more endpoints have been drawn, right click to end the pattern
                
                        
 * Details -  
            The structure of fractals is 
 *
 * Issues and Bugs - 
            No bugs to speak of.
 *
 ******************************************************************************/
#include "fractalGraphics.h"
#include <cmath>

using namespace std;

// keyboard press flags

keyboardManager keys;

bool up_pressed = false;
bool down_pressed = false;
bool left_pressed = false;
bool right_pressed = false;

bool minus_pressed = false;
bool plus_pressed = false;

bool w_pressed = false;
bool s_pressed = false;
bool a_pressed = false;
bool d_pressed = false;

bool enter_pressed = false;
bool space_pressed = false;
bool shift_pressed = false;

// screen state
screen current_screen = INITIATOR_SHAPE;
int ScreenWidth = 1280;
int ScreenHeight = 512;
int fps = 60;

// function prototypes
void initOpenGL( void );
void screenSetup( void );
void display( void );
void step( int value);
void reshape( int w, int h );
void keyboard_up( unsigned char key, int x, int y );
void keyboard_down( unsigned char key, int x, int y );
void special_up( int key, int x, int y );
void special_down( int key, int x, int y );

// step functions
void initiator_step();
void generator_step();
void fractal_step();
void shared_step();
 
 /***************************************************************************//**
 * main
 * Authors - Derek Stotz, Charles Parsons
 *
 * The entry point of the fractal application.  Sets up the environment.
 *
 * Parameters - 
            argc - the number of arguments from the command prompt.
            argv - the command line arguments.
 ******************************************************************************/
int main ( int argc, char *argv[] )
{  
    //start displaying
    screenMenuSetup();
    glutInit(&argc, argv);
    initOpenGL();
    glutMainLoop();    

    return 0;
}


 /***************************************************************************//**
 * initOpenGL
 * Authors - Derek Stotz, Charles Parsons
 *
 * Sets up OpenGL and creates the main window.
 ******************************************************************************/
void initOpenGL( void )
{
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );     // 32-bit graphics and double buffering

    glutInitWindowSize( ScreenWidth, ScreenHeight );    // initial window size
    glutInitWindowPosition( 100, 50 );                  // initial window position
    glutCreateWindow( "Fractals" );                  // window title

    glutIgnoreKeyRepeat(1); // ignore repeated key presses
    glutKeyboardUpFunc( keyboard_up );
    glutKeyboardFunc( keyboard_down );
    glutSpecialUpFunc( special_up );
    glutSpecialFunc( special_down );

    glClearColor( 0.0, 0.0, 0.0, 1.0 );                 // use black for glClear command
    glutDisplayFunc( display );
    glutReshapeFunc( reshape );
    glutTimerFunc( 1000/fps, step, 0 );
}


 /***************************************************************************//**
 * step
 * Authors - Derek Stotz, Charles Parsons
 *
 * Does a step in the application, handled differently depending on which screen is active
 * 
 * Parameters - 
    value - an unused integer passed by glutTimerFunc
 ******************************************************************************/
void step ( int value )
{
    switch( current_screen )
    {
        case INITIATOR_SHAPE:
            initiator_step( main_menu );
            break;
        case GENERATOR_PATTERN:
            generator_step( practice_menu );
            break;
        case FRACTAL:
            fractal_step();
            break;
        default:
            break;
    }
    glutPostRedisplay();
    glutTimerFunc( 1000/fps, step, 0 );
}

 /***************************************************************************//**
 * display
 * Authors - Derek Stotz, Charles Parsons
 *
 * The display callback, taking into account the current screen
 ******************************************************************************/
void display( void )
{
    glClear( GL_COLOR_BUFFER_BIT );
    switch( current_screen )
    {
        case INITIATOR_SHAPE:
            display_initiator();
            break;
        case GENERATOR_PATTERN:
            display_generator();
            break;
        case FRACTAL:
            display_fractal();
            break;
        default:
            break;
    }

    glutSwapBuffers();
    glFlush();

}

 /***************************************************************************//**
 * reshape
 * Authors - Dr. John Weiss
 *
 * The callback function which reshapes the window
 *
 * Parameters -
    w - the width of the screen
    h - the height of the screen
 ******************************************************************************/
void reshape( int w, int h )
{
    // orthographic projection of 3-D scene onto 2-D, maintaining aspect ratio
    glMatrixMode( GL_PROJECTION );      // use an orthographic projection
    glLoadIdentity();                   // initialize transformation matrix
    if ( w > h )                        // use width:height aspect ratio to specify view extents
        gluOrtho2D( - ScreenWidth, ScreenWidth, - ScreenHeight, ScreenHeight );
    else
        gluOrtho2D( - ScreenWidth, ScreenWidth, -ScreenHeight, ScreenHeight );
    glViewport( 0, 0, w, h );           // adjust viewport to new window

    // switch back to (default) model view mode, for transformations
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

 /***************************************************************************//**
 * screenSetup
 * Authors - Derek Stotz, Charles Parsons
 *
 * Sets up the objects to be used in the screen modes
 ******************************************************************************/
void screenSetup()
{
}

 /***************************************************************************//**
 * keyboard_down
 * Authors - Derek Stotz, Charles Parsons
 *
 * handles key press events
 ******************************************************************************/
void keyboard_down( unsigned char key, int x, int y )
{
    switch( key )
    {
        case '-':
            minus_pressed = true;
            break;
        case '=':
        case '+':
            plus_pressed =  true;
            break;
        case 'w':
        case 'W':
            w_pressed = true;
            break;
        case 's':
        case 'S':
            s_pressed = true;
            break;
        case 'a':
        case 'A':
            a_pressed = true;
            break;
        case 'd':
        case 'D':
            d_pressed = true;
            break;
        case 13:
            enter_pressed = true;
            break;
        case ' ':
            space_pressed = true;
            break;
        case 27:
            exit ( 0 );
        default:
            break;
    }
}

 /***************************************************************************//**
 * keyboard_up
 * Authors - Derek Stotz, Charles Parsons
 *
 * handles key release events
 ******************************************************************************/
void keyboard_up( unsigned char key, int x, int y )
{
    switch( key )
    {
        case '-':
            minus_pressed = false;
            break;
        case '+':
        case '=':
            plus_pressed = false;
            break;
        case 'w':
        case 'W':
            w_pressed = false;
            break;
        case 's':
        case 'S':
            s_pressed = false;
            break;
        case 'a':
        case 'A':
            a_pressed = false;
            break;
        case 'd':
        case 'D':
            d_pressed = false;
            break;
        case '\n':
            enter_pressed = false;
            break;
        case ' ':
            space_pressed = false;
        default:
            break;
    }
}

 /***************************************************************************//**
 * special_down
 * Authors - Derek Stotz, Charles Parsons
 *
 * handles key press events for arrow keys
 ******************************************************************************/
void special_down( int key, int x, int y )
{
    switch( key )
    {
        case GLUT_KEY_UP:
            up_pressed = true;
            break;
        case GLUT_KEY_DOWN:
            down_pressed = true;
            break;
        case GLUT_KEY_LEFT:
            left_pressed = true;
            break;
        case GLUT_KEY_RIGHT:
            right_pressed = true;
        default:
            break;
    }
}

 /***************************************************************************//**
 * special_up
 * Authors - Derek Stotz, Charles Parsons
 *
 * handles key release events for special keys
 ******************************************************************************/
void special_up( int key, int x, int y )
{
    switch( key )
    {
        case GLUT_KEY_UP:
            up_pressed = false;
            break;
        case GLUT_KEY_DOWN:
            down_pressed = false;
            break;
        case GLUT_KEY_LEFT:
            left_pressed = false;
            break;
        case GLUT_KEY_RIGHT:
            right_pressed = false;
        default:
            break;
    }
}


 /***************************************************************************//**
 * Game Step
 * Authors - Derek Stotz, Charles Parsons
 *
 * Does a step in the initiator generation screen mode
 ******************************************************************************/
void initiator_step()
{
    shared_step();

    }


 /***************************************************************************//**
 * Shared Step
 * Authors - Derek Stotz, Charles Parsons
 *
 * Does a step in the environment, telling what parts of the application's state
        need to change.  Used by all other steps.
 ******************************************************************************/
void shared_step()
{
}

