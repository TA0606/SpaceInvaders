#ifndef PILLBOX_H_INCLUDED_
#define PILLBOX_H_INCLUDED_

#include "DxLib.h"
#include "RectEx.h"
#include "Utils.h"

//�g�[�`�J
class Pillbox
{
private:
	int m_ImgHandle;//���ۂ̕`��Ɏg���摜�n���h��
	int m_SoftImg;//�摜����pCPU�����C���[�W
	int m_SoftMaskImg;//�}�X�N�pCPU�����C���[�W
	RectEx m_Rect;//�ʒu�A�T�C�Y

	void CutForBullet(RectEx r);//�摜��؂���@�e�Փˎ��Ɏg�p����B
	void CutFill(RectEx r);//�摜��؂���@�L�����N�^�Փˎ��Ɏg�p����B
	bool CheckPixel(RectEx r);//��f����@true�ŏՓ�

public:
	Pillbox(Location loc);
	~Pillbox(void);

	RectEx GetRect(){ return m_Rect; }
	bool Collision(RectEx r, bool bullet);//�g�[�`�J�Ƃ̏Փ˔���@��2�����F�e�Ȃ�true���Z�b�g(���ʂȏ����̂��߁j
	void Draw();
};

#endif //PILLBOX_H_INCLUDED_