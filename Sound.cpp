#include "Sound.h"

Sound::Sound(void) : m_Load(false)
{
}

Sound::~Sound(void)
{
	map<string, int>::iterator it = m_Sounds.begin();
	while(it != m_Sounds.end())
	{
		DeleteSoundMem((*it).second);
		it++;
	}

	m_Sounds.clear();
}

void Sound::Load()
{
	m_Sounds.insert( pair<string, int>( "HeroShot", LoadSoundMem("./Resources/Sound/HeroShot.wav")) );
	m_Sounds.insert( pair<string, int>( "EnemyShot", LoadSoundMem("./Resources/Sound/EnemyShot.wav")) );
	m_Sounds.insert( pair<string, int>( "TroopMove_1", LoadSoundMem("./Resources/Sound/TroopMove_1.wav")) );
	m_Sounds.insert( pair<string, int>( "TroopMove_2", LoadSoundMem("./Resources/Sound/TroopMove_2.wav")) );
	m_Sounds.insert( pair<string, int>( "TroopMove_3", LoadSoundMem("./Resources/Sound/TroopMove_3.wav")) );
	m_Sounds.insert( pair<string, int>( "TroopMove_4", LoadSoundMem("./Resources/Sound/TroopMove_4.wav")) );
	m_Sounds.insert( pair<string, int>( "UFOTheme", LoadSoundMem("./Resources/Sound/UFOTheme.wav")) );
	m_Sounds.insert( pair<string, int>( "EnemyDead", LoadSoundMem("./Resources/Sound/EnemyDead.wav")) );
	m_Sounds.insert( pair<string, int>( "HeroDead", LoadSoundMem("./Resources/Sound/HeroDead.wav")) );
	m_Sounds.insert( pair<string, int>( "Decide", LoadSoundMem("./Resources/Sound/Decide.wav")) );
	m_Sounds.insert( pair<string, int>( "StageTitle", LoadSoundMem("./Resources/Sound/StageTitle.wav")) );
	m_Sounds.insert( pair<string, int>( "GameOver", LoadSoundMem("./Resources/Sound/GameOver.wav")) );
	m_Sounds.insert( pair<string, int>( "Clear", LoadSoundMem("./Resources/Sound/Clear.wav")) );
	m_Sounds.insert( pair<string, int>( "Ending", LoadSoundMem("./Resources/Sound/Ending.wav")) );
	m_Load = true;
}

void Sound::Play(string song_name, int type, int top)
{
	if(m_Sounds.find(song_name) != m_Sounds.end())
	{
		
		if(PlaySoundMem(m_Sounds[song_name], type, top) == -1)
		{
			song_name += string("ÇÃââëtÇ…é∏îsÇµÇ‹ÇµÇΩÅB");
			MessageBox( GetMainWindowHandle(), song_name.c_str(), "Error", MB_OK);
			exit(-1);
		}
	}
	else
	{
		song_name += string("\nÇÕå©Ç¬Ç©ÇËÇ‹ÇπÇÒÅBèIóπÇµÇ‹Ç∑ÅB");
		MessageBox( GetMainWindowHandle(), song_name.c_str(), "Error", MB_OK);
		exit(-1);
	}
}

void Sound::Stop(string song_name)
{
	if(m_Sounds.find(song_name) != m_Sounds.end())
	{
		if(StopSoundMem(m_Sounds[song_name]) == -1)
		{
			song_name += string("ÇÃââëtí‚é~Ç…é∏îsÇµÇ‹ÇµÇΩÅB");
			MessageBox( GetMainWindowHandle(), song_name.c_str(), "Error", MB_OK);
			exit(-1);
		}
	}
}