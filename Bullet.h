#ifndef BULLET_H_INCLUDED_
#define BULLET_H_INCLUDED_

#include "RectEx.h"
#include "ImgData.h"
#include "Utils.h"

//各弾丸のベースとなるクラス
class Bullet
{
protected:
	int m_Type;//弾のタイプ
	int m_ImgIndex;//現在のイメージを指す要素番号
	int m_Count;//内部カウンタ
	bool m_Delete;//消去フラグ
	RectEx m_Rect;//位置、サイズ
	ImgData m_Imgs;//画像データ

public:
	Bullet() : m_Type(0), m_ImgIndex(0), m_Count(0), m_Delete(false),
				  m_Rect(), m_Imgs(){}
	virtual ~Bullet(void) = 0{}

	enum BulletType{ HERO, ENEMY };

	int GetType(){ return m_Type; }
	RectEx GetRect(){ return m_Rect; }
	bool GetDeleteFlg(){ return m_Delete; }
	void SetDeleteFlg(bool f){ m_Delete = f; }

	virtual void Action();
	virtual void Move();
	virtual void Draw();
};

#endif //BULLET_H_INCLUDED_