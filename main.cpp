#include <iostream>
#include "robot.h"

using namespace std;
using namespace rbt;

int main()
{
    float valor;
    Robot robot;
    robot.imprimirDatos();

    valor = robot.getPesoTotal();
    cout << "Peso total: " << valor << endl;

    return 0;
}
