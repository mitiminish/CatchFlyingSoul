#pragma once
class Ckey
{
private:
	unsigned int stateKey[256];
public:
	void update();
	int getKey(int keycode){
		if(keycode<0 || keycode>_countof(stateKey)){
			printfDx("keyCode�̒l���s���ł�\n");
			return -1;
		}
		return stateKey[keycode];
	}
	Ckey(void);
	~Ckey(void);
};

