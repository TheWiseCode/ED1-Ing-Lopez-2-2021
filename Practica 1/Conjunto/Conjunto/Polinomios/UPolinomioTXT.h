#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class PolinomioTXT
{
private: 
	string filename;
	int buscarExp(int exp);
public:
	PolinomioTXT(string file);
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void asignar_coeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro_ter);
	string to_str();
};

