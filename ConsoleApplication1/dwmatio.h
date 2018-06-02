#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "dwmatio.h"



using namespace std;

class kratisi;

class dwmatio
{
public:
	dwmatio();
	~dwmatio();
	dwmatio(const dwmatio& orig);
	dwmatio& operator=(const dwmatio& orig);
	int dwm_id;

	bool prosthiki_kratisis(kratisi& k);
	double timologisi();
	bool akirwsi(int &kwd_krat);
	string plirotita();
	
	void set_max_cap(int cap);
	int get_max_cap();

	void set_timi_ana_atomo(double timi);
	double get_timi_ana_atomo();
//private:
	

	kratisi* diathes[30]{0};


private:
	double timi_ana_atomo;
	int max_cap;
	static int kwd_dwm ;
};



