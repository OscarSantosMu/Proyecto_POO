#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <vector>
#include "getGeometryInput.h"

#include <iostream>
#include "robot.h"

using namespace rbt;

static int slices = 16;
static int stacks = 16;

int k=0, aux=0, actual=0, actual2=0, paso=5, flag=0;
float th1i, th2i, th3i, th4i, th5i, th6i;
float th1f, th2f, th3f, th4f, th5f, th6f;
float rth1, rth2, rth3, rth4, rth5, rth6;
float posicion[100][4];
//float th1, th2, th3, th4, th5, th6;

/* GLUT callback Handlers */

class Modelo
{
public:
    std::vector<triangle> f;
}M0, M1, M2, M3, M4, M5, M6;

Robot robot;
//Robot robot(100.00,27.12,-64.90,-38.99,30.72,120.98,"azul","acero");      //1
//Robot robot(100.00,27.12,-64.90,141.01,-30.72,-59.02,"verde","acero");     //2
//Robot robot(100.00,40.00,-89.00,-30.00,40.00,110.00,"naranja","acero");     //2
//Robot robot(100.00,40.00,-89.00,150.00,-40.00,-70.00,"cyan","acero");  //3
//Robot robot(-80.00,-40.00,-64.90,158.99,63.70,95.80,"café","acero");      //4
//Robot robot(-80.00,-40.00,-64.90,-21.01,-63.70,-84.20,"morado","acero");    //5
//Robot robot(-80.00,-27.12,-89.00,156.37,53.32,100.78,"blanco","acero");   //6
//Robot robot(-80.00,-27.12,-89.00,-23.63,-53.32,-79.22,"negro","acero");  //7

