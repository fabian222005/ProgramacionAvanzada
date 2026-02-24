
/************************
Instituto Tecnologico de Durango
Departamento Metal-Mecanica

Programacion Avanzada 7U
Fabian Quiñones Escarzaga 23040871
Ing. Mario Gerardo Hernandez Marines
2026-02-24.13-37
Practica Practica Herencias Multiples
************************/

#include <iostream>

class A {
public:
 A() {std::cout<<"A\n";}
};
class B {
public:
 B() {std::cout<<"B\n";}
};

class AB : public B, public A {
public:
AB(){std::cout<<"AB\n";}
};


int main(){
AB q;
}
