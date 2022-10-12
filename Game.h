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
	int m_Count;//�J�E���^
	int m_StageNum;//�X�e�[�W�ԍ�
	int m_HighScore;//�n�C�X�R�A
	static int m_Score;//�X�R�A
	shared_ptr<Hero> m_Hero;//��l��
	vector<shared_ptr<Pillbox> > m_Pillboxs;//�g�[�`�J
	BulletManager m_BulletManager;//�e
	shared_ptr<UFO> m_UFO;//UFO
	shared_ptr<EnemyTroops> m_EnemyTroops;//�G�R

	void InputHighScore();
	void OutputHighScore(int score);
	void Update();//�����̍X�V
	void Shot();//�V���b�g����
	void Action();//����i�S�āj
	void Move();//�ړ��i�S�āj
	void Draw();//�`��
	void Collision();//�Փ˔���
	void SpecialUpdate();//UFO�ȂǓ��ʂȍX�V����
	void Judge_Hero_And_EnemyBullet();//��l���ƓG�e
	void Judge_Enemy_And_HeroBullet();//�G�Ǝ�l���e (UFO�܂�)
	void Judge_Enemy_And_Pillbox();//�g�[�`�J�ƓG
	void Judge_Pillbox_And_Bullet();//�g�[�`�J�ƑS�Ă̒e
	bool PillboxCollision(RectEx r, bool bullet);

public:
	Game(int stage);
	~Game(void);
	void Refresh();
};

#endif //GAME_H_INCLUDED_