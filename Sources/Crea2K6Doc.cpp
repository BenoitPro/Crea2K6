/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier : Crea2K6Doc.cpp
*
******************************************************************************/
#include "stdafx.h"
#include "Crea2K6.h"

#include "Crea2K6Doc.h"

/***************************
*		inclusions		   *
****************************/
#include "constantes.h"
#include "Crea2K6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCrea2K6Doc

IMPLEMENT_DYNCREATE(CCrea2K6Doc, CDocument)

BEGIN_MESSAGE_MAP(CCrea2K6Doc, CDocument)
	//{{AFX_MSG_MAP(CCrea2K6Doc)
	ON_COMMAND(ID_FORMAT_CARTEDEVISITE, OnFormatCartedevisite)
	ON_COMMAND(ID_FORMAT_CARTEDEVOEUX, OnFormatCartedevoeux)
	ON_COMMAND(ID_FORMAT_CARTEPOSTALE, OnFormatCartepostale)
	ON_COMMAND(ID_FORMAT_INVITATION, OnFormatInvitation)
	ON_UPDATE_COMMAND_UI(ID_FORMAT_CARTEDEVISITE, OnUpdateFormatCartedevisite)
	ON_UPDATE_COMMAND_UI(ID_FORMAT_CARTEDEVOEUX, OnUpdateFormatCartedevoeux)
	ON_UPDATE_COMMAND_UI(ID_FORMAT_CARTEPOSTALE, OnUpdateFormatCartepostale)
	ON_UPDATE_COMMAND_UI(ID_FORMAT_INVITATION, OnUpdateFormatInvitation)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCrea2K6Doc construction/destruction

CCrea2K6Doc::CCrea2K6Doc()
{
	m_Format = CARTEVOEUX;
	m_begin = TRUE;
	m_couleurFond = RGB(255,255,255);
	m_imgFond = new CImg();

if(!::GetCurrentDirectory(sizeof(m_RepAppli) - 1, m_RepAppli))
{
  // ::GetLastError()
}

}

CCrea2K6Doc::~CCrea2K6Doc()
{
}

BOOL CCrea2K6Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCrea2K6Doc serialization

void CCrea2K6Doc::Serialize(CArchive& ar)
{
	
	POSITION aPos;
	aPos = m_EntiteList.GetHeadPosition();
	while(aPos)
	{
		CEntite* ent = m_EntiteList.GetNext(aPos);
		if (ent->GetType()==IMAGE)
		{
			CImg* img =static_cast<CImg*>(ent) ;
			m_ImgList.AddHead(img->m_chemin);
			m_ImgPosList.AddHead(img->m_pos);
		}
	}
	
	m_imgFondString="";
	m_imgFondString = m_imgFond->m_chemin ;

	m_ImgList.Serialize(ar);	// sauv. les chemin des images
	m_ImgPosList.Serialize(ar);	// sauv. les chemin des images
	m_EntiteList.Serialize(ar);
	if (ar.IsStoring())
	{
	ar<<m_Format<<m_begin<<m_Origine<<m_RectVue<<m_imgFondString;
	}
	else
	{
	m_imgFondString="";
	ar>>m_Format>>m_begin>>m_Origine>>m_RectVue>>m_imgFondString;

	POSITION aPos,aPos2;
	aPos=m_ImgList.GetHeadPosition();
	aPos2=m_ImgPosList.GetHeadPosition();

	while(aPos)
		{
		CString ch =m_ImgList.GetNext(aPos);
		CPoint p = m_ImgPosList.GetNext(aPos2);	
		CImg* i = new CImg(p,ch);
		AddEntite(i);
		}
	if(m_imgFondString!="")
		m_imgFond = new CImg(m_Origine,m_imgFondString);

	}
}




/////////////////////////////////////////////////////////////////////////////
// CCrea2K6Doc diagnostics

#ifdef _DEBUG
void CCrea2K6Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCrea2K6Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


/************************************
		Supprime une entité
*************************************/

