/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier : constante.h
*
******************************************************************************/
#ifndef OurConstants_h
#define OurConstants_h

//Définition des types d'entité
const WORD TEXTE		= 101U;
const WORD IMAGE		= 102U;

// Valeur des format
const CSize CARTEVOEUX	= CSize(CPoint(450,540));	// 10 * 12 cm
const CSize CARTEVISITE	= CSize(CPoint(405,270));	//  9 *  6 cm
const CSize INVITATION	= CSize(CPoint(585,585));	// 13 * 13 cm
const CSize CARTEPOSTALE= CSize(CPoint(540,405));	// 12 *  9 cm 


//Valeur de couleur de dessin
const COLORREF BLACK	= RGB(0,0,0);
const COLORREF RED		= RGB(255,0,0);
const COLORREF BLUE		= RGB(0,0,255);
const COLORREF GREEN	= RGB(0,255,0);
const COLORREF YELLOW	= RGB(255,255,0);

#endif

