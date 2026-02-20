
/************************
Instituto Tecnologico de Durango
Departamento Metal-Mecanica

Programacion Avanzada 7U
Fabian Quiñones Escarzaga 23040871
Ing. Mario Gerardo Hernandez Marines
2026-02-20.11-31
Practica clasesHeredadasconConstructor
************************/
#include <iostream>
class A {
public:
A(int argA){
std::cout<<"Hola desde A\n";
varA=argA;
}
int getA(){return(varA);}
private:
int varA;
};

class B : public A {
public:
	B(int argA) : A(argA){
		std::cout<<"Hola desde B\n";
	}
};

int main(){
A testA(10);
std::cout<<"varA: "<<testA.getA();
B testB(101);
}
