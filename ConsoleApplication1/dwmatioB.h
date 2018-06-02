#pragma once
#include "dwmatioA.h"
class dwmatioB :
	public dwmatioA
{
public:
	dwmatioB();
	~dwmatioB();
	double timologisi();
	
	void set_eptwsi(double ekptwsi);
	double get_ekptwsi();
	bool akirwsi(int &kwd_krat);

	double get_ekptwsi_ana_mera();
	void set_ekptwsi_ana_mera(double ekptwsi);


private:
	double ekptwsi_ana_mera;
};

