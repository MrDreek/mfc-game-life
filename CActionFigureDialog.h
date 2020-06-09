#pragma once

// Диалоговое окно CActionFigureDialog

class CActionFigureDialog : public CDialog
{
	DECLARE_DYNAMIC(CActionFigureDialog)

public:
	CActionFigureDialog(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CActionFigureDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CActionFigureDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_actionIcon;
	virtual BOOL OnInitDialog();
	CStatic m_action2Icon;
	CStatic m_gosperIcon;
	CStatic m_gosper2Icon;
};
