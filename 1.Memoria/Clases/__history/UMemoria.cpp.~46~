// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UMemoria.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

CSMemoria::CSMemoria() {
	mem = new NodoM[MAX];
	for(int i = 0;i < MAX;i++){
		mem[i].link = i + 1;
	}
	mem[MAX - 1].link = -1;
    libre = 0;
}

int numero_ids(string cad){
	int c = 0;
	for(int i = 0;i < cad.length();i++)
		if(cad[i] == ',')
			c++;
	return c + 1;
}

string obtener_id(string cad, int pos){
	int cont = 1;
	while(cad.length() > 0){
		int p = cad.find_first_of(",");
		if(cont == pos){
			if(p == -1)
                p = cad.length();
			string sub = cad.substr(0, p);
			return sub;
		}
		cont++;
		cad.erase(0, p + 1);
	}
    return "";
}

int CSMemoria::new_espacio(string cad) {
	int cant = numero_ids(cad);
	//if(cant <= espacio_disponible()){
	int dir = libre;
	int d = libre;
	for(int i = 0;i < cant - 1;i++){
		mem[d].id = obtener_id(cad, i + 1);
		d = mem[d].link;
	}
	libre = mem[d].link;
	mem[d].link = -1;
	mem[d].id = obtener_id(cad, cant);
    return dir;
	//}
}

void CSMemoria::delete_espacio(int dir) {
	int x = dir;
	while(mem[x].link != -1)
		x = mem[x].link;
	mem[x].link = libre;
    libre = dir;
}

void CSMemoria::poner_dato(int dir, string id, int valor) {
	int z = dir;
	id = id.substr(2, id.length() - 2);
	while(z != NULO){
		if(mem[z].id == id)
			mem[z].dato = valor;
        z = mem[z].link;
	}
}

int CSMemoria::obtener_dato(int dir, string lugar) {
	int z = dir;
	lugar = lugar.substr(2, lugar.length() - 2);
	while(z != NULO){
		if(mem[z].id == lugar)
			return mem[z].dato;
		z = mem[z].link;
	}

}

int CSMemoria::espacio_disponible() {
	int x = libre;
	int c = 0;
	while(x != -1){
		c++;
        x = mem[x].link;
	}
    return c;
}

int CSMemoria::espacio_ocupado() {
	return MAX - espacio_disponible();
}

bool CSMemoria::dir_libre(int dir) {
	int x = libre;
	bool c = false;
	while(x != -1 && c == false){
		if(x == dir)
			c = true;
		x = mem[x].link;
	}
    return c;
}

void CSMemoria::mostrar() {
	string cab = "| DIR |  DATO  |    ID    | LINK |\n";
	string lin = "+" + string(cab.length() - 3, '-') + "+\n";
	string out = lin + cab + lin;
	int edir = 3, edat = 8, eid = 10; // eid lo cambian
	for (int i = 0; i < MAX; i++) {
		int rel = edir - to_string(i).length();
		string dir = " " + string(rel, '0') + to_string(i) + " ";
		rel = edat - to_string(mem[i].dato).length();
		string dat = string(rel, ' ') + to_string(mem[i].dato);
		rel = eid - mem[i].id.length();
		string id = string(rel, ' ') + mem[i].id;
		rel = edir - to_string(mem[i].link).length();
		string lnk = "  " + string(rel, ' ') + to_string(mem[i].link) + " ";
		out += "|" + dir + "|" + dat + "|" + id + "|" + lnk + "|\n";
	}
	out += lin;
	out += "Libre = " + to_string(libre) + "\n";
	out += "Espacios libres = " + to_string(espacio_disponible()) + "\n";
	out += "Espacios ocupados = " + to_string(espacio_ocupado()) + "\n";
	cout << out;
}
