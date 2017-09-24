#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include "AVL.h"
#include "Node.h"
using namespace std;

AVL tree;

//structure that stores a vertex with coordinates (x,y)
struct vertex{
	int x;
	int y;
	int line;
	int side; //0 if left, 1 if rigth
};

struct less_than_x{
	inline bool operator() (const vertex& v1, const vertex& v2){
		return (v1.x < v2.x);
	}
};

struct less_than_y{
	inline bool operator() (const vertex& v1, const vertex& v2){
		return (v1.y < v2.y);
	}
};

//vertex 1 of any line to be drawn
vertex v1;

//vector of vertices
vector<vertex> points;

//stucture that stores a line
struct line {
	vertex v1;
	vertex v2;
};

//vector with drawn lines
vector <line> lines;

//Check orientation between 3 points
int orientation(vertex p, vertex q, vertex r){
	int o = ((q.y - p.y)*(r.x - q.x)) - ((q.x - p.x) * (r.y - q.y));

	if (o == 0){
		return 0; //the points are colinear
	}

	return (o>0) ?  1: 2; //clock or counterclock wise
}

//Check if two lines have intersection
bool doIntersect(line l1, line l2){
	int o1 = orientation(l1.v1, l1.v2, l2.v1);
	int o2 = orientation(l1.v1, l1.v2, l2.v2);
	int o3 = orientation(l2.v1, l2.v2, l1.v1);
	int o4 = orientation(l2.v1, l2.v2, l1.v2);

	if(o1 != o2 && o3 != o4){
		return true;
	}else{
		return false;
	}

}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
void myMouse(int button, int state, int x, int y)
{
    int yy;
    yy = glutGet(GLUT_WINDOW_HEIGHT);
    y = yy - y; /* In Glut, Y coordinate increases from top to bottom */
    //define red the color of any drawing for now in this function
    glColor3f(1.0, 0, 0);
    glPointSize(5.0f);

    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
    {
    	if(v1.x == 0.0 && v1.y == 0.0){ //that means: if this mouse click was the first of the line to be drawn
    		//then, this point is stored in v1
    		v1.x = x;
            v1.y = y;
            v1.line = lines.size();

            //and drawn on the screen
           
        	glBegin(GL_POINTS);
	        	glVertex2i(x, y);
	        glEnd();
	        
    	}
    	else{ //that means: if this mouse click was the second of the line to be drawn
    		//drawn the point in the screen

    		glBegin(GL_POINTS);
	        	glVertex2i(x, y);
	        glEnd();
	        //draw a line connecting the two points

    		glBegin(GL_LINES);
    			glVertex2i(v1.x, v1.y);
    			glVertex2i(x,y);
    		glEnd();

    		//stores the second point in a vertex structure
    		vertex v2;
    		v2.x = x;
    		v2.y = y;
    		v2.line = lines.size();
    		
    		if (v1.x < v2.x){
    			v1.side = 0;
    			v2.side = 1;
    		}
    		else{
    			v1.side = 1;
    			v2.side = 0;	
    		}
            points.push_back(v1);
    		points.push_back(v2);

    		sort(points.begin(), points.end(), less_than_x()); 




    		//create a new line with this two vertices
    		line l;
    		l.v1 = v1;
    		l.v2 = v2;
    		//put the line in the vector of lines
    		lines.push_back(l);

    		//set v1 with zero to be possible draw a new line in the next click
    		v1.x = 0.0;
    		v1.y = 0.0;

    		if(lines.size()>1){

				for (int i = 0; i < lines.size() - 1; i++){
					if (doIntersect(lines[i], lines.back())){
						//The intersection can be defined using determinants
						vertex intersection;
	    				intersection.x = ((((lines[i].v1.x * lines[i].v2.y) - (lines[i].v1.y * lines[i].v2.x))*(lines.back().v1.x - lines.back().v2.x)) - ((lines[i].v1.x - lines[i].v2.x)*((lines.back().v1.x * lines.back().v2.y)-(lines.back().v1.y * lines.back().v2.x)))) /
	    				                 (((lines[i].v1.x - lines[i].v2.x)*(lines.back().v1.y - lines.back().v2.y)) - ((lines[i].v1.y - lines[i].v2.y)*(lines.back().v1.x - lines.back().v2.x)));
	    				intersection.y = ((((lines[i].v1.x * lines[i].v2.y) - (lines[i].v1.y * lines[i].v2.x))*(lines.back().v1.y - lines.back().v2.y)) - ((lines[i].v1.y - lines[i].v2.y)*((lines.back().v1.x * lines.back().v2.y)-(lines.back().v1.y * lines.back().v2.x)))) /
	    				                 (((lines[i].v1.x - lines[i].v2.x)*(lines.back().v1.y - lines.back().v2.y)) - ((lines[i].v1.y - lines[i].v2.y)*(lines.back().v1.x - lines.back().v2.x)));
	    				glColor3f(0.0, 1.0, 0.0);

	    				glPointSize(7.5f);
	    				
	    				glBegin(GL_POINTS);
				        	glVertex2f(intersection.x, intersection.y);
				        glEnd();

				        
					}
				}    			

		    	
	    	} 
    	}

    

    }
    glFlush();
}
void myInit(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}



int main(int argc, char** argv)
{
	v1.x = 0.0;
	v1.y = 0.0;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Trabalho 1 -  Computacao Grafica I - Raffael Siqueira");
    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);
/*glutMotionFunc(myPressedMove);*/
    myInit();
    glutMainLoop();
}