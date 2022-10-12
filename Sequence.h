#ifndef SEQUENCE_H_INCLUDED_
#define SEQUENCE_H_INCLUDED_

#include "ImgData.h"

class Sequence
{
protected:
	int m_NextSequence;//SequenceValue�̒l�������@���̃V�[�P���X������킷
	bool m_End;//�V�[�P���X�̏I���t���O�@true�ŏI��
	ImgData m_Imgs;//�V�[�P���X�摜
public:
	enum SequenceValue{ TITLE, STAGE_TITLE, GAME, CLEAR, GAMEOVER, ENDING };//�Z�b�g�V�[�P���X�ɐݒ肷��l
	Sequence() : m_NextSequence(0), m_End(false), m_Imgs(){}
	virtual ~Sequence() = 0 {}
	virtual void Refresh() = 0;
	int Next() const { return m_NextSequence; }
	bool End() const { return m_End; }

};

#endif //SEQUENCE_H_INCLUDED_