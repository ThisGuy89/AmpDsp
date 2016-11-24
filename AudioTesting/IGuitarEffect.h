#pragma once
#include "deps\STK\include\Stk.h"
#include "deps\STK\include\RtAudio.h"

class IGuitarEffect
{
public:
	IGuitarEffect()
	{
	};
	virtual int applyEffect(double* iData, double* oData, unsigned int bufferSize) = 0;
	virtual ~IGuitarEffect();

};

