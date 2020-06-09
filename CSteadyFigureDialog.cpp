// CSteadyFigureDialog.cpp: файл реализации
//

#include "pch.h"
#include "kursach.h"
#include "CSteadyFigureDialog.h"
#include "afxdialogex.h"


// Диалоговое окно CSteadyFigureDialog

IMPLEMENT_DYNAMIC(CSteadyFigureDialog, CDialog)

CSteadyFigureDialog::CSteadyFigureDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CSteadyFigureDialog, pParent)
{

}

CSteadyFigureDialog::~CSteadyFigureDialog()
{
}

void CSteadyFigureDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BLOCK, m_blockIcon);
	DDX_Control(pDX, IDC_BLOCK2, m_block2Icon);
	DDX_Control(pDX, IDC_HIVE, m_hiveIcon);
	DDX_Control(pDX, IDC_HIVE2, m_hive2Icon);
	DDX_Control(pDX, IDC_LOAF, m_loafIcon);
	DDX_Control(pDX, IDC_LOAF2, m_loaf2Icon);
	DDX_Control(pDX, IDC_LOAF3, m_loaf3Icon);
	DDX_Control(pDX, IDC_BOX, m_boxIcon);
	DDX_Control(pDX, IDC_BOX2, m_box2Icon);
	DDX_Control(pDX, IDC_OTHER, m_otherIcon);
	DDX_Control(pDX, IDC_OTHER2, m_other2Icon);
}


BEGIN_MESSAGE_MAP(CSteadyFigureDialog, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений CSteadyFigureDialog


BOOL CSteadyFigureDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	CPngImage image;
	image.Load(IDB_BLOCK, AfxGetInstanceHandle());
	m_blockIcon.SetBitmap((HBITMAP)image.Detach());

	image.Load(IDB_BIBLOCK, AfxGetInstanceHandle());
	m_block2Icon.SetBitmap((HBITMAP)image.Detach());

	image.Load(IDB_HIVE, AfxGetInstanceHandle());
	m_hiveIcon.SetBitmap((HBITMAP)image.Detach());

	image.Load(IDB_HIVE2, AfxGetInstanceHandle());
	m_hive2Icon.SetBitmap((HBITMAP)image.Detach());

	image.Load(IDB_LOAF, AfxGetInstanceHandle());
	m_loafIcon.SetBitmap((HBITMAP)image.Detach());

	image.Load(IDB_LOAF2, AfxGetInstanceHandle());
	m_loaf2Icon.SetBitmap((HBITMAP)image.Detach());

	image.Load(IDB_LOAF3, AfxGetInstanceHandle());
	m_loaf3Icon.SetBitmap((HBITMAP)image.Detach());

	image.Load(IDB_BOX, AfxGetInstanceHandle());
	m_boxIcon.SetBitmap((HBITMAP)image.Detach());

	image.Load(IDB_BOX2, AfxGetInstanceHandle());
	m_box2Icon.SetBitmap((HBITMAP)image.Detach());

	image.Load(IDB_OTHER, AfxGetInstanceHandle());
	m_otherIcon.SetBitmap((HBITMAP)image.Detach());

	image.Load(IDB_OTHER2, AfxGetInstanceHandle());
	m_other2Icon.SetBitmap((HBITMAP)image.Detach());

	return TRUE;  // return TRUE unless you set the focus to a control
				  // Исключение: страница свойств OCX должна возвращать значение FALSE
}
