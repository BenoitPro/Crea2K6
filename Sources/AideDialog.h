/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier : AideDialog.h
*
******************************************************************************/
#if !defined(AFX_AIDEDIALOG_H__20FD1247_676E_4F9F_A135_1195850F6E44__INCLUDED_)
#define AFX_AIDEDIALOG_H__20FD1247_676E_4F9F_A135_1195850F6E44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AideDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAideDialog dialog

class CAideDialog : public CDialog
{
// Construction
public:
	CAideDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAideDialog)
	enum { IDD = IDD_DIALOG_AIDE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAideDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAideDialog)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AIDEDIALOG_H__20FD1247_676E_4F9F_A135_1195850F6E44__INCLUDED_)
