#ifndef ENEMYTROOPS_H_INCLUDED_
#define ENEMYTROOPS_H_INCLUDED_

#include "TroopMemberCreator.h"
#include <memory>
using namespace std;

//インベーダー軍（敵）　全員に規則的な動きを強いるためクラス化
class EnemyTroops
{
private:
	int m_Direction;//軍の移動方向
	int m_InvasionY;//侵略完了Y座標
	int m_Count;//内部カウンタ
	int m_Speed;//移動速度
	bool m_Down;//下へ移動するフラグ（DirectionValueに含めると次に進む方向が右か左かの判別処理が増えるため別にしている。）
	int m_NextMove;//次に移動する敵は誰か
	Location m_MoveVal;
	bool m_Move;
	int m_SoundIndex;
	vector<string> m_Sounds;
	vector< shared_ptr<TroopMember> > m_Enemies;//敵達
	int EdgeOfTroops(int direction);//左端または右端のキャラクタインデックスを返す　引数にはDirectionValueをセットする
	int AliveLength();//生きている敵の数
	int CalcMove_X();//左または右への移動量の計算

public:
	EnemyTroops(Location start, int invasion_y);
	~EnemyTroops(void);

	enum DirectionValue{ LEFT, RIGHT, };

	int Length(){ return static_cast<int>(m_Enemies.size()); }//軍の敵数を返す
	int GetScore(int num) const { return m_Enemies[num]->GetScore(); }//指定の敵のスコアを返す
	bool GetShotFlag(int num){ return m_Enemies[num]->GetShotFlag(); }//指定の敵の発射フラグを得る
	bool IsDead(int num){ return m_Enemies[num]->IsDead(); }//指定の敵が死んでいるか
	bool GameIsOver(int num){ return m_Enemies[num]->GameIsOver(); }//指定の敵がゲームオーバーか
	bool IsAnnihilation();//全滅か？　trueなら全滅
	bool CheckInvasion();//侵略完了かどうか trueで侵略完了
	RectEx GetRect(int num){ return m_Enemies[num]->GetRect(); }//指定の敵の四角形を得る。
	void Kill(int num);
	void Action();//全軍の動作
	void Move();//全軍の移動
	void Draw();//全軍の描画
};

#endif //ENEMYTROOPS_H_INCLUDED_