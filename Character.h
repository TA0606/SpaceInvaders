#ifndef CHARACTER_H_INCLUDED_
#define CHARACTER_H_INCLUDED_

#include "Utils.h"
#include "CharacterData.h"

//�e�L�����N�^�[�̃x�[�X�ƂȂ�N���X
class Character
{
protected:
	CharacterData m_Data;

public:
	Character() : m_Data(){}
	virtual ~Character(void) = 0{}

	virtual void Move() = 0;//�ړ�
	virtual void Action() = 0;//����
	virtual void Kill();//�E��
	virtual void Draw();//�`��
	int GetScore() const { return m_Data.Score; }//�X�R�A�𓾂�
	int GetLife() const { return m_Data.Life; }//�c�@�𓾂�
	bool GetShotFlag() const{ return m_Data.Shot; }//�V���b�g�t���O���擾 true�ŃV���b�g
	bool IsDead() const { return m_Data.Death; }//����ł邩�H�@true�Ŏ��S��
	bool GameIsOver() const { return m_Data.GameOver; }//�c�@�O�ŃQ�[���I�[�o�[���H true�ŃQ�[���I�[�o�[
	RectEx GetRect() const { return m_Data.Rect; }//�l�p�`�𓾂�
};

#endif //CHARACTER_H_INCLUDED_