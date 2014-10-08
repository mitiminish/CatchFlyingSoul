#include "Check_time.h"

void CCheck_time::enter_func_tm(char str[],int flag){
	int i;
	LONGLONG nowtm;
	if(func_count>=FUNC_MAX){
		printfDx("func_count‚Ì’l%d‚ªˆÙí‚Å‚·",func_count);
		return;
	}
	nowtm=GetNowHiPerformanceCount();
	if(nowtm-lt<INT_MAX){
		func_tm[func_count].tm=(int)(nowtm-lt);
		memcpy(func_tm[func_count].str,str,STR_MAX-1);
		func_tm[func_count].str[STR_MAX-1]=0;
	}
	else
		func_tm[func_count].tm=-1;
	lt=nowtm;
	if(flag==1){
		for(i=func_count+1;i<FUNC_MAX;i++)
			func_tm[i].str[0]=0;
		func_count=0;
	}
	else
		func_count++;
}

void CCheck_time::draw_func_tm(int x,int y){
	int i;
	unsigned int total=0;
	for(i=0;i<FUNC_MAX;i++){
		if(func_tm[i].str[0]==0)break;
		DrawFormatString(x,y+14*i,0xffffff,"%05.2f:%s",func_tm[i].tm/1000.0,func_tm[i].str);
		total+=func_tm[i].tm;
	}
	DrawFormatString(x,y+14*i,0xffffff,"‡Œv:%05.2f",total/1000.0);
}


CCheck_time::CCheck_time(void)
{
	static func_tm_t funczero={0};
	for(int i=0;i<_countof(func_tm);i++){
		func_tm[i]=funczero;
	}
}


CCheck_time::~CCheck_time(void)
{
}
