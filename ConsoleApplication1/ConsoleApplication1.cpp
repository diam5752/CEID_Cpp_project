// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "kratisi.h"
#include "dwmatio.h"
#include "ksenodoxeio.h"
#include "dwmatioA.h"
#include "dwmatioB.h"
#include "dwmatioC.h"
#include "VIP_dwmatio.h"
#include "Strict_dwmatio.h"

using namespace std;

void arxiki_katastasi_menu(ksenodoxeio& k) {
	cout << "=============================================================== Arxiki katastasi  :" << endl << endl ;
	

	int akirwsi = rand() % 4 + 1;
	cout << "akirwsi = " << akirwsi << endl;
	if (akirwsi == 1) {
		cout << "tha iparksei akirwsi ..." << endl;
		int rand_stopper;
		if (k.Lk.size() != 0) { rand_stopper = rand() % k.Lk.size(); }
		else { rand_stopper = 0; }
		cout << "rand stoper = " << rand_stopper << endl;
		int counter = 0;
		for (list<kratisi*>::iterator it = k.Lk.begin(); it != k.Lk.end(); it++) {
			cout << "counter = " << counter << endl;
			if (counter == rand_stopper) {
				k.akirwsi_kratisis((*it)->krat_id);
				break;
			}
			counter++;
		}
	}
}

kratisi* user_krat( kratisi& krat) {
	//kratisi krat;
	int temp, chooser, chosen_id;
	int afiks, meres, atoma;
	string onoma;

	cout << "Dwste Onoma : " << endl;
	cin >> onoma;
	krat.set_onoma(onoma);
	cout << " Afiksi :" << endl;
	cin >> afiks;
	krat.set_afiksi(afiks);
	cout << "Meres : " << endl;
	cin >> meres;
	krat.set_meres(meres);
	cout << " Atoma : " << endl;
	cin >> atoma;
	krat.set_atoma(atoma);
	return &krat;
}

void prostihi_kratisis_menu(ksenodoxeio &k , kratisi& krat) {
	
	int temp, chooser, chosen_id;
	int afiks, meres, atoma;
	string onoma;

	cout << " Kwdikos dwmatiou : (an den thelete na dwsete pliktrologiste -1 )" << endl;
	cin >> temp;
	if ( temp == -1 ) {
		chooser = rand() % k.Ld.size()  ;
		int counter = 0;
		cout << chooser << " chooser " << endl;
		for (list<dwmatio*>::iterator it = k.Ld.begin(); it != k.Ld.end(); it++ ) {
			if (counter == chooser) {
				chosen_id = (*it)->dwm_id;
				break;
			}
			counter++;
		}
		
		k.prosthiki_kratisis_se_dwmatio(krat,chosen_id);
		//k.prosthiki_kratisis_se_lista(krat);
	
	}
	else {

		k.prosthiki_kratisis_se_dwmatio(krat, temp);
		k.prosthiki_kratisis_se_lista(krat);
	
	}
}

void akirwsi_kratisis_menu(ksenodoxeio &k) {
	int kwd_krat;
	cout << " Akirwsi kratisis apo menu :" << endl;
	cout << "Dwse ton kwdiko tis kratisis pou thes na akirwthei : " << endl;
	cin >> kwd_krat;
	k.akirwsi_kratisis(kwd_krat);
}

void provoli_menu() {
	cout << endl << endl << " =============================================================================" << endl << endl;
	cout << " Epilekste me ton antistoixo arithmo, ti thelete na kanete : " << endl;
	cout << " Menu: " << endl;
	cout << " 1. Epomeni Epanalipsi." << endl;
	cout << " 2. Prosthiki Kratisis." << endl;
	cout << " 3. Akirwsi Kratisis." << endl;
	cout << " 4. Provoli Kratisewn." << endl;
	cout << " 5. Provoli Dwmatiwn." << endl;
	cout << " 6. Provoli Planou Kratisewn." << endl;
	cout << " 7. Provoli Esodwn." << endl;
	cout << " 8. Termatismos Programmatos." << endl;
}

