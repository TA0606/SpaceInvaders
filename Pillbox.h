#ifndef PILLBOX_H_INCLUDED_
#define PILLBOX_H_INCLUDED_

#include "DxLib.h"
#include "RectEx.h"
#include "Utils.h"

//トーチカ
class Pillbox
{
private:
	int m_ImgHandle;//実際の描画に使う画像ハンドル
	int m_SoftImg;//画像判定用CPU扱いイメージ
	int m_SoftMaskImg;//マスク用CPU扱いイメージ
	RectEx m_Rect;//位置、サイズ

	void CutForBullet(RectEx r);//画像を切り取る　弾衝突時に使用する。
	void CutFill(RectEx r);//画像を切り取る　キャラクタ衝突時に使用する。
	bool CheckPixel(RectEx r);//画素判定　trueで衝突

public:
	Pillbox(Location loc);
	~Pillbox(void);

	RectEx GetRect(){ return m_Rect; }
	bool Collision(RectEx r, bool bullet);//トーチカとの衝突判定　第2引数：弾ならtrueをセット(特別な処理のため）
	void Draw();
};

#endif //PILLBOX_H_INCLUDED_