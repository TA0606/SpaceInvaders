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
	SequenceManager(void);//Createで作成
	~SequenceManager(void);
	shared_ptr<Sequence> m_Sequence;//表示シーケンス
	static int m_StageNum;//ステージ番号
	static SequenceManager* m_Instance;//この実体

	SequenceManager(const SequenceManager& r);
    SequenceManager& operator=(const SequenceManager& r);

public:
	static void Create();//実体作成
	static void Delete();//実体消去
	static SequenceManager* GetInstance();//実体の取得
	void SetSequence(int type);//表示するシーケンスのセット
	void Refresh();//画面の更新
};

#endif //SEQUENCEMANAGER_H_INCLUDED_