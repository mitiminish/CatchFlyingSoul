#include "DxLib.h"
#include "fps.h"

void Cfps::calc(){
	int term,i,gnt;
	static int t=0;
	if(fps_count==0){
		if(t==0)
			term=0;
		else
			term=1000+count0t-GetNowCount();
	}
	else 
		term=(int)(count0t+fps_count*(1000.0/FLAME))-GetNowCount();
	if(term>0)
		Sleep(term);

	gnt=GetNowCount();
	if(fps_count==0){
		count0t=gnt;
	}
	f[fps_count]=gnt-t;
	t=gnt;

	//•½‹ÏŒvŽZ
	if(fps_count==FLAME-1){
		ave=0;
		for(i=0;i<FLAME;i++){
			ave+=f[i];
		}
		ave/=FLAME;
	}
	fps_count =(++fps_count)%FLAME;
}

void Cfps::draw(int x,int y){
	if(ave!=0){
		DrawFormatString(x,y,0xffffff,"[%.1f]",1000/ave);
	}

}

