#pragma once
#include "ScaleShift.h"
#include <vector>

class CCalc :
	public CScaleShift
{
public:
	CCalc();
	~CCalc();
protected:
	double m_Rk;
	double m_H;
public:
	CPoint GetPoint(float i);
	void SetPar( double Rk, double H) {  
		m_Rk = Rk; 
		m_H = H; 
	};
	size_t GetVseTochki(std::vector<CPoint> &vecPt);
};

