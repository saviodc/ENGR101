#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include "wav.hpp" // make sure to include this helper library 

using namespace std; 

int main(){
	int volume = 690;
	int freq1 = 1500;
	int freq2 = 1000;
	int sample_rate = 44100;
	int dur = 4;
	double dt = 1 / (double) sample_rate;
	int totalSamps = dur * sample_rate;
	int * waveform = new int[totalSamps];
	for(int i = 0 ; i < dur * 4; i++){
		int freqNow;
		if(i % 2) freqNow = freq1;
		else freqNow = freq2;
		for(int j = 0; j < (44100 / 4); j++){
				int calculated_value = volume*sin(2* M_PI *freqNow * (j + ((44100 / 4) *i)) * dt);
				waveform[j + ((44100 / 4) *i)] = calculated_value;
		}
	}
	   MakeWavFromInt("toneComp.wav",sample_rate, waveform, totalSamps); //file name can be changed but keep extension .wav 
	   delete[] (waveform); //if using array 
	   return 0; 
}
