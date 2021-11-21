#include <iostream>
#include "Listas\UListaPD.h"
#include "Conjuntos\UConjuntoV.h"
#include "Conjuntos\UConjuntoP.h"
#include "Polinomios\UPolinomioL.h"
#include "UPolinomioV1.h"
#include <math.h>
#include <string>

using namespace std;

void p1();
void p2();
void p3();
float area(PolinomioV1* p);

int main() {
	p3();
	system("pause");
	return 0;
}

float area(PolinomioV1* p, float a, float b) {
	int n = p->numero_terminos();
	float evA = 0, evB = 0;
	for (int i = 1; i <= n; i++) {
		int exp = p->exponente(i);
		int coef = p->coeficiente(exp);
		float inteA = (coef * 1.0 / (exp + 1))*pow(a, exp + 1);
		float inteB = (coef * 1.0 / (exp + 1))*pow(b, exp + 1);
		evA += inteA;
		evB += inteB;
	}
	cout << evB << endl;
	cout << evA << endl;
	return abs(evB) + abs(evA);
}

void p3() {
	PolinomioV1* p = new PolinomioV1();
	//p->poner_termino(4, 3);
	//p->poner_termino(2, 2);
	p->poner_termino(2, 0);
	cout << p->to_str() << endl;
	float a = -2, b = 2;
	float are = area(p, a, b);
	cout << "Area: " << to_string(are) << endl;
}

void p2() {
	PolinomioV1* p = new PolinomioV1();
	p->poner_termino(4, 4);
	p->poner_termino(5, 2);
	cout << p->to_str() << endl;
	p->poner_termino(1, 7);
	//cout << p->coeficiente(4);
	cout << p->to_str() << endl;
	p->poner_termino(-14, 18);
	cout << p->to_str() << endl;
	p->poner_termino(-5, 2);
	cout << p->to_str() << endl;
	p->poner_termino(14, 18);
	cout << p->to_str() << endl;
	p->poner_termino(-4, 4);
	cout << p->to_str() << endl;
	p->poner_termino(-1, 7);
	cout << p->to_str() << endl;
	cout << p->numero_terminos() << endl;
}

void p1() {
	ListaPD* l = new ListaPD();
	l->inserta_ultimo(10);
	cout << l->to_str() << endl;
	l->inserta_ultimo(11);
	cout << l->to_str() << endl;
	l->inserta_ultimo(12);
	cout << l->to_str() << endl;
	l->suprime(l->primero());
	cout << l->to_str() << endl;
	l->inserta_primero(99);
	cout << l->to_str() << endl;
	l->inserta(l->primero(), 98);
	cout << l->to_str() << endl;
	l->inserta(l->anterior(l->fin()), 100);
	cout << l->to_str() << endl;
	l->suprime(l->anterior(l->fin()));
	cout << l->to_str() << endl;
	l->suprime(l->primero());
	l->suprime(l->primero());
	cout << l->to_str() << endl;
	l->suprime(l->primero());
	l->suprime(l->primero());
	l->suprime(l->primero());
	l->suprime(l->primero());
	cout << l->to_str() << endl;
	l->inserta(l->primero(), 96);

}