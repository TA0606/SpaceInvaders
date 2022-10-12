#include "StageTitle.h"

StageTitle::StageTitle(int stage) : m_StageNum(0), m_Count(0)
{
	m_StageNum = stage;
	RectEx r = Utils::ClientRectEx();
	m_Imgs.Init(1, 1, r.W, r.H, 0, 0, std::string("./Resources/Sequence/StageTitle.png"));
	Utils::SoundPlay("StageTitle", DX_PLAYTYPE_BACK, TRUE);
}

void StageTitle::Refresh()
{
	if(m_Count > 200 && m_End == false)
	{
		m_End = true;
		m_NextSequence = Sequence::GAME;
	}
	else
	{
		int s_height = 24;
		int s_width = GetDrawFormatStringWidth("STAGE%d", m_StageNum + 1);
		RectEx client_r = Utils::ClientRectEx();
		Location loc(client_r.CenterX() - (s_width / 2), client_r.CenterY() - (s_height / 2));
		SetFontSize(s_height);
		ChangeFontType(DX_FONTTYPE_ANTIALIASING);
		Utils::DrawImg(m_Imgs.NowImgHandle(NULL), client_r);
		DrawFormatString(loc.X, loc.Y, GetColor(255, 255, 255), "STAGE%d", m_StageNum + 1);
		m_Count++;
	}
}