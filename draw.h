/**
@file draw.h
Intersection Points
@author Raffael Siqueira
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>
using namespace std;

void myDisplay(void);
void drawVertex(vertex v);
void drawLine(vertex v1, vertex v2);
void myMouse(int button, int state, int x, int y);
void myInit(void);