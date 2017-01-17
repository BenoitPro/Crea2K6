// RedimensionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Crea2K6.h"
#include "RedimensionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRedimensionDlg dialog


CRedimensionDlg::CRedimensionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRedimensionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRedimensionDlg)
	m_edit = _T("");
	//}}AFX_DATA_INIT
}


void CRedimensionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRedimensionDlg)
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRedimensionDlg, CDialog)
	//{{AFX_MSG_MAP(CRedimensionDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRedimensionDlg message handlers
