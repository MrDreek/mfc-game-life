
// kursachDlg.h: файл заголовка
//

#pragma once
#include "Cell.h"
#include <vector>

// Диалоговое окно CKursachDlg
class CKursachDlg : public CDialogEx
{
// Создание
public:
	CKursachDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KURSACH_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	void resetCells();
	void initCells();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	std::vector<std::vector<Cell>> cells;
	afx_msg void OnExitBtnClick();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	bool flop = false;
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPauseRunBtnClick();

	bool isTimerRun = false;
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnResetBtnClick();
	afx_msg void OnRulesMenu();
	afx_msg void OnControlsMenu();
	afx_msg void OnSteadyFigureMenu();
	afx_msg void OnMovingFigureMenu();
};
