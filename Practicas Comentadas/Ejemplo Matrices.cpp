/************************
Instituto Tecnologico de Durango
Departamento Metal-Mecanica

Programacion Avanzada 7U
Fabian Quiñones Escarzaga 23040871
Ing. Mario Gerardo Hernandez Marines
Clase Matrices
************************/
#include <iostream>
#include <string.h>

int matrix[3][3] = 
{
{1,2,3},
{4,5,6},
{7,8,9}
};

int main(){
	using namespace std;
	for(int i=0; i<3;i++){
		for(int j = 0; j<3; j++)
			cout<< matrix[i][j] <<" ";
		cout << endl;
	};
	return 0;
}
