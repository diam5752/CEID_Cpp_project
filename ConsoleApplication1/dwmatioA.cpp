#include "stdafx.h"
#include "dwmatioA.h"
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "kratisi.h"

dwmatioA::dwmatioA()
{
}


dwmatioA::~dwmatioA()
{
}

double dwmatioA::timologisi() {
	cout << endl << "=============================== timologisi A ======================" << endl;
	double total_cost=0;
	int day_count=0;
	double timi_gia_mera = timi_ana_mera;
	
	for (int c = 0; c < 30; c++) {
		if (diathes[c] == NULL) {

		}
		else {
			day_count++;
			
		}
	}
	cout << "timi: "<< timi_gia_mera << endl;
	cout << "meres:" << day_count << endl;
	total_cost = timi_gia_mera*day_count;

	return total_cost;
}



double dwmatioA::get_timi_ana_mera() {
	return timi_ana_mera;
}

void dwmatioA::set_timi_ana_mera(double timi) {
	timi_ana_mera = timi;
}