// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UListaS.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ListaS::ListaS() {
	m = new CSMemoria();
	longit = 0;
	ptrElementos = NULO;
}

ListaS::ListaS(CSMemoria* mem) {
	m = mem;
	longit = 0;
	ptrElementos = NULO;
}

int ListaS::fin() {
	if (vacia()) {
		cout << "Lista vacia\n";
	}
	else {
		int x = ptrElementos;
		int ptrFin = NULO;
		while (x != NULO) {
			ptrFin = x;
			// x = x->sig;
			x = m->obtener_dato(x, sig);
		}
		return ptrFin;
	}
}

int ListaS::primero() {
	if (!vacia()) {
		return ptrElementos;
	}
	else {
		cout << "Lista vacia\n";
	}
}

int ListaS::siguiente(int dir) {
	if (vacia()) {
		cout << "Lista vacia\n";
	}
	else {
		if (dir == fin())
			cout << "Direccion erronea\n";
		else
			// return dir->sig;
				return m->obtener_dato(dir, sig);
	}
}

int ListaS::anterior(int dir) {
	if (vacia()) {
		cout << "Lista vacia\n";
	}
	else {
		if (dir == primero()) {
			cout << "Direccion erronea\n";
		}
		else {
			int x = ptrElementos;
			int ant = NULO;
			while (x != NULO) {
				if (x == dir)
					return ant;
				ant = x;
				// x = x->sig;
				x = m->obtener_dato(x, sig);
			}
			return NULO;
		}
	}
}

bool ListaS::vacia() {
	return longit == 0;
}

int ListaS::recupera(int dir) {
	if (vacia()) {
		cout << "Lista vacia\n";
	}
	else {
		// return dir->elemento;
		return m->obtener_dato(dir, elemento);
	}
}

int ListaS::longitud() {
	return longit;
}

void ListaS::inserta(int dir, int e) {
	// NodoL* x = new NodoL();
	int x = m->new_espacio(datos);
	if (x != NULO) {
		// x->elemento = e;
		// x->sig = NULO;
		m->poner_dato(x, elemento, e);
		m->poner_dato(x, sig, NULO);
		if (vacia()) {
			ptrElementos = x;
			longit = 1;
		}
		else {
			if (dir == primero()) {
				// x->sig = dir;
				m->poner_dato(x, sig, dir);
				ptrElementos = dir;
			}
			else {
				int ant = anterior(dir);
				// ant->sig = x;
				// x->sig = dir;
				m->poner_dato(ant, sig, x);
				m->poner_dato(x, sig, dir);
			}
		}
	}
}

void ListaS::inserta_primero(int e) {
	// NodoL* x = new NodoL();
	int x = m->new_espacio(datos);
	if (x != NULO) {
		// x->elemento = e;
		// x->sig = ptrElementos;
		m->poner_dato(x, elemento, e);
		m->poner_dato(x, sig, ptrElementos);
		longit++;
		ptrElementos = x;
	}
}

void ListaS::inserta_ultimo(int e) {
	// NodoL* x = new NodoL();
	int x = m->new_espacio(datos);
	if (x != NULO) {
		// x->elemento = e;
		// x->sig = NULO;
		m->poner_dato(x, elemento, e);
		m->poner_dato(x, sig, NULO);
		if (longit != 0)
			// fin()->sig = x;
				m->poner_dato(fin(), sig, x);
		else
			ptrElementos = x;
		longit++;
	}
}

void ListaS::suprime(int dir) {
	if (longit == 0) {
		cout << "Lista vacia\n";
		return;
	}
	if (dir == ptrElementos) {
		int x = ptrElementos;
		// ptrElementos = ptrElementos->sig;
		ptrElementos = m->obtener_dato(ptrElementos, sig);
		// delete x;
		m->delete_espacio(x);
	}
	else {
		int ant = anterior(dir);
		// ant->sig = dir->sig;
		// dir->sig  <=> m->obtener_dato(dir, sig)
		int dir_sig = m->obtener_dato(dir, sig);
		m->poner_dato(ant, sig, dir_sig);
		// delete dir;
		m->delete_espacio(dir);
	}
	longit--;
}

void ListaS::modifica(int dir, int e) {
	if (vacia()) {
		cout << "Lista vacia\n";
	}
	else {
		// dir->elemento = e;
		m->poner_dato(dir, elemento, e);
	}
}

string ListaS::to_str() {
	string s = "[";
	int aux = ptrElementos;
	while (aux != NULO) {
		// int el = aux->elemento;
		int el = m->obtener_dato(aux, elemento);
		s += to_string(el);
		// aux = aux->sig;
		aux = m->obtener_dato(aux, sig);
		if (aux != NULO)
			s += ",";
	}
	return s + "]";
}
