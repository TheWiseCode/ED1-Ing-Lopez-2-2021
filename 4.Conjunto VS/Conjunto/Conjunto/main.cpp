#include <iostream>
#include "Conjuntos\UConjuntoV.h"
#include "Conjuntos\UConjuntoP.h"

using namespace std;

int main() {
	ConjuntoP* a = new ConjuntoP();
	a->inserta(1);
	a->inserta(3);
	a->inserta(4);
	a->inserta(6);
	ConjuntoP* b = new ConjuntoP();
	b->inserta(1);
	b->inserta(3);
	b->inserta(56);
	b->inserta(100);
	ConjuntoP* c = new ConjuntoP();
	cout << a->to_str() << endl;
	cout << b->to_str() << endl;
	cout << c->to_str() << endl;
	a->interseccion(a, b, c);
	cout << a->to_str() << endl;
	cout << b->to_str() << endl;
	cout << c->to_str() << endl;
	system("pause");
	return 0;
}