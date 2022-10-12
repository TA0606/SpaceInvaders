#ifndef UTILS_H_INCLUDED_
#define UTILS_H_INCLUDED_

#include "DxLib.h"
#include "RectEx.h"
#include "Sound.h"

class Utils
{
private:
	static int KeyState[256];//�L�[��Ԃ��i�[���܂��B0�Ŗ����͏�ԁA�P�ȏ�Ȃ���͏�Ԃł��B
	static Sound SoundManager;//�T�E���h�Ǘ��N���X

public:
	static void SoundStop(string song_name);//�T�E���h�̒�~
	static void SoundPlay(string song_name, int type, int top);//�T�E���h�̍Đ�
	static bool WithinLimits(RectEx r);//�l�p�`���N���C�A���g�̈�ȓ����ǂ����𔻒f�ireturn�j�g��=true, �g�O=false
	static bool WithinLimits(Location loc);//�ʒu���N���C�A���g�̈�ȓ����ǂ����𔻒f�ireturn�j�g��=true, �g�O=false
	static RectEx ClientRectEx();//�N���C�A���g�̈�̎l�p�`���擾����
	static void DrawImg(int handle, RectEx r);//�摜�𓙔{��r��XY�ʒu�ɕ`�悵�܂��B
	static bool Collision(RectEx r1, RectEx r2);//�Փ˔�����s���B(return)�Փ�=true�A���Փ�=false
	static int KeyDownCheck(int key);//�L�[���͂��`�F�b�N����@(return)�L�[���̓J�E���g
	static bool KeyStateUpdate();//KeyDownCheck�̑O�ɌĂяo���A�L�[��Ԃ��X�V���܂��B(return)����=true, ���s=false
	static void ErrorProcess(std::string err_msg);//�G���[�������s��
};

#endif //UTILS_H_INCLUDED_