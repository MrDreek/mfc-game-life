#pragma once


// Диалоговое окно CControlDialog

class CControlDialog : public CDialog
{
	DECLARE_DYNAMIC(CControlDialog)

public:
	CControlDialog(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CControlDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CControlDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
