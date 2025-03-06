#include <iostream> // input-output library
#include <math.h>  // library for sin function
#include <vector>  // if using vectors
#include "wav.hpp" // make sure to include this helper library
#include <fstream>
#include <string>

using namespace std;

int main(){
	int volume = 3000;
	vector<int> waveform;
	int sample_rate = 44100;
	int freq = 400;
	double dt = 1 / (double)sample_rate;
	for(int i = 0; i < sample_rate; i++){
		double thisVolume;
		if(i < 1000){
		thisVolume = i * (volume /1000.0);
	}else{
		thisVolume = (44100 - i) * (volume / (44100.0-1000));
	}
		double ti = i * dt;
		double val = thisVolume*sin(2*M_PI*freq*ti);
		waveform.push_back(val);
	}
	
	MakeWavFromVector("piano.wav",sample_rate, waveform);
	waveform.clear();
	return 0;
	
}
