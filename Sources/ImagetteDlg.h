/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier :ImagetteDlg.h
*
******************************************************************************/
#if !defined(AFX_IMAGETTEDLG_H__78FC8EE6_CB4C_48A9_9F4D_8B9601EB0FF3__INCLUDED_)
#define AFX_IMAGETTEDLG_H__78FC8EE6_CB4C_48A9_9F4D_8B9601EB0FF3__INCLUDED_

#include "LesImagesRessources.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImagetteDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CImagetteDlg dialog

class CImagetteDlg : public CDialog
{
// Construction
public:
	CString m_theme;
	CLesImagesRessources m_imgRess;
	CString m_fichier;
	CImagetteDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CImagetteDlg)
	enum { IDD = IDD_DIALOG_IMAGETTE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImagetteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CImagetteDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeList1();
	afx_msg void OnAppliquer();
	afx_msg void OnSelchangeList2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGETTEDLG_H__78FC8EE6_CB4C_48A9_9F4D_8B9601EB0FF3__INCLUDED_)
