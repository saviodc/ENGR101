#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include <vector>  // if using vectors 
#include "wav.hpp" // make sure to include this helper library 
// " " instead of <> means that library is in the same folder as your program 
 
using namespace std; 
 
int main(){ 
	int sample_rate = 44100; // samples per second, select value which provides good quality sound  
	double duration=5; // how long [seconds] it will sound 
	int n_samples = sample_rate * duration; // if sound is "duration" seconds long and there are "sample_rate" samples per second 
	double dt = 1/(double)44100; // time between samples 
	int* waveform = new int[n_samples]; // creates the array 
	int frequency= 6900;// pitch of the sound 
	int volume= 690;
	
	for(int i_sample = 0; i_sample < n_samples ; i_sample++){  
		waveform[i_sample] = volume*sin(2* M_PI *frequency * i_sample * dt);// 
	} 
	
	MakeWavFromInt("tone1.wav",sample_rate, waveform, n_samples); 
	delete[] (waveform); 
	return 0;
}
