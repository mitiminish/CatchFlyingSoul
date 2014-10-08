#define GLOBAL_INSTANCE
#include "GV.h"

int ProcessLoop(){
	if(ProcessMessage()!=0)return -1;
	if(clsDx()!=0)return -1;
	if(ClearDrawScreen()!=0)return -1;
	if(CheckHitKey(KEY_INPUT_ESCAPE)!=0)return -1;
	key.update();
	
	return 0;
}


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
						LPSTR lpCmdLine, int nCmdShow )
{
	ChangeWindowMode(TRUE);
	SetBackgroundColor(128,128,128);
	
	if( DxLib_Init() == -1 )		// �c�w���C�u��������������
	{
		return -1 ;			// �G���[���N�����璼���ɏI��
	}
	SetDrawScreen(DX_SCREEN_BACK);
	load();
	ini();
	while(ProcessLoop()==0){
		
						check_time.enter_func_tm("�ŏ�");
		ch_calc_main();	check_time.enter_func_tm("�L�������C��");
		soul_main();	check_time.enter_func_tm("�����C��");
		bar_main();		check_time.enter_func_tm("�_���C��");
		out_main();		check_time.enter_func_tm("�����胁�C��");
		draw_main();	check_time.enter_func_tm("�`�惁�C��");
		fps.calc();		check_time.enter_func_tm("�҂�������",1);
		ScreenFlip();
		game_cnt++;
		if(key.getKey(KEY_INPUT_SPACE)==1){
			ini();
		}
	}




	DxLib_End() ;				// �c�w���C�u�����g�p�̏I������

	return 0 ;				// �\�t�g�̏I�� 
}