void provoli_kratisewn(ksenodoxeio& k) {
	cout << "Kwdikos kratisis    |    Onoma Pelati    |    Kwdikos Dwmatiou    " << endl;
	cout << "____________________|____________________|__________________________" << endl;

	for (list<kratisi*>::iterator it = k.Lk.begin(); it != k.Lk.end(); it++) {
		cout << "        "<<(*it)->krat_id << "           |       " << (*it)->get_onoma() << "     |      " << (*it)->p_dwmatio->dwm_id << endl;
	}

}

void provoli_dwmatiwn(ksenodoxeio& k) {
	cout << "Kwdikos Dwmatiou    |    Plirotita       |           Esoda          " << endl;
	cout << "____________________|____________________|__________________________" << endl;

	for (list<dwmatio*>::iterator it = k.Ld.begin(); it != k.Ld.end(); it++) {
		cout << "        " << (*it)->dwm_id << "           |       " << (*it)->plirotita() << "     |      " << (*it)->timologisi() << endl;
	}

}

void provli_esodwn_menu(ksenodoxeio& k) {
	int chooser;
	cout << " Kwdikos dwmatiou : (an dn thes na dwseis sigkekrimeno kwdiko, pliktrologise -1)" << endl;
	cin >> chooser;

	if (chooser==-1) {
		k.ipologismos_esodwn();
	}
	else {
		for (list<dwmatio*>::iterator it = k.Ld.begin(); it != k.Ld.end(); it++) {
			if ((*it)->dwm_id == chooser ) {
				cout << " esoda dwmatiou me kwdiko :" << chooser << " einai :" << (*it)->timologisi() << endl;
			}
		}
	}
}

int si = 0;
kratisi* rand_kratisi(kratisi &krat0) {

	string onoma;
	string p = "pelatis";
	
	int afiksi, meres, atoma;

	afiksi = rand() % 30 + 1;
	krat0.set_afiksi(afiksi);
	atoma = rand() % 8 + 1;
	krat0.set_atoma(atoma);
	meres = rand() % 3 + 1;
	krat0.set_meres(meres);
	onoma = p + to_string(si);
	krat0.set_onoma(onoma);
	si++;
	return &krat0;
}


