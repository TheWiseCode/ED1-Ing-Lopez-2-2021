#pragma once
#include <iostream>
#include <string>

using namespace std;

struct NodoLD {
	int elemento;
	NodoLD* sig;
	NodoLD* ant;
};

class ListaPD {
private:
	NodoLD* ptrElementos;
	int longit;

public:
	ListaPD();
	NodoLD* fin();
	NodoLD* primero();
	NodoLD* siguiente(NodoLD* dir);
	NodoLD* anterior(NodoLD* dir);
	bool vacia();
	int recupera(NodoLD* dir);
	int longitud();
	void inserta(NodoLD* dir, int e);
	void inserta_primero(int e);
	void inserta_ultimo(int e);
	void suprime(NodoLD* dir);
	void modifica(NodoLD* dir, int e);
	string to_str();

};

