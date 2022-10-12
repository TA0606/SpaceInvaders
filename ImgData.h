#ifndef IMGDATA_H_INDLUDED_
#define IMGDATA_H_INDLUDED_

#include <vector>
#include <string>
#include "Utils.h"
using namespace std;

class ImgData
{
private:
	int m_AnimationSpeed;
	int m_Division;
	int m_XNum;//�摜�̉������̐�
	int m_YNum;//�摜�̏c�����̐�
	int m_W;//1�̉摜�̕�
	int m_H;//�P�̉摜�̍���
	int m_Start;//�J�n�C���f�b�N�X
	vector<int> m_Handles;//�摜�n���h��

public:
	ImgData(void);
	~ImgData(void);
	int GetXNum() const { return m_XNum; }
	int GetYNum() const { return m_YNum; }
	int GetW() const { return m_W; }
	int GetH() const { return m_H;}
	int GetStartIndex() const { return m_Start; }
	int GetAnimationSpeed() const { return m_AnimationSpeed / m_XNum; }
	void SetAnimationSpeed(int s);
	void SetStart(int index){ m_Start = index; }
	int NowImgHandle(int now_count);//���݂̃J�E���g�ŕ\�����ׂ��摜�n���h����Ԃ��B
	void Init(int x_num, int y_num, int w, int h, int start,int speed_scale, string path);//�f�[�^�����o������

};

#endif //IMGDATA_H_INDLUDED_