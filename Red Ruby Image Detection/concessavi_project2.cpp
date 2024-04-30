#include <iostream>
#include "E101.h"

using namespace std;

/**
 * Checks value of pixel to classify if it is Red.
 * Returns 0 of false and 1 if true.
 */
int getRed(int red, int blue, int green, int row, int col){
	if (red > 1.3 * (green+blue)){
		set_pixel(row, col, 255,0,0);		
		return 1;
	}
	return 0;
}

int main() {
  int err = init(0);
  cout<<"Error: "<<err<<endl;
  open_screen_stream();
  int pre_red, p_col, p_row;
  for (int countrun = 0; countrun < 1000; countrun++) {
	take_picture();
	int totRed = 0;
	int shift_r, shift_c;
	
    // for all pixels in latest image
    for (int row = 0 ; row < 240 ; row++) {	
		for (int col = 0; col < 320; col++) {
			int red, blue, green;
			red = (int)get_pixel(row, col, 0);
			blue = (int)get_pixel(row, col, 1);
			green = (int)get_pixel(row, col, 2);
			if(getRed(red, blue, green, row, col)){
				totRed++;
				shift_r+=row;
				shift_c += col;
			}
		}
	}
	
	if (totRed != 0){
		shift_r /= totRed;
		shift_c /= totRed;
	}
	
	update_screen();

	if (countrun == 0) continue;
	if (countrun > 1){
		if (abs(totRed - pre_red)> 200 || (totRed < 3500 && totRed > 5500)){
			cout<<totRed<<endl;
			cout<<"Ruby tampered with - Red"<<endl;
			return 0;
		}
		
		if (countrun == 7){
			p_col = shift_c;
			p_row = shift_r;
			
		} else if(countrun > 7){
			if(p_col != shift_c || p_row != shift_r) {
				cout<<totRed<<endl;
			cout<<"Ruby tampered with - Shift"<<endl;
			return 0;
			}
		}

		cout<<"Ruby remains"<<endl;

	}else{
		if (totRed >= 3500 && totRed < 5500){
			cout<<"Ruby detected"<<endl;
		}else {
			cout<<totRed<<endl;
			cout<<"No/invalid ruby detected"<<endl;
			return 0;
		}

	}
	
	cout<<" countrun: "<<countrun<<endl<<endl;
	cout<<" Total red: "<<totRed<<endl;
	
	sleep1(100); 
	pre_red=totRed;
	
  }  
  close_screen_stream();
  return 0;
}
