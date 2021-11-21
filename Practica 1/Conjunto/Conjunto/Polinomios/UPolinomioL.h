#pragma once

#include <iostream>
#include <string>
#include "../Listas/UListaP.h"

using namespace std;

class PolinomioL {
private:
	ListaP* pol;
	NodoL* buscar_exponente(int exp);
	NodoL* buscar_termino_n(int i);

public:
	PolinomioL();
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void asignar_coeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro_ter);
	void sumar(PolinomioL* p1, PolinomioL* p2);
	void restar(PolinomioL* p1, PolinomioL* p2);
	void multiplicar(PolinomioL* p1, PolinomioL* p2);
	string to_str();
};