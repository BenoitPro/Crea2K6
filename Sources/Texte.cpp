/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier : Texte.cpp
*
******************************************************************************/

#include "stdafx.h"
#include "Crea2K6.h"
#include "Texte.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


IMPLEMENT_SERIAL(CTexte,CEntite,1)
/****************************************
*			Constructeurs				*
****************************************/
CTexte::CTexte()
{
	ZeroMemory(&m_lf, sizeof(LOGFONT) );
}

CTexte::CTexte(CString contenu,LOGFONT lf,UINT nFormat,COLORREF couleur,CPoint position,CDC* pDC) 
:CEntite(CRect(position,position),TEXTE)
{

	// Initialisation des variables
	m_contenu	= contenu;
	m_lf		= lf ;
	m_couleur	= couleur;
	m_nFormat	= nFormat;

	// Création de la font
	CFont font;
	// On initialise la font avec notre LOGFONT perso
	font.CreateFontIndirect(&lf);
	
	
	// On selectionne la font dans le contexte de périphérique
	CFont * pOldFont = pDC->SelectObject(&font);
	CSize size=pDC->GetTextExtent(contenu);

	m_EnclosingRect = CRect(position,CPoint(position.x+size.cx+10,position.y+size.cy+4));
	m_EnclosingRect.NormalizeRect();

}

/****************************************
*			Destructeur 				*
****************************************/
CTexte::~CTexte()
{

}
/****************************************
*			Méthodes de classe			*
****************************************/

void CTexte::Draw(CDC *pDC) {
	
	// Création de la font
	CFont font;

	// On initialise la font avec notre LOGFONT perso
	font.CreateFontIndirect(&m_lf);
	
	// On selectionne la font dans le contexte de périphérique
	CFont * pOldFont = pDC->SelectObject(&font);

	// On définie la couleur du texte
	COLORREF OldColor = pDC->SetTextColor(m_couleur);

	// On récupere la taille que va faire le texte avec le nouveau contenu
	CSize size=pDC->GetTextExtent(m_contenu);
	
	// Mise a jour de la taille du rectangle englobant
	CPoint& pointHautGauche = m_EnclosingRect.TopLeft();
	CPoint& pointBasDroit =pointHautGauche+size;
	pointBasDroit.x+=10;
	pointBasDroit.y+=4;

	m_EnclosingRect = CRect(pointHautGauche,pointBasDroit);

	// Fond du texte transparent
	pDC->SetBkMode(TRANSPARENT);
	// Affichage du texte dans le rectangle englobant et selon le nFormat défine	
	pDC->DrawText(m_contenu,&m_EnclosingRect,m_nFormat);

	// Restitution de l'ancienne police ds le CDC
	pDC->SelectObject(pOldFont);
	pDC->SelectObject(&OldColor);
}

void CTexte::Serialize(CArchive &ar)
{

	/* Sérialisation de la logfont */
	int Height = m_lf.lfHeight;
	int Width = m_lf.lfWidth;
	int Escapment = m_lf.lfEscapement;
	int Orientation = m_lf.lfOrientation;
	int Weight = m_lf.lfWeight;
	BYTE italic = m_lf.lfItalic;
	BYTE underline = m_lf.lfUnderline;
	BYTE strikeout = m_lf.lfStrikeOut;
	BYTE charset = m_lf.lfCharSet;
	BYTE outprecision = m_lf.lfOutPrecision;
	BYTE clipprecision = m_lf.lfClipPrecision;
	BYTE quality = m_lf.lfQuality;
	BYTE pitchandfamily  = m_lf.lfPitchAndFamily;
	CString police=m_lf.lfFaceName;

	CEntite::Serialize(ar);
if(ar.IsStoring())
	ar<<m_contenu<<m_couleur<<m_nFormat<<Height<<Width<<Escapment<<Orientation<<Weight<<italic<<underline<<
		strikeout<<charset<<outprecision<<clipprecision<<quality<<pitchandfamily<<police;
else {
	ar>>m_contenu>>m_couleur>>m_nFormat>>Height>>Width>>Escapment>>Orientation>>Weight>>italic>>underline>>
		strikeout>>charset>>outprecision>>clipprecision>>quality>>pitchandfamily>>police;

	/* Désérialisation de la Logfont */
	strcpy(m_lf.lfFaceName,police);
	m_lf.lfHeight	= Height; 
	m_lf.lfWidth	= Width; 
	m_lf.lfEscapement= Escapment; 
	m_lf.lfOrientation	= Orientation; 
	m_lf.lfWeight	= Weight; 
	m_lf.lfItalic	= italic; 
	m_lf.lfUnderline= underline; 
	m_lf.lfStrikeOut= strikeout; 
	m_lf.lfCharSet	= charset; 
	m_lf.lfOutPrecision	= outprecision; 
	m_lf.lfClipPrecision	= clipprecision; 
	m_lf.lfQuality	= quality; 
	m_lf.lfPitchAndFamily	= pitchandfamily; 


	}
}


/**********************************************************************
* 2ieme méthode draw pour savoir ci il s'agit de l'element selectionné
***********************************************************************/
void CTexte::Draw(CDC *pDC,CEntite* pEntite)
{
	if(this==pEntite) {
		Draw(pDC);
		DrawEnclosingRect(pDC);
	}
	else {
		Draw(pDC);
	}
}

/***********************************
*	Déplace le rectangle englobant *
***********************************/

void CTexte::Move(const CSize& size) {
	m_EnclosingRect +=size;
}