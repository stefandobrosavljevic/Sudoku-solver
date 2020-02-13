#include "Tabla.h"
#include <iostream>
#include <fstream>
using namespace std;


Tabla::Tabla()
{
	mat = new polje* [9];
	for (int i = 0; i < 9; i++) {
		mat[i] = new polje[9];
		for (int j = 0; j < 9; j++) {
			mat[i][j].vrednost = 0;
			mat[i][j].vrsta = i;
			mat[i][j].kolona = j;
		}
	}
}


Tabla::~Tabla()
{
	for (int i = 0; i < 9; i++)
		delete[] mat[i];
	delete[] mat;
}


void Tabla::prikaz()
{
	cout << "\n\n";
	for (int i = 0; i < 9; i++) {
		cout << "\t";
		for (int j = 0; j < 9; j++) {
			if (mat[i][j].vrednost == 0)
				cout << "_";
			else
				cout << mat[i][j].vrednost;
			if ((j + 1) % 3 == 0 && j<8)
				cout << " | ";
			else
				cout << " ";
		}
		if ((i + 1) % 3 == 0)
			cout << endl << endl;
		else
			cout << endl;
	}
	cout << endl;
}




int Tabla::nadjiNulu()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (mat[i][j].vrednost == 0) {
				return (mat[i][j].vrsta * 9 + mat[i][j].kolona);
			}
		}
	}
	return -1;
}


bool Tabla::moze(polje p, int k)
{
	// kolone
	for (int i = 0; i < 9; i++) {
		if (mat[i][p.kolona].vrednost == k)
			return false;
	}
	//vrste
	for (int i = 0; i < 9; i++) {
		if (mat[p.vrsta][i].vrednost == k)
			return false;
	}
	//kocka
	int q = (int)(p.vrsta / 3) * 3;
	int w = (int)(p.kolona / 3) * 3;

	for (int i = q; i <= q + 2; i++) {
		for (int j = w; j <= w + 2; j++) {
			if (mat[i][j].vrednost == k)
				return false;
		}
	}
	return true;
}



bool Tabla::resi()
{
	int pom = nadjiNulu();
	if (pom == -1)
		return true;
	int i = pom / 9;
	int j = pom % 9;

	for (int k = 1; k <= 9; k++) {
		if (moze(mat[i][j], k)) {
			mat[i][j].vrednost = k;
			if (resi())
				return true;
			mat[i][j].vrednost = 0;
		}
	}
	return false;
}



void Tabla::ucitaj()
{
	ifstream text("Text.txt");
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			text >> mat[i][j].vrednost;
		}
	}
	text.close();
}