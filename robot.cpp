#include "robot.h"
#include <iostream>

namespace rbt
{
    Robot::Robot()
    {
        numEslabones = 6;
        tamanio1 = 100; // cm
        tamanio2 = 100; // cm
        tamanio3 = 100; // cm
        tamanio4 = 100; // cm
        tamanio5 = 100; // cm
        tamanio6 = 100; // cm
        pesoTotal = 2000; // kg
        color = "gris";
        material = "acero";
    }

    Robot::Robot(int _numEslabones, float _tamanio1, float _tamanio2, float _tamanio3,float _tamanio4, float _tamanio5, float _tamanio6,
              float _pesoTotal, std::string _color, std::string _material)
    {
        numEslabones = _numEslabones;
        tamanio1 = _tamanio1; // cm
        tamanio2 = _tamanio2; // cm
        tamanio3 = _tamanio3; // cm
        tamanio4 = _tamanio4; // cm
        tamanio5 = _tamanio5; // cm
        tamanio6 = _tamanio6; // cm
        pesoTotal = _pesoTotal; // kg
        color = _color;
        material = _material;
    }

    int Robot::getPesoTotal(){return pesoTotal;}

    int Robot::getNumEslabones(){return numEslabones;}

    void Robot::setNumEslabones(float _numEslabones){numEslabones = _numEslabones;}

    std::string Robot::getColor(){return color;}

    void Robot::setColor(std::string _color){color = _color;}

    std::string Robot::getMaterial(){return material;}

    void Robot::setMaterial(std::string _material){material = _material;}

    void Robot::imprimirDatos()
    {
        std::cout << "numEslabones = " << numEslabones << std::endl;
        std::cout << "tamanio1 = " << tamanio1 << std::endl;
        std::cout << "tamanio2 = " << tamanio2 << std::endl;
        std::cout << "tamanio3 = " << tamanio3 << std::endl;
        std::cout << "tamanio4 = " << tamanio4 << std::endl;
        std::cout << "tamanio5 = " << tamanio5 << std::endl;
        std::cout << "tamanio6 = " << tamanio6 << std::endl;
        std::cout << "pesoTotal = " << pesoTotal << std::endl;
        std::cout << "color = " << color << std::endl;
        std::cout << "material = " << material << std::endl;
    }
}