void CCrea2K6Doc::DeleteEntite(CEntite *pEntite)
{
	// Si l'entite existe (nb : elle existe forcément...)
	if (pEntite){
		// Récupération de la position
		POSITION aPos = m_EntiteList.Find(pEntite);
		if(aPos) // Si il a été trouvé
		{
			m_EntiteList.RemoveAt(aPos); // on le supprime
			SetModifiedFlag();
		}
		delete pEntite;
	}
}


void CCrea2K6Doc::SendToBack(CEntite *pEntite)
{
	if(pEntite) {
		POSITION aPos = m_EntiteList.Find(pEntite);
		if(aPos) 
		{
		m_EntiteList.RemoveAt(aPos);
		m_EntiteList.AddHead(pEntite);
		}
	}

}

/***************************************
*		Gestion des évenements			*
*****************************************/

void CCrea2K6Doc::OnFormatCartedevisite() 
{

	/* Suppression de tout les éléments contenue sur le vue */
	m_EntiteList.RemoveAll();

	m_Format = CARTEVISITE;
	m_imgFond = new CImg();

	POSITION aPos = GetFirstViewPosition();
	CCrea2K6View* pView =static_cast<CCrea2K6View*>(GetNextView(aPos));
	
	 pView->GetClientRect(m_RectVue);

	m_Origine = CPoint( (m_RectVue.Width()/2) -  (m_Format.cx/2) ,
		(m_RectVue.Height()/2) -  (m_Format.cy/2) );

	pView->Invalidate();
	


}

void CCrea2K6Doc::OnFormatCartedevoeux() 
{
	/* Suppression de tout les éléments contenue sur le vue */
	m_EntiteList.RemoveAll();

	m_Format = CARTEVOEUX;
	m_imgFond = new CImg();

	
	POSITION aPos = GetFirstViewPosition();
	CCrea2K6View* pView =static_cast<CCrea2K6View*>(GetNextView(aPos));

	pView->GetClientRect(m_RectVue);
	m_Origine = CPoint( (m_RectVue.Width()/2) -  (m_Format.cx/2) ,
		(m_RectVue.Height()/2) -  (m_Format.cy/2) );


	pView->Invalidate();
}

void CCrea2K6Doc::OnFormatCartepostale() 
{
	/* Suppression de tout les éléments contenue sur le vue */
	m_EntiteList.RemoveAll();

	m_Format = CARTEPOSTALE;
	m_imgFond = new CImg();

	POSITION aPos = GetFirstViewPosition();
	CCrea2K6View* pView =static_cast<CCrea2K6View*>(GetNextView(aPos));
	
	pView->GetClientRect(m_RectVue);
	m_Origine = CPoint( (m_RectVue.Width()/2) -  (m_Format.cx/2) ,
		(m_RectVue.Height()/2) -  (m_Format.cy/2) );
	
	pView->Invalidate();
}

void CCrea2K6Doc::OnFormatInvitation() 
{
	/* Suppression de tout les éléments contenue sur le vue */
	m_EntiteList.RemoveAll();

	m_Format = INVITATION;
	m_imgFond = new CImg();
	
	POSITION aPos = GetFirstViewPosition();
	CCrea2K6View* pView =static_cast<CCrea2K6View*>(GetNextView(aPos));
	
	pView->GetClientRect(m_RectVue);
	m_Origine = CPoint( (m_RectVue.Width()/2) -  (m_Format.cx/2) ,
		(m_RectVue.Height()/2) -  (m_Format.cy/2) );
	
	pView->Invalidate();
}

void CCrea2K6Doc::OpenDoc(CString fichier)
{


	
	CDocument::OnOpenDocument(fichier);
}

void CCrea2K6Doc::OnUpdateFormatCartedevisite(CCmdUI* pCmdUI) 
{
pCmdUI->SetCheck(m_Format==CARTEVISITE);	
}

void CCrea2K6Doc::OnUpdateFormatCartedevoeux(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_Format==CARTEVOEUX);		
}

void CCrea2K6Doc::OnUpdateFormatCartepostale(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		pCmdUI->SetCheck(m_Format==CARTEPOSTALE);
}

void CCrea2K6Doc::OnUpdateFormatInvitation(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		pCmdUI->SetCheck(m_Format==INVITATION);
	
}

