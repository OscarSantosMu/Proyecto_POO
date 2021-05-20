#include <iostream>
#include "robot.h"

using namespace std;
using namespace rbt;

int main()
{
    float valor;
    Robot robot;

    robot.T01.ravel();
    cout << endl;
    robot.T02.ravel();
    cout << endl;
    robot.T03.ravel();
    cout << endl;
    robot.T04.ravel();
    cout << endl;
    robot.T05.ravel();
    cout << endl;
    robot.T06.ravel();



    /*robot.imprimirDatos();

    valor = robot.getPesoTotal();
    cout << "Peso total: " << valor << endl;

    Matriz4x4 m1, m2, m3;
    cout << "M1\n";
    cin >> m1;
    cout << "M2\n";
    cin >> m2;
    cout << "M3 = M1*M2\n";
    m3 = m1*m2;
    cout << m3;

    */
    return 0;
}
