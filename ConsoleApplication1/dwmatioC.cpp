#include "stdafx.h"
#include "dwmatioC.h"


dwmatioC::dwmatioC()
{
}


dwmatioC::~dwmatioC()
{
}

bool dwmatioC::prosthiki_kratisis(kratisi &k) {
	cout << endl << "=============================== stoixeia kratisis gia dwmatio C =======================" << endl;
	
	int afiksi = k.get_afiksi();
	cout << "afiksi: " << afiksi << endl;
	int atoma = k.get_atoma();
	cout << "atoma: " << atoma << endl;
	int meres = k.get_meres();
	cout << "meres: " << meres << endl;
	string onoma = k.get_onoma();
	cout << "onoma: " << onoma << endl;

	if (atoma < elaxista_atoma) {
		cout << " Eiste :" << atoma << " atoma.  To elaxisto gia na kleisete to dwmatio einai : " << elaxista_atoma << " atoma. I kratisi akirwthike." << endl;
		return false;
	}
	if (meres < elaxistes_meres) {
		cout << " Thelete na kleisete gia :" << meres << " meres.Oi elaxistes gia na kleisete to dwmatio einai : " << elaxistes_meres << " . I kratisi akirwthike." << endl;
		return false;
	}
	//kratisi *diathes[30]
	int counter = afiksi - 1 + meres - 1; // xrisimopoioume stin for gia na kseroume pou na stamatisei to i
	for (int i = (afiksi - 1); i <= counter; i++) {

		if (diathes[i] != NULL) {
			cout << "oi meres einai piasmenes. den mporei na ginei i kratisi." << endl;
			return false;
		}
		else {
			//cout << "i mera: " << (i+1) << " einai diathesimi!" << endl;
		}
	}
	if (atoma <= get_max_cap()) {
		//cout << " ta atoma xwrane sto dwmatio! " << endl;
	}
	else {
		cout << "ta atoma den xwrane sto dwmatio. I kratisi den mporei na ginei dekti" << endl;
		return false;
	}
	for (int j = (afiksi - 1); j <= counter; j++) {
		diathes[j] = &k;
	}

	cout << "I kratisi egine me epitixia!" << endl;
	
	return true;
}




int dwmatioC::get_elaxista_atoma() {
	return elaxista_atoma;
}
void dwmatioC::set_elaxista_atoma(int atoma) {
	elaxista_atoma = atoma;
}

int dwmatioC::get_elaxistes_meres() {
	return elaxistes_meres;
}
void dwmatioC::set_elaxistes_meres(int meres) {
	elaxistes_meres = meres;
}