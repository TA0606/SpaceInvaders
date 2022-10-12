#include "Pillbox.h"

Pillbox::Pillbox(Location loc) : m_ImgHandle(0), m_SoftImg(0), m_SoftMaskImg(0), m_Rect()
{
	m_Rect.Set(loc, 60, 45);
	m_SoftImg = LoadSoftImage("./Resources/Pillbox/Pillbox.png");
	m_SoftMaskImg = LoadSoftImage("./Resources/Pillbox/Mask.png");
	m_ImgHandle = CreateGraphFromSoftImage(m_SoftImg);
}

Pillbox::~Pillbox(void)
{
	DeleteGraph(m_ImgHandle);
	DeleteSoftImage(m_SoftImg);
	DeleteSoftImage(m_SoftMaskImg);
}

void Pillbox::CutForBullet(RectEx r)//独特の破壊された感じで塗りつぶす （マスクイメージに依存）
{
	int W, H, mask_W, mask_H, R, G, B, A;
	r.Add(-m_Rect.X, -m_Rect.Y, 0, 0);

	GetSoftImageSize(m_SoftImg, &W, &H);
	GetSoftImageSize(m_SoftMaskImg, &mask_W, &mask_H);
	int add_W = (mask_W - r.W);
	int add_H = (mask_H - r.H);
	r.Add(-(add_W / 2), -(add_H / 2), add_W, add_H);

	for(int x = 0; x <= mask_W; x++)
	{
		for(int y = 0; y <= mask_H; y++)
		{
			if( r.X + x >= 0 && r.X + x <= W && r.Y + y >= 0 && r.Y + y <= H)
			{
				GetPixelSoftImage(m_SoftMaskImg, x, y, &R, &G, &B, &A);
				if(A != 0) DrawPixelSoftImage(m_SoftImg, r.X + x, r.Y + y, R, G, B, A);
			}
		}
	}

	m_ImgHandle = CreateGraphFromSoftImage(m_SoftImg);
}

void Pillbox::CutFill(RectEx r)//全部黒で塗りつぶす
{
	int W, H, R = 0, G = 0, B = 0, A = 255;
	r.Add(-m_Rect.X, -m_Rect.Y, 0, 0);

	GetSoftImageSize(m_SoftImg, &W, &H);
	int right = r.Right(), bottom = r.Bottom();

	for(int x = r.X; x <= right; x++)
	{
		for(int y = r.Y; y <= bottom; y++)
		{
			if( x >= 0 && x <= W && y >= 0 && y <= H)
			{
				DrawPixelSoftImage(m_SoftImg, x, y, R, G, B, A);
			}
		}
	}

	m_ImgHandle = CreateGraphFromSoftImage(m_SoftImg);
}

bool Pillbox::CheckPixel(RectEx r)
{
	int W, H, R, G, B, A;
	bool collision = false;
	r.Add(-m_Rect.X, -m_Rect.Y, 0, 0);//チェックのための座標に変更
	GetSoftImageSize(m_SoftImg, &W, &H);

	for(int x = r.X; x <= r.Right() && collision == false; x++)
	{
		for(int y = r.Y; y <= r.Bottom() && collision == false; y++)
		{
			GetPixelSoftImage(m_SoftImg, x, y, &R, &G, &B, &A);

			if(R == 0 && G == 48 && B == 255) collision = true;
		}
	}

	return collision;
}

bool Pillbox::Collision(RectEx r, bool bullet)
{
	if(Utils::Collision(m_Rect, r))//画像内に入っているか
	{
		if( CheckPixel(r) )
		{
			if(bullet) CutForBullet(r);
			else CutFill(r);

			return true;
		}
	}

	return false;
}

void Pillbox::Draw()
{
	Utils::DrawImg(m_ImgHandle, m_Rect);
}