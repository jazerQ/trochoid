// Kurs1Dlg.h : файл заголовка
//

#pragma once

#include "MyGraph.h"
#include "Calc.h"
#include "IfaceKurs.h"
#include "afxwin.h"
#include "afxcmn.h"

struct Scale_Shift_s
{
	double ScaleX;
	double ScaleY;
	int ShiftX, ShiftY;
	struct Scale_Shift_s() {
		ScaleX = 1; ScaleY = 1; ShiftX = ShiftY = 100;
	}

};



// диалоговое окно CKurs1Dlg
class CKurs1Dlg : public CDialogEx 
	, IfaceKurs
{
// Создание
public:
	CKurs1Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KURS1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CMyGraph m_paint;
	CCalc m_Calc;
	std::vector<CPoint> m_vecPt;
	std::vector<std::vector<CPoint>> m_vecOfVec;
	void Risovat(double Rk, double H);
	afx_msg void OnBnClickedWindowTileVert();
	virtual int GetVecPt(std::vector<CPoint> &vec, std::vector<std::vector<CPoint>>& vecOfVec) const override;
protected:
	CEdit m_EdRk;
	CEdit m_EdH;
	CEdit m_EdSpeed;
	CEdit m_EdLength;
	double m_Len = 0;
	double m_Rk;
	double m_H;
	int speed = 0;
	Scale_Shift_s m_ScShift;
	bool m_bInited;
protected:
	void ScaleShift();
public:
	afx_msg void OnEnChangeEditRk();
	afx_msg void OnBnClickedButScup();
	afx_msg void OnBnClickedButScdn();
	//afx_msg void OnBnClickedBtnScUp();
	
	afx_msg void OnNMCustomdrawSliderScale(NMHDR *pNMHDR, LRESULT *pResult);
public:
	CSliderCtrl m_SliderScale;
	afx_msg void OnTRBNThumbPosChangingSliderScale(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSliderScale(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCheck1();
	CButton m_ckTik;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CComboBox m_cmbPicBg;
	afx_msg void OnCbnSelchangeCombPicbg();
	afx_msg void OnBnClickedSave();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnGreen();
	afx_msg void OnBlue();
	afx_msg void OnGrey();
	afx_msg void OnEnChangeEditH();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnEnChangeEditLength();
	afx_msg void OnBnClickedButton6();
};
