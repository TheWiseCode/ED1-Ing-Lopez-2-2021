#include "UListaPD.h"

ListaPD::ListaPD() {
	ptrElementos = NULL;
	longit = 0;
}
NodoLD* ListaPD::fin() {
	if (vacia()) {
		cout << "Lista vacia\n";
		return NULL;
	}
	else {
		NodoLD* x = ptrElementos;
		NodoLD* ptrFin = NULL;
		while (x != NULL) {
			ptrFin = x;
			x = x->sig;
		}
		return ptrFin;
	}
}

NodoLD* ListaPD::primero() {
	return ptrElementos;
}
NodoLD* ListaPD::siguiente(NodoLD* dir) {
	return dir->sig;
}
NodoLD*ListaPD::anterior(NodoLD* dir) {
	return dir->ant;
}
bool ListaPD::vacia() {
	return longit == 0;
}
int ListaPD::recupera(NodoLD* dir) {
	return dir->elemento;
}

int ListaPD::longitud() {
	return longit;
}
void ListaPD::inserta(NodoLD* dir, int e) {
	NodoLD* x = new NodoLD();
	if (x != NULL) {
		x->elemento = e;
		x->sig = x->ant = NULL;
		if (vacia()) {
			ptrElementos = x;
			longit = 1;
		}
		else {
			if (dir == primero()) {
				x->sig = dir;
				dir->ant = x;
				ptrElementos = x;
			}
			else {
				NodoLD* ant = dir->ant;
				ant->sig = x;
				x->sig = dir;
				dir->ant = x;
				x->ant = dir;
			}
			longit++;
		}
	}
}

void ListaPD::inserta_primero(int e) {
	NodoLD* x = new NodoLD();
	if (x != NULL) {
		x->elemento = e;
		x->ant = x->sig = NULL;
		if (vacia()) 
			ptrElementos = x;
		else {
			x->sig = ptrElementos;
			ptrElementos->ant = x;
			ptrElementos = x;
		}
		longit++;
	}
}

void ListaPD::inserta_ultimo(int e) {
	NodoLD* x = new NodoLD();
	if (x != NULL) {
		x->elemento = e;
		x->sig = x->ant = NULL;
		if (longit != 0) {
			NodoLD* fini = fin();
			fini->sig = x;
			x->ant = fini;
		}
		else
			ptrElementos = x;
		longit++;
	}
}

void ListaPD::suprime(NodoLD* dir) {
	if (longit == 0) {
		cout << "Lista vacia\n";
		return;
	}
	if (dir == ptrElementos) {
		NodoLD* x = ptrElementos;
		ptrElementos = ptrElementos->sig;
		if(ptrElementos != NULL)
			ptrElementos->ant = NULL;
	}
	else {
		NodoLD* ant = dir->ant;
		NodoLD* sig = dir->sig;
		ant->sig = sig;
		if (sig != NULL)
			sig->ant = ant;
	}
	delete dir;
	longit--;
}

void ListaPD::modifica(NodoLD* dir, int e) {
	dir->elemento = e;
}

string ListaPD::to_str() {
	string s = "[";
	NodoLD* aux = ptrElementos;
	while (aux != NULL) {
		int el = aux->elemento;
		s += to_string(el);
		aux = aux->sig;
		if (aux != NULL)
			s += ",";
	}
	return s + "]";
}