#include "Utils.h"

int Utils::KeyState[256] = {};//初期値は全て0
Sound Utils::SoundManager;

//サウンドの停止
void Utils::SoundStop(string song_name)
{
	if(SoundManager.Loaded()) SoundManager.Stop(song_name);
}

//サウンドの再生
void Utils::SoundPlay(string song_name, int type, int top)
{
	if(!SoundManager.Loaded()) SoundManager.Load();
	SoundManager.Play(song_name, type, top);
}

//四角形がクライアント領域以内かどうかを判断（return）枠内=true, 枠外=false
bool Utils::WithinLimits(RectEx r)
{
	RectEx client_r = ClientRectEx();

	if(r.Left() < client_r.Left() || r.Right() > client_r.Right() ||
		r.Top() < client_r.Top() || r.Bottom() > client_r.Bottom())
	{
		return false;
	}

	return true;
}

//位置がクライアント領域以内かどうかを判断（return）枠内=true, 枠外=false
bool Utils::WithinLimits(Location loc)
{
	RectEx client_r = ClientRectEx();

	if(loc.X < client_r.Left() || loc.X > client_r.Right() ||
		loc.Y < client_r.Top() || loc.Y  > client_r.Bottom())
	{
		return false;
	}

	return true;
}

//クライアント領域の四角形を取得する
RectEx Utils::ClientRectEx()
{
	RECT t_r;
	GetWindowCRect(&t_r);//t_rにはウィンドウの位置が格納。
	return ( RectEx(0, 0, t_r.right - t_r.left, t_r.bottom - t_r.top) );//キャラクタ座標で使えるように変換する
}

//画像を等倍でrのXY位置に描画します。
void Utils::DrawImg(int handle, RectEx r)
{
	if(DrawGraph(r.X, r.Y, handle, TRUE) == -1)
	{
		ErrorProcess("描画に失敗しました。");
		exit(-1);
	}
}

//衝突判定を行う。(return)衝突=true、未衝突=false
bool Utils::Collision(RectEx r1, RectEx r2)
{
	if( r1.X < r2.Right() && r2.X < r1.Right() && r1.Y < r2.Bottom() && r2.Y < r1.Bottom())
		return true;
	else
		return false;
}

//キー入力をチェックする　(return)キー入力カウント
int Utils::KeyDownCheck(int key)
{
	return KeyState[key];
}

//KeyDownCheckの前に呼び出し、キー状態を更新します。(return)成功=true, 失敗=false
bool Utils::KeyStateUpdate()
{
	char tempKeys[256];

	if(GetHitKeyStateAll( tempKeys ) == -1) return false;

	for( int i=0; i<256; i++ )
	{ 
			if( tempKeys[i] != 0 ) 
				KeyState[i]++;
			else
				KeyState[i] = 0;
	}

	return true;
}

void Utils::ErrorProcess(std::string err_msg)
{
	MessageBox( GetMainWindowHandle(),  err_msg.c_str(), "Error", MB_OK);
	ErrorLogAdd(err_msg.c_str());
}