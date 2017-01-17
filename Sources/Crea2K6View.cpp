/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier : Crea2K6View.cpp
*
******************************************************************************/

#include "stdafx.h"
#include "Crea2K6.h"

#include "Crea2K6View.h"

/* Mes inclusions */
#include "Texte.h"		// pour inséré du texte
#include "Img.h"		// pour inséré une image
#include "constantes.h"	// pour les constantes

#include "TexteDialog.h"	// Dialog de mise en forme du texte
#include "ImageFondDlg.h"	// Dialog d'insertion d'une image de fond
#include "ImagetteDlg.h"	// Dialog d'insertion d'une image

#include "FontPredefDlg.h"
#include "RedimDlg.h"
#include "AideDialog.h"
#include "PrintData.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCrea2K6View

IMPLEMENT_DYNCREATE(CCrea2K6View, CView)

BEGIN_MESSAGE_MAP(CCrea2K6View, CView)
	//{{AFX_MSG_MAP(CCrea2K6View)
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_INSERTION_TEXTE, OnInsertionTexte)
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_TO_BACK, OnSendToBack)
	ON_COMMAND(ID_DEPLACER, OnDeplacer)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_MENU0_EDITER, OnMenu0Editer)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_INSERTION_IMAGE, OnInsertionImage)
	ON_WM_KEYDOWN()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_RESSOURCES_IMAGEDEFOND, OnRessourcesImagedefond)
	ON_COMMAND(ID_RESSOURCES_IMAGETTES, OnRessourcesImagettes)
	ON_COMMAND(ID_RESSOURCES_POLICESPRDFINIES, OnRessourcesPolicesprdfinies)
	ON_COMMAND(ID_RESSOURCES_COULEURDUFOND, OnRessourcesCouleurdufond)
	ON_COMMAND(ID__AIDE, OnAide)
	ON_COMMAND(ID_MENU1_REDIMENSIONNER, OnMenu1Redimensionner)
	ON_COMMAND(ID_MENU2_SUPPRIMERUNIMAGEDEFOND, OnMenu2Supprimerunimagedefond)
	ON_COMMAND(ID_DEPLACER2, OnDeplacer)
	ON_COMMAND(ID_DELETE, OnDelete)
	ON_WM_SETCURSOR()
	ON_COMMAND(ID_MENU2_AJOUTERUNTEXTE, OnInsertionTexte)
	ON_COMMAND(ID_MENU2_AJOUTERUNEPOLICEPRDFINIE, OnRessourcesPolicesprdfinies)
	ON_COMMAND(ID_MENU2_AJOUTERUNEIMAGE, OnRessourcesImagedefond)
	ON_COMMAND(ID_MENU2_AJOUTERUNECOULEURDEFOND, OnRessourcesCouleurdufond)
	ON_COMMAND(ID_MENU2_AJOUTERUNEIMAGETTE, OnRessourcesImagettes)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/****************************************************
*				Constructeur 						*
****************************************************/
CCrea2K6View::CCrea2K6View()
{
	m_pSelected=NULL;
	m_MoveMode=FALSE;			// Pr savoir si on est en mode Déplacement
	m_CursorPoint=CPoint(0,0);	// position du curseur
	m_FirstPos=CPoint(0,0);		// position de départ de l'entite

}

/****************************************************
*				Destructeur 						*
****************************************************/

CCrea2K6View::~CCrea2K6View()
{

}

/****************************************************
*				Méthode de classe					*
****************************************************/


/*** Méthode par défauts... ***/

BOOL CCrea2K6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}




#ifdef _DEBUG
void CCrea2K6View::AssertValid() const
{
	CView::AssertValid();
}

void CCrea2K6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCrea2K6Doc* CCrea2K6View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCrea2K6Doc)));
	return (CCrea2K6Doc*)m_pDocument;
}
#endif //_DEBUG


