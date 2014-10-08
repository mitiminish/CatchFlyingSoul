#include "GV.h"
#include <math.h>
//“®‚«‚Ü‚¹‚ñ
void bar_pattern0(int i){
	return;
}

//‰º‚É‚ä‚Á‚­‚è‰º‚è‚Ä‚«‚Ü‚·
void bar_pattern1(int i){
	int t=bar[i].cnt;
	if(t==0)
		bar[i].vy+=1;
}

void bar_pattern2(int i){
	int t=bar[i].cnt;
	if(t==0)
		bar[i].vy-=1;
}

 void bar_pattern3(int i)
{
	
	bar[i].vx=-2.0;
 
}

 void bar_pattern4(int i){
	 bar[i].vx=+2.0;
 }
 
 void bar_pattern5(int i){
	 static int cnt=0;
	 float spd=0.5f;
	 if((cnt%100)/50==0){
		 bar[i].vy=+spd;
	 }else{
		 bar[i].vy=-spd;
	 }
	 cnt++;
 }
 

 void bar_pattern6(int i){
	int t=bar[i].cnt;
	bar[i].vy=sin((PI/100.0)*t);
	bar[i].vx=-2.0;
 }


