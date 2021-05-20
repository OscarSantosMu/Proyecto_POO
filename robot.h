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
        float *ravel();
        friend std::ostream & operator << (std::ostream &o, const Matriz4x4 &mat);
        friend std::istream & operator >> (std::istream &i, const Matriz4x4 &mat);
    };

    class Robot
    {
    protected:
        int numEslabones;
        float L1, L2, L3, L4, L5, L6;
        float th1, th2, th3, th4, th5, th6;
        float pesoTotal;
        float M_DH[6][6][6];

        std::string color;
        std::string material;
    public:

        Robot();
        Robot(int _numEslabones, float _tamanio1, float _tamanio2, float _tamanio3,float _tamanio4, float _tamanio5, float _tamanio6,
              float _pesoTotal, std::string _color, std::string _material);
        int getPesoTotal();
        int getNumEslabones();
        void setNumEslabones(float _numEslabones);

        void setTh1(float _th1);
        void setTh2(float _th2);
        void setTh3(float _th3);
        void setTh4(float _th4);
        void setTh5(float _th5);
        void setTh6(float _th6);


        std::string getColor();
        void setColor(std::string _color);
        std::string getMaterial();
        void setMaterial(std::string _material);

        void actualizarPosicion();

        void imprimirDatos();
        Matriz4x4 T01,T12,T23,T34,T45,T56;
        Matriz4x4 T02,T03,T04,T05,T06;
        // Funciones para OPENGL
        void dibujar();



    };
}

#endif
