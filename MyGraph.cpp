// MyGraph.cpp: файл реализации
//

#include "stdafx.h"
#include "Kurs1.h"
#include "MyGraph.h"
//#include "Kurs1Dlg.h"

// CMyGraph

IMPLEMENT_DYNAMIC(CMyGraph, CStatic)

CMyGraph::CMyGraph()
: mR(255)
, mG(128)
{

}

CMyGraph::~CMyGraph()
{
}


BEGIN_MESSAGE_MAP(CMyGraph, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// обработчики сообщений CMyGraph




void CMyGraph::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CStatic::OnPaint() for painting messages
	CRect rc;
	GetClientRect(&rc);
	CRgn rgn;
	rgn.CreateRectRgn(rc.left, rc.top, rc.right, rc.bottom);
	dc.SelectClipRgn(&rgn);
	COLORREF bkCol = RGB(0, 128, 128);
	switch (mBkCol)
	{
	case 1: bkCol = RGB(0, 0, 128); break;
	case 2: bkCol = RGB(128, 128, 128); break;
	}
	dc.FillSolidRect(&rc, bkCol);

	CPoint pt = rc.CenterPoint();

	CPen pen1;
	pen1.CreatePen(PS_SOLID, 1, RGB(200, 200, 200));
	CPen *pOp = dc.SelectObject(&pen1);


	dc.MoveTo(0, pt.y + 125);
	dc.LineTo(rc.right, pt.y + 125);
	dc.MoveTo(pt.x - 140, 0);
	dc.LineTo(pt.x - 140, rc.bottom);

	
	//CKurs1Dlg *mainWnd = (CKurs1Dlg *)AfxGetMainWnd();
	//if(mainWnd)
	{
		//std::vector<CPoint> vecP =	mainWnd->m_vecPt;
		CPen penG;
		//char R = 255;
		penG.CreatePen(PS_SOLID, 3, RGB(mR, mG, 0));
		if(mR > 128)
			mR -= 1;
		if (mG < 255)
			mG += 1;

		dc.SelectObject(&penG);
		size_t szV = m_vecP.size();
		for (size_t i = 0; i < vecOfVec.size(); i++) {
			for (size_t j = 0; j < vecOfVec[i].size(); j++)
			{
				if (!j)
					dc.MoveTo(vecOfVec[i][0]);
				else
					dc.LineTo(vecOfVec[i][j]);
			}
		}
		for (size_t i = 0; i < m_vecP.size(); i++)
		{
			if(!i)
				dc.MoveTo(m_vecP[0]);
			else
				dc.LineTo(m_vecP[i]);
			if (i > m_Snake)
				break;
		}

	}


	dc.SelectObject(pOp);
}


int CMyGraph::GetVecPt(IfaceKurs const * iface)
{
	iface->GetVecPt(m_vecP,vecOfVec);
	return m_vecP.size();
}
