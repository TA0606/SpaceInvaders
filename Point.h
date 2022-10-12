#ifndef POINT_H_INCLUDED_
#define POINT_H_INCLUDED_

struct Point
{
public:
	int X;
	int Y;
	Point() : X(0), Y(0){}
	Point(int x, int y){ X = x; Y = y;}
	void Set(int x, int y){ X = x; Y = y;}
	void Add(int x, int y){ X += x; Y += y;}
};

typedef struct Point Location;

#endif //POINT_H_INCLUDED_