#include <iostream>
#include <string.h>
using namespace std;
class empleados {
  public:
    char nombre[64];
    long id_empleado;
    float salario;
    void ver_empleado(void)
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Id: " << id_empleado << endl;
        cout << "Salario: " << salario << endl;
    }
};

int main()
{
    empleados trabajador, jefe;

    strcpy(trabajador.nombre, "martin jaime");
    trabajador.id_empleado = 12345;
    trabajador.salario = 25000;

    strcpy(jefe.nombre, "Jamsa Felix");
    jefe.id_empleado = 101;
    jefe.salario = 101101.00;

    trabajador.ver_empleado();
}
