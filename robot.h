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
        friend std::ostream & operator << (std::ostream &o, const Matriz4x4 &mat);
        friend std::istream & operator >> (std::istream &i, const Matriz4x4 &mat);
    };

    class Robot
    {
    protected:
        int numEslabones;
        float L1, L2, L3, L4, L5, L6;
        float pesoTotal;
        float M_DH[6][6][6];
        Matriz4x4 T01,T12,T23,T34,T45,T56;

        std::string color;
        std::string material;
    public:
        Robot();
        Robot(int _numEslabones, float _tamanio1, float _tamanio2, float _tamanio3,float _tamanio4, float _tamanio5, float _tamanio6,
              float _pesoTotal, std::string _color, std::string _material);
        int getPesoTotal();
        int getNumEslabones();
        void setNumEslabones(float _numEslabones);

        std::string getColor();
        void setColor(std::string _color);
        std::string getMaterial();
        void setMaterial(std::string _material);

        void imprimirDatos();
        // Funciones para OPENGL
        void dibujar();



    };
}

#endif
