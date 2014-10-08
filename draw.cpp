#include "GV.h"
#include <math.h>
/*
int DrawBox(double x1,double y1,double x2,double y2,int color,bool fillFlag){
	return DrawBox((int)x1,(int)y1,(int)x2,(int)y2,color,fillFlag);
}
*/

void draw_ch(){
	if(ch.state==0){
		DrawLine((int)(ch.x-10),(int)(ch.y+ch.sizeY),(int)(ch.x+ch.sizeX+10),(int)(ch.y+ch.sizeY),0xffffff);
	}

	DrawBox((int)ch.x, (int)ch.y, (int)(ch.x + ch.sizeX), (int)(ch.y + ch.sizeY), 0xffffff, TRUE);
}

void draw_bar(){
	for(int i=0;i<BAR_MAX;i++){
		if(bar[i].flag>0){
			DrawLine(bar[i].x,bar[i].y,
				bar[i].x+(int)(bar[i].length*cos(bar[i].ang)),
				bar[i].y+(int)(bar[i].length*sin(bar[i].ang)),0xffffff);
		}
	}
}

void draw_soul(){
	for(int i=0;i<SOUL_MAX;i++){
		if(soul[i].flag>0){
			DrawFormatString((int)soul[i].x,(int)soul[i].y,color[soul[i].cl],"ç∞");
		}
	}
}

void draw_score(){
	DrawFormatString(FIELD_MAX_X+50,FIELD_Y+50,0xffffff,"score:%d",ch.score);
}



void draw_board(){
	for(int i=0;i<5;i++){
		DrawBox(FIELD_X-i,FIELD_Y-i,FIELD_MAX_X+i,FIELD_MAX_Y+i,GetColor(255,255,255),FALSE);
	}
}


void draw_develop(){
	printfDx("\nch.vy=%f",ch.vy);	
	printfDx("\nch.y=%f", ch.y);
}



void draw_main(){
	SetDrawArea(FIELD_X,FIELD_Y,FIELD_MAX_X,FIELD_MAX_Y);
	DrawBox(FIELD_X,FIELD_Y,FIELD_MAX_X,FIELD_MAX_Y,0x000000,TRUE);
	draw_develop();
	draw_ch();
	draw_soul();
	draw_bar();
	SetDrawArea(0,0,640,480);
	draw_score();
	draw_board();
	draw_develop();
	fps.draw(0,465);
	check_time.draw_func_tm(450,250);
}