/*** Méthode OnDraw	***/
void CCrea2K6View::OnDraw(CDC* pDC)
{
// Récupération d'un pointeur sur doc
	CCrea2K6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	
// taille zone cliente
GetClientRect(pDoc->m_RectVue);

if(pDoc->m_begin) {
		pDoc->OnFormatCartedevoeux();
		pDoc->m_begin=FALSE;
	
}
	/** Définition du nouveau format **/
	pDC->IntersectClipRect(CRect(pDoc->m_Origine,pDoc->m_Origine+pDoc->m_Format)); // limite la zone de dessin au format de la carte
	CPen aPen;
	aPen.CreatePen(PS_SOLID,1,RGB(160,160,160));
	CPen* pOldPen = pDC->SelectObject(&aPen);
	CBrush brush(pDoc->m_couleurFond);
	CBrush* pOldBrush = pDC->SelectObject(&brush);
	pDC->Rectangle(CRect(pDoc->m_Origine,pDoc->m_Origine+pDoc->m_Format));		  // dessine le format de la carte
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);



	/** Dessin des entités **/
	POSITION aPos=pDoc->GetListHeadPosition();		//position du premier element de la liste
	CEntite* pEntite=NULL;
	
	//ASSERT_VALID(pDoc->m_imgFond);
		pDoc->m_imgFond->Draw(pDC);
		

	while(aPos)								//boucle sur tous les éléments
	{
		pEntite=pDoc->GetNext(aPos);
		if(pDC->RectVisible(pEntite->GetBoundRect())) //vérifie si Rect est entierement dans la vue
			pEntite->Draw(pDC,m_pSelected);
			
	}
	AfficheInfo(pDC);
}

/*** Méthode de selection d'une entite sous la souris ***/
CEntite * CCrea2K6View::SelectEntite(CPoint point)
{


	CEntite *pEntite;					//crée un pointeur sur élément
	POSITION aPos;
	CCrea2K6Doc *pDoc=GetDocument();	//pointeur sur C...Doc
	CRect aRect;						//création d'un rectangle

	CClientDC aDC(this);
//	OnPrepareDC(&aDC);
//	aDC.DPtoLP(&point);					//convertion des points des repères en coord logique
	aPos=pDoc->GetListTailPosition();
	while (aPos)
	{ pEntite=pDoc->GetPrev(aPos);
	  aRect=pEntite->GetBoundRect();		//retourne le rectangle englobant
	  if (aRect.PtInRect(point))		//vérifie si les coordonnées données (position souris ici) sont ds le rectangle
		 return pEntite;
	}
	return NULL;

}

/*** Méthode de déplacement d'une entité ***/
void CCrea2K6View::MoveEntite(CClientDC &aDC, const CPoint &point)
{
	
	// Récupération d'un pointeur sur doc
	CCrea2K6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	CSize distance;
	distance= point - m_CursorPoint;
	m_CursorPoint=point;
	
	if (m_pSelected){
		// Récupération de la position
		POSITION aPos = pDoc->m_EntiteList.Find(m_pSelected);
		if(aPos) // S'il a été trouvé
		{
			pDoc->m_EntiteList.RemoveAt(aPos); // on le supprime
			Invalidate();
		}
			
		m_pSelected->Move(distance);			// déplacement
		
		// Ajout de l'entité déplace ds la liste
		pDoc->AddEntite(m_pSelected);

		// Dessin de l'entité ainsi déplacé
		m_pSelected->Draw(&aDC,m_pSelected);	// redessine a l'emplacement
		}
	
}




/************************************
*		Gestion des évènements		*
*************************************/

/********************************
*		Evenement SOURIS		*
*********************************/
// Bouton gauche lever
void CCrea2K6View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// Appel de la méthode mère
	CView::OnLButtonUp(nFlags, point);

	if(m_MoveMode)
		m_MoveMode=FALSE;

}

