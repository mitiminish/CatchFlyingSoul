#include "GV.h"
//-ang~ang‚Ü‚Å‚Ì’l‚ð•Ô‚µ‚Ü‚·
double randAng(double ang){
	return -ang+ang*2*GetRand(10000)/10000.0;
}


int getEmptySoul(){
	for(int i=0;i<SOUL_MAX;i++){
		if(soul[i].flag==0)
			return i;
	}
	return -1;
}
void soul_enter(){
	if(game_cnt%10==0){
		int k;
		if((k=getEmptySoul())!=-1){
			soul[k].x=GetRand(FIELD_MAX_X-FIELD_X)+FIELD_X;
			soul[k].y=FIELD_Y-10-GetRand(30);
			soul[k].vx=0;
			soul[k].vy=GetRand(3)+1;
			soul[k].cl=GetRand(6);
			soul[k].flag=1;
		}
	}
}

void soul_calc(){
	for(int i=0;i<SOUL_MAX;i++){
		if(soul[i].flag>0){
			soul[i].x+=soul[i].vx;
			soul[i].y+=soul[i].vy;
			if(soul[i].x<FIELD_X-10 || soul[i].x>FIELD_MAX_X+10)
				soul[i].flag=0;
			if(soul[i].y>FIELD_MAX_Y+10)
				soul[i].flag=0;
		}
	}

}



void soul_main(){
	soul_enter();
	soul_calc();
}
