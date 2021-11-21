#include "UConjuntoP.h"

ConjuntoP::ConjuntoP()
{
	ptrConj = NULL;
	cant = 0;
}

bool ConjuntoP::vacio()
{
	return cant == 0;
}

bool ConjuntoP::pertenece(int e)
{
	bool resp = false;
	NodoCj* pc = ptrConj;
	while (pc != NULL) {
		if (pc->dato == e) {
			resp = true;
			pc = NULL;
		}
		else {
			pc = pc->sig;
		}
	}
	return resp;
}

void ConjuntoP::inserta(int e)
{
	if (!pertenece(e)) {
		NodoCj* dir = new NodoCj();
		if (dir != NULL) {
			dir->dato = e;
			dir->sig = ptrConj;
			ptrConj = dir;
			cant++;
		}
	}
}

int ConjuntoP::cardinal()
{
	return cant;
}

int ConjuntoP::ordinal(int e)
{
	int resp = 0;
	NodoCj* pc = ptrConj;
	while (pc != NULL) {
		resp++;
		if (e == pc->dato)
			return resp;
		else
			pc = pc->sig;
	}
	return -1;
}

void ConjuntoP::suprime(int e)
{
	if (pertenece(e)) {
		NodoCj* dir = NULL;
		NodoCj* pc = ptrConj;
		while (pc != NULL) {
			if (pc->dato == e)
				break;
			dir = pc;
			pc = pc->sig;
		}
		if (dir == NULL)
			ptrConj = ptrConj->sig;
		else
			dir->sig = pc->sig;
		delete pc;
		cant--;
	}
}

int ConjuntoP::muestrea()
{
	if (!vacio()) {
		int ele;
		int pos = (rand() % cardinal()) + 1;
		int cont = 0;
		NodoCj* pc = ptrConj;
		while (pc != NULL)
		{
			cont++;
			if (cont == pos) {
				ele = pc->dato;
				pc = NULL;
			}
			else {
				pc = pc->sig;
			}
		}
		return ele;
	}
	else {
		cout << "Conjunto vacio\n";
		return -1;
	}

}

void ConjuntoP::unionC(ConjuntoP * a, ConjuntoP * b, ConjuntoP * c)
{
	int e;
	ConjuntoP* aux = new ConjuntoP();
	while (!a->vacio()) {
		e = a->muestrea();
		c->inserta(e);
		a->suprime(e);
		aux->inserta(e);
	}
	while (!aux->vacio()) {
		e = aux->muestrea();
		a->inserta(e);
		aux->suprime(e);
	}
	while (!b->vacio()) {
		e = b->muestrea();
		c->inserta(e);
		b->suprime(e);
		aux->inserta(e);
	}
	while (!aux->vacio()) {
		e = aux->muestrea();
		b->inserta(e);
		aux->suprime(e);
	}
}

void ConjuntoP::interseccion(ConjuntoP * a, ConjuntoP * b, ConjuntoP * c)
{
	int e;
	ConjuntoP* aux = new ConjuntoP();
	while (!a->vacio()) {
		e = a->muestrea();
		if(a->pertenece(e) && b->pertenece(e))
			c->inserta(e);
		a->suprime(e);
		aux->inserta(e);
	}
	while (!aux->vacio()) {
		e = aux->muestrea();
		a->inserta(e);
		aux->suprime(e);
	}
}

string ConjuntoP::to_str()
{
	string s = "";
	NodoCj* pc = ptrConj;
	while (pc != NULL) {
		s += to_string(pc->dato) + ",";
		pc = pc->sig;
	}
	return s.substr(0, s.length() - 1);
}
