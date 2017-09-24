#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>

float pontos[2][2];

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
void myMouse(int button, int state, int x, int y)
{
    int yy;
    yy = glutGet(GLUT_WINDOW_HEIGHT);
    y = yy - y; /* In Glut, Y coordinate increases from top to bottom */
    glColor3f(1.0, 0, 0);
    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
    {
        if(pontos[0][0] == 0.0 && pontos[0][1] == 0.0){
            pontos[0][0] = x;
            pontos[0][1] = y;
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();        
        }else{
            for(int i = pontos[0][0] ; i < x ; i++){
                for (int j = pontos[0][1] ; j < y ; j++){
                    glBegin(GL_POINTS);
                glVertex2i(i, j);
                glEnd();
                }
            }
            pontos[0][0] = 0.0;
            pontos[0][1] = 0.0;
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
    
    pontos[0][0] = 0.0;
    pontos[0][1] = 0.0;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Draw Pixel");
    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);
/*glutMotionFunc(myPressedMove);*/
    myInit();
    glutMainLoop();
}