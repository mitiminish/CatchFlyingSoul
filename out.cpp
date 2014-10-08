#include"GV.h"
#include <math.h>



//moveX,moveYに四捨五入を導入すると
//斜めの地域でがたがたしなくなります

//vx.vyをpt1,pt2に導入
//vy=bar[k].vyを導入
//ここまでで水平で上下に動く棒になら
//乗れるようになりました
void ch_and_bar(){
	pt_t ch_l(ch.x,ch.y+ch.sizeY);
	pt_t ch_r(ch.x+ch.sizeX,ch.y+ch.sizeY);
	pt_t ch_moved_l=pt_t(ch.vx,ch.vy)+ch_l;
	pt_t ch_moved_r=pt_t(ch.vx,ch.vy)+ch_r;
	double moveX=ch.vx;
	double moveY=ch.vy;
	for(int i=0;i<BAR_MAX;i++){
		if(bar[i].flag>0){
			pt_t pt1(bar[i].x,bar[i].y);
			pt_t pt2(bar[i].x+bar[i].length*cos(bar[i].ang),bar[i].y+bar[i].length*sin(bar[i].ang));

			
// 足元の判定 		
			if(ch.vy>bar[i].vy){
				//右したの判定
				if(isLineCrossed(ch_r,ch_moved_r,pt1,pt2)){
					pt_t cross=whereLineCrossed(ch_r,ch_moved_r,pt1,pt2);
					
					ch.vx = bar[i].vx;
					ch.vy=bar[i].vy;//これ重要
					//上向きのバーにも下向きのバーにも乗れるようになります

					//intへのキャストは切り捨てられるので
					//四捨五入してるよ
					moveY=(int)(cross.y+0.5)-ch.y-ch.sizeY-1.0;
					
					ch.jampFlag=false;

					
					
					if (!(-PI / 32.0 < bar[i].ang && bar[i].ang < PI / 32.0)){
						moveX = cross.x - ch.x - ch.sizeX;
					}
						
					//結果としては線分の交点の1ピクセル上の座標にいくことになります
					//なので垂直な壁とは判定できません
					//線分と交わらなくなるまで上に昇っていくでしょう
				}
				//左したの判定
				if(isLineCrossed(ch_l,ch_moved_l,pt1,pt2)){
					pt_t cross=whereLineCrossed(ch_l,ch_moved_l,pt1,pt2);
					ch.vy=bar[i].vy;
					ch.vx = bar[i].vx;

					moveY=(int)(cross.y)-ch.y-ch.sizeY-1.0;
					ch.jampFlag=false;

					
					
					if(!(-PI/32.0 <bar[i].ang && bar[i].ang<PI/32.0)){
						moveX=cross.x-ch.x;
					}
					//printfDx("cl_y=%f,bar_y=%f",cross.y,bar[i].y);
				}
				//刺さらないための判定
				if(isLineCrossed(ch_l,ch_r,pt1,pt2)){
					pt_t cross=whereLineCrossed(ch_l,ch_r,pt1,pt2);
					ch.vy=bar[i].vy;
					moveY=(int)(cross.y+0.5)-ch.y-ch.sizeY-1.0;
				}
			}
		}
	}
	printfDx("%f",moveY);
	ch.x+=moveX;
	ch.y+=moveY;
}

const double soul_sizeX=15;
const double soul_sizeY=15;
int isInside_ch(double x,double y){
	if(ch.x<x && ch.x+ch.sizeX>x)
		if(ch.y<y && ch.y+ch.sizeY>y)
			return 1;
	return 0;
}
void ch_and_soul(){
	for(int i=0;i<SOUL_MAX;i++){
		if(soul[i].flag>0){
			int result=0;
			result+=isInside_ch(soul[i].x,soul[i].y);
			result+=isInside_ch(soul[i].x+soul_sizeX,soul[i].y);
			result+=isInside_ch(soul[i].x,soul[i].y+soul_sizeY);
			result+=isInside_ch(soul[i].x+soul_sizeX,soul[i].y+soul_sizeY);
			if(result>0){
				soul[i].flag=0;
				ch.score++;
			}
		}
	}
}


void out_main(){
	ch_and_bar();
	ch_and_soul();
}
