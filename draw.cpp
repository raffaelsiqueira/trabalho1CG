/**
@file draw.cpp
Intersection Points
@author Raffael Siqueira
*/

#include "globals.h"
#include "intersections.h"
#include "draw.h"

/*
* Responsible for the display
* @fn void myDisplay(void)
*/
void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

/*
* Draw the vertex on the display
* @fn void drawVertex(vertex v)
* @param v The vertex we want to draw
*/
void drawVertex(vertex v){
	glColor3f(1.0, 0, 0);
    glPointSize(5.0f);
	glBegin(GL_POINTS);
    	glVertex2i(v.x, v.y);
    glEnd();
}

/*
* Draw the line on the display
* @fn void drawLine(line l)
* @param l The line we want to draw
*/
void drawLine(line l) {
	glColor3f(1.0, 0, 0);
    glPointSize(5.0f);
	glBegin(GL_LINES);
		glVertex2i(l.v1.x, l.v1.y);
		glVertex2i(l.v2.x, l.v2.y);
	glEnd();
}

/*
* Responsible to recognize the click of the mouse and define how to do next
* @fn void myMouse(int button, int state, int x, int y
* @param button Wich button of the mouse was clicked
* @param state The state of the mouse
* @param x The coordinate x of the click
* @param y The coordinate y of the click
*/
void myMouse(int button, int state, int x, int y){
    int yy;
    yy = glutGet(GLUT_WINDOW_HEIGHT);
    y = yy - y; /* In Glut, Y coordinate increases from top to bottom */
    //define red the color of any drawing for now in this function
    

    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
    {
    	/*v1.x == 0.0 && v1.y == 0.0*/
    	if( points.size() % 2 == 0 ){ //that means: if this mouse click was the first of the line to be drawn
    		//then, this point is stored in v1
    		v.x = x;
            v.y = y;
            v.line = lines.size();

            //and drawn on the screen
            drawVertex(v);
            points.push_back(v);
           
        	
	        
    	}
    	else{ //that means: if this mouse click was the second of the line to be drawn
    		//drawn the point in the screen

    		vertex v2;
    		v2.x = x;
    		v2.y = y;
    		v2.line = lines.size();
    		drawVertex(v2);	        

    		//create a new line with this two vertices
    		line l;
    		l.v1 = v;
    		l.v2 = v2;

	        //draw a line connecting the two points
    		drawLine(l);

    		//put the line in the vector of lines
    		lines.push_back(l);

    		//stores the two points in a vertex structure
            
    		points.push_back(v2);    		

    		checkIntersections();
    	}

    

    }
    glFlush();
}

/*
* Responsible to init all the application
* @fn void myInit(void)
*/
void myInit(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}