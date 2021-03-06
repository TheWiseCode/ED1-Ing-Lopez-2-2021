// ---------------------------------------------------------------------------

#ifndef UListaPH
#define UListaPH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

struct NodoL {
	int elemento;
	NodoL* sig;
};

class ListaP {
private:
	NodoL* ptrElementos;
	int longit;

public:
	ListaP();
	NodoL* fin();
	NodoL* primero();
	NodoL* siguiente(NodoL* dir);
	NodoL* anterior(NodoL* dir);
	bool vacia();
	int recupera(NodoL* dir);
	int longitud();
	void inserta(NodoL* dir, int e);
	void inserta_primero(int e);
	void inserta_ultimo(int e);
	void suprime(NodoL* dir);
	void modifica(NodoL* dir, int e);
    string to_str();

};
#endif
