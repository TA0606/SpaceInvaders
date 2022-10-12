#ifndef BULLETMANAGER_H_INCLUDED_
#define BULLETMANAGER_H_INCLUDED_

#include "BulletCreator.h"
#include <memory>
using namespace std;

class BulletManager
{
private:
	vector<shared_ptr<Bullet> > m_Bullets;//�e��

public:
	BulletManager(void);

	RectEx GetRect(int index){ return m_Bullets[index]->GetRect(); }//�w��̎l�p�`��Ԃ�
	int Length(){ return static_cast<int>(m_Bullets.size()); }//�e�̐���Ԃ�
	int GetType(int index){ return m_Bullets[index]->GetType(); }//�w��̒e�̃^�C�v��Ԃ�
	int GetHeroBullet();//��l���̒e�̃C���f�b�N�X��Ԃ��@���s�Ȃ�-1
	bool IsEmpty(int index);//�w��̒e�����݂��邩 true�Ȃ瑶�݂��Ȃ�
	void Create(int type, Location loc);//�e�ۍ쐬
	void Delete(int index);//�w��̒e�������B
	void Refresh();//�X�V(�g�O�Ȃ�����Ȃǁj�K��Action, Move, Draw�̑O�ɌĂяo��
	void Action();//�S�Ă̒e�̓���
	void Move();//�S�Ă̒e�̈ړ�
	void Draw();//�S�Ă̒e�̕`��
};

#endif //BULLETMANAGER_H_INCLUDED_