/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier : ImageRessource.cpp
*
******************************************************************************/

#include "stdafx.h"
#include "Crea2K6.h"
#include "ImageRessource.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/* Constructeurs */
CImageRessource::CImageRessource()
{

}


CImageRessource::CImageRessource(CString domaine,CString sousDomaine,CString fichier)
{
	m_domaine = domaine;
	m_sousDomaine = sousDomaine;
	m_fichier	= fichier;
}


/* Destructeurs */
CImageRessource::~CImageRessource()
{

}
