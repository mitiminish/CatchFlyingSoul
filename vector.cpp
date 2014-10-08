#include "vector.h"
#include <math.h>
double vector2OuterProcuct(vector2_t v1,vector2_t v2){
	return v1.x * v2.y - v1.y * v2.x;
}

double vector2InnerProduct(vector2_t v1,vector2_t v2){
	return v1.x * v2.x + v1.y * v2.y;
} 
//pt1pt2の距離を返します
double ptGetdistance(pt_t p1,pt_t p2){
	double x=p1.x-p2.x;
	double y=p1.y-p2.y;
	return sqrt(x*x+y*y);
}


//aを中心とするabとcとの角度を計算
//返り値は-πからπの範囲
double getTheta_l_p(pt_t a,pt_t b,pt_t c){
	vector2_t ab(b,a);
	vector2_t ac(c,a);
	double out=vector2OuterProcuct(ab,ac);//a,b*sin
	double in=vector2InnerProduct(ab,ac);//a,b*cos
	double theta=atan2(out,in);
	return theta;
}

double getDistance_line_p(pt_t a,pt_t b,pt_t c){
	double theta=getTheta_l_p(a,b,c);
	return sin(abs(theta))*ptGetdistance(a,c);
}

double getDistance_segment_p(pt_t a,pt_t b,pt_t c){
	vector2_t ab(b,a);
	vector2_t ac(c,a);
	if(vector2InnerProduct(ab,ac)<0)
		//線分abのa側の外側にcがいます
		return ptGetdistance(a,c);
	vector2_t ba(a,b);
	vector2_t bc(c,b);
	if(vector2InnerProduct(ba,bc)<0)
		//線分abのb側の外側にcがいます
		return ptGetdistance(b,c);
	return getDistance_line_p(a,b,c);
}

bool isLineCrossed(pt_t p1,pt_t p2,pt_t v1,pt_t v2){
	vector2_t p(p2,p1);
	vector2_t p1v1(v1,p1);
	vector2_t p1v2(v2,p1);
	vector2_t v(v2,v1);
	vector2_t v1p1(p1,v1);
	vector2_t v1p2(p2,v1);
	if(vector2OuterProcuct(p1v1,p)*vector2OuterProcuct(p1v2,p)<0
		 && vector2OuterProcuct(v1p1,v) * vector2OuterProcuct(v1p2,v)<0){
		return true;
	}
	return false;
}


pt_t whereLineCrossed(pt_t p1,pt_t p2,pt_t v1,pt_t v2){
	if(isLineCrossed(p1,p2,v1,v2)!=true)
		return pt_t(-100,-100);
	vector2_t v(v2,v1);
	double d1=abs(vector2OuterProcuct(v,vector2_t(p1,v1)));
	double d2=abs(vector2OuterProcuct(v,vector2_t(p2,v1)));
	double t=d1/(d1+d2);
	return p1+(p2-p1)*t;
}


