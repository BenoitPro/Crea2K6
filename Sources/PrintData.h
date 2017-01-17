/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier :PrintData.h
*
******************************************************************************/
#if !defined(AFX_PRINTDATA_H__AB8ECFB5_167B_46EC_BBD3_6036A27E9247__INCLUDED_)
#define AFX_PRINTDATA_H__AB8ECFB5_167B_46EC_BBD3_6036A27E9247__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PrintData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPrintData window

class CPrintData : public CWnd
{
// Construction
public:
	CPrintData();			//contructeur définit inline a vide

// Attributes
public:
	UINT m_nWidth;			//nb de page en largeur
	UINT m_nLength;			//nb de page en hauteur
	CPoint m_DocRefPoint;	//point haut gauche du document de dessin
	CString m_DocTitle;		//contient le titre de la page

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintData)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPrintData();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPrintData)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTDATA_H__AB8ECFB5_167B_46EC_BBD3_6036A27E9247__INCLUDED_)