void secuencia_puntos();
void guardar_punto();

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
    //robot.setColor("rojo");
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    //const double a = t*90.0;
    //const double a = 0;
    double y=-4.7;
    double offset = -2.5;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);

    if(k==1)
    {
        if(robot.getTh6()>th6f) robot.setTh6(robot.getTh6()-rth6);
        if(robot.getTh6()<th6f) robot.setTh6(robot.getTh6()+rth6);
        if((robot.getTh6()<th6f+1&&robot.getTh6()>th6f)||(robot.getTh6()>th6f-1&&robot.getTh6()<th6f)) robot.setTh6(th6f);

        if(robot.getTh5()>th5f) robot.setTh5(robot.getTh5()-rth5);
        if(robot.getTh5()<th5f) robot.setTh5(robot.getTh5()+rth5);
        if((robot.getTh5()<th5f+1&&robot.getTh5()>th5f)||(robot.getTh5()>th5f-1&&robot.getTh5()<th5f)) robot.setTh5(th5f);

        if(robot.getTh4()>th4f) robot.setTh4(robot.getTh4()-rth4);
        if(robot.getTh4()<th4f) robot.setTh4(robot.getTh4()+rth4);
        if((robot.getTh4()<th4f+1&&robot.getTh4()>th4f)||(robot.getTh4()>th4f-1&&robot.getTh4()<th4f)) robot.setTh4(th4f);

        if(robot.getTh3()>th3f) robot.setTh3(robot.getTh3()-rth3);
        if(robot.getTh3()<th3f) robot.setTh3(robot.getTh3()+rth3);
        if((robot.getTh3()<th3f+1&&robot.getTh3()>th3f)||(robot.getTh3()>th3f-1&&robot.getTh3()<th3f)) robot.setTh3(th3f);

        if(robot.getTh2()>th2f) robot.setTh2(robot.getTh2()-rth2);
        if(robot.getTh2()<th2f) robot.setTh2(robot.getTh2()+rth2);
        if((robot.getTh2()<th2f+1&&robot.getTh2()>th2f)||(robot.getTh2()>th2f-1&&robot.getTh2()<th2f)) robot.setTh2(th2f);

        if(robot.getTh1()>th1f) robot.setTh1(robot.getTh1()-rth1);
        if(robot.getTh1()<th1f) robot.setTh1(robot.getTh1()+rth1);
        if((robot.getTh1()<th1f+1&&robot.getTh1()>th1f)||(robot.getTh1()>th1f-1&&robot.getTh1()<th1f)) robot.setTh1(th1f);

        if(robot.getTh1()==th1f&&robot.getTh2()==th2f&&robot.getTh3()==th3f&&robot.getTh4()==th4f&&robot.getTh5()==th5f&&robot.getTh6()==th6f) k=0;
        if(robot.getTh1()==th1f&&robot.getTh2()==th2f&&robot.getTh3()==th3f&&robot.getTh4()==th4f&&robot.getTh5()==th5f&&robot.getTh6()==th6f&&aux==1) k=0, aux=2;
        if(robot.getTh1()==th1f&&robot.getTh2()==th2f&&robot.getTh3()==th3f&&robot.getTh4()==th4f&&robot.getTh5()==th5f&&robot.getTh6()==th6f&&flag==1)
        {
            actual2++;
            if(actual2!=actual)
            {
                secuencia_puntos();
            }
            else
            {
                flag = 0;
                k = 0;
                actual2 = 0;
            }
        }
    }

    robot.actualizarPosicion();
    //robot.imprimirT06();
    double Origen[16] = {0.0, 0.0, 1.0, 0.0,
                         1.0, 0.0, 0.0, 0.0,
                         0.0, 1.0, 0.0, 0.0,
                         0.0, -2.2+offset, -6.0, 1.0};
    glPushMatrix();

        glMultMatrixd(Origen);
        //ORIGEN
        glBegin(GL_TRIANGLES);
        glColor3d(robot.getColorR(),robot.getColorG(),robot.getColorB());
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

        glMultMatrixd(Origen);
        //F0
        glMultMatrixd(robot.T01.ravel_transpose());

        glBegin(GL_TRIANGLES);
        glColor3d(robot.getColorR(),robot.getColorG(),robot.getColorB());
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

        glMultMatrixd(Origen);
        //F0
        glMultMatrixd(robot.T02.ravel_transpose());
        //F2
        glBegin(GL_TRIANGLES);
        glColor3d(robot.getColorR(),robot.getColorG(),robot.getColorB());
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

        glMultMatrixd(Origen);
        //F0
        glMultMatrixd(robot.T03.ravel_transpose());
        //F3
        glBegin(GL_TRIANGLES);
        glColor3d(robot.getColorR(),robot.getColorG(),robot.getColorB());
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

        glMultMatrixd(Origen);
        //F0
        glMultMatrixd(robot.T04.ravel_transpose());
        //F4
        glBegin(GL_TRIANGLES);
        glColor3d(robot.getColorR(),robot.getColorG(),robot.getColorB());
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

        glMultMatrixd(Origen);
        //F0
        glMultMatrixd(robot.T05.ravel_transpose());
        //F5
        glBegin(GL_TRIANGLES);
        glColor3d(robot.getColorR(),robot.getColorG(),robot.getColorB());
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

        glMultMatrixd(Origen);
        //F0
        glMultMatrixd(robot.T06.ravel_transpose());
        //F6
        glBegin(GL_TRIANGLES);
        glColor3d(robot.getColorR(),robot.getColorG(),robot.getColorB());
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

    if(aux==2 && k==0)
    {
        k=1;
        std::cout << "\nEscribe la posicion a la que deseas llegar:\n" << std::endl;
        fflush(stdin);
        fflush(stdin);
        std::cout<<"Theta1: ";
        std::cin>>th1f;
        std::cout<<"Theta2: ";
        std::cin>>th2f;
        std::cout<<"Theta3: ";
        std::cin>>th3f;
        std::cout<<"Theta4: ";
        std::cin>>th4f;
        std::cout<<"Theta5: ";
        std::cin>>th5f;
        std::cout<<"Theta6: ";
        std::cin>>th6f;
        rth1=((th1f-th1i)/floor(th1f-th1i))/paso*10;
        rth2=((th2f-th2i)/floor(th2f-th2i))/paso*10;
        rth3=((th3f-th3i)/floor(th3f-th3i))/paso*10;
        rth4=((th4f-th4i)/floor(th4f-th4i))/paso*10;
        rth5=((th5f-th5i)/floor(th5f-th5i))/paso*10;
        rth6=((th6f-th6i)/floor(th6f-th6i))/paso*10;
        if(rth1<0) rth1*=-1;
        if(rth2<0) rth2*=-1;
        if(rth3<0) rth3*=-1;
        if(rth4<0) rth4*=-1;
        if(rth5<0) rth5*=-1;
        if(rth6<0) rth6*=-1;
        aux=0;
    }
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
            robot.setTh1(robot.getTh1()+1);
            //std::cout<<robot.getTh1()<<std::endl;
            break;

        case 'z':
            robot.setTh1(robot.getTh1()-1);
            //std::cout<<robot.getTh1()<<std::endl;
            break;

        case 's':
            robot.setTh2(robot.getTh2()+1);
            break;

        case 'x':
            robot.setTh2(robot.getTh2()-1);
            break;

        case 'd':
            robot.setTh3(robot.getTh3()+1);
            break;

        case 'c':
            robot.setTh3(robot.getTh3()-1);
            break;

        case 'f':
            robot.setTh4(robot.getTh4()+1);
            break;

        case 'v':
            robot.setTh4(robot.getTh4()-1);
            break;

        case 'g':
             robot.setTh5(robot.getTh5()+1);
            break;

        case 'b':
             robot.setTh5(robot.getTh5()-1);
            break;

        case 'h':
            robot.setTh6(robot.getTh6()+1);
            break;

        case 'n':
            robot.setTh6(robot.getTh6()-1);
            break;

        case 'o':

            while(robot.getTh6()!=0)
            {
                if(robot.getTh6()>0) robot.setTh6(robot.getTh6()-1);
                if(robot.getTh6()<0) robot.setTh6(robot.getTh6()+1);
                glutMainLoop();
            }
            while(robot.getTh5()!=0)
            {
                if(robot.getTh5()>0) robot.setTh5(robot.getTh5()-1);
                if(robot.getTh5()<0) robot.setTh5(robot.getTh5()+1);
                glutMainLoop();
            }
            while(robot.getTh4()!=0)
            {
                if(robot.getTh4()>0) robot.setTh4(robot.getTh4()-1);
                if(robot.getTh4()<0) robot.setTh4(robot.getTh4()+1);
                glutMainLoop();
            }
            while(robot.getTh3()!=0)
            {
                if(robot.getTh3()>0) robot.setTh3(robot.getTh3()-1);
                if(robot.getTh3()<0) robot.setTh3(robot.getTh3()+1);
                glutMainLoop();
            }
            while(robot.getTh2()!=0)
            {
                if(robot.getTh2()>0) robot.setTh2(robot.getTh2()-1);
                if(robot.getTh2()<0) robot.setTh2(robot.getTh2()+1);
                glutMainLoop();
            }
            while(robot.getTh1()!=0)
            {
                if(robot.getTh1()>0) robot.setTh1(robot.getTh1()-1);
                if(robot.getTh1()<0) robot.setTh1(robot.getTh1()+1);
                glutMainLoop();
            }
            break;
        case 'p':
            robot.setTh1(0);
            robot.setTh2(0);
            robot.setTh3(0);
            robot.setTh4(0);
            robot.setTh5(0);
            robot.setTh6(0);
            break;
        case 'k':
            guardar_punto();
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

