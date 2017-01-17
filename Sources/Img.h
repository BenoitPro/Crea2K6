/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier :Img.h
*
******************************************************************************/
#if !defined(AFX_IMG_H__9AE6883E_E98C_4056_8DC2_41AD97ED458F__INCLUDED_)
#define AFX_IMG_H__9AE6883E_E98C_4056_8DC2_41AD97ED458F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entite.h"		// pour la classe mere
#include "Picture.h"	// pour l'image (en jpg)

class CImg  : public CEntite
{
public:
	CPoint m_pos;
	CString m_chemin;
	
	/* Variables de classe */
	CPicture m_picture ;

	/* Constructeur */
	CImg();
	CImg(CPoint,CString);

	/* Méthodes */
	void Draw(CDC * pDC);
	void Draw(CDC *pDC,CEntite* pEntite);
//	void DrawEnclosingRect(CDC* pDC); 

	void Move(const CSize& size) ;			// déplace l'entité



	/* Destructeur */
	virtual ~CImg();


				
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CImg)		// pour la sérialisation

};

#endif // !defined(AFX_IMG_H__9AE6883E_E98C_4056_8DC2_41AD97ED458F__INCLUDED_)
