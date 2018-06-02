#include "stdafx.h"
#include "dwmatioB.h"


dwmatioB::dwmatioB()
{
}


dwmatioB::~dwmatioB()
{
}

double dwmatioB::timologisi() {
	cout << endl << "=============================== timologisi B ======================" << endl;
	double dicounted_cost=0;
	int day_counter=0;
	int ekptwsi = get_ekptwsi();
	int timi_ekptwsis = get_ekptwsi();

	cout << "timi an amera= " << get_timi_ana_mera() << endl;

	for (int c = 0; c < 30; c++) {
	
		if (diathes[c] == NULL) {

		}
		else {
			day_counter++;
			if (day_counter > 1) {
				dicounted_cost = dicounted_cost - ekptwsi;
				if ( (dicounted_cost ) < (get_timi_ana_mera()*0.5 ) ) {
					dicounted_cost = get_timi_ana_mera()*0.5;
					 }
			}
			else
			{
				dicounted_cost = get_timi_ana_mera();
			}
			cout << "discounted cost " << dicounted_cost << endl;
		}
	}
	

	return dicounted_cost;

}

void dwmatioB::set_eptwsi(double ekptwsi) {
	if(ekptwsi > get_timi_ana_mera()/2 ){
		cout << "den mporeis na vales ekptwsi panw apo 50%" << endl;
		cout << "Thetw tin ekptwsi stin megisti dinati timi tis, diladi sta 50%" << endl;
		ekptwsi_ana_mera = get_timi_ana_mera() / 2;
	}
	else {
		ekptwsi_ana_mera = ekptwsi;
	}
}

double dwmatioB::get_ekptwsi() {
	return ekptwsi_ana_mera;
}

bool dwmatioB::akirwsi(int &krat_id) {
	cout << endl << "========================= akrirwsi B=============================" << endl;
	cout << "den mporei na ginei akirwsi sto dwmatioB" << endl;
	return false;
}


double dwmatioB::get_ekptwsi_ana_mera() {
	return ekptwsi_ana_mera;
}
void dwmatioB::set_ekptwsi_ana_mera(double ekptwsi) {
	ekptwsi_ana_mera = ekptwsi;
}