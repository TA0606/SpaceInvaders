#include "EnemyTroops.h"

EnemyTroops::EnemyTroops(Location start, int invasion_y) :
	m_Direction(RIGHT), m_InvasionY(invasion_y), m_Count(0), m_Speed(20), m_SoundIndex(-1), m_Down(false), m_NextMove(0), m_MoveVal(), m_Move(false)
{
	m_Sounds.push_back("TroopMove_1");
	m_Sounds.push_back("TroopMove_2");
	m_Sounds.push_back("TroopMove_3");
	m_Sounds.push_back("TroopMove_4");

	const int kind = 5;//�G�̎��
	const int space = 10;//�G�̌���
	int length[kind] = { 13, 13, 13, 13, 13 };//�e�G�̐�
	int type[kind] = { TroopMemberCreator::TYPE_B, TroopMemberCreator::TYPE_A, TroopMemberCreator::TYPE_A, TroopMemberCreator::TYPE_C, TroopMemberCreator::TYPE_C };//�G�̃^�C�v
	Location loc(start);

	for (int i = 0; i < kind; i++)
	{
		for (int z = 0; z < length[i]; z++)
		{
			m_Enemies.push_back(shared_ptr<TroopMember>(TroopMemberCreator::Create(type[i], loc)));
			loc.Add(m_Enemies[i]->GetRect().W + space, 0);
		}

		loc.X = start.X;
		loc.Add(0, m_Enemies[i * length[i]]->GetRect().H + space);
	}
}

EnemyTroops::~EnemyTroops(void)
{
	m_Enemies.clear();
}

int EnemyTroops::AliveLength()
{
	int alive = 0;
	for (int i = 0, size = Length(); i < size; i++)
	{
		if (m_Enemies[i]->GameIsOver() == false) alive++;
	}

	return alive;
}

bool EnemyTroops::IsAnnihilation()
{
	for (int i = 0, size = Length(); i < size; i++)
	{
		if (!m_Enemies[i]->GameIsOver()) return false;
	}

	return true;
}

bool EnemyTroops::CheckInvasion()
{
	//���S�`�F�b�N�͏Ȃ��i����ł��炻�̏�ňړ���߂�̂�m_InvasionY�ɓ��B���邱�Ƃ͂Ȃ�����j
	for (int i = 0, size = Length(); i < size; i++)
	{
		if (m_Enemies[i]->GetRect().Bottom() >= m_InvasionY) return true;
	}

	return false;
}

int EnemyTroops::EdgeOfTroops(int direction)
{
	int index = 0;

	for (int i = 0, size = Length(); i < size; i++)
	{
		if (m_Enemies[i]->IsDead() == false)
		{
			index = i;
			break;
		}
	}

	for (int i = index + 1, size = Length(); i < size; i++)
	{
		if (m_Enemies[i]->IsDead() == false)
		{
			if (direction == LEFT)//��
				index = (m_Enemies[index]->GetRect().X < m_Enemies[i]->GetRect().X ? index : i);
			else//�E
				index = (m_Enemies[index]->GetRect().Right() > m_Enemies[i]->GetRect().Right() ? index : i);
		}
	}

	return index;
}

void EnemyTroops::Kill(int num)
{
	m_Enemies[num]->Kill();

	int alive = AliveLength();

	if (alive <= 32 && alive > 0)
	{
		int anim_speed = 2;

		for (int i = 0, size = Length(); i < size; i++)//�A�j���[�V�������x���グ��
		{
			m_Enemies[i]->AddAnimationSpeed(-anim_speed);
		}
	}
}

void EnemyTroops::Action()
{
	m_Count++;
	int shot_num = 0;

	for (int i = 0, size = Length(); i < size; i++)
	{
		m_Enemies[i]->Action();
		m_Enemies[i]->SetShotFlag(false);//�V���b�g����U�N���A
	}

	if (m_Count % 50 == 0)//50�J�E���g�����Ƀ����_���ɒN��������
	{
		SRand(GetNowCount());
		int index = GetRand(Length() - 1);

		if (!m_Enemies[index]->IsDead()) m_Enemies[index]->SetShotFlag(true);//����łȂ�������V���b�g�̃Z�b�g
	}
}

int EnemyTroops::CalcMove_X()
{
	int x = 0;
	RectEx r(m_Enemies[EdgeOfTroops(m_Direction)]->GetRect());

	if (m_Direction == LEFT)
	{
		x = -m_Speed;
		r.Add(Point(-m_Speed, 0));

		if (!Utils::WithinLimits(r))
		{
			x += Utils::ClientRectEx().X - r.X;//�݂͂����Ȃ��悤�ړ��ʒ���
			m_Direction = RIGHT;
			m_Down = true;
		}
	}
	else
	{
		x = m_Speed;
		r.Add(Point(m_Speed, 0));

		if (!Utils::WithinLimits(r))
		{
			x += Utils::ClientRectEx().Right() - r.Right();//�݂͂����Ȃ��悤�ړ��ʒ���
			m_Direction = LEFT;
			m_Down = true;
		}
	}

	return x;
}

void EnemyTroops::Move()
{
	if (m_Move)
	{
		while (m_NextMove >= 0 && m_Enemies[m_NextMove]->IsDead())m_NextMove--;

		if (m_NextMove < 0)//���Ɉړ����ׂ��G���ȓ��Ȃ珈����Ԃ��B
		{
			m_Move = false;
			return;
		}

		m_Enemies[m_NextMove]->Move(m_MoveVal);//�����ׂ��G�𓮂���
		m_NextMove--;

		if (m_NextMove < 0) m_Move = false;
		return;
	}

	if (m_Count % m_Enemies[0]->GetAnimationSpeed() != 0) return;//�`��X�V��������Ȃ�������Ԃ��i�������Ȃ�������\�����邽�߁j
	m_SoundIndex = (m_SoundIndex + 1) % static_cast<int>(m_Sounds.size());
	Utils::SoundPlay(m_Sounds[m_SoundIndex], DX_PLAYTYPE_BACK, TRUE);//�����Ȃ炷�iBGM�����ł͑ʖځB�A�j���[�V�����Ɠ����ɖ炳�Ȃ��Ƒ��xUP�ɑΉ��ł��Ȃ��j

	m_MoveVal.Set(0, 0);

	if (m_Down)
	{
		m_MoveVal.Y = 15;
		m_Down = false;
	}
	else
	{
		m_MoveVal.X = CalcMove_X();
	}

	m_NextMove = Length() - 1;
	m_Move = true;
}

void EnemyTroops::Draw()
{
	for (int i = 0, size = Length(); i < size; i++)
	{
		m_Enemies[i]->Draw();
	}
}
