#pragma once
#include "IGuitarEffect.h"
#include <vector>
#include <fstream>


class EffectManager
{
public:	
	EffectManager();
	void setEffect(IGuitarEffect* effect);
	int applyEffect(double* iData, double* oData, unsigned int bufferSize);
	void deallocateEffects();
	~EffectManager();
private:
	std::vector<IGuitarEffect*> effects_;
	bool streamStarted_ = false;
	std::ofstream inputdata_, outputdata_; // Logging streams
};

