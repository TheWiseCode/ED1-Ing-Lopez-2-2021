#include "UPolinomioTXT.h"

int PolinomioTXT::buscarExp(int exp)
{
	ifstream infile(filename);
	string line;
	int cont = 0;
	while (getline(infile, line))
	{
		cont++;
		int pos = line.find_first_of(",");
		line.erase(0, pos + 1);
		int expLine = atoi(line.c_str());
		if (expLine == exp) {
			infile.close();
			return cont;
		}
	}
	infile.close();
	return -1;
}

PolinomioTXT::PolinomioTXT(string file)
{
	filename = file;
}

bool PolinomioTXT::es_cero()
{
	return numero_terminos() == 0;
}

int PolinomioTXT::grado()
{
	return 0;
}

int PolinomioTXT::coeficiente(int exp)
{
	int pos = buscarExp(exp);
	if (pos > 0) {
		ifstream infile(filename);
		string line;
		int cont = 0;
		while (infile >> line) {
			cont++;
			if (cont == pos) {
				int coma = line.find_first_of(",");
				int coef = atoi(line.substr(0, pos).c_str());
				return coef;
			}
		}
	}
	cout << "No existe ese exponente\n";
	return 0;
}

void PolinomioTXT::asignar_coeficiente(int coef, int exp)
{
	int pos = buscarExp(exp);
	if (exp >= 0 && pos > 0) {
		ifstream filein(filename);
		ofstream fileout("temp.txt");
		string strTemp;
		int cont = 0;
		while (filein >> strTemp)
		{
			cont++;
			if (cont == pos) {
				if (coef != 0)
					strTemp = to_string(coef) + "," + to_string(exp);
				else
					strTemp = "";
			}
			if (strTemp != "")
				strTemp += "\n";
			fileout << strTemp;
		}
		filein.close();
		fileout.close();
		filein.open("temp.txt");
		fileout.open(filename);
		while (filein >> strTemp)
			fileout << strTemp << endl;
		filein.close();
		fileout.close();
	}
}

void PolinomioTXT::poner_termino(int coef, int exp)
{
	if (coef != 0 && exp >= 0) {
		int pos = buscarExp(exp);
		if (pos == -1) {
			ofstream outfile;
			outfile.open(filename, ios::app);
			outfile << to_string(coef) << "," << to_string(exp) << endl;
			outfile.close();
		}
		else {
			ifstream filein(filename);
			ofstream fileout("temp.txt");
			string strTemp;
			int cont = 0;
			while (filein >> strTemp)
			{
				cont++;
				if (cont == pos) {
					int posL = strTemp.find_first_of(",");
					int acoef = atoi(strTemp.substr(0, posL).c_str());
					int ncoef = coef + acoef;
					if (ncoef != 0)
						strTemp = to_string(ncoef) + "," + to_string(exp);
					else
						strTemp = "";
				}
				if (strTemp != "")
					strTemp += "\n";
				fileout << strTemp;
			}
			filein.close();
			fileout.close();
			filein.open("temp.txt");
			fileout.open(filename);
			while (filein >> strTemp)
				fileout << strTemp << endl;
			filein.close();
			fileout.close();
		}
	}
}

int PolinomioTXT::numero_terminos()
{
	int n = 0;
	ifstream infile(filename);
	while (infile >> string())
		n++;
	return n;
}

int PolinomioTXT::exponente(int nro_ter)
{
	if (nro_ter > 0 && nro_ter <= numero_terminos()) {
		ifstream infile(filename);
		string line;
		int cont = 0;
		while (infile >> line) {
			cont++;
			if (cont == nro_ter) {
				int coma = line.find_first_of(",");
				line.erase(0, coma + 1);
				return atoi(line.c_str());
			}

		}
	}
	cout << "Nro termino invalido\n";
	return 0;
}

string PolinomioTXT::to_str()
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

