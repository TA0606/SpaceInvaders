#ifndef CHARACTERDATA_H_INCLUDED_
#define CHARACTERDATA_H_INCLUDED_

#include "ImgData.h"

struct CharacterData
{
public:
	int ImgIndex;//現在のイメージを指す要素番号
	int Count;//内部カウンタ
	int Life;//残機
	int Score;//保持スコア
	bool Shot;//ショットフラグ
	bool Death;//死亡フラグ
	bool GameOver;//残機0で復活不可かどうか示すフラグ
	RectEx Rect;//位置、サイズ
	ImgData Imgs;//通常イメージ
	ImgData DeathImgs;//死亡時イメージ

	CharacterData() : ImgIndex(0), Count(0), Life(0), Score(0), Shot(false),
	                    Death(false), GameOver(false), Rect(), Imgs(), DeathImgs(){}
};

#endif //CHARACTERDATA_H_INCLUDED_