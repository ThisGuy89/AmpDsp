#pragma once
#include "IGuitarEffect.h"
#include "deps/STK/include/Delay.h"

class CombFilter : public IGuitarEffect
{
public:
	CombFilter(int delayTime) {
		m_delay.setDelay(delayTime);
	}
	int applyEffect(double* iData, double* oData, unsigned int bufferSize);
	~CombFilter();

private:
	stk::Delay m_delay;
};

