#pragma once


// Диалоговое окно CRulesDialog

class CRulesDialog : public CDialog
{
	DECLARE_DYNAMIC(CRulesDialog)

public:
	CRulesDialog(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CRulesDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RULES_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
