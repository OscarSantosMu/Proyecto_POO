#ifndef _ROBOT
#define _ROBOT

#include <iostream>

#define PI 3.141592653589793238462

namespace rbt
{
    class Matriz4x4
    {
    private:
        int n, m;
        float **M;
        static int mat;
    public:
        Matriz4x4();
        ~Matriz4x4();
        Matriz4x4 operator+ (Matriz4x4 obj1);
        Matriz4x4 operator- (Matriz4x4 obj1);
        Matriz4x4 operator= (Matriz4x4 obj1);
        Matriz4x4 operator* (Matriz4x4 obj1);
        Matriz4x4 operator= (float DH[6][6][6]);
        double *ravel_transpose();
        double *getLastColumn();
        friend std::ostream & operator << (std::ostream &o, const Matriz4x4 &mat);
        friend std::istream & operator >> (std::istream &i, const Matriz4x4 &mat);
    };

    class Robot
    {
    protected:
        float L1 = 2.90; // m
        float L2 = 2.70; // m
        float L3 = 0.70; // m
        float L4 = 3.02; // m
        float L5 = 0.0; // m
        float L6 = 0.72; // m
        double th1, th2, th3, th4, th5, th6;
        float pesoTotal;
        float M_DH[6][6][6];
        float alpha[6];
        float a[6];
        float d[6];
        float theta[6];

        std::string color;
        double colorR, colorG, colorB;
        std::string material;
    public:

        Robot();
        Robot(double _th1, double _th2, double _th3, double _th4, double _th5, double _th6, std::string _color, std::string _material);
        int getPesoTotal();
        void setTh1(float _th1);
        void setTh2(float _th2);
        void setTh3(float _th3);
        void setTh4(float _th4);
        void setTh5(float _th5);
        void setTh6(float _th6);
        double getTh1();
        double getTh2();
        double getTh3();
        double getTh4();
        double getTh5();
        double getTh6();

        std::string getColor();
        double getColorR();
        double getColorG();
        double getColorB();
        void setColor(std::string _color);
        std::string getMaterial();
        void setMaterial(std::string _material);

        void actualizarPosicion();

        void imprimirDatos();
        void imprimirValoresTh();
        void imprimirT06();
        void imprimirPxyzEfector();
        Matriz4x4 T01,T12,T23,T34,T45,T56;
        Matriz4x4 T02,T03,T04,T05,T06;
        // Funciones para OPENGL
        void dibujar();



    };
}

#endif
