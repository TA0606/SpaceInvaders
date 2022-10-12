#ifndef UTILS_H_INCLUDED_
#define UTILS_H_INCLUDED_

#include "DxLib.h"
#include "RectEx.h"
#include "Sound.h"

class Utils
{
private:
	static int KeyState[256];//キー状態を格納します。0で未入力状態、１以上なら入力状態です。
	static Sound SoundManager;//サウンド管理クラス

public:
	static void SoundStop(string song_name);//サウンドの停止
	static void SoundPlay(string song_name, int type, int top);//サウンドの再生
	static bool WithinLimits(RectEx r);//四角形がクライアント領域以内かどうかを判断（return）枠内=true, 枠外=false
	static bool WithinLimits(Location loc);//位置がクライアント領域以内かどうかを判断（return）枠内=true, 枠外=false
	static RectEx ClientRectEx();//クライアント領域の四角形を取得する
	static void DrawImg(int handle, RectEx r);//画像を等倍でrのXY位置に描画します。
	static bool Collision(RectEx r1, RectEx r2);//衝突判定を行う。(return)衝突=true、未衝突=false
	static int KeyDownCheck(int key);//キー入力をチェックする　(return)キー入力カウント
	static bool KeyStateUpdate();//KeyDownCheckの前に呼び出し、キー状態を更新します。(return)成功=true, 失敗=false
	static void ErrorProcess(std::string err_msg);//エラー処理を行う
};

#endif //UTILS_H_INCLUDED_