int main()
{
	int max_cap;
	int timi_ana_atomo , elaxista_atoma , elaxistes_meres;
	double ekptwsi_ana_mera , timi_ana_mera;
ksenodoxeio k;

dwmatio dwm;
max_cap = 10;
dwm.set_max_cap(max_cap);
timi_ana_atomo = 40;
dwm.set_timi_ana_atomo(timi_ana_atomo);
k.prosthiki_dwmatiou_se_lista(dwm);

dwmatioA dwmA;
max_cap = 10;
dwmA.set_max_cap(max_cap);
timi_ana_atomo = 35;
dwmA.set_timi_ana_atomo(timi_ana_atomo);
timi_ana_mera = 20;
dwmA.set_timi_ana_mera(timi_ana_mera);
k.prosthiki_dwmatiou_se_lista(dwmA);

dwmatioB dwmB;
max_cap = 8;
dwmB.set_max_cap(max_cap);
timi_ana_atomo = 45;
dwmB.set_timi_ana_atomo(timi_ana_atomo);
ekptwsi_ana_mera = 10;
dwmB.set_ekptwsi_ana_mera(ekptwsi_ana_mera);
k.prosthiki_dwmatiou_se_lista(dwmB);

dwmatioC dwmC;
elaxista_atoma = 3;
dwmC.set_elaxista_atoma(elaxista_atoma);
elaxistes_meres = 4;
dwmC.set_elaxistes_meres(elaxistes_meres);
max_cap = 5;
dwmC.set_max_cap(max_cap);
timi_ana_atomo = 15;
dwmC.set_timi_ana_atomo(timi_ana_atomo);
k.prosthiki_dwmatiou_se_lista(dwmC);

Strict_dwmatio dwmS;
k.prosthiki_dwmatiou_se_lista(dwmS);
max_cap = 4;
dwmS.set_max_cap(max_cap);
dwmS.meres_dianomis = 5;
timi_ana_atomo = 20;
dwmS.set_timi_ana_atomo(timi_ana_atomo);

VIP_dwmatio dwmV;
k.prosthiki_dwmatiou_se_lista(dwmV);
max_cap = 3;
dwmV.set_max_cap(max_cap);
timi_ana_atomo = 17;
dwmV.set_timi_ana_atomo(timi_ana_atomo);

dwmatio dwm2;
k.prosthiki_dwmatiou_se_lista(dwm2);
max_cap = 4;
dwm2.set_max_cap(max_cap);
timi_ana_atomo = 20;
dwm2.set_timi_ana_atomo(timi_ana_atomo);


dwmatioA dwmA2;
max_cap = 3;
dwmA2.set_max_cap(max_cap);
timi_ana_atomo = 10;
dwmA2.set_timi_ana_atomo(timi_ana_atomo);
timi_ana_mera = 15;
dwmA2.set_timi_ana_mera(timi_ana_mera);
k.prosthiki_dwmatiou_se_lista(dwmA2);

dwmatioB dwmB2;
ekptwsi_ana_mera = 5;
dwmB2.set_ekptwsi_ana_mera(ekptwsi_ana_mera);
max_cap = 3;
dwmB2.set_max_cap(max_cap);
timi_ana_atomo = 40;
dwmB2.set_timi_ana_atomo(timi_ana_atomo);
timi_ana_mera = 35;
dwmB2.set_timi_ana_mera(timi_ana_mera);
k.prosthiki_dwmatiou_se_lista(dwmB2);

dwmatioC dwmC2;
elaxista_atoma = 6;
dwmC2.set_elaxista_atoma(elaxista_atoma);
elaxistes_meres = 10;
dwmC2.set_elaxistes_meres(elaxistes_meres);
max_cap = 20;
dwmC2.set_max_cap(max_cap);
timi_ana_atomo = 6;
dwmC2.set_timi_ana_atomo(timi_ana_atomo);
k.prosthiki_dwmatiou_se_lista(dwmC2);

Strict_dwmatio dwmS2;
max_cap = 5;
dwmS2.set_max_cap(max_cap);
dwmS2.meres_dianomis = 6;
timi_ana_atomo = 19;
dwmS2.set_timi_ana_atomo(timi_ana_atomo);
k.prosthiki_dwmatiou_se_lista(dwmS2);

VIP_dwmatio dwmV2;
max_cap = 2;
dwmV2.set_max_cap(max_cap);
timi_ana_atomo = 8;
dwmV2.set_timi_ana_atomo(timi_ana_atomo);
k.prosthiki_dwmatiou_se_lista(dwmV2);

cout << " ksenodoxeio list : " << k.Ld.size() << endl;
srand(time(NULL));

kratisi* krat0 = new kratisi;
krat0 = rand_kratisi( *krat0);
k.Prosthiki_Kratisis(*krat0);

	arxiki_katastasi_menu(k); 

while (1) {
	provoli_menu();
	
	int l;
	cin >> l;
	
	switch (l) {
	case 1: { 
		kratisi* krat0 = new kratisi;
		krat0 = rand_kratisi(*krat0);
		k.Prosthiki_Kratisis(*krat0);
		arxiki_katastasi_menu(k); }break;
	case 2: {
		kratisi* krat = new kratisi;
		krat = user_krat( *krat);
		prostihi_kratisis_menu(k , *krat); 		
	} break;
	case 3:  akirwsi_kratisis_menu(k); break;
	case 4:  provoli_kratisewn(k); break;
	case 5:  provoli_dwmatiwn(k); break;
	case 6:  k.plano_kratisewn(); break;
	case 7:  provli_esodwn_menu(k); break;
	case 8:  exit(0); break;
	}
}

	return 0;
}

         