#pragma once
#include "dwmatio.h"
#include "kratisi.h"

class dwmatioC :
	public dwmatio
{
public:
	dwmatioC();
	~dwmatioC();
	
	bool prosthiki_kratisis(kratisi &k);

	int get_elaxista_atoma();
	void set_elaxista_atoma(int atoma);

	int get_elaxistes_meres();
	void set_elaxistes_meres(int meres);


private:
	int elaxista_atoma;
	int elaxistes_meres;
};

