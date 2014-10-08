#include "DxLib.h"
#include "key.h"

void Ckey::update(){
	char gethitstate[256];
	GetHitKeyStateAll(gethitstate);
	for(int i=0;i<_countof(gethitstate);i++){
		if(gethitstate[i]==1)
			stateKey[i]++;
		else
			stateKey[i]=0;
	}
}


Ckey::Ckey(void)
{
	
}


Ckey::~Ckey(void)
{
}
