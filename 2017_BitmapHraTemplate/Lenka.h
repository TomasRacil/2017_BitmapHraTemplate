#pragma once
#include "bitmapa.h"

#define LENKA_LEFT 2
#define LENKA_RIGHT 1
#define LENKA_UP 3
#define LENKA_DOWN 0

class CLenka
{
	CBitmapa m_Btm; // bitmapa s animacemi (dlazdicemi)
	int m_Direction; // smer, kterym se LENKA pohybuje
	int m_AnimPhase; // cislo animacni faze - index faze(dlazdice) v bitmape 
	int m_AnimRow; // cislo radku v bitmape pro animacni fazi
	int m_MaxAnimPhase; // maximalni index animacni faze (dlazdice) v bitmape  
	DWORD m_TimeFrameInterval; // interval v ms kdy se bude menit animacni faze
	DWORD m_LastTime; // posledni cas, kdy se menila animacni faze
	float m_Scale; // zvetseni  - meritko postavy

	int m_X; // pozice LENKAa na obrazovce
	int m_Y;

public:
	void LoadData(HDC dc);
	void Display(HDC dc);
	void Move();
	void SetDirRight() { m_Direction=LENKA_RIGHT; m_AnimRow=1;};
	void SetDirLeft() { m_Direction=LENKA_LEFT; m_AnimRow=0;};
	void SetDirUp() { m_Direction=LENKA_UP; m_AnimRow=2;};
	void SetDirDown() { m_Direction=LENKA_DOWN; m_AnimRow=3;};
	CLenka(void);
	~CLenka(void);
};
