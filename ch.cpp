#include "GV.h"
/*
�W�����v�̏�����-4[dot/frm]
�W�����v�J�n�̏u�Ԃɉ������̈ړ����x�̐�Βl����2[dot/frm]�𒴂��Ă���Ƃ��ɂ́A����ɖ�-0.5[dot/frm]�̏㏸�����x���������
�d�͉����x�͖�0.3[dot/frm]
�㏸���̂݁A�`�{�^���������ꑱ���Ă���Ɩ�-0.2[dot/frm]�̉����x��������
�������x��5[dot/frm]�𒴂���ƁA����ȏ�͉������Ȃ��B
x�������̋󒆐����Ɋւ��Ă��펯�I�ȏ����B���ʂȂ��Ƃ͂���Ă��Ȃ������B

�ȏ���v���O�����Ŏ��ۂɍČ����Ă݂悤
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
//�����Z�͕ʂ̏ꏊ�ł��܂�

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
