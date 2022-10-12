#ifndef SOUND_H_INCLUDED_
#define SOUND_H_INCLUDED_

#include "DxLib.h"
#include <map>
#include <string>
using namespace std;

class Sound
{
private:
	bool m_Load;//ロード済みかどうかのフラグ　trueならロード済み
	map<string, int> m_Sounds;//サウンドハンドル

public:
	Sound(void);
	~Sound(void);

	bool Loaded(){ return m_Load; }
	void Load();
	void Play(string song_name, int type, int top);
	void Stop(string song_name);
};

#endif //SOUND_H_INCLUDED_