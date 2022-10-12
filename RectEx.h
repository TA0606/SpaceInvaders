#ifndef RECTEX_H_INDLUDED_
#define RECTEX_H_INDLUDED_

#include "Point.h"

struct RectEx
{
public:
	int X;
	int Y;
	int W;
	int H;

	RectEx(void) : X(0), Y(0), W(0), H(0){}
	RectEx(int x, int y, int w, int h){ X = x; Y = y; W = w; H = h; }
	RectEx(const RectEx& r){ X = r.X; Y = r.Y; W = r.W; H = r.H; }
	RectEx(const Location& loc, int w, int h){ X = loc.X; Y = loc.Y; W = w; H = h; }

	int Top(){ return Y; }
	int Bottom(){ return (Y + H); }
	int Left(){ return X; }
	int Right(){ return (X + W); }
	int CenterX(){ return (X + W / 2); }//中心X座標
	int CenterY(){ return (Y + H / 2); }//中心Y座標
	void Add(int x, int y, int w, int h){ X += x; Y += y; W += w; H += h; }
	void Add(RectEx r){ X += r.X; Y += r.Y; W += r.W; H += r.H; }
	void Add(Location loc){ X += loc.X; Y += loc.Y;}
	void Add(Location loc, int w, int h){ X += loc.X; Y += loc.Y; W += w; H += h; }
	void Set(int x, int y, int w, int h){ X = x; Y = y; W = w; H = h; }
	void Set(RectEx r){ X = r.X; Y = r.Y; W = r.W; H = r.H; }
	void Set(Location loc){ X = loc.X; Y = loc.Y;}
	void Set(Location loc, int w, int h){ X = loc.X; Y = loc.Y; W = w; H = h; }
};

#endif //RECTEX_H_INDLUDED_