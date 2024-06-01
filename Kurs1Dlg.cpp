
// Kurs1Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Kurs1.h"
#include "Kurs1Dlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "initguid.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define TIMER_ID 123456

DEFINE_GUID(ImageFormatBMP, 0xb96b3cab, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// диалоговое окно CKurs1Dlg



CKurs1Dlg::CKurs1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_KURS1_DIALOG, pParent)
	, m_Rk(0)
	, m_H(0)
	, speed(0)
	, m_Len(0)
	, m_ScShift()
	, m_bInited(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKurs1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_RK, m_EdRk);
	DDX_Control(pDX, IDC_EDIT2, m_EdLength);
	DDX_Control(pDX, IDC_EDIT_H, m_EdH);
	DDX_Control(pDX, IDC_EDIT3, m_EdSpeed);
	DDX_Control(pDX, IDC_SLIDER_SCALE, m_SliderScale);
	DDX_Control(pDX, IDC_CHECK1, m_ckTik);
	DDX_Control(pDX, IDC_COMB_PICBG, m_cmbPicBg);
}

BEGIN_MESSAGE_MAP(CKurs1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CKurs1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(ID_WINDOW_TILE_VERT, &CKurs1Dlg::OnBnClickedWindowTileVert)
	ON_EN_CHANGE(IDC_EDIT_RK, &CKurs1Dlg::OnEnChangeEditRk)
	ON_BN_CLICKED(IDC_BUT_SCUP, &CKurs1Dlg::OnBnClickedButScup)
	ON_BN_CLICKED(IDC_BUT_SCDN, &CKurs1Dlg::OnBnClickedButScdn)
	//ON_BN_CLICKED(IDC_BTN_SC_UP, &CKurs1Dlg::OnBnClickedBtnScUp)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_SCALE, &CKurs1Dlg::OnNMCustomdrawSliderScale)
	ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_SLIDER_SCALE, &CKurs1Dlg::OnTRBNThumbPosChangingSliderScale)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_SCALE, &CKurs1Dlg::OnNMReleasedcaptureSliderScale)
	ON_BN_CLICKED(IDC_CHECK1, &CKurs1Dlg::OnBnClickedCheck1)
	ON_WM_TIMER()
	ON_CBN_SELCHANGE(IDC_COMB_PICBG, &CKurs1Dlg::OnCbnSelchangeCombPicbg)
	ON_BN_CLICKED(IDC_SAVE, &CKurs1Dlg::OnBnClickedSave)
	ON_WM_MOUSEWHEEL()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_GREEN, &CKurs1Dlg::OnGreen)
	ON_COMMAND(ID_BLUE, &CKurs1Dlg::OnBlue)
	ON_COMMAND(ID_GREY, &CKurs1Dlg::OnGrey)
	ON_EN_CHANGE(IDC_EDIT_H, &CKurs1Dlg::OnEnChangeEditH)
	ON_EN_CHANGE(IDC_EDIT3, &CKurs1Dlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON1, &CKurs1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CKurs1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CKurs1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CKurs1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CKurs1Dlg::OnBnClickedButton5)
	ON_EN_CHANGE(IDC_EDIT2, &CKurs1Dlg::OnEnChangeEditLength)
	ON_BN_CLICKED(IDC_BUTTON6, &CKurs1Dlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// обработчики сообщений CKurs1Dlg

BOOL CKurs1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
		bNameValid = strAboutMenu.LoadString(IDS_STR_SAVE);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDS_STR_SAVE, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	m_paint.SubclassDlgItem(IDC_GRAPH, this);

	m_Calc.Scale(m_ScShift.ScaleX);
	CRect rc;
	m_paint.GetClientRect(&rc);
	m_ScShift.ShiftX = rc.CenterPoint().x;
	m_ScShift.ShiftY = rc.CenterPoint().y;
	m_Calc.Shift(CPoint(m_ScShift.ShiftX, m_ScShift.ShiftY));
	m_SliderScale.SetRange(1, 10, TRUE);
	m_SliderScale.SetPos(10);
	m_cmbPicBg.SetCurSel(0);
	/*UINT uA = AfxGetApp()->GetProfileIntW(L"Settings", L"ParamA", 10);
	m_Rk = uA;
	CString strA;
	strA.Format(L"%f.0", m_Rk);
	m_EdRk.SetWindowTextW(strA);*/
	m_bInited = true;
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CKurs1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else if ((nID ) == IDS_STR_SAVE)
	{
		OnBnClickedSave();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CKurs1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		CPaintDC dc(this);
		POINT pt1 = { 0,0 }, pt2 = {20,20};
		CRect rect(pt1, pt2);
		COLORREF cl = RGB(255, 0, 255);
		dc.FillSolidRect(LPCRECT(rect), cl);
		//GetClientRect(&rect);

	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CKurs1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CKurs1Dlg::OnBnClickedOk()
{
	//SetWindowText(L"Привет курсовая");
	AfxGetApp()->WriteProfileInt(L"Settings", L"ParamA", (UINT)m_Rk);
	CDialogEx::OnOK();
}


void CKurs1Dlg::Risovat(double Rk, double H) // функция отрисовки графика
{
	m_Calc.SetPar(Rk, H); // задаем тут к классу CCalc нужные данные

	if (m_Calc.GetVseTochki(m_vecPt)) // отностительно которых мы потом получаем вектор с точками
	{
		for (int i = 0; i < m_vecPt.size(); i++) {
			m_vecPt[i].x -= 100;
		}
		m_paint.GetVecPt(this); // отрисовка
		m_paint.Invalidate();
	}

}


void CKurs1Dlg::OnBnClickedWindowTileVert()
{
	Risovat(m_Rk, m_H);
}

int CKurs1Dlg::GetVecPt(std::vector<CPoint>& vec, std::vector<std::vector<CPoint>>& vecOfVec) const // функция для переопределения данных которая используется для отрисовки
{
	vec = m_vecPt;
	vecOfVec = m_vecOfVec;
	return 0;
}






void CKurs1Dlg::ScaleShift() // функция масштаба
{
	m_Calc.Scale(m_ScShift.ScaleX);
	m_Calc.Shift(CPoint(m_ScShift.ShiftX, m_ScShift.ShiftY));
}

void CKurs1Dlg::OnEnChangeEditRk() // обработчик событий к текстовому каналу отвечающему за радиус катящейся окружности
{
	CString strA;
	m_EdRk.GetWindowText(strA);

	m_Rk = _wtof(strA);
	OnBnClickedWindowTileVert();
}


void CKurs1Dlg::OnBnClickedButScup()
{
	/*m_ScShift.ScaleX *= 1.25;
	m_ScShift.ScaleY = m_ScShift.ScaleX;
	ScaleShift();
	OnBnClickedWindowTileVert();*/
	m_SliderScale.SetPos(m_SliderScale.GetPos() - 1);
	LRESULT res;
	OnNMReleasedcaptureSliderScale(nullptr, &res);
}


void CKurs1Dlg::OnBnClickedButScdn()
{
	/*m_ScShift.ScaleX /= 1.25;
	m_ScShift.ScaleY = m_ScShift.ScaleX;
	ScaleShift();
	OnBnClickedWindowTileVert();*/
	m_SliderScale.SetPos(m_SliderScale.GetPos() + 1);
	LRESULT res;
	OnNMReleasedcaptureSliderScale(nullptr, &res);
}




void CKurs1Dlg::OnNMCustomdrawSliderScale(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CKurs1Dlg::OnTRBNThumbPosChangingSliderScale(NMHDR *pNMHDR, LRESULT *pResult)
{
	// This feature requires Windows Vista or greater.
	// The symbol _WIN32_WINNT must be >= 0x0600.
	NMTRBTHUMBPOSCHANGING *pNMTPC = reinterpret_cast<NMTRBTHUMBPOSCHANGING *>(pNMHDR);
	int nPos = m_SliderScale.GetPos()-10;
	m_ScShift.ScaleX = nPos ? 1.25 * nPos : 1;
	*pResult = 0;
}


void CKurs1Dlg::OnNMReleasedcaptureSliderScale(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	if (!m_bInited)
		return;
	int nPos = 10 - m_SliderScale.GetPos();
	m_ScShift.ScaleX = nPos ? 1.25 * nPos : 1;
	ScaleShift();
	OnBnClickedWindowTileVert();
	*pResult = 0;
}


void CKurs1Dlg::OnBnClickedCheck1()
{
	if (m_ckTik.GetCheck())
	{
		SetTimer(TIMER_ID, 42, NULL);
		m_paint.m_Snake = 1;
	}
	else
		KillTimer(TIMER_ID);
	
}


void CKurs1Dlg::OnTimer(UINT_PTR nIDEvent) // функция для последовательной отрисовки
{
	//m_Fi += .017; 
	m_paint.m_Snake+=speed;
	Risovat(m_Rk, m_H);
	if (m_paint.m_Snake > m_vecPt.size())
		KillTimer(TIMER_ID);
	__super::OnTimer(nIDEvent);
}


void CKurs1Dlg::OnCbnSelchangeCombPicbg()
{
	int nSel = m_cmbPicBg.GetCurSel();
	m_paint.SetBkColor(nSel);
	Risovat(m_Rk, m_H);
}


void CKurs1Dlg::OnBnClickedSave() // функция сохранения графика в формате BMP
{
	CWindowDC cwDC(&m_paint);
	CRect rcPic;
	m_paint.GetClientRect(&rcPic);
	CMemDC memdc( cwDC, rcPic);

	CBitmap bmap;
	bmap.CreateCompatibleBitmap(&cwDC, rcPic.Width(), rcPic.Height());

	HGDIOBJ pOld = memdc.GetDC().SelectObject(&bmap);

	memdc.GetDC().BitBlt(0,0, rcPic.Width(), rcPic.Height(), &cwDC, 0, 0, SRCCOPY);
	memdc.GetDC().SelectObject(pOld);
	CString strMask(_T("BMP файлы (*.bmp)|*.bmp||"));
	CFileDialog dlgF(FALSE, _T("*.bmp"), NULL, 6UL, strMask);
	if (IDOK == dlgF.DoModal())
	{
		CImage im;
		im.Attach(HBITMAP(bmap));
		CString sPath = dlgF.GetOFN().lpstrFile;
		HRESULT hres = im.Save(sPath, ImageFormatBMP);
	}
	
}


BOOL CKurs1Dlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	CPoint pt1;
	GetCursorPos(&pt1);
	CRect rc;
	m_paint.GetClientRect(&rc);
	m_paint.ScreenToClient(&pt1);
	if (rc.PtInRect(pt1))
	{
		if (zDelta > 0)
			OnBnClickedButScup();
		else if (zDelta < 0)
			OnBnClickedButScdn();

	}
	return __super::OnMouseWheel(nFlags, zDelta, pt);
}


void CKurs1Dlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	CPoint pt1;
	GetCursorPos(&pt1);
	CRect rc;
	m_paint.GetClientRect(&rc);
	m_paint.ScreenToClient(&pt1);
	if (rc.PtInRect(pt1))
	{
		CMenu mn;
		mn.LoadMenuW(IDR_MENU2);
		CMenu *file_menu = mn.GetSubMenu(0);
		ASSERT(file_menu);

		ClientToScreen(&point);
		bool bret = file_menu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x,
			point.y, this);
		//mn.TrackPopupMenu(0, point.x, point.y, this);
	}

	__super::OnRButtonUp(nFlags, point);
}


