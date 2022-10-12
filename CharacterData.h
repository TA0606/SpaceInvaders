#ifndef CHARACTERDATA_H_INCLUDED_
#define CHARACTERDATA_H_INCLUDED_

#include "ImgData.h"

struct CharacterData
{
public:
	int ImgIndex;//���݂̃C���[�W���w���v�f�ԍ�
	int Count;//�����J�E���^
	int Life;//�c�@
	int Score;//�ێ��X�R�A
	bool Shot;//�V���b�g�t���O
	bool Death;//���S�t���O
	bool GameOver;//�c�@0�ŕ����s���ǂ��������t���O
	RectEx Rect;//�ʒu�A�T�C�Y
	ImgData Imgs;//�ʏ�C���[�W
	ImgData DeathImgs;//���S���C���[�W

	CharacterData() : ImgIndex(0), Count(0), Life(0), Score(0), Shot(false),
	                    Death(false), GameOver(false), Rect(), Imgs(), DeathImgs(){}
};

#endif //CHARACTERDATA_H_INCLUDED_