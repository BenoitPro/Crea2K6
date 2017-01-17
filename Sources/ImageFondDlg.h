/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier :ImageFondDlg.h
*
******************************************************************************/
#if !defined(AFX_IMAGEFONDDLG_H__67B7E039_304E_4C64_A712_639312B54160__INCLUDED_)
#define AFX_IMAGEFONDDLG_H__67B7E039_304E_4C64_A712_639312B54160__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImageFondDlg.h : header file
//

/* Mes inclusions */
#include "LesImagesRessources.h"

class CImageFondDlg : public CDialog
{
// Construction
public:
	CString m_nom;
	CString m_theme;

	/* Variables de classe */
	CLesImagesRessources m_imgRess ;
	
	CImageFondDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CImageFondDlg)
	enum { IDD = IDD_DIALOG_IMGFOND };
	CString	m_carte;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageFondDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CImageFondDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeList1();
	virtual void OnOK();
	afx_msg void OnAppliquer1();
	afx_msg void OnSelchangeList2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEFONDDLG_H__67B7E039_304E_4C64_A712_639312B54160__INCLUDED_)
