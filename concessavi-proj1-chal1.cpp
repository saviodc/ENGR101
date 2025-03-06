#include <iostream> // input-output library
#include <math.h>  // library for sin function
#include <vector>  // if using vectors
#include "wav.hpp" // make sure to include this helper library
#include <fstream> //allows for file input/output
#include <string> 	//String use
using namespace std;

int main(){
	//setting values for sound formula
	int volume = 3000;
	int sample_rate = 44100;
	double dt = 1 / (double)sample_rate;
	//declare wave vector
	vector<int> waveform;
	//decide text input to use - can be set to any txt file
	string str = "odetojoy.txt";
	ifstream myfile(str);
	//reports and returns if failure with loading file
	if(myfile.fail()){
		cout<<"Failure" << endl;
		return 1;
	}
	//what iteration we are in
	int i = 0;
	while(!myfile.eof()){
		string temp;
		getline(myfile, temp);
			double freq = stod(temp);
			double peakPoint = 750; //peak of attack phase
			//j loop for samples in a note - each note lasts less than a second		
			for(int j= 0; j < 30000; j++){
				double ti = i*dt;
				double thisVolume;
				//the logic below makes the sound not have clicks
				//but more importantly imitates a piano note with an early peak point and a long decay
				if (j < peakPoint){
					thisVolume = (j / peakPoint) * volume;
				}else {
					thisVolume = ((30000 - j) / (30000 - peakPoint)) * volume;
				}
				int val = thisVolume*sin(2*M_PI*freq*ti);
				waveform.push_back(val);
				i++; //move through iteration
		}

	}
	MakeWavFromVector("chalSong.wav",sample_rate, waveform);
	waveform.clear();
	return 0;
}
