#include "stdafx.h"
#include "Strict_dwmatio.h"
#include "kratisi.h"


Strict_dwmatio::Strict_dwmatio()
{
	meres_dianomis = 2;
}


Strict_dwmatio::~Strict_dwmatio()
{
}

bool Strict_dwmatio::prosthiki_kratisis(kratisi &k) {
	cout << endl << "=============================== stoixeia kratisis Strict_dwmatio =======================" << endl;
	int afiksi = k.get_afiksi();
	cout << "afiksi: " << afiksi << endl;
	int atoma = k.get_atoma();
	cout << "atoma: " << atoma << endl;
	int meres = k.get_meres();
	cout << "meres: " << meres << endl;
	string onoma = k.get_onoma();
	cout << "onoma: " << onoma << endl;
	k.p_dwmatio = this;

	//kratisi *diathes[30]

	int counter = afiksi - 1 + meres - 1; // xrisimopoioume stin for gia na kseroume pou na stamatisei to i
	for (int i = (afiksi - 1); i <= counter; i++) {
		if (diathes[i] != NULL) {
			cout << "oi meres einai piasmenes. den mporei na ginei i kratisi." << endl;
			return false;
		}

		else {
			cout << "i mera: " << (i + 1) << " einai diathesimi!" << endl;
		}

	}

	if (k.get_atoma() <= get_max_cap() ) {
		//cout << " ta atoma xwrane sto dwmatio! " << endl;
		//cout << "tester...  " << atoma << " = atoma and maxcap= " << max_cap << endl;
	}
	else {
		cout << "tester...  " << atoma << " = atoma and maxcap= " << get_max_cap() << endl;
		cout << "ta atoma den xwrane sto dwmatio. I kratisi den mporei na ginei dekti" << endl;

		return false;
	}
	 if (k.get_meres() != meres_dianomis) {
			cout << " oi meres diamonis den einai oses prepei. To dwmatio apaitei oi meres diamonis na einai : " << meres_dianomis << "  enw i kratisi dinei : " << k.get_meres() << " meres dianomis." << endl;
			cout << " I kratisi den mporei na ginei dekti. " << endl;
			return false;
		}
	for (int j = (afiksi - 1); j <= counter; j++) {

		diathes[j] = &k;
		cout << " pinakas diathes , ananewthike ." << endl;
	}


	cout << "I kratisi egine me epitixia!" << endl;
	return true;
}