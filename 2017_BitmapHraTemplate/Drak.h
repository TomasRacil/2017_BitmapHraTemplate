#pragma once
#include "bitmapa.h"

#define DRAK_LEFT 2
#define DRAK_RIGHT 1
#define DRAK_UP 3
#define DRAK_DOWN 0

class CDrak
{
	CBitmapa m_Btm; // bitmapa s animacemi (dlazdicemi)
	int m_Direction; // smer, kterym se drak pohybuje
	int m_AnimPhase; // cislo animacni faze - index faze(dlazdice) v bitmape 
	int m_AnimRow; // cislo radku v bitmape pro animacni fazi
	int m_MaxAnimPhase; // maximalni index animacni faze (dlazdice) v bitmape  
	DWORD m_TimeFrameInterval; // interval v ms kdy se bude menit animacni faze
	DWORD m_LastTime; // posledni cas, kdy se menila animacni faze

	int m_X; // pozice draka na obrazovce
	int m_Y;

public:
	void LoadData(HDC dc);
	void Display(HDC dc);
	void Move();
	void SetDirRight() { m_Direction=DRAK_RIGHT; m_AnimRow=2;};
	void SetDirLeft() { m_Direction=DRAK_LEFT; m_AnimRow=1;};
	void SetDirUp() { m_Direction=DRAK_UP; m_AnimRow=3;};
	void SetDirDown() { m_Direction=DRAK_DOWN; m_AnimRow=0;};
	CDrak(void);
	~CDrak(void);
};
