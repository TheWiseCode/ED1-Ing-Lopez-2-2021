#pragma once

#include <iostream>
#include <string>

using namespace std;

const int MAX_VP = 30;

class PolinomioV {
private:
	int* vc;
	int* ve;
	int nt;

	int buscar_exponente(int exp);

public:
	PolinomioV();
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void asignar_coeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro_ter);
	string to_str();
	PolinomioV* PolinomioV::producto(PolinomioV* a, PolinomioV* b);

};
