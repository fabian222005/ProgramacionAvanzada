/************************
Instituto Tecnologico de Durango
Departamento Metal-Mecanica

Programacion Avanzada 7U
Fabian Quiñones Escarzaga 23040871
Ing. Mario Gerardo Hernandez Marines
2026-02-20.11-23
Practica clasesConstructor
************************/
#include <iostream>
#include <string.h>

using namespace std;
int cuenta_precio;
class serie_libros {
 public:
  serie_libros(char *, char *);
  void ver_libro();
  void poner_precio();
  void poner_pags(int *);
 private:
  static int pags;
  static int precio;
  char titulo[64];
  char autor[64];
};
int serie_libros::pags;
int serie_libros::precio;
void serie_libros::poner_pags(int* pags){
	cout<<"Dame el número de páginas\n";
	cin>> *pags;
}

serie_libros::serie_libros(char* titulo, char* autor){
	strcpy(serie_libros::titulo, titulo);
	strcpy(serie_libros::autor, autor);
	serie_libros::poner_precio();
	serie_libros::poner_pags(&serie_libros::pags);
}

void serie_libros::poner_precio(){
	cout << "Dame el precio para el libro "<<serie_libros::titulo<<" :\n";
	cin >> serie_libros::precio;
}

void serie_libros::ver_libro(){
	cout << "----------------\n";
	cout << "Nombre: " << serie_libros::titulo<<endl;
	cout << "Autor: " << serie_libros::autor<<endl;
	cout << "Precio: " << serie_libros::precio<<endl;
	cout << "Páginas: " << serie_libros::pags<<endl;

	cout << "----------------\n";
}
int main(){
serie_libros* quimicaII = new serie_libros("Quimica: La Ciencia Central","Brown");
quimicaII->ver_libro();
serie_libros* misIdeales = new serie_libros("Mein Kampf","A. Hitler");
misIdeales->ver_libro();
return(0);
}
