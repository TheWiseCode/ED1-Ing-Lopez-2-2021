#pragma once
#include <iostream>
#include <string>
#include "../Listas/UListaV.h"

class PolinomioLS
{
private:
	ListaV* pol;
	int buscar_exponente(int exp);
	int buscar_termino_n(int i);
public:
	PolinomioLS();
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void asignar_coeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro_ter);
	void sumar(PolinomioLS* p1, PolinomioLS* p2);
	void restar(PolinomioLS* p1, PolinomioLS* p2);
	void multiplicar(PolinomioLS* p1, PolinomioLS* p2);
	string to_str();
};

