#include <iostream>

class Puerta
{
 public:
	int ancho;
	int alto;
	int color;
	bool abierto;
	
	void abrir(){
		abierto = true;
	}
	void cerrar(){
		abierto = false;
	}

	void estado()
	{
		std::cout << "Estado de la puerta\n";
		std::cout << "Ancho: " << ancho<< "\n";
		std::cout << "Alto: " << alto<<"\n";
		std::cout << "Color: " << color<<"\n";
		std::cout << "Abierto: " << abierto<<"\n";
	}
};

int main(){
Puerta p1300;
p1300.ancho =20;
p1300.alto = 100;
p1300.color = 0xff00ff;
p1300.abrir();
p1300.estado();
p1300.cerrar();
p1300.estado();
}