/* Program entry point */

void regresar_home()
{
    th1f=0;
    th2f=0;
    th3f=0;
    th4f=0;
    th5f=0;
    th6f=0;
    robot.setTh1(0);
    robot.setTh2(0);
    robot.setTh3(0);
    robot.setTh4(0);
    robot.setTh5(0);
    robot.setTh6(0);
}

void regresar_progresivamente_home()
{
    //Para ir al origen
    k=1;
    th1i=robot.getTh1();
    th2i=robot.getTh2();
    th3i=robot.getTh3();
    th4i=robot.getTh4();
    th5i=robot.getTh5();
    th6i=robot.getTh6();
    th1f=0;
    th2f=0;
    th3f=0;
    th4f=0;
    th5f=0;
    th6f=0;
    rth1=((th1f-th1i)/floor(th1f-th1i))/paso;
    rth2=((th2f-th2i)/floor(th2f-th2i))/paso;
    rth3=((th3f-th3i)/floor(th3f-th3i))/paso;
    rth4=((th4f-th4i)/floor(th4f-th4i))/paso;
    rth5=((th5f-th5i)/floor(th5f-th5i))/paso;
    rth6=((th6f-th6i)/floor(th6f-th6i))/paso;
    if(rth1<0) rth1*=-1;
    if(rth2<0) rth2*=-1;
    if(rth3<0) rth3*=-1;
    if(rth4<0) rth4*=-1;
    if(rth5<0) rth5*=-1;
    if(rth6<0) rth6*=-1;
}

