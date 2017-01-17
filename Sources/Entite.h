/******************************************************************************
* Projet : IHM - Cr�ation de cartes en tout genre 
* Auteurs : Anthony et Beno�t Mar�chal
* Derni�re modification : 19 / 01 / 2006
* 
* Fichier :Entite.h
*
******************************************************************************/

#if !defined(AFX_ENTITE_H__D82419B6_908C_4CE0_8F47_BB3559D60B6C__INCLUDED_)
#define AFX_ENTITE_H__D82419B6_908C_4CE0_8F47_BB3559D60B6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/************************
*		Mes inclusions	*
***********************/
#include "constantes.h"


class CEntite : public CObject 
{

public :
	/* Variables de classes */

	CRect		m_EnclosingRect;// rectangle d�limitant une entit�
	WORD		m_type;			// type de l'entit� (image, text...)

public:
	/* Constructeur */
	CEntite();
	CEntite(CRect,WORD);

	/* M�thode de classes */

	// Getters
	CRect GetBoundRect(void) const;			// obtient le rectangle englobant d'une entit�
	WORD GetType() { return m_type; }		// donne le type de l'entit�

	// Dessin
	virtual void Draw(CDC * pDC) {};				// dessine l'entite
	virtual void Draw(CDC* pDC,CEntite* pEnt) {};	// dessine l'entite et son rect si elle est selectionn�
	void DrawEnclosingRect(CDC* pDC)  ;	// dessine le rect englobant

	virtual void Move(const CSize& size) {};			// d�place l'entit�


	// Sauvegarde
//	virtual void Serialize(CArchive& ar);//pour l'enregistrement
//	DECLARE_SERIAL(CElement)			 //pour l'enregistrement

	/* Destructeur */
	virtual ~CEntite();


	
				
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CEntite)		// pour la s�rialisation



};

#endif // !defined(AFX_ENTITE_H__D82419B6_908C_4CE0_8F47_BB3559D60B6C__INCLUDED_)
