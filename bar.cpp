#include "GV.h"
extern void bar_pattern0(int i);
extern void bar_pattern1(int i);
extern void bar_pattern2(int i);
extern void bar_pattern3(int i);
extern void bar_pattern4(int i);
extern void bar_pattern5(int i);

void (*bar_pattern[BAR_PATTERN_MAX])(int)={
	bar_pattern0,bar_pattern1,
	bar_pattern2,bar_pattern3,
	bar_pattern4,bar_pattern5,
};



int getEmptyBar(){
	for(int i=0;i<BAR_MAX;i++){
		if(bar[i].flag==0){
			static bar_t barZero;
			bar[i]=barZero;
			return i;
		}
	}
	return -1;
}



void bar_enter(){
	int k;
	if(game_cnt==0){

		if((k=getEmptyBar())!=-1){
			bar[k].x=0;
			bar[k].y=380;
			bar[k].ptn=0;
			bar[k].ang=0;
			bar[k].flag=1;
			bar[k].length=640;
		}
		if((k=getEmptyBar())!=-1){
			bar[k].x=100;
			bar[k].y=270;
			bar[k].ptn=5;
			bar[k].ang=0;
			bar[k].flag=1;
			bar[k].length=100;
		}
	}
	
	if(game_cnt%100==49){
		if((k=getEmptyBar())!=-1){
			bar[k].x=30;
			bar[k].y=-20;
			bar[k].length=100;
			bar[k].flag=1;
			
			bar[k].ptn=1;
		}
	}
	
	if(game_cnt%100==99){
		if((k=getEmptyBar())!=-1){
			bar[k].x=300;
			bar[k].y=480;
			bar[k].length=100;
			bar[k].flag=1;
			bar[k].ptn=2;
		}
	}

	if(game_cnt%100==99){
		if((k=getEmptyBar())!=-1){
			bar[k].x=400;
			bar[k].y=280;
			bar[k].length=100;
			bar[k].flag=1;
			bar[k].ptn=3;
		}
	}
	/**/
}
void bar_calc(){
	for(int i=0;i<BAR_MAX;i++){
		if(bar[i].flag>0){
			bar_pattern[bar[i].ptn](i);
			bar[i].x+=(int)bar[i].vx;
			bar[i].y+=(int)bar[i].vy;
			if(bar[i].y>480+20)
				bar[i].flag=false;
			if(bar[i].y<-30)
				bar[i].flag=false;
			if(bar[i].x<-20)
				bar[i].flag=false;
			bar[i].cnt++;
		}
	}
}


void bar_main(){
	bar_enter();
	bar_calc();
}



