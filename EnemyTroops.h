#ifndef ENEMYTROOPS_H_INCLUDED_
#define ENEMYTROOPS_H_INCLUDED_

#include "TroopMemberCreator.h"
#include <memory>
using namespace std;

//�C���x�[�_�[�R�i�G�j�@�S���ɋK���I�ȓ����������邽�߃N���X��
class EnemyTroops
{
private:
	int m_Direction;//�R�̈ړ�����
	int m_InvasionY;//�N������Y���W
	int m_Count;//�����J�E���^
	int m_Speed;//�ړ����x
	bool m_Down;//���ֈړ�����t���O�iDirectionValue�Ɋ܂߂�Ǝ��ɐi�ޕ������E�������̔��ʏ����������邽�ߕʂɂ��Ă���B�j
	int m_NextMove;//���Ɉړ�����G�͒N��
	Location m_MoveVal;
	bool m_Move;
	int m_SoundIndex;
	vector<string> m_Sounds;
	vector< shared_ptr<TroopMember> > m_Enemies;//�G�B
	int EdgeOfTroops(int direction);//���[�܂��͉E�[�̃L�����N�^�C���f�b�N�X��Ԃ��@�����ɂ�DirectionValue���Z�b�g����
	int AliveLength();//�����Ă���G�̐�
	int CalcMove_X();//���܂��͉E�ւ̈ړ��ʂ̌v�Z

public:
	EnemyTroops(Location start, int invasion_y);
	~EnemyTroops(void);

	enum DirectionValue{ LEFT, RIGHT, };

	int Length(){ return static_cast<int>(m_Enemies.size()); }//�R�̓G����Ԃ�
	int GetScore(int num) const { return m_Enemies[num]->GetScore(); }//�w��̓G�̃X�R�A��Ԃ�
	bool GetShotFlag(int num){ return m_Enemies[num]->GetShotFlag(); }//�w��̓G�̔��˃t���O�𓾂�
	bool IsDead(int num){ return m_Enemies[num]->IsDead(); }//�w��̓G������ł��邩
	bool GameIsOver(int num){ return m_Enemies[num]->GameIsOver(); }//�w��̓G���Q�[���I�[�o�[��
	bool IsAnnihilation();//�S�ł��H�@true�Ȃ�S��
	bool CheckInvasion();//�N���������ǂ��� true�ŐN������
	RectEx GetRect(int num){ return m_Enemies[num]->GetRect(); }//�w��̓G�̎l�p�`�𓾂�B
	void Kill(int num);
	void Action();//�S�R�̓���
	void Move();//�S�R�̈ړ�
	void Draw();//�S�R�̕`��
};

#endif //ENEMYTROOPS_H_INCLUDED_