#ifndef SEQUENCE_H_INCLUDED_
#define SEQUENCE_H_INCLUDED_

#include "ImgData.h"

class Sequence
{
protected:
	int m_NextSequence;//SequenceValueの値をいれる　次のシーケンスをあらわす
	bool m_End;//シーケンスの終了フラグ　trueで終了
	ImgData m_Imgs;//シーケンス画像
public:
	enum SequenceValue{ TITLE, STAGE_TITLE, GAME, CLEAR, GAMEOVER, ENDING };//セットシーケンスに設定する値
	Sequence() : m_NextSequence(0), m_End(false), m_Imgs(){}
	virtual ~Sequence() = 0 {}
	virtual void Refresh() = 0;
	int Next() const { return m_NextSequence; }
	bool End() const { return m_End; }

};

#endif //SEQUENCE_H_INCLUDED_