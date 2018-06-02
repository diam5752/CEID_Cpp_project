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


class kratisi
{
public:
	kratisi();
	~kratisi();
	void anathesi(dwmatio &d);

	kratisi(const kratisi& orig) ;
	kratisi& operator=(const kratisi& orig);
	int krat_id;  
	
	void set_onoma(string name);
	string get_onoma();

	void set_afiksi(int afiks);
	int get_afiksi();

	void set_meres( int day);
	int get_meres();

	void set_atoma(int guys);
	int get_atoma();
//private:
	
	
	dwmatio* p_dwmatio = new dwmatio;

private:
	int atoma;
	int afiksi;
	int meres;
	string onoma;
	static int kwd_krat;
};

