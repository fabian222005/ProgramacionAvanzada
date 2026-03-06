/************************
Instituto Tecnologico de Durango
Departamento Metal-Mecanica

Programacion Avanzada 7U
Fabian Quiñones Escarzaga 23040871
Ing. Mario Gerardo Hernandez Marines
Clase Estructuras
************************/
#include <iostream>
#include <string.h>

using namespace std;

struct {
	int age;
	char CountryCode[3];
	char Name[256];
	void print(){ // Véase como la struct puede tener funciones como miembros. 
        cout << "Nombre: " << Name << " Pais: " << CountryCode << " Edad: " << age;
	};
} Luis; // Observe como pongo el nombre del OBJETO abajo y despues de la declaracion del struct antes del punto y coma para definir un objeto, si se colocara después de struct fuera un tipo de dato organizado;

int main(){
	Luis.age =20;
	strcpy(Luis.CountryCode,"MX");
	strcpy(Luis.Name,"Luis Perez");
	
	Luis.print();
	
	return 0;
}
