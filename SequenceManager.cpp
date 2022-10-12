#include "SequenceManager.h"

int SequenceManager::m_StageNum = 0;
SequenceManager* SequenceManager::m_Instance = NULL;

SequenceManager::SequenceManager(void) : m_Sequence()
{
	SetSequence(Sequence::TITLE);
}

SequenceManager::~SequenceManager(void)
{
}

void SequenceManager::Create()
{
	m_Instance = new SequenceManager();
}

void SequenceManager::Delete()
{
	delete m_Instance;
	m_Instance = NULL;
}

SequenceManager* SequenceManager::GetInstance()
{
	return m_Instance;
}

void SequenceManager::SetSequence(int type)
{
	switch(type)
	{
	case Sequence::TITLE:
		m_StageNum = 0;
		m_Sequence.reset(new Title());
		break;
	case Sequence::STAGE_TITLE:
		m_Sequence.reset(new StageTitle(m_StageNum));
		break;
	case Sequence::GAME:
		m_Sequence.reset(new Game(m_StageNum));
		break;
	case Sequence::CLEAR:
		m_StageNum++;
		m_Sequence.reset(new Clear(m_StageNum));
		break;
	case Sequence::GAMEOVER:
		m_Sequence.reset(new GameOver());
		break;
	case Sequence::ENDING:
		m_Sequence.reset(new Ending());
		break;
	}
}

void SequenceManager::Refresh()
{
	if(m_Instance->m_Sequence->End() == true)
		SetSequence(m_Instance->m_Sequence->Next());

	m_Instance->m_Sequence->Refresh();
}