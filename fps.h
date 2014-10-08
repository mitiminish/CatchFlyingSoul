#pragma once

#define FLAME 60

class Cfps{
private:
	int fps_count,count0t;
	int f[FLAME];
	double ave;
public:
	void calc();
	void draw(int x=0,int y=465);
	Cfps(){
		fps_count=count0t=0;
		for(int i=0;i<FLAME;i++){
			f[i]=0;
		}
		ave=0;
	}
};