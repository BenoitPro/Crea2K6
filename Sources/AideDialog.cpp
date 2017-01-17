/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier : AideDialog.cpp
*
******************************************************************************/

#include "stdafx.h"
#include "Crea2K6.h"
#include "AideDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#include "Crea2K6View.h" // pour le pointeur sur vue
#include "Crea2K6Doc.h" // pour le pointeur sur vue
/////////////////////////////////////////////////////////////////////////////
// CAideDialog dialog


CAideDialog::CAideDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CAideDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAideDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAideDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAideDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAideDialog, CDialog)
	//{{AFX_MSG_MAP(CAideDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAideDialog message handlers

void CAideDialog::OnButton1() 
{

	// Récupération du pointeur sur C...View
	CCrea2K6View *pView=static_cast<CCrea2K6View *>(m_pParentWnd); 
	
	// Détermination de l'origine de la carte (pour la position)
	CCrea2K6Doc* pDoc = pView->GetDocument();
	ASSERT_VALID(pDoc);
	CString cmd;
	cmd.Format("%s\\res\\manuel.doc",pDoc->m_RepAppli);
	system(cmd);
	
}
