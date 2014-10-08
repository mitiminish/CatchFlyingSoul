#pragma once
#include "DxLib.h"
struct pt_t{
	double x,y;
	
	pt_t operator+(pt_t p){
		pt_t sum(0,0);
		sum.x=x+p.x;
		sum.y=y+p.y;
		return sum;
	}
	pt_t operator-(pt_t p){
		pt_t sub(0,0);
		sub.x=x-p.x;
		sub.y=y-p.y;
		return sub;
	}
	pt_t operator*(double num){
		pt_t mul;
		mul.x=x*num;
		mul.y=y*num;
		return mul;
	}


	pt_t(double x,double y){
		this->x=x;
		this->y=y;
	}

	pt_t(){
		x=y=0;
	}
};

class vector2_t{
public:
	double x,y;
	vector2_t operator+(vector2_t v){
		vector2_t sum;
		sum.x=x+v.x;
		sum.y=y+v.y;
		return sum;
	}
	vector2_t operator-(vector2_t v){
		vector2_t sub;
		sub.x=x-v.x;
		sub.y=y-v.y;
		return sub;
	}
	vector2_t operator*(double num){
		vector2_t res;
		res.x=x*num;
		res.y=y*num;
		return res;
	}
	vector2_t operator/(double num){
		vector2_t res;
		res.x=x/num;
		res.y=y/num;
		return res;
	}


	vector2_t(double x,double y){
		this->x=x;
		this->y=y;
	}
	vector2_t(pt_t end,pt_t origin){
		this->x=end.x-origin.x;
		this->y=end.y-origin.y;
	}
	vector2_t(){
		x=y=0;
	}
};


double ptGetdistance(pt_t p1,pt_t p2);
double getTheta_l_p(pt_t a,pt_t b,pt_t c);
double getDistance_line_p(pt_t a,pt_t b,pt_t c);
double getDistance_segment_p(pt_t a,pt_t b,pt_t c);
bool isLineCrossed(pt_t p1,pt_t p2,pt_t v1,pt_t v2);
pt_t whereLineCrossed(pt_t p1,pt_t p2,pt_t v1,pt_t v2);