#pragma once
#include "IGuitarEffect.h"
class CleanEffect :public IGuitarEffect{
public:

	int applyEffect(double* iData, double* oData, unsigned int bufferSize) {
		// We know we only have 1 sample per frame here.
		for (unsigned int i = 0; i < bufferSize; i++) {
			oData[i] = iData[i];
		}
		return 0;
	}
	CleanEffect();
	~CleanEffect();
};

