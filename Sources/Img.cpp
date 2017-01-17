/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier : Img.cpp
*
******************************************************************************/
#include "stdafx.h"
#include "Crea2K6.h"
#include "Img.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(CImg,CEntite,1)

/* Constructeur */
CImg::CImg()
{

}

CImg::CImg(CPoint position, CString fileImg)
: CEntite(CRect(position,position),IMAGE)
{
	// Chargement de l'image
	m_chemin = fileImg;
	m_pos = position;
	m_picture.Load(fileImg);
	// Récupération de la taille de l'image
	CSize size(CPoint(m_picture.m_Width,m_picture.m_Height));

	// Définition du rectangle englobant
	m_EnclosingRect = CRect(position,CPoint(position.x+size.cx,position.y+size.cy));
	m_EnclosingRect.NormalizeRect();
}


/* Méthodes */

void CImg::Draw(CDC *pDC) {

   	m_picture.UpdateSizeOnDC(pDC);
	m_picture.Show(pDC,
                m_EnclosingRect);	
}


void CImg::Move(const CSize& size) {
		m_EnclosingRect +=size;
		m_pos +=size;
}

void CImg::Draw(CDC *pDC,CEntite* pEntite)
{

	if(this==pEntite) {
		Draw(pDC);
		DrawEnclosingRect(pDC);
	}
	else {
		Draw(pDC);
	}
}

/* Destructeur */
CImg::~CImg()
{

}

void CImg::Serialize(CArchive& ar)
{ CEntite::Serialize(ar);
m_picture.Serialize(ar);

}