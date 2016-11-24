#pragma once
#include "IGuitarEffect.h"
#include <vector>

class EffectManager
{
public:
	
	EffectManager() {
	};
	void setEffect(IGuitarEffect* effect) {
		m_effects.emplace_back(effect);
	}
	int applyEffect(double* iData, double* oData, unsigned int bufferSize) {
	//	m_effect->applyEffect(iData, oData, bufferSize);
		
		for (auto& element : m_effects) element->applyEffect(iData, oData, bufferSize);
		
		return 0;
	}
	void deallocateEffects() {
		for (auto element : m_effects)
			delete element;
		m_effects.clear();
	}
	~EffectManager() {
		for (auto element : m_effects)
			delete element;
	}
private:
	std::vector<IGuitarEffect*> m_effects;
};

