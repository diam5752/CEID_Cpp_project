#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <list>
#include "dwmatio.h"
#include "kratisi.h"
#include "ksenodoxeio.h"
#include "dwmatioA.h"
#include "dwmatioB.h"
#include "dwmatioC.h"

using namespace std;


ksenodoxeio::ksenodoxeio()
{
}

ksenodoxeio::~ksenodoxeio()
{
}

void ksenodoxeio::prosthiki_dwmatiou_se_lista(dwmatio &d) {
	cout << endl << "================= prosthiki dwmatiou se lista =============" <<endl<< endl;
	Ld.push_back(&d);
	cout << " to dwmatio protethike sti lista me epitixia " << endl;
}

void ksenodoxeio::prosthiki_kratisis_se_lista(kratisi &k) {
	cout <<endl <<"================= prosthiki kratisis se lista =============" << endl << endl;
	Lk.push_back(&k);
//	cout << " AAAAA " << Lk.front()->krat_id << endl;
	cout << "i kratisi mpike st lista me epitixia!" << "  onoma kratisis : "<< k.get_onoma() << endl;
	cout << " neo megethos listas : " << Lk.size() << endl;

	

}

dwmatio* ksenodoxeio::anaktisi_dwmatiou_apo_kwdiko(int &kwd_dwm) {
	cout << "================= anaktisi kwdikou dwmatiou apo lista =============" << endl << endl;

	list<dwmatio*>::iterator  ite;
	dwmatio* d;
	
	if (Ld.empty() == 1) { cout << " i lista einai adeia " << endl;  return NULL; }
	for (ite = Ld.begin(); ite != Ld.end(); ++ite) {
		if ( (*ite)->dwm_id == kwd_dwm ) {
			cout << "to dwmatio iparxei sti lista. Tha epistrepsw to antikeimeno ."<< endl;
			
			d = (*ite);
			
			return d;
		}
		
		}

	return NULL;
	}

kratisi* ksenodoxeio::anaktisi_kratisis_apo_kwdiko(int &kwd_krat) {
	cout << "================= anaktisi kwdikou kratisis apo lista =============" << endl << endl;
	list<kratisi*>::iterator  iter;
	kratisi k ;
	kratisi* pk = &k;
	cout << " megethos listas kratisewn : " << Lk.size() << endl;
	cout << " kwdikos kratisis pou theloume na akirwsoume : " << kwd_krat << endl;
	for (iter = Lk.begin(); iter != Lk.end(); iter++) {
		cout << " current kwdikos : " << (*iter)->krat_id << endl;
		if ( (*iter)->krat_id == kwd_krat) {
			cout << "i kratisi iparxei sti lista. Tha epistrepsw to antikeimeno ." << endl;
			//*pk = *iter;
			//pk = iter;
			return (*iter);
		}
		else {
			cout << "i kratisi den iparxei sti lista. ." << endl;

		}
	}
	return NULL;

}


bool ksenodoxeio::prosthiki_kratisis_se_dwmatio(kratisi &k, int &kwd_dwm) {
	cout << "================= kratisi se dwmatio =============" << endl << endl;
	dwmatio* dwm = new dwmatio ;
	dwmatio* checker;
	
	checker = anaktisi_dwmatiou_apo_kwdiko(kwd_dwm);
	
	if (checker == NULL) {
	
		bool  krat_checker = dwm->prosthiki_kratisis(k);
		if (krat_checker != 0) {
			cout << "i kratisi  se dwmatio  egine me epitixia!!!!!!!!!  sto onoma : "<< k.get_onoma() << endl;
			prosthiki_kratisis_se_lista(k);
		
			return true;
		}
	}
	else {
		dwm = checker;
		bool  krat_checker = dwm->prosthiki_kratisis(k);
		if (krat_checker != 0) {
			cout << "i kratisi se dwmatio egine me epitixia!!!!    sto onoma :    " << k.get_onoma()  << endl;
		
			prosthiki_kratisis_se_lista(k);
		
			return true;
		}
	}
	

		cout << "i kratisi den egine..." << endl;
	return false;
	

}


