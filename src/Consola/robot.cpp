#include "robot.h"
#include <iostream>
#include <cmath>

namespace rbt
{
    Robot::Robot():alpha( {-90*PI/180, 0, -90*PI/180, 90*PI/180, -90*PI/180, 0} ), a( {0, L2, L3, 0, 0, 0} ), d( {L1, 0, 0, L4, 0, L6} )
    {
        th1 = 0;
        th2 = 0;
        th3 = 0;
        th4 = 0;
        th5 = 0;
        th6 = 0;
        pesoTotal = 2000; // kg
        setColor("rojo");
        material = "acero";
        //float alpha[6] = {-90*PI/180, 0, -90*PI/180, 90*PI/180, -90*PI/180, 0};
        //float a[6] = {0, L2, L3, 0, 0, 0};
        //float d[6] = {L1, 0, 0, L4, 0, L5};
        float theta[6] = {th1*PI/180, (th2-90)*PI/180, th3*PI/180, th4*PI/180, th5*PI/180, (th6+180)*PI/180};

        for(int i=0;i<6;i++)
        {
            M_DH[i][0][0] = cos(theta[i]);
            M_DH[i][0][1] = -sin(theta[i]) * cos(alpha[i]);
            M_DH[i][0][2] = sin(alpha[i]) * sin(theta[i]);
            M_DH[i][0][3] = a[i] * cos(theta[i]);
            M_DH[i][1][0] = sin(theta[i]);
            M_DH[i][1][1] = cos(theta[i]) *  cos(alpha[i]);
            M_DH[i][1][2] = -sin(alpha[i]) * cos(theta[i]);
            M_DH[i][1][3] = a[i] * sin(theta[i]);
            M_DH[i][2][0] = 0;
            M_DH[i][2][1] = sin(alpha[i]);
            M_DH[i][2][2] = cos(alpha[i]);
            M_DH[i][2][3] = d[i];
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
        std::cout << "\nT06" << std::endl;
        std::cout << T06;
        //float *myarray = T06.ravel();
        //for(int i=0;i<16;i++)
            //std::cout << myarray[i] << " ";
        //delete[] myarray;

    }

    Robot::Robot(double _th1, double _th2, double _th3, double _th4, double _th5, double _th6, std::string _color, std::string _material):alpha( {-90*PI/180, 0, -90*PI/180, 90*PI/180, -90*PI/180, 0} ), a( {0, L2, L3, 0, 0, 0} ), d( {L1, 0, 0, L4, 0, L6} )
    {
        th1 = _th1;
        th2 = _th2;
        th3 = _th3;
        th4 = _th4;
        th5 = _th5;
        th6 = _th6;
        pesoTotal = 2000; // kg
        setColor(_color);
        material = _material;
        float theta[6] = {th1*PI/180, (th2-90)*PI/180, th3*PI/180, th4*PI/180, th5*PI/180, (th6+180)*PI/180};

        for(int i=0;i<6;i++)
        {
            M_DH[i][0][0] = cos(theta[i]);
            M_DH[i][0][1] = -sin(theta[i]) * cos(alpha[i]);
            M_DH[i][0][2] = sin(alpha[i]) * sin(theta[i]);
            M_DH[i][0][3] = a[i] * cos(theta[i]);
            M_DH[i][1][0] = sin(theta[i]);
            M_DH[i][1][1] = cos(theta[i]) *  cos(alpha[i]);
            M_DH[i][1][2] = -sin(alpha[i]) * cos(theta[i]);
            M_DH[i][1][3] = a[i] * sin(theta[i]);
            M_DH[i][2][0] = 0;
            M_DH[i][2][1] = sin(alpha[i]);
            M_DH[i][2][2] = cos(alpha[i]);
            M_DH[i][2][3] = d[i];
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
        std::cout << "\nT06" << std::endl;
        std::cout << T06;
    }

    int Robot::getPesoTotal(){return pesoTotal;}

    void Robot::setTh1(float _th1){th1 = _th1;}
    void Robot::setTh2(float _th2){th2 = _th2;}
    void Robot::setTh3(float _th3){th3 = _th3;}
    void Robot::setTh4(float _th4){th4 = _th4;}
    void Robot::setTh5(float _th5){th5 = _th5;}
    void Robot::setTh6(float _th6){th6 = _th6;}
    double Robot::getTh1(){return th1;}
    double Robot::getTh2(){return th2;}
    double Robot::getTh3(){return th3;}
    double Robot::getTh4(){return th4;}
    double Robot::getTh5(){return th5;}
    double Robot::getTh6(){return th6;}

    std::string Robot::getColor(){return color;}
    double Robot::getColorR(){return colorR;}
    double Robot::getColorG(){return colorG;}
    double Robot::getColorB(){return colorB;}

    void Robot::setColor(std::string _color)
    {
        color = _color;
        if(color=="rojo")
        {
            colorR = 1.0;
            colorG = 0.0;
            colorB = 0.0;
        }
        else if(color=="verde")
        {
            colorR = 0.0;
            colorG = 1.0;
            colorB = 0.0;
        }
        else if(color=="azul")
        {
            colorR = 0.0;
            colorG = 0.0;
            colorB = 1.0;
        }
        else if(color=="amarillo")
        {
            colorR = 1.0;
            colorG = 1.0;
            colorB = 0.0;
        }
        else if(color=="magenta")
        {
            colorR = 1.0;
            colorG = 0.0;
            colorB = 1.0;
        }
        else if(color=="cyan")
        {
            colorR = 0.0;
            colorG = 1.0;
            colorB = 1.0;
        }
        else if(color=="negro")
        {
            colorR = 0.15;
            colorG = 0.15;
            colorB = 0.15;
        }
        else if(color=="blanco")
        {
            colorR = 1.0;
            colorG = 1.0;
            colorB = 1.0;
        }
        else if(color=="rosa")
        {
            colorR = 1.0;
            colorG = 0.0;
            colorB = 0.5;
        }
        else if(color=="naranja")
        {
            colorR = 1.0;
            colorG = 0.5;
            colorB = 0.0;
        }
        else if(color=="morado")
        {
            colorR = 0.5;
            colorG = 0.0;
            colorB = 0.5;
        }
        else if(color=="café")
        {
            colorR = 0.5;
            colorG = 0.25;
            colorB = 0.0;
        }
        else
        {
            colorR = 0.5;
            colorG = 0.5;
            colorB = 0.5;
        }
    }

    std::string Robot::getMaterial(){return material;}

    void Robot::setMaterial(std::string _material){material = _material;}

    void Robot::actualizarPosicion()
    {
        float theta[6] = {th1*PI/180, (th2-90)*PI/180, th3*PI/180, th4*PI/180, th5*PI/180, (th6+180)*PI/180};
        for(int i=0;i<6;i++)
        {
            M_DH[i][0][0] = cos(theta[i]);
            M_DH[i][0][1] = -sin(theta[i]) * cos(alpha[i]);
            M_DH[i][0][2] = sin(alpha[i]) * sin(theta[i]);
            M_DH[i][0][3] = a[i] * cos(theta[i]);
            M_DH[i][1][0] = sin(theta[i]);
            M_DH[i][1][1] = cos(theta[i]) *  cos(alpha[i]);
            M_DH[i][1][2] = -sin(alpha[i]) * cos(theta[i]);
            M_DH[i][1][3] = a[i] * sin(theta[i]);
            M_DH[i][2][0] = 0;
            M_DH[i][2][1] = sin(alpha[i]);
            M_DH[i][2][2] = cos(alpha[i]);
            M_DH[i][2][3] = d[i];
            M_DH[i][3][0] = 0;
            M_DH[i][3][1] = 0;
            M_DH[i][3][2] = 0;
            M_DH[i][3][3] = 1;
        }
        // Imprimir matrices
        /*
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
        */

        //std::cout << "Reasignando tabla en objetos de la clase Matriz4x4" << std::endl;
        T01 = M_DH;
        //std::cout << T01;
        T12 = M_DH;
        //std::cout << T12;
        T23 = M_DH;
        //std::cout << T23;
        T34 = M_DH;
        //std::cout << T34;
        T45 = M_DH;
        //std::cout << T45;
        T56 = M_DH;
        //std::cout << T56;
        T02 = T01*T12;
        //std::cout << T02;
        T03 = T02*T23;
        //std::cout << T03;
        T04 = T03*T34;
        //std::cout << T04;
        T05 = T04*T45;
        //std::cout << T05;
        T06 = T05*T56;
        //std::cout << "\nT06" << std::endl;
        //std::cout << T06;
        //float *myarray = T06.ravel();
        //for(int i=0;i<16;i++)
            //std::cout << myarray[i] << " ";
        //delete[] myarray;

    }

    void Robot::imprimirDatos()
    {
        std::cout << "L1 = " << L1 << " m" << std::endl;
        std::cout << "L2 = " << L2 << " m" << std::endl;
        std::cout << "L3 = " << L3 << " m" << std::endl;
        std::cout << "L4 = " << L4 << " m" << std::endl;
        std::cout << "L5 = " << L5 << " m" << std::endl;
        std::cout << "L6 = " << L6 << " m" << std::endl;
        std::cout << "pesoTotal = " << pesoTotal << " kg" << std::endl;
        std::cout << "color = " << color << std::endl;
        std::cout << "material = " << material << std::endl;
    }

    void Robot::imprimirValoresTh()
    {
        std::cout << "Theta1 = " << th1 << " grados" << std::endl;
        std::cout << "Theta2 = " << th2 << " grados" << std::endl;
        std::cout << "Theta3 = " << th3 << " grados" << std::endl;
        std::cout << "Theta4 = " << th4 << " grados" << std::endl;
        std::cout << "Theta5 = " << th5 << " grados" << std::endl;
        std::cout << "Theta6 = " << th6 << " grados" << std::endl;
    }

    void Robot::imprimirT06()
    {
        std::cout << T06 << std::endl;
    }

    void Robot::imprimirPxyzEfector()
    {
        std::cout << "Punto del efector con respecto al origen" << std::endl;
        std::cout << "P(x,y,z) = (" << T06.getLastColumn()[0] << ", " << T06.getLastColumn()[1] << ", " << T06.getLastColumn()[2] << ")" << std::endl;
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
        /*
        for(int i=0;i<m;i++){
            delete M[i];
        }
        delete M;
        std::cout << "Libera memoria" << std::endl;*/
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
        // Verificar el valor de la matriz a la que se accede
        //std::cout << mat << std::endl;
        mat += 1;
        if(mat==6)
        {
            mat = 0;
        }
        return temp;
    }

    double* Matriz4x4::ravel_transpose()
    {
        double *arr = new double[16];
        int k=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr[k] = M[j][i];
                k++;
            }
        }

        // Imprime el arreglo unidimensional
        /*
        for(int i=0;i<16;i++)
            std::cout << arr[i] << " ";
        */
        return arr;
    }

    double* Matriz4x4::getLastColumn()
    {
        double *arr = new double[3];
        arr[0] = M[0][3];
        arr[1] = M[1][3];
        arr[2] = M[2][3];
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
