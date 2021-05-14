#ifndef _ROBOT
#define _ROBOT

#include <iostream>

namespace rbt
{
    class Robot
    {
    protected:
        int numEslabones;
        float tamanio1, tamanio2, tamanio3, tamanio4, tamanio5, tamanio6;
        float pesoTotal;
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