void mover_a()
{
    // para ir a
    k=1;
    th1i=robot.getTh1();
    th2i=robot.getTh2();
    th3i=robot.getTh3();
    th4i=robot.getTh4();
    th5i=robot.getTh5();
    th6i=robot.getTh6();
    std::cout<<"\nEscribe la posicion a la que deseas llegar:\n"<<std::endl;
    fflush(stdin);
    fflush(stdin);
    std::cout<<"Theta1: ";
    std::cin>>th1f;
    std::cout<<"Theta2: ";
    std::cin>>th2f;
    std::cout<<"Theta3: ";
    std::cin>>th3f;
    std::cout<<"Theta4: ";
    std::cin>>th4f;
    std::cout<<"Theta5: ";
    std::cin>>th5f;
    std::cout<<"Theta6: ";
    std::cin>>th6f;
    rth1=((th1f-th1i)/floor(th1f-th1i))/paso;
    rth2=((th2f-th2i)/floor(th2f-th2i))/paso;
    rth3=((th3f-th3i)/floor(th3f-th3i))/paso;
    rth4=((th4f-th4i)/floor(th4f-th4i))/paso;
    rth5=((th5f-th5i)/floor(th5f-th5i))/paso;
    rth6=((th6f-th6i)/floor(th6f-th6i))/paso;
    if(rth1<0) rth1*=-1;
    if(rth2<0) rth2*=-1;
    if(rth3<0) rth3*=-1;
    if(rth4<0) rth4*=-1;
    if(rth5<0) rth5*=-1;
    if(rth6<0) rth6*=-1;
}

void mover_desde()
{
    // ir desde
    std::cout<<"\nEscribe la posicion donde deseas partir:\n"<<std::endl;
    fflush(stdin);
    fflush(stdin);
    std::cout<<"Theta1: ";
    std::cin>>th1f;
    std::cout<<"Theta2: ";
    std::cin>>th2f;
    std::cout<<"Theta3: ";
    std::cin>>th3f;
    std::cout<<"Theta4: ";
    std::cin>>th4f;
    std::cout<<"Theta5: ";
    std::cin>>th5f;
    std::cout<<"Theta6: ";
    std::cin>>th6f;
    th1i=th1f;
    th2i=th2f;
    th3i=th3f;
    th4i=th4f;
    th5i=th5f;
    th6i=th6f;
    rth1=((th1f-robot.getTh1())/floor(th1f-robot.getTh1()))/paso;
    rth2=((th2f-robot.getTh2())/floor(th2f-robot.getTh2()))/paso;
    rth3=((th3f-robot.getTh3())/floor(th3f-robot.getTh3()))/paso;
    rth4=((th4f-robot.getTh4())/floor(th4f-robot.getTh4()))/paso;
    rth5=((th5f-robot.getTh5())/floor(th5f-robot.getTh5()))/paso;
    rth6=((th6f-robot.getTh6())/floor(th6f-robot.getTh6()))/paso;
    if(rth1<0) rth1*=-1;
    if(rth2<0) rth2*=-1;
    if(rth3<0) rth3*=-1;
    if(rth4<0) rth4*=-1;
    if(rth5<0) rth5*=-1;
    if(rth6<0) rth6*=-1;
    aux=1;
    k=1;
    std::cout<<"\nTrasladandose al punto de partida..."<<std::endl;
}

