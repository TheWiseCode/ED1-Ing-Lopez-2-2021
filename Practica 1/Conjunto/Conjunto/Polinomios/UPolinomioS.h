#pragma once

#include <iostream>
#include <string>
#include "../Extras/UMemoria.h"

using namespace std;

const string datosPo = "coef,exp,sig";
const string coefPo = "->coef";
const string expPo = "->exp";
const string sigPo = "->sig";

class PolinomioS {
private:
	CSMemoria* mem;
	int ptr_poli;
	int nt;

	int buscar_exponente(int exp);
	int buscar_termino_n(int i);
	int anterior(int dir);
	void suprime(int dir);

public:
	PolinomioS();
	PolinomioS(CSMemoria* m);
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void asignar_coeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro_ter);
	void mostrar_integral();
	string to_str();

};