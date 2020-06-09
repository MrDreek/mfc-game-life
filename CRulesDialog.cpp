// CRulesDialog.cpp: файл реализации
//

#include "pch.h"
#include "kursach.h"
#include "CRulesDialog.h"
#include "afxdialogex.h"


// Диалоговое окно CRulesDialog

IMPLEMENT_DYNAMIC(CRulesDialog, CDialog)

CRulesDialog::CRulesDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RULES_DIALOG, pParent)
{

}

CRulesDialog::~CRulesDialog()
{
}

void CRulesDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRulesDialog, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений CRulesDialog