void guardar_punto()
{
    posicion[actual][0] = robot.getTh1();
    posicion[actual][1] = robot.getTh2();
    posicion[actual][2] = robot.getTh3();
    posicion[actual][3] = robot.getTh4();
    posicion[actual][4] = robot.getTh5();
    posicion[actual][5] = robot.getTh6();
    std::cout << "ID de punto: " << actual << std::endl;
    actual++;
}

void ir_a_punto()
{
    // para ir a
    int id;
    std::cout << "Ingrese el ID del punto al que desea ir: ";
    std::cin >> id;
    /*
    robot.setTh1(posicion[id][0]);
    robot.setTh2(posicion[id][1]);
    robot.setTh3(posicion[id][2]);
    robot.setTh4(posicion[id][3]);
    robot.setTh5(posicion[id][4]);
    robot.setTh6(posicion[id][5]);
    */
    k=1;
    th1i=robot.getTh1();
    th2i=robot.getTh2();
    th3i=robot.getTh3();
    th4i=robot.getTh4();
    th5i=robot.getTh5();
    th6i=robot.getTh6();
    th1f=posicion[id][0];
    th2f=posicion[id][1];
    th3f=posicion[id][2];
    th4f=posicion[id][3];
    th5f=posicion[id][4];
    th6f=posicion[id][5];
    rth1=((th1f-th1i)/floor(th1f-th1i))/paso;
    rth2=((th2f-th2i)/floor(th2f-th2i))/paso;
    rth3=((th3f-th3i)/floor(th3f-th3i))/paso;
    rth4=((th4f-th4i)/floor(th4f-th4i))/paso;
    rth5=((th5f-th5i)/floor(th5f-th5i))/paso;
    rth6=((th6f-th6i)/floor(th6f-th6i))/paso;
    if(rth1<0) rth1*=-1;
    if(rth2<0) rth2*=-1;
    if(rth3<0) rth3*=-1;
    if(rth4<0) rth4*=-1;
    if(rth5<0) rth5*=-1;
    if(rth6<0) rth6*=-1;
}

void secuencia_puntos()
{
    flag = 1;
    std::cout << "Simulando..." << std::endl;
    k=1;
    th1i=robot.getTh1();
    th2i=robot.getTh2();
    th3i=robot.getTh3();
    th4i=robot.getTh4();
    th5i=robot.getTh5();
    th6i=robot.getTh6();
    th1f=posicion[actual2][0];
    th2f=posicion[actual2][1];
    th3f=posicion[actual2][2];
    th4f=posicion[actual2][3];
    th5f=posicion[actual2][4];
    th6f=posicion[actual2][5];
    rth1=((th1f-th1i)/floor(th1f-th1i))/paso;
    rth2=((th2f-th2i)/floor(th2f-th2i))/paso;
    rth3=((th3f-th3i)/floor(th3f-th3i))/paso;
    rth4=((th4f-th4i)/floor(th4f-th4i))/paso;
    rth5=((th5f-th5i)/floor(th5f-th5i))/paso;
    rth6=((th6f-th6i)/floor(th6f-th6i))/paso;
    if(rth1<0) rth1*=-1;
    if(rth2<0) rth2*=-1;
    if(rth3<0) rth3*=-1;
    if(rth4<0) rth4*=-1;
    if(rth5<0) rth5*=-1;
    if(rth6<0) rth6*=-1;
}

void menu_principal(int opcion)
{
    switch(opcion)
    {
        case 1:
            robot.imprimirDatos();
            break;
        case 2:
            regresar_home();
            break;
        case 3:
            guardar_punto();
            break;
        case 4:
            robot.imprimirValoresTh();
            break;
        case 5:
            robot.imprimirT06();
            break;
        case 6:
            robot.imprimirPxyzEfector();
            break;
        case 7:
            exit( 0 );
    }

}

