#ifndef GAME_H_INCLUDED_
#define GAME_H_INCLUDED_

#include "Sequence.h"
#include "EnemyTroops.h"
#include "Hero.h"
#include "UFO.h"
#include "BulletManager.h"
#include "PillBox.h"
#include <fstream>
using namespace std;

class Game : public Sequence
{
private:
	int m_Count;//カウンタ
	int m_StageNum;//ステージ番号
	int m_HighScore;//ハイスコア
	static int m_Score;//スコア
	shared_ptr<Hero> m_Hero;//主人公
	vector<shared_ptr<Pillbox> > m_Pillboxs;//トーチカ
	BulletManager m_BulletManager;//弾
	shared_ptr<UFO> m_UFO;//UFO
	shared_ptr<EnemyTroops> m_EnemyTroops;//敵軍

	void InputHighScore();
	void OutputHighScore(int score);
	void Update();//処理の更新
	void Shot();//ショット処理
	void Action();//動作（全て）
	void Move();//移動（全て）
	void Draw();//描画
	void Collision();//衝突判定
	void SpecialUpdate();//UFOなど特別な更新処理
	void Judge_Hero_And_EnemyBullet();//主人公と敵弾
	void Judge_Enemy_And_HeroBullet();//敵と主人公弾 (UFO含む)
	void Judge_Enemy_And_Pillbox();//トーチカと敵
	void Judge_Pillbox_And_Bullet();//トーチカと全ての弾
	bool PillboxCollision(RectEx r, bool bullet);

public:
	Game(int stage);
	~Game(void);
	void Refresh();
};

#endif //GAME_H_INCLUDED_