/*
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <vector>
#include "getGeometryInput.h"
*/
#include <iostream>
#include "robot.h"

using namespace rbt;

static int slices = 16;
static int stacks = 16;

float th1, th2, th3, th4, th5, th6;

/* GLUT callback Handlers */
/*
class Modelo
{
public:
    std::vector<triangle> f;
}M0, M1, M2, M3, M4, M5, M6;

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    //const double a = t*90.0;
    //const double a = 0;
    double y=-4.7;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);

    glPushMatrix();
        glTranslated(0,y,-6);
        glRotated(90,1,0,0);
        glRotated(180,0,1,0);
        glRotated(90,0,0,1);
        //ORIGEN
        glBegin(GL_TRIANGLES);
        glColor3d(1,0,0);
        for(int i=0;i<M0.f.size();i++)
        {
            glNormal3f(M0.f[i].normal.x,M0.f[i].normal.y,M0.f[i].normal.z);
            glVertex3f(M0.f[i].point[0].x,M0.f[i].point[0].y,M0.f[i].point[0].z);
            glVertex3f(M0.f[i].point[1].x,M0.f[i].point[1].y,M0.f[i].point[1].z);
            glVertex3f(M0.f[i].point[2].x,M0.f[i].point[2].y,M0.f[i].point[2].z);
        }
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,y,-6);
        glRotated(90,1,0,0);
        glRotated(180,0,1,0);
        glRotated(90,0,0,1);
        //F0
        glTranslated(0,0,2.9);
        glRotated(th1,0,0,1);
        glRotated(-90,1,0,0);

        glBegin(GL_TRIANGLES);
        glColor3d(1,0,0);
        for(int i=0;i<M1.f.size();i++)
        {
            glNormal3f(M1.f[i].normal.x,M1.f[i].normal.y,M1.f[i].normal.z);
            glVertex3f(M1.f[i].point[0].x,M1.f[i].point[0].y,M1.f[i].point[0].z);
            glVertex3f(M1.f[i].point[1].x,M1.f[i].point[1].y,M1.f[i].point[1].z);
            glVertex3f(M1.f[i].point[2].x,M1.f[i].point[2].y,M1.f[i].point[2].z);
        }
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,y,-6);
        glRotated(90,1,0,0);
        glRotated(180,0,1,0);
        glRotated(90,0,0,1);
        //F0
        glTranslated(0,0,2.9);
        glRotated(th1,0,0,1);
        glRotated(-90,1,0,0);
        //F1
        glRotated(th2-90,0,0,1);
        glTranslated(2.7,0,0);
        //F2
        glBegin(GL_TRIANGLES);
        glColor3d(1,0,0);
        for(int i=0;i<M2.f.size();i++)
        {
            glNormal3f(M2.f[i].normal.x,M2.f[i].normal.y,M2.f[i].normal.z);
            glVertex3f(M2.f[i].point[0].x,M2.f[i].point[0].y,M2.f[i].point[0].z);
            glVertex3f(M2.f[i].point[1].x,M2.f[i].point[1].y,M2.f[i].point[1].z);
            glVertex3f(M2.f[i].point[2].x,M2.f[i].point[2].y,M2.f[i].point[2].z);
        }
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,y,-6);
        glRotated(90,1,0,0);
        glRotated(180,0,1,0);
        glRotated(90,0,0,1);
        //F0
        glTranslated(0,0,2.9);
        glRotated(th1,0,0,1);
        glRotated(-90,1,0,0);
        //F1
        glRotated(th2-90,0,0,1);
        glTranslated(2.7,0,0);
        //F2
        glRotated(th3,0,0,1);
        glTranslated(0.7,0,0);
        glRotated(-90,1,0,0);
        //F3
        glBegin(GL_TRIANGLES);
        glColor3d(1,0,0);
        for(int i=0;i<M3.f.size();i++)
        {
            glNormal3f(M3.f[i].normal.x,M3.f[i].normal.y,M3.f[i].normal.z);
            glVertex3f(M3.f[i].point[0].x,M3.f[i].point[0].y,M3.f[i].point[0].z);
            glVertex3f(M3.f[i].point[1].x,M3.f[i].point[1].y,M3.f[i].point[1].z);
            glVertex3f(M3.f[i].point[2].x,M3.f[i].point[2].y,M3.f[i].point[2].z);
        }
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,y,-6);
        glRotated(90,1,0,0);
        glRotated(180,0,1,0);
        glRotated(90,0,0,1);
        //F0
        glTranslated(0,0,2.9);
        glRotated(th1,0,0,1);
        glRotated(-90,1,0,0);
        //F1
        glRotated(th2-90,0,0,1);
        glTranslated(2.7,0,0);
        //F2
        glRotated(th3,0,0,1);
        glTranslated(0.7,0,0);
        glRotated(-90,1,0,0);
        //F3
        glRotated(th4,0,0,1);
        glTranslated(0,0,3.02);
        glRotated(90,1,0,0);
        //F4
        glBegin(GL_TRIANGLES);
        glColor3d(1,0,0);
        for(int i=0;i<M4.f.size();i++)
        {
            glNormal3f(M4.f[i].normal.x,M4.f[i].normal.y,M4.f[i].normal.z);
            glVertex3f(M4.f[i].point[0].x,M4.f[i].point[0].y,M4.f[i].point[0].z);
            glVertex3f(M4.f[i].point[1].x,M4.f[i].point[1].y,M4.f[i].point[1].z);
            glVertex3f(M4.f[i].point[2].x,M4.f[i].point[2].y,M4.f[i].point[2].z);
        }
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,y,-6);
        glRotated(90,1,0,0);
        glRotated(180,0,1,0);
        glRotated(90,0,0,1);
        //F0
        glTranslated(0,0,2.9);
        glRotated(th1,0,0,1);
        glRotated(-90,1,0,0);
        //F1
        glRotated(th2-90,0,0,1);
        glTranslated(2.7,0,0);
        //F2
        glRotated(th3,0,0,1);
        glTranslated(0.7,0,0);
        glRotated(-90,1,0,0);
        //F3
        glRotated(th4,0,0,1);
        glTranslated(0,0,3.02);
        glRotated(90,1,0,0);
        //F4
        glRotated(th5,0,0,1);
        glRotated(-90,1,0,0);
        //F5
        glBegin(GL_TRIANGLES);
        glColor3d(1,0,0);
        for(int i=0;i<M5.f.size();i++)
        {
            glNormal3f(M5.f[i].normal.x,M5.f[i].normal.y,M5.f[i].normal.z);
            glVertex3f(M5.f[i].point[0].x,M5.f[i].point[0].y,M5.f[i].point[0].z);
            glVertex3f(M5.f[i].point[1].x,M5.f[i].point[1].y,M5.f[i].point[1].z);
            glVertex3f(M5.f[i].point[2].x,M5.f[i].point[2].y,M5.f[i].point[2].z);
        }
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,y,-6);
        glRotated(90,1,0,0);
        glRotated(180,0,1,0);
        glRotated(90,0,0,1);
        //F0
        glTranslated(0,0,2.9);
        glRotated(th1,0,0,1);
        glRotated(-90,1,0,0);
        //F1
        glRotated(th2-90,0,0,1);
        glTranslated(2.7,0,0);
        //F2
        glRotated(th3,0,0,1);
        glTranslated(0.7,0,0);
        glRotated(-90,1,0,0);
        //F3
        glRotated(th4,0,0,1);
        glTranslated(0,0,3.02);
        glRotated(90,1,0,0);
        //F4
        glRotated(th5,0,0,1);
        glRotated(-90,1,0,0);
        //F5
        glRotated(th6+180,0,0,1);
        glTranslated(0,0,0.72);
        //F6
        glBegin(GL_TRIANGLES);
        glColor3d(1,0,0);
        for(int i=0;i<M6.f.size();i++)
        {
            glNormal3f(M6.f[i].normal.x,M6.f[i].normal.y,M6.f[i].normal.z);
            glVertex3f(M6.f[i].point[0].x,M6.f[i].point[0].y,M6.f[i].point[0].z);
            glVertex3f(M6.f[i].point[1].x,M6.f[i].point[1].y,M6.f[i].point[1].z);
            glVertex3f(M6.f[i].point[2].x,M6.f[i].point[2].y,M6.f[i].point[2].z);
        }
        glEnd();
    glPopMatrix();


    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;

        case 'a':
            th1+=1;
            break;

        case 'z':
            th1-=1;
            break;

        case 's':
            th2+=1;
            break;

        case 'x':
            th2-=1;
            break;

        case 'd':
            th3+=1;
            break;

        case 'c':
            th3-=1;
            break;

        case 'f':
            th4+=1;
            break;

        case 'v':
            th4-=1;
            break;

        case 'g':
            th5+=1;
            break;

        case 'b':
            th5-=1;
            break;

        case 'h':
            th6+=1;
            break;

        case 'n':
            th6-=1;
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
*/
/* Program entry point */
/*
int main(int argc, char *argv[])
{
    int error = getGeometryInput(M0.f, "D:\FIMEE\Tareas\IRB120", "Link0.stl");
    if(error==1) return (1);

    error = getGeometryInput(M1.f, "D:\FIMEE\Tareas\IRB120", "Link1.stl");
    if(error==1) return (1);

    error = getGeometryInput(M2.f, "D:\FIMEE\Tareas\IRB120", "Link2.stl");
    if(error==1) return (1);

    error = getGeometryInput(M3.f, "D:\FIMEE\Tareas\IRB120", "Link3.stl");
    if(error==1) return (1);

    error = getGeometryInput(M4.f, "D:\FIMEE\Tareas\IRB120", "Link4.stl");
    if(error==1) return (1);

    error = getGeometryInput(M5.f, "D:\FIMEE\Tareas\IRB120", "Link5.stl");
    if(error==1) return (1);

    error = getGeometryInput(M6.f, "D:\FIMEE\Tareas\IRB120", "Link6.stl");
    if(error==1) return (1);


    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
*/

