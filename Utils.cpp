#include "Utils.h"

int Utils::KeyState[256] = {};//�����l�͑S��0
Sound Utils::SoundManager;

//�T�E���h�̒�~
void Utils::SoundStop(string song_name)
{
	if(SoundManager.Loaded()) SoundManager.Stop(song_name);
}

//�T�E���h�̍Đ�
void Utils::SoundPlay(string song_name, int type, int top)
{
	if(!SoundManager.Loaded()) SoundManager.Load();
	SoundManager.Play(song_name, type, top);
}

//�l�p�`���N���C�A���g�̈�ȓ����ǂ����𔻒f�ireturn�j�g��=true, �g�O=false
bool Utils::WithinLimits(RectEx r)
{
	RectEx client_r = ClientRectEx();

	if(r.Left() < client_r.Left() || r.Right() > client_r.Right() ||
		r.Top() < client_r.Top() || r.Bottom() > client_r.Bottom())
	{
		return false;
	}

	return true;
}

//�ʒu���N���C�A���g�̈�ȓ����ǂ����𔻒f�ireturn�j�g��=true, �g�O=false
bool Utils::WithinLimits(Location loc)
{
	RectEx client_r = ClientRectEx();

	if(loc.X < client_r.Left() || loc.X > client_r.Right() ||
		loc.Y < client_r.Top() || loc.Y  > client_r.Bottom())
	{
		return false;
	}

	return true;
}

//�N���C�A���g�̈�̎l�p�`���擾����
RectEx Utils::ClientRectEx()
{
	RECT t_r;
	GetWindowCRect(&t_r);//t_r�ɂ̓E�B���h�E�̈ʒu���i�[�B
	return ( RectEx(0, 0, t_r.right - t_r.left, t_r.bottom - t_r.top) );//�L�����N�^���W�Ŏg����悤�ɕϊ�����
}

//�摜�𓙔{��r��XY�ʒu�ɕ`�悵�܂��B
void Utils::DrawImg(int handle, RectEx r)
{
	if(DrawGraph(r.X, r.Y, handle, TRUE) == -1)
	{
		ErrorProcess("�`��Ɏ��s���܂����B");
		exit(-1);
	}
}

//�Փ˔�����s���B(return)�Փ�=true�A���Փ�=false
bool Utils::Collision(RectEx r1, RectEx r2)
{
	if( r1.X < r2.Right() && r2.X < r1.Right() && r1.Y < r2.Bottom() && r2.Y < r1.Bottom())
		return true;
	else
		return false;
}

//�L�[���͂��`�F�b�N����@(return)�L�[���̓J�E���g
int Utils::KeyDownCheck(int key)
{
	return KeyState[key];
}

//KeyDownCheck�̑O�ɌĂяo���A�L�[��Ԃ��X�V���܂��B(return)����=true, ���s=false
bool Utils::KeyStateUpdate()
{
	char tempKeys[256];

	if(GetHitKeyStateAll( tempKeys ) == -1) return false;

	for( int i=0; i<256; i++ )
	{ 
			if( tempKeys[i] != 0 ) 
				KeyState[i]++;
			else
				KeyState[i] = 0;
	}

	return true;
}

void Utils::ErrorProcess(std::string err_msg)
{
	MessageBox( GetMainWindowHandle(),  err_msg.c_str(), "Error", MB_OK);
	ErrorLogAdd(err_msg.c_str());
}