void menu_color(int opcion)
{
	switch(opcion)
	{
		case 1:
			robot.setColor("rojo");
			break;
		case 2:
			robot.setColor("verde");
			break;
		case 3:
			robot.setColor("azul");
			break;
        case 4:
			robot.setColor("amarillo");
			break;
        case 5:
			robot.setColor("magenta");
			break;
        case 6:
			robot.setColor("cyan");
			break;
        case 7:
			robot.setColor("negro");
			break;
        case 8:
			robot.setColor("blanco");
			break;
        case 9:
			robot.setColor("rosa");
			break;
        case 10:
			robot.setColor("naranja");
			break;
        case 11:
			robot.setColor("morado");
			break;
        case 12:
			robot.setColor("café");
			break;
	}
}

void menu_home(int opcion)
{
    switch(opcion)
	{
		case 1:
			regresar_home();
			break;
		case 2:
			regresar_progresivamente_home();
			break;
	}
}

void menu_mover(int opcion)
{
    switch(opcion)
	{
		case 1:
			mover_a();
			break;
		case 2:
			mover_desde();
			break;
	}
}

void menu_operaciones(int opcion)
{
    switch(opcion)
	{
		case 1:
			guardar_punto();
			break;
		case 2:
			ir_a_punto();
			break;
        case 3:
            secuencia_puntos();
            break;
	}
}

int main(int argc, char *argv[])
{
    int error = getGeometryInput(M0.f, "D:/FIMEE/Tareas/IRB120/", "Link0.stl");
    if(error == 1)
        return 1;
    error = getGeometryInput(M1.f, "D:/FIMEE/Tareas/IRB120/", "Link1.stl");
    if(error == 1)
        return 1;
    error = getGeometryInput(M2.f, "D:/FIMEE/Tareas/IRB120/", "Link2.stl");
    if(error == 1)
        return 1;
    error = getGeometryInput(M3.f, "D:/FIMEE/Tareas/IRB120/", "Link3.stl");
    if(error == 1)
        return 1;
    error = getGeometryInput(M4.f, "D:/FIMEE/Tareas/IRB120/", "Link4.stl");
    if(error == 1)
        return 1;
    error = getGeometryInput(M5.f, "D:/FIMEE/Tareas/IRB120/", "Link5.stl");
    if(error == 1)
        return 1;
    error = getGeometryInput(M6.f, "D:/FIMEE/Tareas/IRB120/", "Link6.stl");
    if(error == 1)
        return 1;

    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    int submenu_cambiar_color = glutCreateMenu(menu_color);
    glutAddMenuEntry("Rojo",1);
    glutAddMenuEntry("Verde",2);
    glutAddMenuEntry("Azul",3);
    glutAddMenuEntry("Amarillo",4);
    glutAddMenuEntry("Magenta",5);
    glutAddMenuEntry("Cyan",6);
    glutAddMenuEntry("Negro",7);
    glutAddMenuEntry("Blanco",8);
    glutAddMenuEntry("Rosa",9);
    glutAddMenuEntry("Naranja",10);
    glutAddMenuEntry("Morado",11);
    glutAddMenuEntry("Café",12);

    int submenu_home = glutCreateMenu(menu_home);
    glutAddMenuEntry("Home inmediato",1);
    glutAddMenuEntry("Home progresivo",2);

    int submenu_mover = glutCreateMenu(menu_mover);
    glutAddMenuEntry("Mover a",1);
    glutAddMenuEntry("Mover desde",2);

    int submenu_operaciones = glutCreateMenu(menu_operaciones);
    glutAddMenuEntry("Guardar punto",1);
    glutAddMenuEntry("Ir a punto",2);
    glutAddMenuEntry("Simular secuencia",3);

    int menu = glutCreateMenu(menu_principal);
    glutAddSubMenu("Cambiar color",submenu_cambiar_color);
    glutAddMenuEntry("Informacion de Robot",1);
    glutAddSubMenu("Regresar a Home",submenu_home);
    glutAddSubMenu("Mover Robot",submenu_mover);
    glutAddSubMenu("Operaciones",submenu_operaciones);
    glutAddMenuEntry("Mostrar valores de Th",4);
    glutAddMenuEntry("Mostrar matriz T06",5);
    glutAddMenuEntry("Mostrar punto del efector",6);
    glutAddMenuEntry("Salir",7);

    // usaremos el boton derecho del mouse
    glutAttachMenu(GLUT_RIGHT_BUTTON);

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
