// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UListaP.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ListaP::ListaP() {
	longit = 0;
	ptrElementos = NULL;
}

NodoL* ListaP::fin() {
	if (vacia()) {
		cout << "Lista vacia\n";
	}
	else {
		NodoL* x = ptrElementos;
		NodoL* ptrFin = NULL;
		while (x != NULL) {
			ptrFin = x;
			x = x->sig;
		}
		return ptrFin;
	}
}

NodoL* ListaP::primero() {
	return ptrElementos;
}

NodoL* ListaP::siguiente(NodoL* dir) {
	if (vacia()) {
		cout << "Lista vacia\n";
	}
	else {
		return dir->sig;
	}
}

NodoL* ListaP::anterior(NodoL* dir) {
	if (vacia()) {
		cout << "Lista vacia\n";
	}
	else {
		if (dir == primero()) {
			return NULL;
		}
		else {
			NodoL* x = ptrElementos;
			NodoL* ant = NULL;
			while (x != NULL) {
				if (x == dir)
					return ant;
				ant = x;
				x = x->sig;
			}
			return NULL;
		}
	}
}

bool ListaP::vacia() {
	return longit == 0;
}

int ListaP::recupera(NodoL* dir) {
	if (vacia()) {
		cout << "Lista vacia\n";
	}
	else {
		return dir->elemento;
	}

}

int ListaP::longitud() {
	return longit;
}

void ListaP::inserta(NodoL* dir, int e) {
	NodoL* x = new NodoL();
	if (x != NULL) {
		x->elemento = e;
		x->sig = NULL;
		if (vacia()) {
			ptrElementos = x;
			longit = 1;
		}
		else {
			if (dir == primero()) {
				x->sig = dir;
				ptrElementos = dir;
			}
			else {
				NodoL* ant = anterior(dir);
				ant->sig = x;
				x->sig = dir;
			}
		}
	}
}

void ListaP::inserta_primero(int e) {
	NodoL* x = new NodoL();
	if (x != NULL) {
		x->elemento = e;
		x->sig = ptrElementos;
		longit++;
		ptrElementos = x;
	}
}

void ListaP::inserta_ultimo(int e) {
	NodoL* x = new NodoL();
	if (x != NULL) {
		x->elemento = e;
		x->sig = NULL;
		if (longit != 0)
			fin()->sig = x;
		else
			ptrElementos = x;
		longit++;
	}
}

void ListaP::suprime(NodoL* dir) {
	if (longit == 0) {
		cout << "Lista vacia\n";
		return;
	}
	if (dir == ptrElementos) {
		NodoL* x = ptrElementos;
		ptrElementos = ptrElementos->sig;
		delete x;
	}
	else {
		NodoL* ant = anterior(dir);
		ant->sig = dir->sig;
		delete dir;
	}
	longit--;
}

void ListaP::modifica(NodoL* dir, int e) {
	if (vacia()) {
		cout << "Lista vacia\n";
	}
	else {
		dir->elemento = e;
	}
}

string ListaP::to_str() {
	string s = "[";
	NodoL* aux = ptrElementos;
	while (aux != NULL) {
		int el = aux->elemento;
		s += to_string(el);
		aux = aux->sig;
		if (aux != NULL)
			s += ",";
	}
	return s + "]";
}
