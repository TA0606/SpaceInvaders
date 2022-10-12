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
	int m_XNum;//画像の横方向の数
	int m_YNum;//画像の縦方向の数
	int m_W;//1つの画像の幅
	int m_H;//１つの画像の高さ
	int m_Start;//開始インデックス
	vector<int> m_Handles;//画像ハンドル

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
	int NowImgHandle(int now_count);//現在のカウントで表示すべき画像ハンドルを返す。
	void Init(int x_num, int y_num, int w, int h, int start,int speed_scale, string path);//データメンバ初期化

};

#endif //IMGDATA_H_INDLUDED_