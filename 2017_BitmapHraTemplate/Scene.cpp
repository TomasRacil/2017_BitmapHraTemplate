#include "StdAfx.h"
#include "Scene.h"

CScene::CScene(void)
{
}

CScene::~CScene(void)
{
}

void CScene::Init(HDC hdc) {


	CCfgFile cfgfile; //dekoder konfiguracniho souboru sceny

	if (cfgfile.LoadFile("scena1.cfg")>=0) { //nacteme konfiguracni soubor sceny
		// konfiguracni soubor muze byt rozdelen na sekce (oddeleny slozenymi zavorkami {})
		// obsahuje vzdy klicove slovo a hodnotu (string nebo cislo) oddelene symbolem rovna se =

		//**** toto je priklad jak nacitat data z konfiguracniho souboru
		int pocet_objektu = cfgfile.GetIntValue(0,"pocet_objektu"); // nacte ze sekce 0 (prvni sekce v souboru) hodnotu klicoveho slova pocet_objektu
		char nazev_objektu[255];
		cfgfile.GetStrValue(0,"nazev_objektu",nazev_objektu); //nacte string ze sekce 0 pod klicem nazev objektu
	}



	m_Drak.LoadData(hdc); //nahrajeme data k objektu Drak
}


void CScene::Render(HDC hdc) {
	m_Drak.Display(hdc); // zobrazime draka

}

void CScene::UserInput(WPARAM wParam) {
	// zpracujeme uzivateluv vstup z klavesnice
		if (wParam==VK_RIGHT) m_Drak.SetDirRight();
		if (wParam==VK_LEFT) m_Drak.SetDirLeft();
		if (wParam==VK_UP) m_Drak.SetDirUp();
		if (wParam==VK_DOWN) m_Drak.SetDirDown();
}

void CScene::Move() {
	m_Drak.Move(); // pohneme drakem
}