int ksenodoxeio::Prosthiki_Kratisis(kratisi &k) {
	cout << "=================== PROSTHIKI KRATISIS ======================" << endl;

	cout <<" arithmos dwmatiwn :" <<Ld.size() << endl;
	cout << "arithmos kratisewn :" << Lk.size() << endl;

	for (list<dwmatio*>::iterator it = Ld.begin(); it != Ld.end(); it++ ) {
		if ((*(*it)).prosthiki_kratisis(k) == 1) {
			cout << " kwdikos dwmatiou : " << (*(*it)).dwm_id << endl;
			cout << " kratisi id : " << k.krat_id << endl;
			prosthiki_kratisis_se_lista(k);
		}
		else cout << " den mporei na ginei i kratisi se auto to dwmatio ..." << endl;

	}

	return 0;
}

void ksenodoxeio::akirwsi_kratisis(int &kwd_krat) {
	cout << " ===================================================== AKIRWSI KRATISIS ========================================" << endl;
	kratisi* krat = new kratisi;
	kratisi* to_remove = new kratisi;

	if (anaktisi_kratisis_apo_kwdiko(kwd_krat) == NULL) {
		cout << "den vrethike i kratisi ...." << endl;
		return;
	}
	else { krat = anaktisi_kratisis_apo_kwdiko(kwd_krat); }
	
	if (krat->p_dwmatio->akirwsi(kwd_krat)  ==1 ) {
		cout << " egine i akirwsi!" << endl;
		
		for (list<kratisi*>::iterator it = Lk.begin(); it != Lk.end(); it++ ) {
			if ( (*it)->krat_id == kwd_krat  ) {
				cout << " to remove : " << (*it)->get_onoma() << endl;
				(*it) = to_remove;
			}
		}
		cout << " list size befroe remove :" << Lk.size() << endl;
		Lk.remove(to_remove);
		cout << " list size after remove :" << Lk.size() << endl;
	}
	

}


int ksenodoxeio::ipologismos_esodwn(int kwd_dwm)
{
	cout << "============================= IPOLOGISMOS ESODWN  =======================" << endl;
	dwmatio* dwm = new  dwmatio;
	dwmatio* checker = new dwmatio;
	checker = anaktisi_dwmatiou_apo_kwdiko(kwd_dwm);
	dwm = checker;
	
	if (checker == NULL ) {
		cout << " to dwmatio me den iparxei ..." << endl;
		return 0;
	}
	else {
		for (int l = 0; l < 30; l++) {
			cout << "diathesim : " << dwm->diathes[l] << endl;
		
		}
		
		cout << " esoda : " <<dwm->timologisi() << endl;
		return dwm->timologisi();
	}

}


int ksenodoxeio::ipologismos_esodwn() {
	cout << " ==========================  IPOLOGISMOS SINOLIKWN ESODWN =====================" << endl;
	int sum = 0;
	for (list<dwmatio*>::iterator it = Ld.begin(); it != Ld.end(); it++ ) {
		sum = sum + (*it)->timologisi();
		cout << "curent sum :" << sum << endl;
	}

	
	return sum;
}


void ksenodoxeio::plano_kratisewn() {
	cout << "======================================== PLANO KRATISEWN  =====================================" << endl << endl;

	cout << "Dwmatio    ";
	for (int i = 1; i <= 30; i++) {
		if ( i < 10) { cout << "  0" << i; }
		else { cout << "  " << i; }

	}

	cout << endl;


	for (list<dwmatio*>::iterator it = Ld.begin(); it != Ld.end(); it++ ) {
		cout << (*(*it)).dwm_id << "    ";
		for (int i = 0;  i < 30; i++) {
			if (i == 0) { cout << "        "; }
			if ((*(*it)).diathes[i] == NULL) {
				cout << "-   ";
			}
			else { cout << "*   "; }
		}
		cout << endl;
	}
	
}



string ksenodoxeio::get_onoma() {
	return onoma;
}
void ksenodoxeio::set_onoma(string name) {
	onoma = name;
}