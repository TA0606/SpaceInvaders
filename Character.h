#ifndef CHARACTER_H_INCLUDED_
#define CHARACTER_H_INCLUDED_

#include "Utils.h"
#include "CharacterData.h"

//各キャラクターのベースとなるクラス
class Character
{
protected:
	CharacterData m_Data;

public:
	Character() : m_Data(){}
	virtual ~Character(void) = 0{}

	virtual void Move() = 0;//移動
	virtual void Action() = 0;//動作
	virtual void Kill();//殺す
	virtual void Draw();//描く
	int GetScore() const { return m_Data.Score; }//スコアを得る
	int GetLife() const { return m_Data.Life; }//残機を得る
	bool GetShotFlag() const{ return m_Data.Shot; }//ショットフラグを取得 trueでショット
	bool IsDead() const { return m_Data.Death; }//死んでるか？　trueで死亡中
	bool GameIsOver() const { return m_Data.GameOver; }//残機０でゲームオーバーか？ trueでゲームオーバー
	RectEx GetRect() const { return m_Data.Rect; }//四角形を得る
};

#endif //CHARACTER_H_INCLUDED_