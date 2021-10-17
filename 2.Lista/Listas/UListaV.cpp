// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UListaV.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

ListaV::ListaV() {
	this->longit = 0;
	elementos = new int[MAXV];
}

int ListaV::fin() {
	if (!vacia())
		return longit - 1;
	else
		cout << "ERROR: LISTA VACIA\n";
}

int ListaV::primero() {
	if (!vacia())
		return 0;
	else
		cout << "ERROR: LISTA VACIA\n";
}

int ListaV::siguiente(int d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (d == longit - 1)
			cout << "ERROR: DIRECCION ERRONEA\n";
		else
			return d + 1;
	}
}

int ListaV::anterior(int d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (d > 0 && d <= longit - 1)
			return d - 1;
		else
			cout << "ERROR: DIRECCION ERRONEA\n";
	}
}

bool ListaV::vacia() {
	return longit == 0;
}

int ListaV::recupera(int d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (d >= 0 && d <= longit - 1)
			return elementos[d];
		else
			cout << "ERROR: DIRECCION ERRONEA\n";
	}
}

int ListaV::longitud() {
	return longit;
}

void ListaV::inserta(int d, int e) {
	if (longit == MAXV) {
		cout << "ERROR: LISTA LLENA\n";
		return;
	}
	if (vacia()) {
		elementos[0] = e;
		longit++;
		return;
	}
	if (d >= 0 && d <= longit - 1) {
		for (int i = longit; i > d; i--)
			elementos[i] = elementos[i - 1];
		elementos[d] = e;
		longit++;
	}
	else
		cout << "ERROR: DIRECCION ERRONEA\n";
}

void ListaV::inserta_primero(int e) {
	if (longit == MAXV) {
		cout << "ERROR: LISTA LLENA\n";
		return;
	}
	for (int i = longit; i > 0; i--)
		elementos[i] = elementos[i - 1];
	elementos[0] = e;
	longit++;
}

void ListaV::inserta_ultimo(int e) {
	if (longit == MAXV)
		cout << "ERROR: LISTA LLENA\n";
	else {
		elementos[longit] = e;
		longit++;
	}
}

void ListaV::suprime(int d) {
	if (longit == 0) {
		cout << "ERROR: LISTA VACIA\n";
		return;
	}
	if (d >= 0 && d <= longit - 1) {
		for (int i = d; i < longit - 1; i++)
			elementos[i] = elementos[i + 1];
		longit--;
	}
	else
		cout << "ERROR: DIRECCION ERRONEA\n";
}

void ListaV::modifica(int d, int e) {
	if (longit == 0) {
		cout << "ERROR: LISTA VACIA\n";
		return;
	}
	if (d >= 0 && d <= longit - 1)
		elementos[d] = e;
	else
		cout << "ERROR: DIRECCION ERRONEA\n";
}

string ListaV::to_str() {
	string ret = "";
	for (int i = 0; i < longit; i++) {
		ret += to_string(elementos[i]);
		if (i < longit - 1)
			ret += ",";
	}
	return ret;
}
