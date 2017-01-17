/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier : RedimDlg.cpp
*
******************************************************************************/
#include "stdafx.h"
#include "Crea2K6.h"
#include "RedimDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRedimDlg dialog


CRedimDlg::CRedimDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRedimDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRedimDlg)
	m_Width = 0;
	m_Height = 0;
	//}}AFX_DATA_INIT
}


void CRedimDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRedimDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Width);
	DDX_Text(pDX, IDC_EDIT2, m_Height);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRedimDlg, CDialog)
	//{{AFX_MSG_MAP(CRedimDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRedimDlg message handlers

BOOL CRedimDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
