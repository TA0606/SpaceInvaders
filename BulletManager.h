#ifndef BULLETMANAGER_H_INCLUDED_
#define BULLETMANAGER_H_INCLUDED_

#include "BulletCreator.h"
#include <memory>
using namespace std;

class BulletManager
{
private:
	vector<shared_ptr<Bullet> > m_Bullets;//弾丸

public:
	BulletManager(void);

	RectEx GetRect(int index){ return m_Bullets[index]->GetRect(); }//指定の四角形を返す
	int Length(){ return static_cast<int>(m_Bullets.size()); }//弾の数を返す
	int GetType(int index){ return m_Bullets[index]->GetType(); }//指定の弾のタイプを返す
	int GetHeroBullet();//主人公の弾のインデックスを返す　失敗なら-1
	bool IsEmpty(int index);//指定の弾が存在するか trueなら存在しない
	void Create(int type, Location loc);//弾丸作成
	void Delete(int index);//指定の弾を消す。
	void Refresh();//更新(枠外なら消すなど）必ずAction, Move, Drawの前に呼び出す
	void Action();//全ての弾の動作
	void Move();//全ての弾の移動
	void Draw();//全ての弾の描画
};

#endif //BULLETMANAGER_H_INCLUDED_