
// Kurs1.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CKurs1App:
// � ���������� ������� ������ ��. Kurs1.cpp
//

class CKurs1App : public CWinApp
{
public:
	CKurs1App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CKurs1App theApp;