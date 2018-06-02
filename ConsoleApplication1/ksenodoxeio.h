#pragma once
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


class ksenodoxeio
{
public:
	ksenodoxeio();
	~ksenodoxeio();

	list< dwmatio* > Ld;
	list< kratisi* > Lk;

	void  prosthiki_dwmatiou_se_lista(dwmatio &d);
	void prosthiki_kratisis_se_lista(kratisi &k);
	dwmatio* anaktisi_dwmatiou_apo_kwdiko(int &kwd_dwm);
	kratisi* anaktisi_kratisis_apo_kwdiko(int &kwd_krat);
	 bool prosthiki_kratisis_se_dwmatio(kratisi &k, int &kwd_dwm);
	 int Prosthiki_Kratisis(kratisi &k);
	 void akirwsi_kratisis(int &kwd_krat);
	 int ipologismos_esodwn(int kwd_dwm);
	 int ipologismos_esodwn();
	 void plano_kratisewn();

	 string get_onoma();
	 void set_onoma(string name);
private:
	string onoma;
};

