#include "ImgData.h"

ImgData::ImgData(void) : 
m_AnimationSpeed(0), m_Division(0), m_XNum(0),
m_YNum(0), m_W(0), m_H(0), m_Start(0), m_Handles()
{}

ImgData::~ImgData(void)
{
	vector<int>::iterator it = m_Handles.begin();

	while(it != m_Handles.end())
	{
		DeleteGraph(*it);
		it++;
	}

	m_Handles.clear();
}

void ImgData::SetAnimationSpeed(int s)
{
	m_AnimationSpeed = m_XNum * (s <= 0 ? 1 : s);
	m_Division = m_AnimationSpeed / m_XNum;
}

//データメンバの初期化
//第6引数にはアニメーション速度の倍率を入れる 1以上で大きくなるほどアニメーション速度が遅くなる
//第7引数には画像のパスを入れる。（相対可）
void ImgData::Init(int x_num, int y_num, int w, int h, int start, int speed_scale, string path)
{
	m_XNum = x_num;
	m_YNum = y_num;
	m_W = w;
	m_H = h;
	m_Start = start;
	m_AnimationSpeed = m_XNum * (speed_scale <= 0 ? 1 : speed_scale);
	m_Division = m_AnimationSpeed / m_XNum;

	int total = m_XNum * m_YNum;
	int* temp_imgs = new int[total];

	if(LoadDivGraph(path.c_str(), total, m_XNum, m_YNum, m_W, m_H, temp_imgs) == -1)
	{
		string result("ファイルの読込に失敗しました。終了します。[File] ");
		result += path;
		Utils::ErrorProcess(result);
		delete [] temp_imgs;
		exit( -1 );
	}
	
	m_Handles.clear();

	for(int i = 0; i < total; i++)
	{
		m_Handles.push_back(temp_imgs[i]);
	}

	delete [] temp_imgs;
}

//現在のカウントで表示すべき画像ハンドルを返す。
int ImgData::NowImgHandle(int now_count)
{
	int index = (now_count % m_AnimationSpeed) / m_Division;
	return m_Handles[m_Start + index];
}