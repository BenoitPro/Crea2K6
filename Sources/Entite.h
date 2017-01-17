/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
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

	CRect		m_EnclosingRect;// rectangle délimitant une entité
	WORD		m_type;			// type de l'entité (image, text...)

public:
	/* Constructeur */
	CEntite();
	CEntite(CRect,WORD);

	/* Méthode de classes */

	// Getters
	CRect GetBoundRect(void) const;			// obtient le rectangle englobant d'une entité
	WORD GetType() { return m_type; }		// donne le type de l'entité

	// Dessin
	virtual void Draw(CDC * pDC) {};				// dessine l'entite
	virtual void Draw(CDC* pDC,CEntite* pEnt) {};	// dessine l'entite et son rect si elle est selectionné
	void DrawEnclosingRect(CDC* pDC)  ;	// dessine le rect englobant

	virtual void Move(const CSize& size) {};			// déplace l'entité


	// Sauvegarde
//	virtual void Serialize(CArchive& ar);//pour l'enregistrement
//	DECLARE_SERIAL(CElement)			 //pour l'enregistrement

	/* Destructeur */
	virtual ~CEntite();


	
				
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CEntite)		// pour la sérialisation



};

#endif // !defined(AFX_ENTITE_H__D82419B6_908C_4CE0_8F47_BB3559D60B6C__INCLUDED_)
