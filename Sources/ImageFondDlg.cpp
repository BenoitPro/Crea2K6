/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier : ImageFondDlg.cpp
*
******************************************************************************/

#include "stdafx.h"
#include "Crea2K6.h"
#include "ImageFondDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "Crea2K6View.h" // pour le pointeur sur vue
#include "Crea2K6Doc.h" // pour le pointeur sur vue
#include "Img.h"		// pour dessiner l'image


/////////////////////////////////////////////////////////////////////////////
// CImageFondDlg dialog


CImageFondDlg::CImageFondDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImageFondDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImageFondDlg)
	m_carte = -1;
	//}}AFX_DATA_INIT
}


void CImageFondDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImageFondDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CImageFondDlg, CDialog)
	//{{AFX_MSG_MAP(CImageFondDlg)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	ON_BN_CLICKED(IDC_APPLIQUER1, OnAppliquer1)
	ON_LBN_SELCHANGE(IDC_LIST2, OnSelchangeList2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageFondDlg message handlers

BOOL CImageFondDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
 


  // Ajout des ressources carte de voeux
	m_imgRess.Add(new CImageRessource(CString("voeux"),CString("Annee"),CString("artifice.jpg")));
	m_imgRess.Add(new CImageRessource(CString("voeux"),CString("Annee"),CString("herable.jpg")));
	m_imgRess.Add(new CImageRessource(CString("voeux"),CString("Annee"),CString("houx.jpg")));
	m_imgRess.Add(new CImageRessource(CString("voeux"),CString("Annee"),CString("table.jpg")));

	m_imgRess.Add(new CImageRessource(CString("voeux"),CString("Noel"),CString("bonhomme.jpg")));
	m_imgRess.Add(new CImageRessource(CString("voeux"),CString("Noel"),CString("boule.jpg")));
	m_imgRess.Add(new CImageRessource(CString("voeux"),CString("Noel"),CString("boules.jpg")));
	m_imgRess.Add(new CImageRessource(CString("voeux"),CString("Noel"),CString("pere_noel.jpg")));

	m_imgRess.Add(new CImageRessource(CString("voeux"),CString("Paques"),CString("3oeufs.jpg")));
	m_imgRess.Add(new CImageRessource(CString("voeux"),CString("Paques"),CString("chocolat.jpg")));
	m_imgRess.Add(new CImageRessource(CString("voeux"),CString("Paques"),CString("enfants.jpg")));
	m_imgRess.Add(new CImageRessource(CString("voeux"),CString("Paques"),CString("oeufs.jpg")));

	m_imgRess.Add(new CImageRessource(CString("voeux"),CString("St Valentin"),CString("amoureux.jpg")));
	m_imgRess.Add(new CImageRessource(CString("voeux"),CString("St Valentin"),CString("coeur.jpg")));
	m_imgRess.Add(new CImageRessource(CString("voeux"),CString("St Valentin"),CString("coeurs.jpg")));
	m_imgRess.Add(new CImageRessource(CString("voeux"),CString("St Valentin"),CString("coeurs2.jpg")));
	m_imgRess.Add(new CImageRessource(CString("voeux"),CString("St Valentin"),CString("diddl.jpg")));

	
	// Ajout des ressources carte postale
	m_imgRess.Add(new CImageRessource(CString("postale"),CString("Animaux"),CString("chatons.jpg")));
	m_imgRess.Add(new CImageRessource(CString("postale"),CString("Animaux"),CString("chiot.jpg")));
	m_imgRess.Add(new CImageRessource(CString("postale"),CString("Animaux"),CString("dauphins.jpg")));
	m_imgRess.Add(new CImageRessource(CString("postale"),CString("Animaux"),CString("poussins.jpg")));
	m_imgRess.Add(new CImageRessource(CString("postale"),CString("Animaux"),CString("vaches.jpg")));

	m_imgRess.Add(new CImageRessource(CString("postale"),CString("Hiver"),CString("freestyle.jpg")));
	m_imgRess.Add(new CImageRessource(CString("postale"),CString("Hiver"),CString("skieur.jpg")));
	m_imgRess.Add(new CImageRessource(CString("postale"),CString("Hiver"),CString("montagne.jpg")));
	m_imgRess.Add(new CImageRessource(CString("postale"),CString("Hiver"),CString("paysage.jpg")));

	m_imgRess.Add(new CImageRessource(CString("postale"),CString("Paysages"),CString("ile.jpg")));
	m_imgRess.Add(new CImageRessource(CString("postale"),CString("Paysages"),CString("cascade.jpg")));
	m_imgRess.Add(new CImageRessource(CString("postale"),CString("Paysages"),CString("chine.jpg")));
	m_imgRess.Add(new CImageRessource(CString("postale"),CString("Paysages"),CString("fond_marins.jpg")));
	m_imgRess.Add(new CImageRessource(CString("postale"),CString("Paysages"),CString("montagne.jpg")));


	// Ajout des ressources carte de visite
	m_imgRess.Add(new CImageRessource(CString("visite"),CString("Branché"),CString("industriel.jpg")));
	m_imgRess.Add(new CImageRessource(CString("visite"),CString("Branché"),CString("industriel2.jpg")));
	m_imgRess.Add(new CImageRessource(CString("visite"),CString("Branché"),CString("cubes3d.jpg ")));
	m_imgRess.Add(new CImageRessource(CString("visite"),CString("Branché"),CString("tubes_violet.jpg ")));
	m_imgRess.Add(new CImageRessource(CString("visite"),CString("Branché"),CString("tubes3d.jpg ")));
	m_imgRess.Add(new CImageRessource(CString("visite"),CString("Branché"),CString("piques.jpg ")));
	m_imgRess.Add(new CImageRessource(CString("visite"),CString("Branché"),CString("piques3d.jpg ")));
	m_imgRess.Add(new CImageRessource(CString("visite"),CString("Branché"),CString("electro.jpg ")));
	m_imgRess.Add(new CImageRessource(CString("visite"),CString("Branché"),CString("tendance.jpg ")));
	
	m_imgRess.Add(new CImageRessource(CString("visite"),CString("Jeunes"),CString("fille.jpg ")));
	m_imgRess.Add(new CImageRessource(CString("visite"),CString("Jeunes"),CString("garcon.jpg ")));
	m_imgRess.Add(new CImageRessource(CString("visite"),CString("Jeunes"),CString("vache.jpg ")));
	m_imgRess.Add(new CImageRessource(CString("visite"),CString("Jeunes"),CString("soleil.jpg ")));
	m_imgRess.Add(new CImageRessource(CString("visite"),CString("Jeunes"),CString("paysage.jpg ")));

	m_imgRess.Add(new CImageRessource(CString("visite"),CString("Sobre"),CString("ciel.jpg ")));
	m_imgRess.Add(new CImageRessource(CString("visite"),CString("Sobre"),CString("fleur.jpg ")));
	m_imgRess.Add(new CImageRessource(CString("visite"),CString("Sobre"),CString("fleurseul.jpg ")));
	m_imgRess.Add(new CImageRessource(CString("visite"),CString("Sobre"),CString("mer.jpg ")));


	// Ajout des ressources carte d'invitation
	m_imgRess.Add(new CImageRessource(CString("invitation"),CString("Fêtes"),CString("fusee.jpg")));
	m_imgRess.Add(new CImageRessource(CString("invitation"),CString("Fêtes"),CString("cadeau.jpg")));
	m_imgRess.Add(new CImageRessource(CString("invitation"),CString("Fêtes"),CString("valentin.jpg ")));
	m_imgRess.Add(new CImageRessource(CString("invitation"),CString("Fêtes"),CString("verres.jpg ")));
	
	m_imgRess.Add(new CImageRessource(CString("invitation"),CString("Mariage"),CString("robe.jpg")));
	m_imgRess.Add(new CImageRessource(CString("invitation"),CString("Mariage"),CString("alliances.jpg")));
	m_imgRess.Add(new CImageRessource(CString("invitation"),CString("Mariage"),CString("alliances2.jpg ")));
	m_imgRess.Add(new CImageRessource(CString("invitation"),CString("Mariage"),CString("fleurs.jpg ")));
	m_imgRess.Add(new CImageRessource(CString("invitation"),CString("Mariage"),CString("table.jpg ")));
	
	m_imgRess.Add(new CImageRessource(CString("invitation"),CString("Halloween"),CString("citrouille.jpg")));
	m_imgRess.Add(new CImageRessource(CString("invitation"),CString("Halloween"),CString("citrouille2.jpg")));
	m_imgRess.Add(new CImageRessource(CString("invitation"),CString("Halloween"),CString("citrouille3.jpg")));
	m_imgRess.Add(new CImageRessource(CString("invitation"),CString("Halloween"),CString("darkchat.jpg")));
	m_imgRess.Add(new CImageRessource(CString("invitation"),CString("Halloween"),CString("petitesorciere.jpg")));
	m_imgRess.Add(new CImageRessource(CString("invitation"),CString("Halloween"),CString("tetedemort.jpg")));
	m_imgRess.Add(new CImageRessource(CString("invitation"),CString("Halloween"),CString("zombie.jpg")));


	CListBox* pBox1;
	pBox1 = static_cast<CListBox*>(GetDlgItem(IDC_LIST1));

	CListBox* pBox2;
	pBox2 = static_cast<CListBox*>(GetDlgItem(IDC_LIST2));

	m_theme = "";
	m_nom = "";

	// Récupération du pointeur sur C...View
	CCrea2K6View *pView=static_cast<CCrea2K6View *>(m_pParentWnd); 
	
	// Détermination de l'origine de la carte (pour la position)
	CCrea2K6Doc* pDoc = pView->GetDocument();
	ASSERT_VALID(pDoc);
// Recherche du format de la carte	
	if(pDoc->m_Format==CARTEVOEUX)
		m_carte="voeux";
	else if(pDoc->m_Format==CARTEVISITE)
		m_carte="visite";
	else if(pDoc->m_Format==CARTEPOSTALE)
		m_carte="postale";
	else if(pDoc->m_Format==INVITATION)
		m_carte="invitation";

	m_imgRess.listeSousDomaine(pBox1,m_carte);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE

  }


