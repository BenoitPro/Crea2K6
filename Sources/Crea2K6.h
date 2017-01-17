/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier : Crea2K6.h
*
******************************************************************************/


#if !defined(AFX_CREA2K6_H__5A7AB63B_11C8_488C_9E41_A8829044CB2B__INCLUDED_)
#define AFX_CREA2K6_H__5A7AB63B_11C8_488C_9E41_A8829044CB2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCrea2K6App:
// See Crea2K6.cpp for the implementation of this class
//

class CCrea2K6App : public CWinApp
{
public:
	CCrea2K6App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCrea2K6App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCrea2K6App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREA2K6_H__5A7AB63B_11C8_488C_9E41_A8829044CB2B__INCLUDED_)