void CKurs1Dlg::OnGreen()
{
	m_paint.SetBkColor(0);
	Risovat( m_Rk, m_H);
}


void CKurs1Dlg::OnBlue()
{
	m_paint.SetBkColor(1);
	Risovat( m_Rk, m_H);
}


void CKurs1Dlg::OnGrey()
{
	m_paint.SetBkColor(2);
	Risovat(m_Rk, m_H);
}


void CKurs1Dlg::OnEnChangeEditH()
{
	CString strA;
	m_EdH.GetWindowText(strA);

	m_H = _wtof(strA);
	OnBnClickedWindowTileVert();
}


void CKurs1Dlg::OnEnChangeEdit3()
{
	CString strA;
	m_EdSpeed.GetWindowText(strA);
	speed = _wtof(strA);
	OnBnClickedWindowTileVert();

}


void CKurs1Dlg::OnBnClickedButton1()
{
	for (size_t i = 0; i < m_vecPt.size(); i++)
	{
		m_vecPt[i].x += m_Len;
	}
	m_paint.GetVecPt(this);
	m_paint.Invalidate();
}


void CKurs1Dlg::OnBnClickedButton2()
{
	for (size_t i = 0; i < m_vecPt.size(); i++)
	{
		m_vecPt[i].x -= m_Len;
	}
	m_paint.GetVecPt(this);
	m_paint.Invalidate();
}


