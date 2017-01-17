/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier : FontPredefDlg.cpp
*
******************************************************************************/
#include "stdafx.h"
#include "Crea2K6.h"
#include "FontPredefDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFontPredefDlg dialog


CFontPredefDlg::CFontPredefDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFontPredefDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFontPredefDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFontPredefDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFontPredefDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFontPredefDlg, CDialog)
	//{{AFX_MSG_MAP(CFontPredefDlg)
	ON_BN_CLICKED(IDC_RADIO1, OnTitre1)
	ON_BN_CLICKED(IDC_RADIO2, OnTitre2)
	ON_BN_CLICKED(IDC_RADIO3, OnTitre3)
	ON_BN_CLICKED(IDC_RADIO5, OnTexte1)
	ON_BN_CLICKED(IDC_RADIO4, OnTexte2)
	ON_BN_CLICKED(IDC_RADIO6, OnTexte3)
	ON_BN_CLICKED(IDC_RADIO7, OnMessage1)
	ON_BN_CLICKED(IDC_RADIO8, OnMessage2)
	ON_BN_CLICKED(IDC_RADIO9, OnMessage3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontPredefDlg message handlers

BOOL CFontPredefDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	LOGFONT lf;
	ZeroMemory(&lf, sizeof(LOGFONT) );	

	// On la personnalise...
	lstrcpy(lf.lfFaceName,"Comic Sans MS");
	lf.lfHeight=40;			// hauteur de la police
	lf.lfItalic=TRUE;		// mise en italique
	lf.lfWeight=100;		// mise en gras
	lf.lfUnderline=FALSE;	// soulignage (humpff)
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFontPredefDlg::OnTitre1() 
{
	// TODO: Add your control notification handler code here
	police=1;
}

void CFontPredefDlg::OnTitre2() 
{
	// TODO: Add  yourcontrol notification handler code here
	police=2;
}

void CFontPredefDlg::OnTitre3() 
{
	// TODO: Add your control notification handler code here
	police=3;
}

void CFontPredefDlg::OnTexte1() 
{
	// TODO: Add your control notification handler code here
	police=4;
}

void CFontPredefDlg::OnTexte2() 
{
	// TODO: Add your control notification handler code here
	police=5;
}

void CFontPredefDlg::OnTexte3() 
{
	// TODO: Add your control notification handler code here
	police=6;
}

void CFontPredefDlg::OnMessage1() 
{
	// TODO: Add your control notification handler code here
	police=7;
}

void CFontPredefDlg::OnMessage2() 
{
	// TODO: Add your control notification handler code here
	police=8;
}

void CFontPredefDlg::OnMessage3() 
{
	// TODO: Add your control notification handler code here
	police=9;
}
