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

void kratisi::anathesi(dwmatio &d) {
	p_dwmatio = &d;

}

int kratisi::kwd_krat = 1;

kratisi::kratisi()
{
	krat_id =kwd_krat++;
	p_dwmatio = NULL;
	
}
kratisi::kratisi(const kratisi& orig) {
	krat_id = orig.krat_id;
}
kratisi& kratisi::operator=(const kratisi& orig) {
	krat_id = orig.krat_id;
	return(*this);
}

kratisi::~kratisi()
{

}

void kratisi::set_onoma(string name) {
	onoma = name;
}
string kratisi::get_onoma() {
	return onoma;
}

void kratisi::set_afiksi(int afiks) {
	afiksi = afiks;
}
int kratisi::get_afiksi() {
	return afiksi;
}

void kratisi::set_meres(int day) {
	meres = day;
}
int kratisi::get_meres() {
	return meres;
}

void kratisi::set_atoma(int guys) {
	atoma = guys;
}
int kratisi::get_atoma() {
	return atoma;
}