void CKurs1Dlg::OnBnClickedButton3()
{
	for (size_t i = 0; i < m_vecPt.size(); i++)
	{
		m_vecPt[i].y += m_Len;
	}
	m_paint.GetVecPt(this);
	m_paint.Invalidate();
}


void CKurs1Dlg::OnBnClickedButton4()
{
	for (size_t i = 0; i < m_vecPt.size(); i++)
	{
		m_vecPt[i].y -= m_Len;
	}
	m_paint.GetVecPt(this);
	m_paint.Invalidate();
}


void CKurs1Dlg::OnBnClickedButton5()
{
	bool flag;
	for (size_t i = 0; i < m_vecPt.size(); i++)
	{
		if (m_vecPt[i].x != 0 || m_vecPt[i].y != 0) {
			flag = false;
		}
		else {
			flag = true;
		}
		m_vecPt[i].x = 0;
		m_vecPt[i].y = 0;

	}
	if (flag) {
		m_vecOfVec.pop_back();

	}
	m_paint.GetVecPt(this);
	m_paint.Invalidate();
}

void CKurs1Dlg::OnEnChangeEditLength()
{
	CString strA;
	m_EdLength.GetWindowText(strA);
	m_Len = _wtof(strA);
}


void CKurs1Dlg::OnBnClickedButton6()
{
	m_vecOfVec.push_back(m_vecPt);
	for (int i = 0; i < m_vecOfVec.size(); i++) {
		m_vecPt = m_vecOfVec[i];
		m_paint.GetVecPt(this);
		m_paint.Invalidate();
	}
}
