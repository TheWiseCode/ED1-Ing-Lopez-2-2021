#pragma once
#include <iostream>
#include <string>
#include "Listas\UListaP.h"

using namespace std;

class PolinomioV1
{
private:
	ListaP* l;
	int nter;
	NodoL* posExp(int exp);
public:
	PolinomioV1();
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void asignar_coeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro_ter);
	string to_str();
};

