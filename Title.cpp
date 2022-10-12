#include "Title.h"

Title::Title(void)
{
	RectEx r = Utils::ClientRectEx();
	m_Imgs.Init(1, 1, r.W, r.H, 0, 0, std::string("./Resources/Sequence/Title.png"));
}

void Title::Refresh()
{
	if(Utils::KeyDownCheck(KEY_INPUT_SPACE) > 0 && m_End == false)
	{
		m_End = true;
		m_NextSequence = Sequence::STAGE_TITLE;
		Utils::SoundPlay("Decide", DX_PLAYTYPE_NORMAL, TRUE);
	}
	else
	{
		Utils::DrawImg(m_Imgs.NowImgHandle(NULL), Utils::ClientRectEx());
	}
}