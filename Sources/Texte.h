/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier :Texte.h
*
******************************************************************************/

#if !defined(AFX_TEXTE_H__F7045FB1_4FCD_4C5B_B38D_F84B5DE972F0__INCLUDED_)
#define AFX_TEXTE_H__F7045FB1_4FCD_4C5B_B38D_F84B5DE972F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entite.h"		// pour la classe mere

class CTexte  : public CEntite
{


public:
	UINT m_nFormat;
	/* Variables de classe */
	CString		m_contenu;		// contenu du texte
	LOGFONT		m_lf ;			// paramètre du style d'ecriture
	COLORREF	m_couleur;		// couleur du texte

	/* Constructeur */
	CTexte();
	
	CTexte(CString,LOGFONT,UINT,COLORREF,CPoint,CDC* pDC);
	CTexte(CString,CFont,UINT,COLORREF,CPoint,CDC* pDC);

	
	/* Méthodes */
	
	void Draw(CDC* pDC);	// opération de dessin
	void Draw(CDC* pDC,CEntite* entite);
	//void DrawEnclosingRect(CDC* pDC);	// pour déssiner le rectangle enclonbant
										// lors de la selection de l'objet

	void Move(const CSize& size);

	
	/* Destructeur */
	virtual ~CTexte();
			
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CTexte)		// pour la sérialisation
};

#endif // !defined(AFX_TEXTE_H__F7045FB1_4FCD_4C5B_B38D_F84B5DE972F0__INCLUDED_)
