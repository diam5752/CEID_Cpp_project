#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "kratisi.h"
#include "dwmatio.h"

using namespace std;

int dwmatio::kwd_dwm = 1;
dwmatio::dwmatio()
{
	dwm_id = kwd_dwm++;
}
dwmatio::dwmatio(const dwmatio& orig) {
	dwm_id = orig.dwm_id;
}
dwmatio& dwmatio::operator=(const dwmatio& orig) {
	dwm_id = orig.dwm_id;
	return(*this);
}

bool dwmatio::prosthiki_kratisis(kratisi &k ) {
	cout <<endl<< "=============================== stoixeia kratisis =======================" << endl;
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

	int counter = afiksi -1 + meres -1; // xrisimopoioume stin for gia na kseroume pou na stamatisei to i
	for (int i = (afiksi -1 ); i<=counter ; i++ ) {
			if (diathes[i] != NULL) {
				cout << "oi meres einai piasmenes. den mporei na ginei i kratisi." << endl;
				return false;
			}
			
			else {
				cout << "i mera: " << (i+1) << " einai diathesimi!" << endl;
			}
		
		}
	
	if (k.get_atoma() <= this->max_cap) { 
		//cout << " ta atoma xwrane sto dwmatio! " << endl;
		//cout << "tester...  " << atoma << " = atoma and maxcap= " << max_cap << endl;
	}
	else { 
		cout << "tester...  " << atoma <<" = atoma and maxcap= " << max_cap << endl;
		cout << "ta atoma den xwrane sto dwmatio. I kratisi den mporei na ginei dekti" << endl;

	return false;
	}
	for (int j = (afiksi -1  ); j <= counter; j++) {
	
		diathes[j] = &k;
		cout << " pinakas diathes , ananewthike ." << endl;
	}
	

	cout << "I kratisi egine me epitixia!" << endl;
	return true;
}


double dwmatio::timologisi() {
	double sum=0;
	//cout <<endl<< "=============================== timologisi ======================" << endl;

	for (int c = 0; c < 30; c++) {
		if (diathes[c]==NULL ) {
			sum = sum + 0;
		}
		else {
			int atoma = diathes[c]->get_atoma();
			sum = sum + atoma*timi_ana_atomo;
		}
	}
	return sum;
}

bool dwmatio::akirwsi(int &krat_id) {
	cout<<endl << "========================= akrirwsi =============================" << endl;
	for (int h = 0; h < 30; h++) {
		if (diathes[h] == NULL) {}
		else {
			cout << "current kwdikos kratisis:" << diathes[h]->krat_id << endl;
			if (diathes[h]->krat_id == krat_id){
				diathes[h] = NULL;
			}
		}
       }
	return true;
}


string dwmatio::plirotita() {
	string s="s";
	int counter=0;
	int percent;
	for (int p = 0; p < 30; p++) {
		if (diathes[p] != NULL) {
			//if (diathes[p]->p_dwmatio->dwm_id != dwm_id) {
			//cout << dwm_id << endl;
			//cout << diathes[p]->p_dwmatio->dwm_id << endl;
				counter++;
			//	cout << counter << endl;
			//}
		}
	}
	percent = 100 * counter / 30;
	s = to_string(percent) + "%" ;
	//cout << "percent:" << s << endl;
	return s;
}

dwmatio::~dwmatio()
{
}

void dwmatio::set_max_cap(int cap) {
	max_cap = cap;
}
int dwmatio::get_max_cap() {
	return max_cap;
}

void dwmatio::set_timi_ana_atomo(double timi) {
	timi_ana_atomo = timi;
}
double dwmatio::get_timi_ana_atomo() {
	return timi_ana_atomo;
}


