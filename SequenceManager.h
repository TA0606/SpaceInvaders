#ifndef SEQUENCEMANAGER_H_INCLUDED_
#define SEQUENCEMANAGER_H_INCLUDED_

#include "Sequence.h"
#include "Title.h"
#include "StageTitle.h"
#include "Game.h"
#include "Clear.h"
#include "GameOver.h"
#include "Ending.h"
#include <memory>
using namespace std;

class SequenceManager
{
private:
	SequenceManager(void);//Create�ō쐬
	~SequenceManager(void);
	shared_ptr<Sequence> m_Sequence;//�\���V�[�P���X
	static int m_StageNum;//�X�e�[�W�ԍ�
	static SequenceManager* m_Instance;//���̎���

	SequenceManager(const SequenceManager& r);
    SequenceManager& operator=(const SequenceManager& r);

public:
	static void Create();//���̍쐬
	static void Delete();//���̏���
	static SequenceManager* GetInstance();//���̂̎擾
	void SetSequence(int type);//�\������V�[�P���X�̃Z�b�g
	void Refresh();//��ʂ̍X�V
};

#endif //SEQUENCEMANAGER_H_INCLUDED_