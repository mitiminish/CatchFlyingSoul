#pragma once

typedef struct{
	double x,y;
	double vx,vy;
	int jampFlag;
	int state;
	double sizeX,sizeY;
	int score;
	int cnt;
}ch_t;

typedef struct{	
	int x,y;//float�ɂ���Ƃ��܂������܂���
	double vx,vy;
	int length;
	double ang;
	int cnt;
	int ptn;
	int flag;
}bar_t;

typedef struct{
	double x,y;
	double vx,vy;
	int flag;
	int cl;
}soul_t;