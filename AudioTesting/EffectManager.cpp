#include "EffectManager.h"

EffectManager::EffectManager() {
	inputdata_.exceptions(std::ofstream::failbit);
	outputdata_.exceptions(std::ofstream::failbit);
}
void EffectManager::setEffect(IGuitarEffect* effect) {
	effects_.emplace_back(effect);
}
int EffectManager::applyEffect(double* iData, double* oData, unsigned int bufferSize) {
	// Apply effects
	for (auto& element : effects_) element->applyEffect(iData, oData, bufferSize);

	//// Log I/O	
	//if (!streamStarted_) {
	//	streamStarted_ = true;
	//	try {
	//		inputdata_.open("..\\python_plots\\Inputstream.txt");
	//		outputdata_.open("..\\python_plots\\Outputstream.txt");
	//	}
	//	catch (std::fstream::failure &open_error) {
	//		std::cerr << "\n\n Exception occured when opening a file\n" << open_error.what() << std::endl;
	//		return 0;
	//	}
	//}

	//if (inputdata_.is_open() && outputdata_.is_open()) {
	//	for (unsigned int i = 0; i < bufferSize; i += 30) {
	//		inputdata_ << iData[i]  << std::endl;
	//		outputdata_ << oData[i] << std::endl;
	//	}
	//}
	//else {
	//	std::cout << "Error opening file" << std::endl;
	//}
	return 0;
}
void EffectManager::deallocateEffects() {
	for (auto element : effects_)
		delete element;
	effects_.clear();
}
EffectManager::~EffectManager() {
	for (auto element : effects_)
		delete element;

	inputdata_.close();
	outputdata_.close();
}