/************************************************
*	Gestion de la selection sur la list de thème
************************************************/
void CImageFondDlg::OnSelchangeList1() 
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
		m_nom = "";
	}

}


void CImageFondDlg::OnSelchangeList2() 
{
	CListBox* pBox2;	
	pBox2=static_cast<CListBox*>(GetDlgItem(IDC_LIST2));
	
	int select = pBox2->GetCurSel();
	if(select!=LB_ERR)
	{
		CString s;
		pBox2->GetText(select,s);

		m_nom = s;
	}
}

void CImageFondDlg::OnOK() 
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
		m_theme=s;
	}

	 select = pBox2->GetCurSel();
	if(select!=LB_ERR)
	{
		CString s;
		pBox2->GetText(select,s);
		m_nom=s;
	}



	CDialog::OnOK();
}

void CImageFondDlg::OnAppliquer1() 
{

	if(strcmp(m_nom,"")!=0) {
	// Récup du pointeur sur C...View
	CCrea2K6View *pView=static_cast<CCrea2K6View *>(m_pParentWnd); 
	
	// Détermination de l'origine de la carte (pour la position)
	CCrea2K6Doc* pDoc = pView->GetDocument();
	ASSERT_VALID(pDoc);

	// Récup' du context de périphérique
	CClientDC aDC(pView); // rq : pointeur sur pView :)

/********/
	CString s;
	CString rep;
	rep.Format("%s",pDoc->m_RepAppli);
	s.Format("%s\\ressources\\%s\\%s\\%s",rep,m_carte,m_theme,m_nom);
/*************/
	CImg* i = new CImg(pDoc->m_Origine,s);
	
	i->Draw(&aDC);
	Invalidate();
	}
}