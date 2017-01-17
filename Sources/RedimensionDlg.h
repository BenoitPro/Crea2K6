#if !defined(AFX_REDIMENSIONDLG_H__F00620E4_3FC3_4693_BF71_B7CF84655384__INCLUDED_)
#define AFX_REDIMENSIONDLG_H__F00620E4_3FC3_4693_BF71_B7CF84655384__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RedimensionDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRedimensionDlg dialog

class CRedimensionDlg : public CDialog
{
// Construction
public:

	CRedimensionDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRedimensionDlg)
	enum { IDD = IDD_DIALOG_REDIM };
	CString	m_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRedimensionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRedimensionDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REDIMENSIONDLG_H__F00620E4_3FC3_4693_BF71_B7CF84655384__INCLUDED_)
