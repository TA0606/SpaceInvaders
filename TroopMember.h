#ifndef TROOPMEMBER_H_INCLUDED_
#define TROOPMEMBER_H_INCLUDED_

#include "Utils.h"
#include "CharacterData.h"

//インベーダー軍の隊員
//隊列を組んで移動するのでEnemyTroopsによって行動は管理される
class TroopMember
{
protected:
	CharacterData m_Data;

public:
	TroopMember();
	virtual ~TroopMember() = 0 {}
	virtual void Kill();//殺す
	virtual void Action();//動作
	virtual void Move(Location loc);//移動（自分で勝手に動くのではなく、管理される）
	virtual void Draw();//描く
	int GetScore() const { return m_Data.Score; }//スコアを得る
	bool GetShotFlag() const{ return m_Data.Shot; }//ショットフラグを取得 trueでショット
	bool IsDead() const { return m_Data.Death; }//死んでるか？　trueで死亡中
	bool GameIsOver() const { return m_Data.GameOver; }//残機０でゲームオーバーか？ trueでゲームオーバー
	RectEx GetRect() const { return m_Data.Rect; }//四角形を得る
	int GetAnimationSpeed() const { return m_Data.Imgs.GetAnimationSpeed(); }//現在の生存時アニメーションスピードを返す
	void SetShotFlag(bool f){ m_Data.Shot = f; }//ショットフラグSet
	void AddAnimationSpeed(int s){ m_Data.Imgs.SetAnimationSpeed(GetAnimationSpeed() + s);};//アニメーションスピードを加える
};

#endif //TROOPMEMBER_H_INCLUDED_