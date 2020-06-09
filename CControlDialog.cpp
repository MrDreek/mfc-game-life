// CControlDialog.cpp: файл реализации
//

#include "pch.h"
#include "kursach.h"
#include "CControlDialog.h"
#include "afxdialogex.h"


// Диалоговое окно CControlDialog

IMPLEMENT_DYNAMIC(CControlDialog, CDialog)

CControlDialog::CControlDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CControlDialog, pParent)
{

}

CControlDialog::~CControlDialog()
{
}

void CControlDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CControlDialog, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений CControlDialog
