#include "UPolinomioV1.h"

PolinomioV1::PolinomioV1()
{
	l = new ListaP();
	nter = 0;
}

bool PolinomioV1::es_cero() {
	return nter == 0;
}
int PolinomioV1::grado() {
	return l->longitud() - 1;
}
int PolinomioV1::coeficiente(int exp) {
	NodoL* pos = posExp(exp);
	if (pos == NULL || l->recupera(pos) == 0) {
		cout << "No existe el termino\n";
		return 0;
	}
	else {
		return l->recupera(pos);
	}

}

void PolinomioV1::asignar_coeficiente(int coef, int exp) {
	int gra = grado();
	NodoL* pos = posExp(exp);
	if (pos != NULL) {
		int acoef = l->recupera(pos);
		l->modifica(pos, coef);
		if (coef == 0) {
			nter--;
			if (exp == gra) {
				while (!l->vacia() && l->recupera(l->primero()) == 0) {
					l->suprime(l->primero());
				}
			}
		}
		if (acoef == 0)
			nter++;
	}
}

void PolinomioV1::poner_termino(int coef, int exp) {
	if (exp >= 0) {
		if (es_cero()) {
			if (coef != 0) {
				l->inserta_ultimo(coef);
				for (int i = 0; i < exp; i++)
					l->inserta_ultimo(0);
				nter++;
			}
		}
		else {
			int gra = grado();
			if (exp > gra) {
				if (coef != 0) {
					int c = exp - gra - 1;
					for (int i = 0; i < c; i++)
						l->inserta_primero(0);
					l->inserta_primero(coef);
				}
				nter++;
			}
			else {
				NodoL* pos = posExp(exp);
				if (pos != NULL) {
					int acoef = l->recupera(pos);
					int ncoef = coef + acoef;
					l->modifica(pos, ncoef);
					if (ncoef == 0) {
						nter--;
						if (exp == gra) {
							while (!l->vacia() && l->recupera(l->primero()) == 0) {
								l->suprime(l->primero());
							}
						}
					}
					if (acoef == 0)
						nter++;
				}
			}
		}
	}
}

NodoL* PolinomioV1::posExp(int exp) {
	NodoL* aux = l->primero();
	int expAux = grado();
	while (aux != NULL) {
		if (expAux == exp)
			return aux;
		expAux--;
		aux = aux->sig;
	}
	return NULL;
}

int PolinomioV1::numero_terminos() {
	return nter;
}

int PolinomioV1::exponente(int nro_ter) {
	NodoL* aux = l->primero();
	int expAux = grado();
	int cont = 0;
	while (aux != NULL) {
		if (l->recupera(aux) != 0)
			cont++;
		if(cont == nro_ter)
			return expAux;
		expAux--;
		aux = aux->sig;
	}
	return 0;
}

string PolinomioV1::to_str() {
	string r = "";
	int n = numero_terminos();
	for (int i = 1; i <= n; i++) {
		int exp = exponente(i);
		int coef = coeficiente(exp);
		if (coef > 0)
			r += "+";
		r += to_string(coef) + "x^" + to_string(exp);
	}
	return r + "    " + l->to_str();
}