#pragma once


// CMyGraph
#include "IfaceKurs.h"
class CMyGraph : public CStatic
{
	DECLARE_DYNAMIC(CMyGraph)

public:
	CMyGraph();
	virtual ~CMyGraph();

protected:
	DECLARE_MESSAGE_MAP()
	std::vector<CPoint> m_vecP;
	std::vector<std::vector<CPoint>> vecOfVec;
public:
	afx_msg void OnPaint();
	int GetVecPt(IfaceKurs const *iface);
	void SetBkColor(int nBk) { mBkCol = nBk; }
protected:
	char mR, mG;
	char mBkCol;
public:
	int m_Snake=0;
};


