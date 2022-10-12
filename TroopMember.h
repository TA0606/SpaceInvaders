#ifndef TROOPMEMBER_H_INCLUDED_
#define TROOPMEMBER_H_INCLUDED_

#include "Utils.h"
#include "CharacterData.h"

//�C���x�[�_�[�R�̑���
//�����g��ňړ�����̂�EnemyTroops�ɂ���čs���͊Ǘ������
class TroopMember
{
protected:
	CharacterData m_Data;

public:
	TroopMember();
	virtual ~TroopMember() = 0 {}
	virtual void Kill();//�E��
	virtual void Action();//����
	virtual void Move(Location loc);//�ړ��i�����ŏ���ɓ����̂ł͂Ȃ��A�Ǘ������j
	virtual void Draw();//�`��
	int GetScore() const { return m_Data.Score; }//�X�R�A�𓾂�
	bool GetShotFlag() const{ return m_Data.Shot; }//�V���b�g�t���O���擾 true�ŃV���b�g
	bool IsDead() const { return m_Data.Death; }//����ł邩�H�@true�Ŏ��S��
	bool GameIsOver() const { return m_Data.GameOver; }//�c�@�O�ŃQ�[���I�[�o�[���H true�ŃQ�[���I�[�o�[
	RectEx GetRect() const { return m_Data.Rect; }//�l�p�`�𓾂�
	int GetAnimationSpeed() const { return m_Data.Imgs.GetAnimationSpeed(); }//���݂̐������A�j���[�V�����X�s�[�h��Ԃ�
	void SetShotFlag(bool f){ m_Data.Shot = f; }//�V���b�g�t���OSet
	void AddAnimationSpeed(int s){ m_Data.Imgs.SetAnimationSpeed(GetAnimationSpeed() + s);};//�A�j���[�V�����X�s�[�h��������
};

#endif //TROOPMEMBER_H_INCLUDED_