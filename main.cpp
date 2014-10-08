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


// プログラムは WinMain から始まります
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
						LPSTR lpCmdLine, int nCmdShow )
{
	ChangeWindowMode(TRUE);
	SetBackgroundColor(128,128,128);
	
	if( DxLib_Init() == -1 )		// ＤＸライブラリ初期化処理
	{
		return -1 ;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);
	load();
	ini();
	while(ProcessLoop()==0){
		
						check_time.enter_func_tm("最初");
		ch_calc_main();	check_time.enter_func_tm("キャラメイン");
		soul_main();	check_time.enter_func_tm("魂メイン");
		bar_main();		check_time.enter_func_tm("棒メイン");
		out_main();		check_time.enter_func_tm("あたりメイン");
		draw_main();	check_time.enter_func_tm("描画メイン");
		fps.calc();		check_time.enter_func_tm("待った時間",1);
		ScreenFlip();
		game_cnt++;
		if(key.getKey(KEY_INPUT_SPACE)==1){
			ini();
		}
	}




	DxLib_End() ;				// ＤＸライブラリ使用の終了処理

	return 0 ;				// ソフトの終了 
}