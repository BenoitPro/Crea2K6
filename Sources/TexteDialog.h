/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier :TexteDialog.h
*
******************************************************************************/
#if !defined(AFX_TEXTEDIALOG_H__2120CCE4_58CC_487C_9D58_3336D3E426D4__INCLUDED_)
#define AFX_TEXTEDIALOG_H__2120CCE4_58CC_487C_9D58_3336D3E426D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TexteDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTexteDialog dialog

class CTexteDialog : public CDialog
{

	
/***************************
*		Attributs    	   *
***************************/
public :


// Construction
public:
	UINT m_nFormat;
	CTexteDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTexteDialog)
	enum { IDD = IDD_DIALOG_TEXTE };
	LOGFONT	m_logfont;
	COLORREF	m_color;
	CString	m_Edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTexteDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTexteDialog)
	afx_msg void OnButtonPolice();
	afx_msg void OnRadioGauche();
	afx_msg void OnRadioCentre();
	afx_msg void OnRadioDroite();
	afx_msg void OnButtonCouleur();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTEDIALOG_H__2120CCE4_58CC_487C_9D58_3336D3E426D4__INCLUDED_)
