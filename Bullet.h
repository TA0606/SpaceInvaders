#ifndef BULLET_H_INCLUDED_
#define BULLET_H_INCLUDED_

#include "RectEx.h"
#include "ImgData.h"
#include "Utils.h"

//�e�e�ۂ̃x�[�X�ƂȂ�N���X
class Bullet
{
protected:
	int m_Type;//�e�̃^�C�v
	int m_ImgIndex;//���݂̃C���[�W���w���v�f�ԍ�
	int m_Count;//�����J�E���^
	bool m_Delete;//�����t���O
	RectEx m_Rect;//�ʒu�A�T�C�Y
	ImgData m_Imgs;//�摜�f�[�^

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