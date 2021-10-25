#include <iostream>
#include "Polinomio\UPolinomioL.h"
#include "Polinomio\UPolinomioLS.h"
#include "Polinomio\UPolinomioV.h"
#include "Polinomio\UPolinomioP.h"
#include "Polinomio\UPolinomioS.h"

using namespace std;

int main() {
	PolinomioS* p = new PolinomioS();
	p->poner_termino(5, 3);
	cout << p->to_str() << endl; 
	p->poner_termino(7, 2);
	cout << p->to_str() << endl;
	p->poner_termino(10, 3);
	cout << p->to_str() << endl;
	p->poner_termino(-7, 2);
	cout << p->to_str() << endl;
	p->asignar_coeficiente(0, 3);
	cout << p->to_str() << endl;
	system("pause");
	return 0;
}