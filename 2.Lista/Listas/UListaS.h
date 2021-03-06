// ---------------------------------------------------------------------------

#ifndef UListaSH
#define UListaSH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UMemoria.h"

using namespace std;

const string datos = "elemento,sig";
const string elemento = "->elemento";
const string sig = "->sig";

class ListaS {
private:
	CSMemoria* m;
	int ptrElementos;
	int longit;

public:
	ListaS();
	ListaS(CSMemoria* mem);
	int fin();
	int primero();
	int siguiente(int dir);
	int anterior(int dir);
	bool vacia();
	int recupera(int dir);
	int longitud();
	void inserta(int dir, int e);
	void inserta_primero(int e);
	void inserta_ultimo(int e);
	void suprime(int dir);
	void modifica(int dir, int e);
	string to_str();
};
#endif
