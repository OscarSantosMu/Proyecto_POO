#include "robot.h"
#include <iostream>
#include <cmath>

namespace rbt
{
    Robot::Robot()
    {
        numEslabones = 6;
        L1 = 290; // cm
        L2 = 270; // cm
        L3 = 70; // cm
        L4 = 302; // cm
        L5 = 0; // cm
        L6 = 72; // cm
        pesoTotal = 2000; // kg
        color = "gris";
        material = "acero";
        float alpha[6] = {0*PI/180, 0, -90*PI/180, 90*PI/180, -90*PI/180, 0};
        float a[6] = {0, L2, L3, 0, 0, 0};
        float d[6] = {L1, 0, 0, L4, 0, L5};
        float theta[6] = {90*PI/180, 90*PI/180, 90*PI/180, 90*PI/180, 90*PI/180, 90*PI/180};

        for(int i=0;i<6;i++)
        {
            M_DH[i][0][0] = cos(theta[i]);
            M_DH[i][0][1] = -sin(theta[i]);
            M_DH[i][0][2] = 0;
            M_DH[i][0][3] = a[i];
            M_DH[i][1][0] = sin(theta[i])*cos(alpha[i]);
            M_DH[i][1][1] = cos(theta[i]) *  cos(alpha[i]);
            M_DH[i][1][2] = -sin(alpha[i]);
            M_DH[i][1][3] = -sin(alpha[i]) * d[i];
            M_DH[i][2][0] = sin(theta[i]) * sin(alpha[i]);
            M_DH[i][2][1] = cos(theta[i]) *  sin(alpha[i]);
            M_DH[i][2][2] = cos(alpha[i]);
            M_DH[i][2][3] = cos(alpha[i]) * d[i];
            M_DH[i][3][0] = 0;
            M_DH[i][3][1] = 0;
            M_DH[i][3][2] = 0;
            M_DH[i][3][3] = 1;
        }
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<4;j++)
            {
                for(int k=0;k<4;k++)
                {
                    std::cout << M_DH[i][j][k] << "\t\t";
                }
                std::cout << "\n";
            }
            std::cout << "\n\n\n";
        }

        /*
        for(int i=0;i<10;i++)
        {
            cos(theta[i]), -sin(theta[i]), 0, a[i],
            sin(theta[i]) * cos(alpha[i]), cos(theta[i]) *  cos(alpha[i]), -sin(alpha[i]), -sin(alpha[i]) * d[i],
            sin(theta[i]) * sin(alpha[i]), cos(theta[i]) *  sin(alpha[i]), cos(alpha[i]), cos(alpha[i]) * d[i],
            0, 0, 0, 1,
        }
        */
        std::cout << "Asignando tabla en objetos de la clase Matriz4x4" << std::endl;
        T01 = M_DH;
        std::cout << T01;
        T12 = M_DH;
        std::cout << T12;
        T23 = M_DH;
        std::cout << T23;
        T34 = M_DH;
        std::cout << T34;
        T45 = M_DH;
        std::cout << T45;
        T56 = M_DH;
        std::cout << T56;
        T02 = T01*T12;
        std::cout << T02;
        T03 = T02*T23;
        std::cout << T03;
        T04 = T03*T34;
        std::cout << T04;
        T05 = T04*T45;
        std::cout << T05;
        T06 = T05*T56;
        std::cout << "\nEsta es la chida" << std::endl;
        std::cout << T06;
        //float *myarray = T06.ravel();
        //for(int i=0;i<16;i++)
            //std::cout << myarray[i] << " ";
        //delete[] myarray;

    }

    Robot::Robot(int _numEslabones, float _tamanio1, float _tamanio2, float _tamanio3,float _tamanio4, float _tamanio5, float _tamanio6,
              float _pesoTotal, std::string _color, std::string _material)
    {
        numEslabones = _numEslabones;
        L1 = _tamanio1; // cm
        L2 = _tamanio2; // cm
        L3 = _tamanio3; // cm
        L4 = _tamanio4; // cm
        L5 = _tamanio5; // cm
        L6 = _tamanio6; // cm
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
        std::cout << "L1 = " << L1 << std::endl;
        std::cout << "L2 = " << L2 << std::endl;
        std::cout << "L3 = " << L3 << std::endl;
        std::cout << "L4 = " << L4 << std::endl;
        std::cout << "L5 = " << L5 << std::endl;
        std::cout << "L6 = " << L6 << std::endl;
        std::cout << "pesoTotal = " << pesoTotal << std::endl;
        std::cout << "color = " << color << std::endl;
        std::cout << "material = " << material << std::endl;
    }

    int Matriz4x4::mat = 0;

    Matriz4x4::Matriz4x4()
    {
        m=4;
        n=4;

        M = new float *[m];
        for(int i=0;i<m;i++)
        {
            M[i] = new float [n];
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==j)
                {
                    M[i][j] = 1;
                }
                else
                {
                    M[i][j] = 0;
                }
            }
        }
    }

    Matriz4x4::~Matriz4x4()
    {
        for(int i=0;i<m;i++){
            delete M[i];
        }
        delete M;
        std::cout << "Libera memoria" << std::endl;
    }

    Matriz4x4 Matriz4x4::operator+ (Matriz4x4 obj1)
    {
        Matriz4x4 temp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               temp.M[i][j] = M[i][j] + obj1.M[i][j];
            }
        }
        return temp;
    }

    Matriz4x4 Matriz4x4::operator- (Matriz4x4 obj1) /// La memoria de obj1 se elimina al terminar la función
    {
        Matriz4x4 temp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp.M[i][j] = M[i][j] - obj1.M[i][j];
            }
        }
        return temp;
    }

    Matriz4x4 Matriz4x4::operator =(Matriz4x4 obj1)
    {
        Matriz4x4 temp;

        n = obj1.n;
        m = obj1.m;
        //M = obj1.M;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               M[i][j] = obj1.M[i][j];
            }
        }

        /// Nos sirve para regresar y poder hacer múltiples igualaciones
        temp.n = obj1.n;
        temp.m = obj1.m;
        //temp.M = obj1.M;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               temp.M[i][j] = obj1.M[i][j];
            }
        }

        return temp;
    }

    Matriz4x4 Matriz4x4::operator =(float DH[6][6][6])
    {
        Matriz4x4 temp;

        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
               M[i][j] = DH[mat][i][j];
            }
        }

        /// Nos sirve para regresar y poder hacer múltiples igualaciones
        //temp.n = obj1.n;
        //temp.m = obj1.m;
        //temp.M = obj1.M;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
               temp.M[i][j] = DH[mat][i][j];
            }
        }
        mat += 1;
        return temp;
    }

    float* Matriz4x4::ravel()
    {
        float *arr = new float[4];
        int k=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr[k] = M[i][j];
                k++;
            }
        }
        for(int i=0;i<16;i++)
            std::cout << arr[i] << " ";
        return arr;
    }

    std::ostream & operator << (std::ostream &o, const Matriz4x4 &mat)
    {
        o << "\n";
        for(int i=0;i<mat.m;i++){
                o << "|\t";
            for(int j=0;j<mat.n;j++){
                o << mat.M[i][j] << "\t";
            }
            o << "\t|\n";
        }
        return o;
    }

    std::istream& operator >> (std::istream &i, const Matriz4x4 &mat)
    {
        std::cout << "Ingrese los datos de la Matriz 4x4:\n";
        for(int k=0;k<mat.m;k++){
            for(int j=0;j<mat.n;j++){
                std::cout << "Matriz [" << k << "][" << j << "] = ";
                std::cin >> mat.M[k][j];
            }
        }
        i.ignore();
        return i;
    }

    Matriz4x4 Matriz4x4::operator* (Matriz4x4 obj1) /// La memoria de obj1 se elimina al terminar la función
    {
        Matriz4x4 temp, returnM;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp.M[i][j] = M[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                returnM.M[i][j] = 0;
                for(int k=0;k<n;k++){
                    returnM.M[i][j] += temp.M[i][k] * obj1.M[k][j];
                }
            }
        }
        return returnM;
    }
}
