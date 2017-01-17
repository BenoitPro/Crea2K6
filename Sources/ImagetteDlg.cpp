/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier : ImagetteDlg.cpp
*
******************************************************************************/

#include "stdafx.h"
#include "Crea2K6.h"
#include "ImagetteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "Crea2K6View.h" // pour le pointeur sur vue
#include "Crea2K6Doc.h" // pour le pointeur sur vue
/////////////////////////////////////////////////////////////////////////////
// CImagetteDlg dialog


CImagetteDlg::CImagetteDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImagetteDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImagetteDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CImagetteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImagetteDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CImagetteDlg, CDialog)
	//{{AFX_MSG_MAP(CImagetteDlg)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	ON_BN_CLICKED(IDC_APPLIQUER, OnAppliquer)
	ON_LBN_SELCHANGE(IDC_LIST2, OnSelchangeList2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImagetteDlg message handlers

BOOL CImagetteDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// Ajout des Imagettes 
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Branché"),CString("Alienware.jpg")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Branché"),CString("Degradé.jpg")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Branché"),CString("Globe.jpg")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Branché"),CString("Papillon.jpg")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Branché"),CString("Style_orange.jpg")));

	
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Diddl"),CString("Ackaturbo_coucou.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Diddl"),CString("Ackaturbo_pense.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Diddl"),CString("Diddl_ange.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Diddl"),CString("Diddl_cache.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Diddl"),CString("Diddl_livre.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Diddl"),CString("Galupy.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Diddl"),CString("Pimboli.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Diddl"),CString("Pimboli_cados.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Diddl"),CString("Pimboli_campignon.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Diddl"),CString("Pimboli_cuisine.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Diddl"),CString("Pimboli_ecrit.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Diddl"),CString("Pimboli_joyeux.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Diddl"),CString("Pimboli_oreillé.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Diddl"),CString("Pimboli_pantoufle.gif")));



	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("Web.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("UserCard.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("Trillian.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("TerreCrayons.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("Search.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("Papier.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("Ordinateur.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("Network.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("Maison.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("Loupe.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("Letter.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("Feuille.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("Feuille5.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("Feuille4.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("Feuille3.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("Feuille2.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("E-Mail.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("Earth.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("Documents.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("CheckUp.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Icones"),CString("Book.gif")));


	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("MeToYou"),CString("Bougie.jpg")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("MeToYou"),CString("Coeur.jpg")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("MeToYou"),CString("Devoir.JPG")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("MeToYou"),CString("Geek.jpg")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("MeToYou"),CString("Lettre.jpg")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("MeToYou"),CString("MeToYou.jpg")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("MeToYou"),CString("Noel.jpg")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("MeToYou"),CString("Oreillé.jpg")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("MeToYou"),CString("Pèche.jpg")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("MeToYou"),CString("Planisfere.jpg")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("MeToYou"),CString("Telephone.jpg")));

	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Symboles"),CString("Anubis.jpg")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Symboles"),CString("Dragon1.jpg")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Symboles"),CString("Dragon2.JPG")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Symboles"),CString("Dragon4.JPG")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Symboles"),CString("Dragon5.JPG")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Symboles"),CString("Symbole.JPG")));

	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Tux"),CString("Cactux.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Tux"),CString("Calimetux.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Tux"),CString("Congelatux.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Tux"),CString("Frankentux.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Tux"),CString("Linktux.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Tux"),CString("Ninjatux.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Tux"),CString("Supertux.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Tux"),CString("Toxictux.gif")));
	m_imgRess.Add(new CImageRessource(CString("imagettes"),CString("Tux"),CString("Tux.gif")));

	
	m_theme = "Branché";
	m_fichier = "";

	CListBox* pBox1;
	pBox1 = static_cast<CListBox*>(GetDlgItem(IDC_LIST1));

	CListBox* pBox2;
	pBox2 = static_cast<CListBox*>(GetDlgItem(IDC_LIST2));

	m_imgRess.listeSousDomaine(pBox1,"imagettes");



	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CImagetteDlg::OnSelchangeList1() 
{

		CListBox* pBox1;	
	pBox1=static_cast<CListBox*>(GetDlgItem(IDC_LIST1));

	CListBox* pBox2;	
	pBox2=static_cast<CListBox*>(GetDlgItem(IDC_LIST2));
	
	int select = pBox1->GetCurSel();
	if(select!=LB_ERR)
	{
		CString s;
		pBox1->GetText(select,s);

		m_imgRess.listeFichier(pBox2,s);
		m_theme = s;
		m_fichier = "";
	}


}

void CImagetteDlg::OnAppliquer() 
{
	
	if (strcmp(m_fichier,"")!=0) {

	// Récup du pointeur sur C...View
	CCrea2K6View *pView=static_cast<CCrea2K6View *>(m_pParentWnd); 
	
	// Détermination de l'origine de la carte (pour la position)
	CCrea2K6Doc* pDoc = pView->GetDocument();
	ASSERT_VALID(pDoc);
	
	// Récup' du context de périphérique
	CClientDC aDC(pView); // rq : pointeur sur pView :)


	CString s;
	CString rep;
	rep.Format("%s",pDoc->m_RepAppli);
	//AfxMessageBox(rep);
	s.Format("%s\\ressources\\imagettes\\%s\\%s",rep,m_theme,m_fichier);

	CImg* i = new CImg(pDoc->m_Origine,s);
	
	i->Draw(&aDC);
	Invalidate();
	}
	
}

void CImagetteDlg::OnSelchangeList2() 
{
	CListBox* pBox2;	
	pBox2=static_cast<CListBox*>(GetDlgItem(IDC_LIST2));
	
	int select = pBox2->GetCurSel();
	if(select!=LB_ERR)
	{
		CString s;
		pBox2->GetText(select,s);

		m_fichier=s;
	}
}
