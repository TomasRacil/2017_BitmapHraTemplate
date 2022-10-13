#include "StdAfx.h"
#include "Drak.h"

CDrak::CDrak(void)
{
	m_Direction=0;
	m_AnimRow=0;
	m_X=m_Y=0;
	m_AnimPhase=0;
	m_TimeFrameInterval=250;
	m_MaxAnimPhase=2;
	m_LastTime=GetTickCount();
}

CDrak::~CDrak(void)
{
}


void CDrak::LoadData(HDC dc) {
	m_Btm.LoadBitmap("drak.bmp",dc);
	m_Btm.SetAnim(192,192);
}

void CDrak::Display(HDC dc) {
	m_Btm.DisplayTransparentAnim(dc,m_X,m_Y,m_AnimPhase,m_AnimRow);
}

void CDrak::Move() {
	if ((GetTickCount()-m_LastTime)>m_TimeFrameInterval) { // zmenime animacni fazi jenom pokud uplyne vetsi cas od posledni zmenu nez je nastaveny
		m_AnimPhase++;
		m_LastTime=GetTickCount();
		if (m_AnimPhase>m_MaxAnimPhase) m_AnimPhase=0; // pokud jsme na konci animacnich fazi, tak se vratme na zacatek
		// posuneme se podle smeru, ktery byl nastaven (kazdy snimek, lze pridat timeframeinterval pro zmenu jenom za urceny cas)
		if (m_Direction==DRAK_RIGHT) m_X+=10;
		if (m_Direction==DRAK_LEFT) m_X-=10;
	}

	
}