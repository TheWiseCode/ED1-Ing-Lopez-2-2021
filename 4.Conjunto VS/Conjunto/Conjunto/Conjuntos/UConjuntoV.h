#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int MAX_V = 100;

class ConjuntoV
{
private:
	bool* v;
	int cant;
public:
	ConjuntoV();
	bool vacio();
	bool pertenece(int e);
	void inserta(int e);
	int cardinal();
	int ordinal(int e);
	void suprime(int e);
	int muestrea();
	string to_str();
};

