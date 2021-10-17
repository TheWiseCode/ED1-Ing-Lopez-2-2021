#include <iostream>
#include <string>
#include "UMemoria.h"

using namespace std;

int main() {
	CSMemoria m;
	do {
		cout << "1.Crear\n";
		cout << "2.Pedir espacio\n";
		cout << "3.Liberar espacio\n";
		cout << "4.Poner dato\n";
		cout << "5.Mostrar memoria\n";
		cout << "6.Salir\n";
		int opcion;
		cout << "Introduzca su opcion: ";
		cin >> opcion;
		if (opcion == 1) {
			cout << "Memoria creada\n";
		}
		else if (opcion == 2) {
			string id;
			cout << "Introduzca los ids: ";
			cin.ignore();
			getline(cin, id);
			m.new_espacio(id);
		}
		else if (opcion == 3) {
			int dir;
			cout << "Direccion a liberar: ";
			cin >> dir;
			m.delete_espacio(dir);
		}
		else if (opcion == 4) {
			int dir;
			cout << "Direccion a colocar: ";
			cin >> dir;
			string id;
			cout << "Introduzca un id: ";
			cin.ignore();
			getline(cin, id);
			int valor;
			cout << "Introduzca el valor: ";
			cin >> valor;
            m.poner_dato(dir, id, valor);
		}
		else if (opcion == 5) {
			m.mostrar();
		}
		else if (opcion == 6) {
			break;
		}

	}
	while (true);
	system("pause");
	return 0;
}
