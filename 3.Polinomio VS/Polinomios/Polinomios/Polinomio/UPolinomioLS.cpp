#include "UPolinomioLS.h"

int PolinomioLS::buscar_exponente(int exp)
{
	if (pol->vacia())
		return -1;
	int dir = pol->siguiente(pol->primero());
	if (dir != -1) {
		int dirExp = -1;
		while (dir != -1 && dirExp == -1) {
			if (pol->recupera(dir) == exp)
				dirExp = dir;
			if (pol->siguiente(dir) == -1)
				break;
			dir = pol->siguiente(pol->siguiente(dir));
		}
		return dirExp;
	}
	return -1;
}

int PolinomioLS::buscar_termino_n(int i)
{
	if (i > 0 && i <= numero_terminos()) {
		int dir = pol->primero();
		int nt = 0;
		if (dir != -1) {
			int dirTer = -1;
			while (dir != -1 && dirTer == -1) {
				nt++;
				if (nt == i)
					dirTer = dir;
				dir = pol->siguiente(pol->siguiente(dir));
			}
			return dirTer;
		}
	}
	return -1;
}

PolinomioLS::PolinomioLS()
{
	pol = new ListaV();
}

bool PolinomioLS::es_cero()
{
	return pol->vacia();
}

int PolinomioLS::grado()
{
	if (pol->vacia()) {
		cout << "Polinomio sin terminos\n";
		return -1;
	}
	int dir = pol->siguiente(pol->primero());
	int maxG = pol->recupera(dir);
	while (dir != -1) {
		if (pol->recupera(dir) > maxG) {
			maxG = pol->recupera(dir);
		}
		if (pol->siguiente(dir) == -1)
			break;
		dir = pol->siguiente(pol->siguiente(dir));
	}
	return maxG;
}

int PolinomioLS::coeficiente(int exp)
{
	int dir = buscar_exponente(exp);
	if (dir != -1) {
		return pol->recupera(pol->anterior(dir));
	}
	else {
		cout << "No existe ese termino\n";
		return -1;
	}
}

void PolinomioLS::asignar_coeficiente(int coef, int exp)
{
	int dirExp = buscar_exponente(exp);
	if (dirExp != -1) {
		int dirCoef = pol->anterior(dirExp);
		pol->modifica(dirCoef, coef);
		if (pol->recupera(dirCoef) == 0) {
			pol->suprime(dirExp);
			pol->suprime(dirCoef);
		}
	}
}

void PolinomioLS::poner_termino(int coef, int exp)
{
	int dirExp = buscar_exponente(exp);
	if (dirExp != -1) {
		int dirCoef = pol->anterior(dirExp);
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

int PolinomioLS::numero_terminos()
{
	return pol->longitud() / 2;
}

int PolinomioLS::exponente(int nro_ter)
{
	int dir = buscar_termino_n(nro_ter);
	if (dir != -1)
		return pol->recupera(pol->siguiente(dir));
	else {
		cout << "No existe ese numero de termino/n";
		return -1;
	}
}

void PolinomioLS::sumar(PolinomioLS * p1, PolinomioLS * p2)
{
}

void PolinomioLS::restar(PolinomioLS * p1, PolinomioLS * p2)
{
}

void PolinomioLS::multiplicar(PolinomioLS * p1, PolinomioLS * p2)
{
}

string PolinomioLS::to_str()
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
