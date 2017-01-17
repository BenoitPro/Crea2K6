/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier :ImageRessource.h
*
******************************************************************************/

#if !defined(AFX_IMAGERESSOURCE_H__FC03B1B5_850A_45D6_8273_109D0A9047EF__INCLUDED_)
#define AFX_IMAGERESSOURCE_H__FC03B1B5_850A_45D6_8273_109D0A9047EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CImageRessource   : public CObject 
{
public:
	/* Variables de classe */
	CString m_fichier;
	CString m_sousDomaine;
	CString m_domaine;

	/* Constructeur */
	CImageRessource();
	CImageRessource(CString m_domaine,CString m_sousDomaine,CString m_fichier);
	
	/* Destructeur */
	virtual ~CImageRessource();

};

#endif // !defined(AFX_IMAGERESSOURCE_H__FC03B1B5_850A_45D6_8273_109D0A9047EF__INCLUDED_)
