/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier :RedimDlg.h
*
******************************************************************************/
#if !defined(AFX_REDIMDLG_H__DEBF307F_2A60_4A09_AD64_21B67561E198__INCLUDED_)
#define AFX_REDIMDLG_H__DEBF307F_2A60_4A09_AD64_21B67561E198__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RedimDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRedimDlg dialog

class CRedimDlg : public CDialog
{
// Construction
public:
	CRedimDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRedimDlg)
	enum { IDD = IDD_DIALOG_REDIM };
	int		m_Width;
	int		m_Height;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRedimDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRedimDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REDIMDLG_H__DEBF307F_2A60_4A09_AD64_21B67561E198__INCLUDED_)
