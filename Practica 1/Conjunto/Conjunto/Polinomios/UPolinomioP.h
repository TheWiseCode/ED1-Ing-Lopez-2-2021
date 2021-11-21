#pragma once

#include <iostream>
#include <string>

using namespace std;

struct NodoPo {
	int coef;
	int exp;
	NodoPo* sig;
};

class PolinomioP {
private:
	NodoPo* ptr_poli;
	int nt;

	NodoPo* buscar_exponente(int exp);
	NodoPo* buscar_termino_n(int i);
	NodoPo* anterior(NodoPo* dir);
	void suprime(NodoPo* dir);

public:
	PolinomioP();
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void asignar_coeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro_ter);
	float evaluar(float x);
	void derivada(PolinomioP *p);
	void mostrar_integral();
	PolinomioP* suma(PolinomioP* a, PolinomioP* b);
	PolinomioP* resta(PolinomioP* a, PolinomioP* b);
	PolinomioP* producto(PolinomioP* a, PolinomioP* b);
	string to_str();

};
