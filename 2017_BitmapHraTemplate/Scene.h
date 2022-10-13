#pragma once

#include "stdafx.h"
#include "drak.h"
#include "lenka.h"
#include "cfgfile.h"


class CScene
{
	//vytvorime nase hlavni objekty
	CDrak m_Drak; // draka

public:
	void Init(HDC hdc);
	void Render(HDC hdc);
	void UserInput(WPARAM wParam);
	void Move();
	CScene(void);
	~CScene(void);
};
