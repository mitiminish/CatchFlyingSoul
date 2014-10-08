#include "GV.h"
/*
ジャンプの初速は-4[dot/frm]
ジャンプ開始の瞬間に横方向の移動速度の絶対値が約2[dot/frm]を超えているときには、さらに約-0.5[dot/frm]の上昇加速度が足される
重力加速度は約0.3[dot/frm]
上昇中のみ、Ａボタンが押され続けていると約-0.2[dot/frm]の加速度が得られる
落下速度は5[dot/frm]を超えると、それ以上は加速しない。
x軸方向の空中制動に関しても常識的な処理。特別なことはやっていなさそう。

以上をプログラムで実際に再現してみよう
*/



void ch_calc(){
	
	if(key.getKey(KEY_INPUT_LEFT)!=0){
		ch.vx=-5;
	}else if(key.getKey(KEY_INPUT_RIGHT)!=0){
		ch.vx=5;
	}else if(ch.jampFlag==true){
		ch.vx=0;
	}
	if(ch.x<FIELD_X){
		ch.x=FIELD_X;
	}
	if(ch.x+ch.sizeX>FIELD_MAX_X){
		ch.x=FIELD_MAX_X-ch.sizeX;
	}


	if(ch.vy<0){
		if(key.getKey(KEY_INPUT_UP)!=0){
			ch.vy-=0.2;
		}
	}
	if(key.getKey(KEY_INPUT_UP)==1 && ch.jampFlag==false){
		ch.jampFlag=true;
		ch.vy=-6.0;
	}
	ch.vy+=0.3;
	if(ch.vy>5.0)
		ch.vy=5.0;
}
//足し算は別の場所でします

void ch_calc_0(){
	if(ch.cnt==0){
		ch.y=0;
		ch.x=(FIELD_MAX_X-FIELD_X)/2.0;
	}

	ch.vy=+2;
	ch.jampFlag=false;
	if(key.getKey(KEY_INPUT_UP)==1){
		ch_calc();
		ch.state=1;
	}
}


void ch_calc_main(){
	switch (ch.state)
	{
	case 0:
		ch_calc_0();
		break;
	case 1:
		ch_calc();
		break;
	default:
		break;
	}
	ch.cnt++;
}
