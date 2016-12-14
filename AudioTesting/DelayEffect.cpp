#include "DelayEffect.h"



DelayEffect::DelayEffect() {
	
	sample_cntr_ = 0; // buffer counter
	sampleRate_ = 44100; // default sample rate
	gain_ = 0.65; // default gain
	
	MAX_DLY_TIME_ = 256*(400); // 
	dlyTime_ = 400; // default delay

	samples_ = new double[MAX_DLY_TIME_];

	for (int i = 0; i < MAX_DLY_TIME_; i++)
	{
		samples_[i] = 0;		
	}
}

DelayEffect::~DelayEffect()
{
	delete samples_;
}


int DelayEffect::applyEffect(double* iData, double * oData, unsigned int bufferSize) 
{	
	// Process data
	// Add delay out(n) = in(n) + gain*out(n-m), where m = delaytime in samples
	int dlySamples = floor((dlyTime_/1000) * sampleRate_); // Number of samples in delay time	
	int dlypos; // position of delaysignal in delay buffer	
	int currpos; // real time position in delay buffer
	for (unsigned int i = 0; i < bufferSize; i++){
		
		currpos = bufferSize*sample_cntr_ + i;
		dlypos= currpos - dlySamples;
		if (dlypos< 0){			
			// Index less than zero, go to 'end' of buffer to find older samples.
			dlypos= MAX_DLY_TIME_ - dlySamples + currpos;
		}		

		// Update delay buffer. Load oData to delaybuffer to replace the oldest data in buffer.		
		oData[i] = 0.5*(iData[i]+ gain_*samples_[dlypos]);
		samples_[currpos] = oData[i];
	}
	
	//Increment buffer counter
	sample_cntr_ += 1;
	
	//Reset buffer counter
	if (sample_cntr_ >= MAX_DLY_TIME_ / 256){
		sample_cntr_ = 0;
	}	
	
	return 0;
}


void DelayEffect::set_gain_(double gain)
{
	gain_ = gain;
}

void DelayEffect::set_dlyTime_(double dlyTime)
{
	dlyTime_ = dlyTime;

}

int DelayEffect::get_gain_()
{
	return gain_;
}
int DelayEffect::get_dlyTime_()
{
	return dlyTime_;
}