/*** Evenement Clique Droit ***/
void CCrea2K6View::OnRButtonUp(UINT nFlags, CPoint point) 
{
	CView::OnRButtonUp(nFlags, point);

	// Déclaration des menu
	CMenu aMenu, * pMenu;
	
	// Récupération de l'objet sous la souris
	m_pSelected = SelectEntite(point);

	// On charge le menu contextuel qu'on à créé
	aMenu.LoadMenu(IDR_CURSOR_MENU);

	// S'il y avait un objet texte sous la souris
	if(m_pSelected) {
	if(m_pSelected->GetType()==TEXTE)
	{
		// On charge dans un pointeur de menu le 1ier sous menu
		pMenu = aMenu.GetSubMenu(0);

		// conversion en coord écran
		ClientToScreen(&point);

		// On affiche le sous menu choisi
		pMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);
	
		m_CursorPoint=point;
	}

	else if(m_pSelected->GetType()==IMAGE)
	{
		// On charge dans un pointeur de menu le 1ier sous menu
		pMenu = aMenu.GetSubMenu(1);

		// conversion en coord écran
		ClientToScreen(&point);

		// On affiche le sous menu choisi
		pMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);
	
		m_CursorPoint=point;
	}
	}
	else {
		// On charge dans un pointeur de menu le 1ier sous menu
		pMenu = aMenu.GetSubMenu(2);

		// conversion en coord écran
		ClientToScreen(&point);

		// On affiche le sous menu choisi
		pMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);
	
	}



}

/*** Evenement lorsque la souris se déplace ***/
void CCrea2K6View::OnMouseMove(UINT nFlags, CPoint point) 
{
	CView::OnMouseMove(nFlags, point);

	CClientDC aDC(this);
	
	CView::OnPrepareDC(&aDC);
	if(m_MoveMode)
	{
		MoveEntite(aDC,point);
	}

}



/*** Insertion d'un Texte ***/
void CCrea2K6View::OnInsertionTexte() 
{
	// Récupération d'un pointeur sur doc
	CCrea2K6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// Récupération d'un contexte de périphérique
	CClientDC aDC(this);

	// teste de l'affichage d'un texte
	LOGFONT lf;
	ZeroMemory(&lf, sizeof(LOGFONT) );
	lstrcpy(lf.lfFaceName,"Arial");
	lf.lfHeight=16;
	
	// FORMAT DU TEXTE DANS LE RECTANGLE ENGLOBANT
	UINT nFormat=DT_CENTER|DT_SINGLELINE;

	// On détermine la position du texte
	CRect aRect;
	GetClientRect(aRect);
	

	int Largeur = aRect.Width();
	int Hauteur = aRect.Height();

	CTexte* t = new CTexte("Entrez votre texte",lf,nFormat,RGB(0,0,0),CPoint(Largeur/2-100,Hauteur/2-50),&aDC);

	pDoc->m_EntiteList.AddTail(t);


	Invalidate();
}

void CCrea2K6View::debug(CString string)
{
	AfxMessageBox(string);
}

/***	Méthode d'impression ***/
BOOL CCrea2K6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	CPrintData* pPrintData = new CPrintData();

	pInfo->m_lpUserData = pPrintData ;


	CCrea2K6Doc * pDoc = GetDocument();

	pPrintData->m_DocRefPoint = CPoint(pDoc->m_Origine);

	pPrintData->m_DocTitle = "Créa2K6 - Impression d'une carte";

	pPrintData->m_nWidth = pDoc->m_Format.cx;
	pPrintData->m_nLength = pDoc->m_Format.cy ;

	pInfo->SetMinPage(1);

	if(!DoPreparePrinting(pInfo))
	{
		delete static_cast<CPrintData*>(pInfo->m_lpUserData);
		return FALSE;
	}
	return TRUE;

	//return DoPreparePrinting(pInfo);
}

void CCrea2K6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCrea2K6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* pInfo)
{
	delete static_cast<CPrintData*>(pInfo->m_lpUserData);
	// TODO: add cleanup after printing
}


/*** Evenement pour supprimer une entité ***/
void CCrea2K6View::OnDelete() 
{// Récupération d'un pointeur sur doc
	CCrea2K6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);


		if(m_pSelected)
		{
			pDoc->DeleteEntite(m_pSelected);
			Invalidate();
			// InvalidateRec(0);
			// pDoc->UpdateAllViews();
			m_pSelected=NULL;
		}

}

