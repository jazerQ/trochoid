#include "stdafx.h"
#include "Calc.h"
#define _USE_MATH_DEFINES
#include "math.h"

CCalc::CCalc()
{
}


CCalc::~CCalc()
{
}

CPoint CCalc::GetPoint(float t)
{
	double x, y;
	x = m_Rk * t - m_H * sin(t);
	y = -(m_Rk - m_H * cos(t));
	return ToGraph(x,y);
}

size_t CCalc::GetVseTochki(std::vector<CPoint>& vecPt)
{
	vecPt.clear();
	float t = 0;
	float stopT = 100 * M_PI;
	for (float i = t; i <= stopT ; i+=0.1)
	{
		CPoint pt = GetPoint(i);
		vecPt.push_back(pt);
	}
	return vecPt.size();
}

