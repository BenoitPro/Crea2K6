/******************************************************************************
* Projet : IHM - Cr�ation de cartes en tout genre 
* Auteurs : Anthony et Beno�t Mar�chal
* Derni�re modification : 19 / 01 / 2006
* 
* Fichier : Entite.cpp
*
******************************************************************************/

#include "stdafx.h"
#include "Crea2K6.h"
#include "Entite.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
// Sauvegarde
IMPLEMENT_SERIAL(CEntite,CObject,1) //pour l'enregistrement

//-----------------------------------------------------------------------------
/* Constructeur */

CEntite::CEntite()
{
	// initialisations
	//m_EnclosingRect= CRect();			//cr�ation d'un rectangle englobant vide
	//m_EnclosingRect.NormalizeRect();	//normalisation des coordonn�es du rectangle
}
CEntite::CEntite(CRect rect,WORD type)
{
	m_EnclosingRect = rect;				//cr�ation d'un rectangle englobant vide
	m_EnclosingRect.NormalizeRect();	//normalisation des coordonn�es du rectangle
	m_type = type ;

}

//-----------------------------------------------------------------------------
/* M�thodes */

//R�cup�ration du rectangle englobant
CRect CEntite::GetBoundRect(void) const 
{
 return m_EnclosingRect;	//on retourne le rectangle englobant
}



void CEntite::DrawEnclosingRect(CDC* pDC)  {	// d�ssine le rect englobant

	/* Cr�e une plume associ�e � l'objet et l'initialise avec la couleur de l'objet
 et l'epaisseur du trait */
 CPen aPen;
 aPen.CreatePen(PS_DOT ,1,RGB(0,0,0));

 /* Selectionne la plume */
 CPen * pOldPen;
 pOldPen=pDC->SelectObject(&aPen);
 CBrush * pOldBrush;
 pOldBrush=static_cast<CBrush *>(pDC->SelectStockObject(NULL_BRUSH));

 /* Dessine maintenant le rectangle */
 pDC->Rectangle(m_EnclosingRect);

 /* Restitue l'ancienne plume et l'ancien pinceau */
 pDC->SelectObject(pOldPen);
 pDC->SelectObject(pOldBrush);


}

//-----------------------------------------------------------------------------
/* Destructeur */
CEntite::~CEntite()
{

}


void CEntite::Serialize(CArchive& ar)
{ CObject::Serialize(ar);

if(ar.IsStoring())
	ar<<m_EnclosingRect<<m_type;
else
	ar>>m_EnclosingRect>>m_type;

}