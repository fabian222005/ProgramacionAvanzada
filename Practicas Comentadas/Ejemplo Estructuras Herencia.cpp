/************************
Instituto Tecnologico de Durango
Departamento Metal-Mecanica

Programacion Avanzada 7U
Fabian Quiñones Escarzaga 23040871
Ing. Mario Gerardo Hernandez Marines
Clase Estructuras Herencia
************************/
#include <iostream>
#include <string.h>

using namespace std;

struct persona {
	int age;
	char CountryCode[3];
	char Name[256];
	virtual void print() { // Véase como la struct puede tener funciones como miembros. 
        cout << "Nombre: " << Name << " Pais: " << CountryCode << " Edad: " << age;
	};
};

struct trabajador : persona { // Véase que el trabajador hereda de persona age, CountryCode, Name los cuales son miembros públicamente accesibles
	int horas_a_la_semana;
	int nomina_semanal;
	// Observe como se realiza un "override" o invalidación de la función de la clase base para implementar la propia de la hija, se necesita que la función sea virtual void 
	void print() override{ 
        cout << "Nombre: " << Name << " | Pais: " << CountryCode << " | Edad: " << age << " | Horas a la semana: "<< horas_a_la_semana << " | Nomina Semanal " << nomina_semanal;
	};
};

int main(){
	trabajador Agustin;
	Agustin.horas_a_la_semana = 40;
	Agustin.nomina_semanal = 8000;
	//Sin mayor preambulo puedo acceder directamente a los miembros de persona del trabajador
	Agustin.age =20;
	strcpy(Agustin.CountryCode,"MX");
	strcpy(Agustin.Name,"Agustin Perez");
	
	Agustin.print();
	return 0;
}
