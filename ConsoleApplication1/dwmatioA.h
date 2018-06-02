#pragma once
#include "dwmatio.h"
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


class dwmatioA :
	public dwmatio
{
public:
	dwmatioA();
	~dwmatioA();

	double timologisi();

	double get_timi_ana_mera();
	void set_timi_ana_mera(double timi);

	

private:
	double timi_ana_mera;
	
};

