#include "UPolinomioL.h"

NodoL* PolinomioL::buscar_exponente(int exp)
{
	if (pol->vacia())
		return NULL;
	NodoL* dir = pol->siguiente(pol->primero());
	if (dir != NULL) {
		NodoL* dirExp = NULL;
		while (dir != NULL && dirExp == NULL) {
			if (pol->recupera(dir) == exp)
				dirExp = dir;
			if (pol->siguiente(dir) == NULL)
				break;
			dir = pol->siguiente(pol->siguiente(dir));
		}
		return dirExp;
	}
	return NULL;
}

NodoL * PolinomioL::buscar_termino_n(int i)
{
	if (i > 0 && i <= numero_terminos()) {
		NodoL* dir = pol->primero();
		int nt = 0;
		if (dir != NULL) {
			NodoL* dirTer = NULL;
			while (dir != NULL && dirTer == NULL) {
				nt++;
				if (nt == i)
					dirTer = dir;
				dir = pol->siguiente(pol->siguiente(dir));
			}
			return dirTer;
		}
	}
	return NULL;
}

PolinomioL::PolinomioL()
{
	pol = new ListaP();
}

bool PolinomioL::es_cero()
{
	return pol->vacia();
}

int PolinomioL::grado()
{
	if (pol->vacia()) {
		cout << "Polinomio sin terminos\n";
		return NULL;
	}
	NodoL* dir = pol->siguiente(pol->primero());
	int maxG = pol->recupera(dir);
	while (dir != NULL) {
		if (pol->recupera(dir) > maxG) {
			maxG = pol->recupera(dir);
		}
		if (pol->siguiente(dir) == NULL)
			break;
		dir = pol->siguiente(pol->siguiente(dir));
	}
	return maxG;
}

int PolinomioL::coeficiente(int exp)
{
	NodoL* dir = buscar_exponente(exp);
	if (dir != NULL) {
		return pol->recupera(pol->anterior(dir));
	}
	else {
		cout << "No existe ese termino\n";
		return NULL;
	}
}

void PolinomioL::asignar_coeficiente(int coef, int exp)
{
	NodoL* dirExp = buscar_exponente(exp);
	if (dirExp != NULL) {
		NodoL* dirCoef = pol->anterior(dirExp);
		pol->modifica(dirCoef, coef);
		if (pol->recupera(dirCoef) == 0) {
			pol->suprime(dirExp);
			pol->suprime(dirCoef);
		}
	}
}

void PolinomioL::poner_termino(int coef, int exp)
{
	NodoL* dirExp = buscar_exponente(exp);
	if (dirExp != NULL) {
		NodoL* dirCoef = pol->anterior(dirExp);
		pol->modifica(dirCoef, pol->recupera(dirCoef) + coef);
		if (pol->recupera(dirCoef) == 0) {
			pol->suprime(dirExp);
			pol->suprime(dirCoef);
		}
	}
	else {
		if (coef != 0) {
			pol->inserta_ultimo(coef);
			pol->inserta_ultimo(exp);
		}
	}
}

int PolinomioL::numero_terminos()
{
	return pol->longitud() / 2;
}

int PolinomioL::exponente(int nro_ter)
{
	NodoL* dir = buscar_termino_n(nro_ter);
	if (dir != NULL)
		return pol->recupera(pol->siguiente(dir));
	else {
		cout << "No existe ese numero de termino/n";
		return NULL;
	}
}

void PolinomioL::sumar(PolinomioL * p1, PolinomioL * p2)
{
}

void PolinomioL::restar(PolinomioL * p1, PolinomioL * p2)
{
}

void PolinomioL::multiplicar(PolinomioL * p1, PolinomioL * p2)
{
}

string PolinomioL::to_str()
{
	string r = "";
	int n = numero_terminos();
	for (int i = 1; i <= n; i++) {
		int exp = exponente(i);
		int coef = coeficiente(exp);
		if (coef > 0)
			r += "+";
		r += to_string(coef) + "x^" + to_string(exp);
	}
	return r;
}
