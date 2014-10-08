#pragma once
#include "DxLib.h"

#define STR_MAX 64
#define FUNC_MAX 30

typedef struct{
	int tm;
	char str[STR_MAX];
}func_tm_t;


class CCheck_time
{
private:
	func_tm_t func_tm[FUNC_MAX];
	int func_count;
	LONGLONG lt;
public:
	void enter_func_tm(char st[],int flag=0);
	void draw_func_tm(int x=450,int y=250);
	CCheck_time(void);
	~CCheck_time(void);
};

