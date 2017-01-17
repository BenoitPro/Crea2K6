/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier :FontPredefDlg.h
*
******************************************************************************/
#if !defined(AFX_FONTPREDEFDLG_H__D4A2BF1F_F844_46F7_A7F7_6B6978D146DF__INCLUDED_)
#define AFX_FONTPREDEFDLG_H__D4A2BF1F_F844_46F7_A7F7_6B6978D146DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FontPredefDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFontPredefDlg dialog

class CFontPredefDlg : public CDialog
{
// Construction
public:
	int police;
	CFontPredefDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFontPredefDlg)
	enum { IDD = IDD_DIALOG_FONTPREDEF };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontPredefDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFontPredefDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTitre1();
	afx_msg void OnTitre2();
	afx_msg void OnTitre3();
	afx_msg void OnTexte1();
	afx_msg void OnTexte2();
	afx_msg void OnTexte3();
	afx_msg void OnMessage1();
	afx_msg void OnMessage2();
	afx_msg void OnMessage3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTPREDEFDLG_H__D4A2BF1F_F844_46F7_A7F7_6B6978D146DF__INCLUDED_)