/*** Evenement pour mettre en Arriere Plan ***/
void CCrea2K6View::OnSendToBack() 
{

	// Récupération d'un pointeur sur doc
	CCrea2K6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	

	if(m_pSelected)
	{
		pDoc->SendToBack(m_pSelected);
		m_pSelected=NULL;
		Invalidate();
	} 
	CClientDC aDC(this);

	Invalidate();

}

/*** Evenement pour déplacer une entité ***/
void CCrea2K6View::OnDeplacer() 
{
	CClientDC aDC(this);
	CView::OnPrepareDC(&aDC);
	GetCursorPos(&m_CursorPoint);
	ScreenToClient(&m_CursorPoint);
	aDC.DPtoLP(&m_CursorPoint);
	m_FirstPos=m_CursorPoint;

	m_MoveMode=TRUE;	// on place le mode de déplacement a vrai	
}


void CCrea2K6View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// Appel de la méthode mère
	CView::OnLButtonDown(nFlags, point);


	// Récupération d'un pointeur sur doc
	CCrea2K6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	// Récupération d'un contexte de périphérique
	CClientDC aDC(this);
		CEntite* m_pCurrentSelected=SelectEntite(point);
		CRect aRect;
		if (m_pCurrentSelected!=m_pSelected){
			if (m_pSelected){
				aRect=m_pSelected->GetBoundRect();
				Invalidate();						//InvalidateRect(aRect); <= marche pas lorque l'on déplace l'ascenseur
			
			}
			m_pSelected=m_pCurrentSelected; 
			if (m_pSelected){
				aRect=m_pSelected->GetBoundRect();
				Invalidate();
			}
		}

	// Gestion de la fin du déplacement

	if(m_MoveMode) 
	{
		m_pSelected=NULL;
		m_MoveMode=FALSE;
		Invalidate();
		m_CursorPoint = CPoint(0,0);
	}
	else {
	CClientDC aDC(this);
	CView::OnPrepareDC(&aDC);
	GetCursorPos(&m_CursorPoint);
	ScreenToClient(&m_CursorPoint);
	aDC.DPtoLP(&m_CursorPoint);
	m_FirstPos=m_CursorPoint;

	m_MoveMode=TRUE;	// on place le mode de déplacement a vrai	
	}

}


void CCrea2K6View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// appel de la méthode mère
	CView::OnRButtonDown(nFlags, point);

	// Gestion de la fin du déplacement
	if(m_MoveMode) 
	{
		CClientDC aDC(this);
		CView::OnPrepareDC(&aDC);
		MoveEntite(aDC,m_FirstPos);
		m_MoveMode=FALSE;
		m_pSelected=NULL;
		Invalidate();
		
		m_CursorPoint = CPoint(0,0);
	}
}

/* Menu du clique droit sur une Entité */
void CCrea2K6View::OnMenu0Editer() 
{

	// Déclaration de la boite de dialog texte
	CTexteDialog txtdlg;

	// Récupération de l'objet selectionné 
	// bien etre sur que c pa autre chose...
	CTexte* text = static_cast<CTexte*>(m_pSelected);

	// Initialisation du texte contenu dans l'edit
	txtdlg.m_Edit		=	text->m_contenu;
	txtdlg.m_color		=	text->m_couleur;
    txtdlg.m_nFormat	=	text->m_nFormat;
	txtdlg.m_logfont	=	text->m_lf;	


	if(txtdlg.DoModal() == IDOK){

		text->m_contenu = txtdlg.m_Edit;
		text->m_couleur = txtdlg.m_color;
		text->m_nFormat = txtdlg.m_nFormat;
		text->m_lf		= txtdlg.m_logfont;
	
		Invalidate();
	}
}


void CCrea2K6View::OnLButtonDblClk(UINT nFlags, CPoint point) 
{

	if(m_pSelected) {
	
		if(m_pSelected->GetType()==TEXTE)
			OnMenu0Editer() ;
		else
			OnMenu1Redimensionner();

	}
		// Déclaration de la boite de dialog texte

	CView::OnLButtonDblClk(nFlags, point);
}

