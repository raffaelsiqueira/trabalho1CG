/**
@file main.cpp
Intersection Points
@author Raffael Siqueira
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>

#include "globals.h"
#include "intersections.h"
#include "draw.h"

using namespace std;

vertex v; /*! Vertex to be used in the draw.cpp class */
vector<vertex> points; /*! Vector to store the points drawn on the screen*/
vector <line> lines; /*! Vector to store the lines drawn on the screen*/

/**
* @fn int main(int argc, char** argv)
*
*/

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Trabalho 1 -  Computacao Grafica I - Raffael Siqueira");
    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);
    myInit();
    glutMainLoop();
}