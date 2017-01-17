/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier : TexteDialog.cpp
*
******************************************************************************/
#include "stdafx.h"
#include "Crea2K6.h"
#include "TexteDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTexteDialog dialog


CTexteDialog::CTexteDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CTexteDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTexteDialog)
	m_Edit = _T("");
	//}}AFX_DATA_INIT
}


void CTexteDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTexteDialog)
	DDX_Text(pDX, IDC_EDIT_CONTENU, m_Edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTexteDialog, CDialog)
	//{{AFX_MSG_MAP(CTexteDialog)
	ON_BN_CLICKED(IDC_BUTTON_POLICE, OnButtonPolice)
	ON_BN_CLICKED(IDC_RADIO1, OnRadioGauche)
	ON_BN_CLICKED(IDC_RADIO2, OnRadioCentre)
	ON_BN_CLICKED(IDC_RADIO3, OnRadioDroite)
	ON_BN_CLICKED(IDC_BUTTON_COULEUR, OnButtonCouleur)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTexteDialog message handlers

void CTexteDialog::OnButtonPolice() 
{
	CFontDialog ftdlg(&m_logfont) ;

	ftdlg.DoModal();


	
	// Récupération de la Structure LOGFONT (par pointeur!)
	ftdlg.GetCurrentFont(&m_logfont);

	// Récupération de la couleur 
	m_color = ftdlg.GetColor();

}

void CTexteDialog::OnRadioGauche() 
{
	m_nFormat=DT_LEFT|DT_SINGLELINE;
}

void CTexteDialog::OnRadioCentre() 
{
	m_nFormat=DT_CENTER|DT_SINGLELINE;
	
}

void CTexteDialog::OnRadioDroite() 
{
	m_nFormat=DT_RIGHT|DT_SINGLELINE;	
}

void CTexteDialog::OnButtonCouleur() 
{
	CColorDialog cdlg(m_color);
	cdlg.DoModal();

	m_color = cdlg.GetColor();
}

void CTexteDialog::OnOK() 
{
	CDialog::OnOK();
}
