//---------------------------------------------------------------------------

#ifndef UMemoriaH
#define UMemoriaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

const int MAX = 20;
const int NULO = -1;

struct NodoM{
	int dato;
	string id;
	int link;
};

class CSMemoriaZZZ{
	private:
		int libre;
		//NodoM mem[MAX];
		NodoM* mem;

	public:
		CSMemoriaZZZ();
		int new_espacio(string cad);
		void delete_espacio(int dir);
		void poner_dato(int dir, string id, int valor);
		int obtener_dato(int dir, string lugar);
		int espacio_disponible();
		int espacio_ocupado();
		bool dir_libre(int dir);
        void mostrar();

};
#endif
