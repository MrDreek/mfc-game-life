// CActionFigureDialog.cpp: файл реализации
//

#include "pch.h"
#include "kursach.h"
#include "CActionFigureDialog.h"
#include "afxdialogex.h"


// Диалоговое окно CActionFigureDialog

IMPLEMENT_DYNAMIC(CActionFigureDialog, CDialog)

CActionFigureDialog::CActionFigureDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CActionFigureDialog, pParent)
{

}

CActionFigureDialog::~CActionFigureDialog()
{
}

void CActionFigureDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ACTION, m_actionIcon);
	DDX_Control(pDX, IDC_ACTION2, m_action2Icon);
	DDX_Control(pDX, IDC_GOSPER, m_gosperIcon);
	DDX_Control(pDX, IDC_GOSPER2, m_gosper2Icon);
}


BEGIN_MESSAGE_MAP(CActionFigureDialog, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений CActionFigureDialog


BOOL CActionFigureDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	CPngImage image;
	image.Load(IDB_ACTION, AfxGetInstanceHandle());
	m_actionIcon.SetBitmap((HBITMAP)image.Detach());

	image.Load(IDB_ACTION2, AfxGetInstanceHandle());
	m_action2Icon.SetBitmap((HBITMAP)image.Detach());

	image.Load(IDB_GOSPER, AfxGetInstanceHandle());
	m_gosperIcon.SetBitmap((HBITMAP)image.Detach());

	image.Load(IDB_GOSPER2, AfxGetInstanceHandle());
	m_gosper2Icon.SetBitmap((HBITMAP)image.Detach());


	return TRUE;  // return TRUE unless you set the focus to a control
				  // Исключение: страница свойств OCX должна возвращать значение FALSE
}