void CCrea2K6View::OnInsertionImage() 
{
	// Récupération du pointeur sur document
	CCrea2K6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	

	// Création de la dialog "Ouvrir ..."
	CFileDialog cfdlg(TRUE);
	cfdlg.DoModal();

	// Si l'utilisateur a saisi un fichier
	if(cfdlg.GetPathName()!="") {
		CString filePath = cfdlg.GetPathName();
		
	
		// récup vue
		CRect aRect;
		GetClientRect(aRect);
	
		// On détermine la position de l'image
		int Largeur = aRect.Width();
		int Hauteur = aRect.Height();

		CImg* i = new CImg(CPoint(Largeur/2-100,Hauteur/2-100),filePath);
		pDoc->AddEntite(i);

	
		Invalidate();
	}
}


/*****************************************
*	Ecoute du clavier
******************************************/
void CCrea2K6View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{

	if (m_pSelected){
	switch(nChar) {
	
	case VK_UP :
		m_pSelected->Move(CSize(CPoint(0,-1)));
		break;
	case VK_DOWN :
		m_pSelected->Move(CSize(CPoint(0,1)));
		break;
	case VK_RIGHT :
		m_pSelected->Move(CSize(CPoint(1,0)));
		break;
	case VK_LEFT :
		m_pSelected->Move(CSize(CPoint(-1,0)));
		break;
	case VK_DELETE :
		OnDelete();
		break;
	case VK_SPACE :
		OnSendToBack();
	
	break;
	}

	Invalidate();

	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CCrea2K6View::OnEraseBkgnd(CDC* pDC) 
{
  // Fixe une brosse avec la couleur de fond choisie
     CBrush BkClrBrush(RGB(240, 240, 240));

     // Sauvegarde l’ancienne brosse.
     CBrush* pOldBrush = pDC->SelectObject(&BkClrBrush);

     CRect rect;
     pDC->GetClipBox(&rect);    // récupère la zone a effacer.

     pDC->PatBlt(rect.left, rect.top, rect.Width(),
                 rect.Height(), PATCOPY);

     pDC->SelectObject(pOldBrush);// restitue l’ancienne brosse.
     return TRUE;	
//	return CView::OnEraseBkgnd(pDC);
}

void CCrea2K6View::OnRessourcesImagedefond() 
{
	// Récupération du pointeur sur document
	CCrea2K6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CImageFondDlg	ifdlg(this) ;


	if( ifdlg.DoModal() == IDOK)
	{
		
		if(ifdlg.m_carte!="" && ifdlg.m_theme!="" && ifdlg.m_nom!="") {
		CString s;
		CString rep;
		rep.Format("%s",pDoc->m_RepAppli);
		s.Format("%s\\ressources\\%s\\%s\\%s",rep,ifdlg.m_carte,ifdlg.m_theme,ifdlg.m_nom);


		CImg* i = new CImg(pDoc->m_Origine,s);
		pDoc->m_imgFond = i;
		
		Invalidate();
		}
	}
}


void CCrea2K6View::OnRessourcesImagettes() 
{
	// Récupération du pointeur sur document
	CCrea2K6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CImagetteDlg	idlg(this) ;

	if( idlg.DoModal() == IDOK)
	{
				
		if( idlg.m_theme!="" && idlg.m_fichier!="") {
		CString s;
		CString rep;
		rep.Format("%s",pDoc->m_RepAppli);
		s.Format("%s\\ressources\\imagettes\\%s\\%s",rep,idlg.m_theme,idlg.m_fichier);
		// récup vue
		CRect aRect;
		GetClientRect(aRect);
	
		// On détermine la position de l'image
		int Largeur = aRect.Width();
		int Hauteur = aRect.Height();
	
		CImg* i = new CImg(CPoint(Largeur/2-100,Hauteur/2-100),s);
		pDoc->AddEntite(i);
		
		Invalidate();
		}
	}
}

void CCrea2K6View::OnRessourcesPolicesprdfinies() 
{
	CFontPredefDlg fpdlg ;

	if(fpdlg.DoModal()==IDOK){
		
		// Récupération d'un pointeur sur doc
		CCrea2K6Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);

		// Récupération d'un contexte de périphérique
		CClientDC aDC(this);

		
		// teste de l'affichage d'un texte
		LOGFONT lf;
		ZeroMemory(&lf, sizeof(LOGFONT) );


		switch(fpdlg.police) {
		case 1:
			lstrcpy(lf.lfFaceName,"Arial Narrow");
			lf.lfHeight=24;
			lf.lfWeight=600;
			break;
		case 2:
			lstrcpy(lf.lfFaceName,"Bell MT");
			lf.lfHeight=24;
			lf.lfWeight=600;
			break;
		case 3:
			lstrcpy(lf.lfFaceName,"Bradley Hand ITC");
			lf.lfHeight=24;
			lf.lfWeight=600;
			break;
		case 4:
			lstrcpy(lf.lfFaceName,"Centaur");
			lf.lfHeight=24;
			lf.lfWeight=600;
			break;
		case 5 :
			lstrcpy(lf.lfFaceName,"Eras Light ITC");
			lf.lfHeight=20;
			lf.lfWeight=600;
			break;
		case 6 :
			lstrcpy(lf.lfFaceName,"Comic Sans MS");
			lf.lfHeight=20;
			lf.lfWeight=600;
			break;
		case 7 :
			lstrcpy(lf.lfFaceName,"Brush Script MT");
			lf.lfHeight=22;
			//lf.lfWeight=600;
			break;
		case 8 :
			lstrcpy(lf.lfFaceName,"Chiller");
			lf.lfHeight=24;
			lf.lfWeight=300;
			break;
		case 9 :
			lstrcpy(lf.lfFaceName,"Gill Sans MT");
			lf.lfHeight=20;
			break;
		default :
			break;
		}
		
		
		// Format
		UINT nFormat=DT_CENTER|DT_SINGLELINE;

		// On détermine la position du texte
		CRect aRect;
		GetClientRect(aRect);

		int Largeur = aRect.Width();
		int Hauteur = aRect.Height();

		CTexte* t = new CTexte("Entrez votre texte",lf,nFormat,RGB(0,0,0),CPoint(Largeur/2-100,Hauteur/2-50),&aDC);

		pDoc->m_EntiteList.AddTail(t);
		Invalidate();
	}
}

void CCrea2K6View::AfficheInfo(CDC *pDC)
{
	if(m_pSelected){
	// Détermination de l'origine de la carte (pour la position)
	CCrea2K6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CRect aRect;
	GetClientRect(aRect);
	int Largeur = aRect.Width();
	int Hauteur = aRect.Height();
	CSize carte = pDoc->m_Format;
	CPoint HG ( (Largeur/2) -  (carte.cx/2) ,  (Hauteur/2) -  (carte.cy/2) );

	// Récup' du contexte de périph.
	CClientDC aDC(this);

	// Définition de l'environnement d'affichage
		
		// police transparent
	aDC.SetBkMode(TRANSPARENT);		
	
		// rectangle englobant l'info
	CRect RectInfo(3,3,220,120);
	
		// Création d'un crayon (pour le cadre du rectangle
	CPen aPen;
	aPen.CreatePen(PS_SOLID,1,RGB(220,220,220));
	aDC.SelectObject(&aPen);
	CFont * pOldFont = static_cast<CFont *>( aDC.SelectStockObject(ANSI_FIXED_FONT)); // font d'ecriture


	// Affichage du rectangle
	aDC.Rectangle(RectInfo);

	CString format;
	CString type;
	CString nom;
	CString taille;

	// Recherche du format de la carte	
	if(pDoc->m_Format==CARTEVOEUX)
		format="Carte de voeux";
	else if(pDoc->m_Format==CARTEVISITE)
		format="Carte de visite";
	else if(pDoc->m_Format==CARTEPOSTALE)
		format="Carte postale";
	else if(pDoc->m_Format==INVITATION)
		format="Carte d'invitation";


	// Recherche des infos sur le texte		
	if(m_pSelected->GetType()==TEXTE)
	{	type ="Type : Texte";		// son type
		CTexte* txt = static_cast<CTexte*>(m_pSelected);	
		nom.Format("Police : %s",txt->m_lf.lfFaceName);
	}
	// recherche des info sur l'image
	else
	{
		type="Type : Image";

	}
	// Recherche de la Position
	CString position;
	position.Format("Position : %dx %dy",
		m_pSelected->m_EnclosingRect.TopLeft().x-HG.x,
		m_pSelected->m_EnclosingRect.TopLeft().y-HG.y
	);

	// Affichage
	aDC.TextOut(5,5,format);
	aDC.TextOut(5,20,type);
	aDC.TextOut(5,35,position);
	aDC.TextOut(5,50,nom);
	aDC.TextOut(5,65,taille);
	
	// Restitution de l'ancienne police ds le CDC
	aDC.SelectObject(pOldFont);
	}
}

void CCrea2K6View::OnPrepareDC(CDC *pDC, CPrintInfo *pInfo)
{
	CView::OnPrepareDC(pDC,pInfo);
	CCrea2K6Doc * pDoc = GetDocument();

	pDC->SetMapMode(MM_ANISOTROPIC); 


	// Définition de la fenetre
	pDC->SetWindowExt(pDoc->m_Format); // format de la carte (CSize)

	pDC->SetViewportExt(pDoc->m_Format.cx,pDoc->m_Format.cy);



}

void CCrea2K6View::OnPrint(CDC *pDC, CPrintInfo *pInfo)
{
	CPrintData* pPrintData = static_cast<CPrintData*>(pInfo->m_lpUserData);


	CCrea2K6Doc * pDoc = GetDocument();

	// sortie du nom de fichier du doc
	pDC->SetTextAlign(TA_CENTER); // Centre le texte suivant
	pDC->TextOut(pInfo->m_rectDraw.right/2, 20,pPrintData->m_DocTitle);

	CString PageNum;
	PageNum.Format("Page %d", pInfo->m_nCurPage);

	pDC->SetTextAlign(TA_LEFT); //Justifie le texte à gauche


	// Remplace l’origine de la fenêtre par celle de la page en
	// cours et enregistre l’ancienne origine
	CPoint OldOrg = pDC->SetWindowOrg(pDoc->m_Origine.x,pDoc->m_Origine.y); // juste

	// Définit 1 rect. de découpage de la taille de la zone imprimée
	CRect rect (pDoc->m_Origine,pDoc->m_Origine+pDoc->m_Format); // juste 
	pDC->IntersectClipRect(rect);

	m_pSelected=NULL; // sinon l'entité selectionné a son cadre autour d'elle :s
	OnDraw(pDC); // Affiche le document

	pDC->SelectClipRgn(NULL); // Supprime le rect. de découpage

	// Restaure l’ancienne origine de la fenêtre
	pDC->SetWindowOrg(OldOrg);
}

void CCrea2K6View::OnRessourcesCouleurdufond() 
{
	CCrea2K6Doc * pDoc = GetDocument();

	CColorDialog cdlg;

	if(cdlg.DoModal() == IDOK)
		pDoc->m_couleurFond=cdlg.GetColor();

	Invalidate();
	
}

void CCrea2K6View::OnAide() 
{
	CAideDialog adlg(this);
	adlg.DoModal();
}

void CCrea2K6View::OnMenu1Redimensionner() 
{
	if(m_pSelected) 
	{
		CRedimDlg rdlg;
		rdlg.m_Width=m_pSelected->m_EnclosingRect.Width();
		rdlg.m_Height=m_pSelected->m_EnclosingRect.Height();
		if(rdlg.DoModal()==IDOK)
		{
			CSize sz(rdlg.m_Width,rdlg.m_Height);
			CPoint hg(m_pSelected->m_EnclosingRect.TopLeft());
			CRect rect(hg,sz);
			m_pSelected->m_EnclosingRect=rect;
			Invalidate();
		}
	}
}



void CCrea2K6View::OnMenu2Supprimerunimagedefond() 
{

CCrea2K6Doc* pDoc = GetDocument();

pDoc->m_imgFond=new CImg();
Invalidate();

}
