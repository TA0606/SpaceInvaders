#include "Clear.h"

Clear::Clear(int stage) :m_Count(0)
{
	RectEx r = Utils::ClientRectEx();
	m_Imgs.Init(1, 1, r.W, r.H, 0, 0, std::string("./Resources/Sequence/Clear.png"));
	Utils::SoundPlay("Clear", DX_PLAYTYPE_BACK, TRUE);
}

void Clear::Refresh()
{
	if(m_Count > 200 && m_End == false)
	{
		m_End = true;
		m_NextSequence = Sequence::STAGE_TITLE;
	}
	else
	{
		Utils::DrawImg(m_Imgs.NowImgHandle(NULL), Utils::ClientRectEx());
		m_Count++;
	}
}