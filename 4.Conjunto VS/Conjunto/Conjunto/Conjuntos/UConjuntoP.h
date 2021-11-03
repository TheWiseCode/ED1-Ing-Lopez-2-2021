#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct NodoCj {
	int dato;
	NodoCj* sig;
};

class ConjuntoP
{
private:
	NodoCj* ptrConj;
	int cant;
public:
	ConjuntoP();
	bool vacio();
	bool pertenece(int e);
	void inserta(int e);
	int cardinal();
	int ordinal(int e);
	void suprime(int e);
	int muestrea();
	void unionC(ConjuntoP* a, ConjuntoP* b, ConjuntoP* c);
	void interseccion(ConjuntoP* a, ConjuntoP* b, ConjuntoP* c);
	string to_str();
};