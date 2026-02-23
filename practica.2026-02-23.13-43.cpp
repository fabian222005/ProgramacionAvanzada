
/************************
Instituto Tecnologico de Durango
Departamento Metal-Mecanica

Programacion Avanzada 7U
Fabian Quiñones Escarzaga 23040871
Ing. Mario Gerardo Hernandez Marines
2026-02-23.13-43
Practica Encapsulamiento y De-encapsulamiento
************************/
#include <iostream>
#include <string.h>

using namespace std;

class Empleado{
	private:
		
		char* m_nombre; //Alerternativa: char m_nombre[30] o string m_nombre;
		char* m_departamento;
		char* m_posicion;
		long m_salario;
		
	public:
	
	void Imprimir(Empleado infoEmpleado);
		void ImprimirInfo();
		void SetNombre(char* nombre) 
			{
				m_nombre = new char[strlen(nombre)+1];
				if(m_nombre != NULL)
					strcpy(m_nombre,nombre);
			};
		void SetDepartamento(char* departamento)
			{ m_departamento = departamento;};
		void SetPosicion ( char* posicion ) 
			{ m_posicion = posicion; }
    	void SetSalario ( long salario ) 
			{ m_salario = salario; }
    	const char* GetNombre() 
			{ return m_nombre; }
    	const char* GetDepartamento() 
			{ return m_departamento; }
    	const char* GetPosicion() 
			{ return m_posicion; }
    	long GetSalario() 
			{ return m_salario; }
	
};

void Empleado::ImprimirInfo(){
	cout << "Nombre: " << m_nombre << endl;
	cout << "Departamento: " << m_departamento << endl;
	cout << "Puesto: " << m_posicion << endl;
	cout << "Salario: $ " << m_salario << endl;
}

int main(){
	//Creacion de un objeto de la clase Empleado
	Empleado e12;
	
	//asignacion de valores a las variables miembro
	e12.SetNombre("Jose");
	e12.SetDepartamento("Sistemas");
	e12.SetPosicion("Programador");
	e12.SetSalario(30000);
	
	//Impresion de los datos
	e12.ImprimirInfo();
	

}
