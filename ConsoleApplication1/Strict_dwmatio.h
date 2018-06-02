#pragma once
#include "dwmatio.h"


class Strict_dwmatio :
	public dwmatio
{
public:
	Strict_dwmatio();
	~Strict_dwmatio();

	bool prosthiki_kratisis(kratisi& k);
	int meres_dianomis;
};

