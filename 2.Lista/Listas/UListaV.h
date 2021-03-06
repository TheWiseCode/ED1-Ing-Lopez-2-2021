// ---------------------------------------------------------------------------

#ifndef UListaVH
#define UListaVH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

const int MAXV = 100;

class ListaV {
private:
	int* elementos; // int elementos[MAXV];
	int longit;

public:
	ListaV();
	int fin();
	int primero();
	int siguiente(int d);
	int anterior(int d);
	bool vacia();
	int recupera(int d);
	int longitud();
	void inserta(int d, int e);
	void inserta_primero(int e);
	void inserta_ultimo(int e);
	void suprime(int d);
	void modifica(int d, int e);
	string to_str();
};
#endif
