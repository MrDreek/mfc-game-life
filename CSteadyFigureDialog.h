#pragma once


// Диалоговое окно CSteadyFigureDialog

class CSteadyFigureDialog : public CDialog
{
	DECLARE_DYNAMIC(CSteadyFigureDialog)

public:
	CSteadyFigureDialog(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CSteadyFigureDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CSteadyFigureDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_blockIcon;
	CStatic m_block2Icon;
	virtual BOOL OnInitDialog();
	CStatic m_hiveIcon;
	CStatic m_hive2Icon;
	CStatic m_loafIcon;
	CStatic m_loaf2Icon;
	CStatic m_loaf3Icon;
	CStatic m_boxIcon;
	CStatic m_box2Icon;
	CStatic m_otherIcon;
	CStatic m_other2Icon;
};
