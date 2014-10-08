#include "GV.h"

void first_ini(){

}

void ini(){
	static ch_t ch_tZero={0};
	ch=ch_tZero;
	ch.x=320;
	ch.y=240;
	ch.sizeX=32;
	ch.sizeY=32;
	auto_scroll=0;
	static bar_t barZero={0};
	for(int i=0;i<_countof(bar);i++){
		bar[i]=barZero;
	}
	static soul_t soulZero={0};
	for(int i=0;i<_countof(soul);i++){
		soul[i]=soulZero;
	}
	game_cnt=0;
}

