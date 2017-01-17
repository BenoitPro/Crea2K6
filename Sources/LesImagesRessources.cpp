/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier : LesImagesRessources.cpp
*
******************************************************************************/

#include "stdafx.h"
#include "Crea2K6.h"
#include "LesImagesRessources.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLesImagesRessources::CLesImagesRessources()
{

}

CLesImagesRessources::~CLesImagesRessources()
{

}

void CLesImagesRessources::listeSousDomaine(CListBox *pBox, CString domaine)
{
	// Suppression de ce qu'il y avait dans la liste
	pBox->ResetContent();

	CStringList temp; // list des theme deja vue
	
	POSITION aPos ;
	aPos = GetHeadPosition();
	CImageRessource* ir ;

	// Ajout de la nouvelle list
	while(aPos) {
		ir = GetNext(aPos);
		int dejaVue=0;	// booleen pour savoir le résultat de la recherche ci après
		if (ir->m_domaine==domaine) {

			// Recherche si c'est un theme deja vue
			POSITION aPos2;
			aPos2 = temp.GetHeadPosition();
			CString s ;
			while(aPos2){
				s=temp.GetNext(aPos2);
				if(s==ir->m_sousDomaine) 
					dejaVue=1;			
			}
			if(dejaVue==0) {
			pBox->AddString(ir->m_sousDomaine);
			temp.AddHead(ir->m_sousDomaine);
			}
		}
	}
}

void CLesImagesRessources::listeFichier(CListBox *pBox, CString sousDomaine)
{
		// Suppression de ce qu'il y avait dans la liste

	pBox->ResetContent();
	
	POSITION aPos ;
	aPos = GetHeadPosition();
	CImageRessource* ir ;

	// Ajout de la nouvelle list
	while(aPos) {
		ir = GetNext(aPos);
		if (ir->m_sousDomaine==sousDomaine)
			pBox->AddString(ir->m_fichier);

	}	

}
