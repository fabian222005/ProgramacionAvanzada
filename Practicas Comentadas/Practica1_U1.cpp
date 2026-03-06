/************************
Instituto Tecnologico de Durango
Departamento Metal-Mecanica

Programacion Avanzada 7U
Fabian Quiñones Escarzaga 23040871
Ing. Mario Gerardo Hernandez Marines
2026-03-03
Practica 1 U1 Regiones de Acceso
************************/

/************
Premisa:
El cliente tiene saldo en el banco y decide disponer, para lo cual
Cajero le pide clave al cliente,
El cliente le confirma la clave,
El cajero revisa saldo total, le da el efectivo y le descuenta del saldo total

Consideraciones:
Saldo en centavos
NIP sin limitacion de dígitos (excepto los valores extremos del tipo int)

*************/

#include <iostream>

class cliente {
	friend class cajero;
	private:
		int NIP;
	protected:
		int saldo_total; 
	public:
		cliente(int saldo, int a_nip) : NIP(a_nip), saldo_total(saldo) {};
		bool autenticar(int intento){
			return(NIP == intento);
		};
};

class cajero {
	public:
		int consultar_saldo(cliente * cl, int NIP){//En estas funciones publicas de la clase es necesario autentificarse para realizar cualquier procedimiento
			if(!cl->autenticar( NIP )) {
				std::cout << "Usuario No Autentificado\n";
				return(0);
			}
			return(interno_consultar_saldo(cl));
		};
		int retirar_saldo(cliente * cl, int NIP, int importe){
			if(!cl->autenticar( NIP )) {
				std::cout << "Usuario No Autentificado\n";
				return(0);
			}
			int saldo = interno_consultar_saldo(cl);
			if(importe < 0){
				std::cout << "Listillo, ese truco no funciona conmigo\n";
				return(0);
			}
			if(importe > saldo){
				std::cout << "Fondos Insuficientes\n";
				return(0);
			}
			cl->saldo_total -= importe;
			interno_estadoCuenta(cl);
			return(importe);
		};
		
		void imprimir_estadoCuenta(cliente * cl, int NIP){
			if(!cl->autenticar( NIP )) {
				std::cout << "Usuario No Autentificado\n";
				return;
			}
			interno_estadoCuenta(cl);
		};
	private:// Aquí no es necesario autentificar, ya que nadie mas que el mismo cajero (ni siquiera otros cajeros) puede consultar saldo sin autentificar
		int interno_consultar_saldo(cliente * cl){ 
			return(cl->saldo_total);
		};
		void interno_estadoCuenta(cliente * cl) {
			std::cout << "-------------------Banco Sustraer-------------------\n";
			std::cout << "Saldo del cliente: $" <<cl->saldo_total/100.00f<<std::endl;
		};
};


int main(){
	cliente Felipe(5457, 1000);
	cliente Carlos(10000, 1100);
	cliente Juan(1000, 1011);
	cliente Alfredo(500, 1101);
	
	cliente * clientes[4]= {&Felipe, &Carlos, &Juan, &Alfredo};
	cajero Adrian;
	while(true){
		std::cout << "Bienvenido al Banco Sustraer.\n\tSi es: \n\t\tFelipe digite 0\n\t\tCarlos digite 1\n\t\tJuan digite 2\n\t\tAlfredo digite 3\n\t\tPara cerrar digite 4\n\t\tIndique la opcion>> ";
		int selectedIdx=-1;
		std::cin >> selectedIdx;
		if(selectedIdx ==4){
			std::cout << "\nBye";
			return(0);
		}
		while(selectedIdx<0 || selectedIdx>3){
			std::cout << "\n Opcion inválida. Digite de nuevo: ";
			std::cin >> selectedIdx;
		}
		std::cout << "\n Digite su NIP: ";
		int NIP;
		std::cin >>NIP;
		while(!clientes[selectedIdx]->autenticar(NIP)){
			std::cout << "\n NIP incorrecto, Intente de nuevo: ";
			std::cin >> NIP;
		};
		std::cout << "\n Saldo Actual\n";
		Adrian.imprimir_estadoCuenta(clientes[selectedIdx],NIP); 
		//Aqui llamamos a imprimir_estadoCuenta y no a interno_estadoCuenta debido a que se esta llamando desde main y lo declarado bajo "private" no es accesible.
		
		int qty=0;
		float buff;
		float retiro=-10.0f;
		while(retiro <= 0){
			if(retiro <= 0){
				std::cout << "\n Cantidad a retirar en pesos ($xx.xx):";
				std::cin >> buff;
				qty= buff * 100;
			}
			if(qty<1){
				std::cout<< "\n Error: El monto minimo a retirar es de 1 centavo";
			};
			std::cout << "\n";
			retiro = Adrian.retirar_saldo(clientes[selectedIdx],NIP,qty)/100.00f;
		};
		std::cout << "Tenga sus $"<< retiro <<"\n";
	}
}