using namespace std;
int main()
{
    float valor;
    cout << "Robot 1 inicializado con constructor por defecto" << endl;
    Robot robot;
    robot.imprimirDatos();
    robot.getTh1();
    robot.getTh2();
    robot.getTh3();
    robot.getTh4();
    robot.getTh5();
    robot.getTh6();
    robot.setColor("naranja");
    robot.setMaterial("aluminio");
    robot.getColor();
    robot.getMaterial();

    cout << robot.T01 << endl;
    cout << robot.T02 << endl;
    cout << robot.T03 << endl;
    cout << robot.T04 << endl;
    cout << robot.T05 << endl;
    cout << robot.T06 << endl;

    double *arr = new double[16];
    arr = robot.T06.ravel_transpose();
    for(int i=0;i<16;i++)
        cout << arr[i] << " ";

    robot.setTh1(45);
    robot.setTh2(32);
    robot.setTh3(12);
    robot.setTh4(88);
    robot.setTh5(90);
    robot.setTh6(42);
    robot.imprimirValoresTh();
    robot.actualizarPosicion();

    cout << robot.T01 << endl;
    cout << robot.T02 << endl;
    cout << robot.T03 << endl;
    cout << robot.T04 << endl;
    cout << robot.T05 << endl;
    cout << robot.T06 << endl;

    robot.imprimirT06();
    robot.imprimirPxyzEfector();

    cout << "Robot 2 inicializado con constructor de parametros" << endl;
    Robot robot2(100.00,27.12,-64.90,-38.99,30.72,120.98,"azul","acero");
    robot2.imprimirDatos();
    cout << "R = " << robot2.getColorR() << endl;
    cout << "G = " << robot2.getColorG() << endl;
    cout << "B = " << robot2.getColorB() << endl;
    robot2.imprimirValoresTh();


    return 0;
}
