/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier :LesImageRessources.h
*
******************************************************************************/

#if !defined(AFX_LESIMAGESRESSOURCES_H__F741B9DF_1725_4791_AED9_8BE9ABF27D76__INCLUDED_)
#define AFX_LESIMAGESRESSOURCES_H__F741B9DF_1725_4791_AED9_8BE9ABF27D76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/* Mes inclusions */
#include "ImageRessource.h"
#include <afxtempl.h>	//pour la CList

class CLesImagesRessources  
{
public:
	void listeFichier(CListBox* pBox,CString sousDomaine);
	void listeSousDomaine(CListBox* pBox,CString domaine);
	/* Variables de classe*/
	CTypedPtrList<CObList,CImageRessource *> m_list;
	/* Constructeur */
	CLesImagesRessources();


	/* Méthodes */

	// Getters	
	POSITION GetHeadPosition() const{ return m_list.GetHeadPosition(); }

	// Récupère la ressource suivante
	CImageRessource * GetNext(POSITION& aPos) {
		return m_list.GetNext(aPos);
	}

	// Modifications de la liste
	void Add(CImageRessource* imgRess){ m_list.AddHead(imgRess) ;}
	

	/* Destructeur */
	virtual ~CLesImagesRessources();

};

#endif // !defined(AFX_LESIMAGESRESSOURCES_H__F741B9DF_1725_4791_AED9_8BE9ABF27D76__INCLUDED_)
