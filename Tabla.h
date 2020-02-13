#pragma once

struct polje
{
	int vrednost;
	int vrsta;
	int kolona;
};

class Tabla
{
private:
	polje** mat;
public:
	Tabla();
	~Tabla();
	void ucitaj();
	void prikaz();
	int nadjiNulu();
	bool moze(polje, int k);
	bool resi();

};

