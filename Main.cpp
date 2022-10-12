#include "SequenceManager.h"
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int)
{
	SetMainWindowText("SpaceInvaders  (FAKE)             ショット : SPACE   移動 : ←,→");
	ChangeWindowMode(TRUE);

	if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK ) != 0)
	{
		return -1;
	}

	LPCSTR fontPath = "./Resources/Font/m52.ttf";//読み込むフォントファイルのパス

	if (AddFontResourceEx(fontPath, FR_PRIVATE, NULL) == 0) 
	{
		Utils::ErrorProcess("m52フォントが見つかりません。強制終了します。");
		return -1;
	}
	else
	{
		ChangeFont( "M52_CHAINSAW KISSED THE BIT", DX_CHARSET_DEFAULT ) ;
		ChangeFontType( DX_FONTTYPE_ANTIALIASING );
	}

	SequenceManager::Create();

	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && Utils::KeyStateUpdate() )
	{
		SequenceManager::GetInstance()->Refresh();
	}

	SequenceManager::GetInstance()->Delete();
	DxLib_End(); // DXライブラリ終了処理
	return 0;
}