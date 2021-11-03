#include "UConjuntoV.h"

ConjuntoV::ConjuntoV()
{
	cant = 0;
	v = new bool[MAX_V];
	for (int i = 0; i < MAX_V; i++)
		v[i] = false;
	srand(time(NULL));
}

bool ConjuntoV::vacio() {
	return cant == 0;
}
bool ConjuntoV::pertenece(int e) {
	if (e > 0 && e <= MAX_V)
		return v[e - 1];
	return false;
}
void ConjuntoV::inserta(int e) {
	if (e > 0 && e <= MAX_V) {
		if (!pertenece(e)) {
			v[e - 1] = true;
			cant++;
		}
	}
}
int ConjuntoV::cardinal() {
	return cant;
}

int ConjuntoV::ordinal(int e) {
	int resp = 0;
	for (int i = 0; i < MAX_V; i++) {
		if (v[i]) {
			resp++;
			if (e == i + 1)
				return resp;
		}
	}
	return -1;
}

void ConjuntoV::suprime(int e) {
	if (e > 0 && e <= MAX_V) {
		if (pertenece(e)) {
			v[e - 1] = false;
			cant--;
		}
	}
}

int ConjuntoV::muestrea() {
	if (!vacio()) {
		int pos = (rand() % cardinal()) + 1;
		int resp = 0;
		for (int i = 0; i < MAX_V; i++) {
			if (v[i]) {
				resp++;
				if (pos == resp)
					return i + 1;
			}
		}
		return -1;
	}
	else {
		cout << "Conjunto vacio\n";
		return -1;
	}
}

string ConjuntoV::to_str() {
	string s = "";
	for (int i = 0; i < MAX_V; i++) {
		if (v[i]) {
			s += to_string(i + 1) + ",";
		}
	}
	return s.substr(0, s.length() - 1);
}