
// kursachDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "kursach.h"
#include "kursachDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "Config.h"


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


// Диалоговое окно CKursachDlg



CKursachDlg::CKursachDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_KURSACH_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKursachDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CKursachDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32771, &CKursachDlg::OnExitBtnClick)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_WM_NCLBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_32772, &CKursachDlg::OnPauseRunBtnClick)
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32773, &CKursachDlg::OnResetBtnClick)
END_MESSAGE_MAP()


// Обработчики сообщений CKursachDlg

BOOL CKursachDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок
	
	CRect rc;
	GetWindowRect(&rc); // getting dialog coordinates
	MoveWindow(rc.left, rc.top, Config::SIZE * Config::WIDTH + 20, Config::SIZE * Config::HIGHT + 60);

	CKursachDlg::initCells();

	int iInstallResult;
	iInstallResult = SetTimer(1, 250, NULL);
	if (iInstallResult == FALSE)
	{
		MessageBox(L"Cannot install timer",
			L"Error message",
			MB_OK + MB_ICONERROR);
	}

	isTimerRun = true;
	SetWindowText(L"Игра \"Жизнь\" - Запущена");

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CKursachDlg::resetCells() {
	cells.clear();

	for (int i = 0; i < Config::WIDTH; i++) {
		std::vector<Cell> row;

		for (int j = 0; j < Config::HIGHT; j++)
		{
			Cell cell(i, j);
			row.push_back(cell);
		}

		cells.push_back(row);
	}

	for (int i = 0; i < Config::WIDTH; i++) {
		for (int j = 0; j < Config::HIGHT; j++) {
			for (int sx = -1; sx <= 1; sx++) {
				for (int sy = -1; sy <= 1; sy++) {
					if (!(sx == 0 && sy == 0)) {
						cells[i][j].nearCells.push_back(&cells[(i + sx + Config::WIDTH) % Config::WIDTH][(j + sy + Config::HIGHT) % Config::HIGHT]);
					}
				}
			}
		}
	}
}

void CKursachDlg::initCells() {
	resetCells();

	for (int i = 10; i < 17; i++) {
		cells[i][10].status = Status::LIVE;
	}

	UpdateData(TRUE);
}

void CKursachDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CKursachDlg::OnPaint()
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
		CPaintDC dc(this); // device context for painting

		CPen MyNewPen;
		MyNewPen.CreatePen(PS_SOLID, 2, RGB(255, 255, 255));

		CPen* pOriginalPen = dc.SelectObject(&MyNewPen);

		for (int i = 0; i < Config::WIDTH; i++) {
			for (int j = 0; j < Config::HIGHT; j++)
			{
				Cell cell = cells[i][j];

				CPen ballPen;
				CBrush* pOldBrush;
				ballPen.CreatePen(PS_SOLID, 2, cell.getColor(cell.status));
				CBrush ballBrush(cell.getColor(cell.status));

				pOriginalPen = dc.SelectObject(&ballPen);
				pOldBrush = dc.SelectObject(&ballBrush);

				CRect MyRectangle(cell.x * Config::SIZE, cell.y * Config::SIZE, (cell.x + 1) * Config::SIZE, (cell.y + 1) * Config::SIZE);
				dc.Rectangle(&MyRectangle);

			}
		}
		dc.SelectObject(pOriginalPen);

		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CKursachDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CKursachDlg::OnExitBtnClick()
{
	OnOK();
}


void CKursachDlg::OnTimer(UINT_PTR nIDEvent)
{
	flop = !flop;
	for (int i = 0; i < Config::WIDTH; i++) {
		for (int j = 0; j < Config::HIGHT; j++) {
			if (flop) {
				cells[i][j].step1();
			}
			else {
				cells[i][j].step2();
			}
		}
	}

	CKursachDlg::Invalidate();
	CKursachDlg::UpdateWindow();

	if (!isTimerRun) {
		KillTimer(1);
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CKursachDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	KillTimer(1);
}


void CKursachDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	auto x = floor(point.x / Config::SIZE);
	auto y = floor(point.y / Config::SIZE);

	cells[x][y].turn();

	CKursachDlg::Invalidate();
	CKursachDlg::UpdateWindow();

	CDialogEx::OnLButtonUp(nFlags, point);
}


BOOL CKursachDlg::OnEraseBkgnd(CDC* pDC)
{
	return true;
}


void CKursachDlg::OnPauseRunBtnClick()
{
	if (isTimerRun) {
		isTimerRun = false;
		SetWindowText(L"Игра \"Жизнь\" - Пауза");
	}
	else {
		isTimerRun = true;
		SetWindowText(L"Игра \"Жизнь\" - Запущена");
		int iInstallResult;
		iInstallResult = SetTimer(1, 250, NULL);
		if (iInstallResult == FALSE)
		{
			MessageBox(L"Cannot install timer",
				L"Error message",
				MB_OK + MB_ICONERROR);
		}
	}
}


void CKursachDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	auto x = floor(point.x / Config::SIZE);
	auto y = floor(point.y / Config::SIZE);

	cells[x][y].flip();

	CKursachDlg::Invalidate();
	CKursachDlg::UpdateWindow();

	CDialogEx::OnRButtonUp(nFlags, point);
}


void CKursachDlg::OnResetBtnClick()
{
	resetCells();
	isTimerRun = false;
	SetWindowText(L"Игра \"Жизнь\" - Пауза");

	CKursachDlg::Invalidate();
	CKursachDlg::UpdateWindow();
}
