#include "StdAfx.h"
#include "lenka.h"

CLenka::CLenka(void)
{
	m_Direction=LENKA_RIGHT;
	m_AnimRow=0;
	m_X=m_Y=0;
	m_AnimPhase=0;
	m_TimeFrameInterval=250;
	m_MaxAnimPhase=2;
	m_LastTime=GetTickCount();
	m_Scale=0.3f;
}

CLenka::~CLenka(void)
{
}


void CLenka::LoadData(HDC dc) {
	m_Btm.LoadBitmap("Lenka-dlazdice.bmp",dc);
	m_Btm.SetAnim(512,512);
}

void CLenka::Display(HDC dc) {
	m_Btm.DisplayTransparentAnimScale(dc,m_X,m_Y,m_AnimPhase,m_AnimRow,m_Scale);
}

void CLenka::Move() {
	if ((GetTickCount()-m_LastTime)>m_TimeFrameInterval) { // zmenime animacni fazi jenom pokud uplyne vetsi cas od posledni zmenu nez je nastaveny
		m_AnimPhase++;
		m_LastTime=GetTickCount();
		if (m_AnimPhase>m_MaxAnimPhase) m_AnimPhase=0; // pokud jsme na konci animacnich fazi, tak se vratme na zacatek

		// posuneme se podle smeru, ktery byl nastaven (kazdy snimek, lze pridat timeframeinterval pro zmenu jenom za urceny cas)
		if (m_Direction==LENKA_RIGHT) m_X+=5;
		if (m_Direction==LENKA_LEFT) m_X-=5;
		if (m_Direction==LENKA_UP)  {
			m_Y-=5;
			m_Scale-=0.05f;
		}
		if (m_Direction==LENKA_DOWN) {
			m_Y+=5;
			m_Scale+=0.05f;
		}
	}

	

}