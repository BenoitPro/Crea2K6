/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier :Crea2K6View.h
*
******************************************************************************/

#if !defined(AFX_CREA2K6VIEW_H__23B34C24_88D3_4AC8_AE6C_B228C6A7AEE3__INCLUDED_)
#define AFX_CREA2K6VIEW_H__23B34C24_88D3_4AC8_AE6C_B228C6A7AEE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Crea2K6Doc.h"
#include "Entite.h"
#include "Img.h"	// Added by ClassView

class CCrea2K6View : public CView
{
protected: // create from serialization only
	CCrea2K6View();
	DECLARE_DYNCREATE(CCrea2K6View)

/************************************
*		Attributs					*
*************************************/
public:
	CCrea2K6Doc* GetDocument();
	CEntite* m_pSelected;		// pour connaitre le dernier element selectionné
	CPoint m_FirstPos;			// position de départ d'une entité
	CPoint m_CursorPoint;		// position de la souris
	BOOL m_MoveMode;			// pr savoir si on est en mode déplacement

/************************************
*		Méthodes					*
*************************************/
public:
	void debug(CString string);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCrea2K6View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual void OnDelete();  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void OnPrint(CDC* pDC,CPrintInfo* pInfo);
	void OnPrepareDC(CDC* pDC,CPrintInfo* pInfo);
	void AfficheInfo(CDC* pDC);
	void MoveEntite(CClientDC& aDC,const CPoint& point);
	CEntite * SelectEntite(CPoint point);
	virtual ~CCrea2K6View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCrea2K6View)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnInsertionTexte();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSendToBack();
	afx_msg void OnDeplacer();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMenu0Editer();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnInsertionImage();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnRessourcesImagedefond();
	afx_msg void OnRessourcesImagettes();
	afx_msg void OnRessourcesPolicesprdfinies();
	afx_msg void OnRessourcesCouleurdufond();
	afx_msg void OnAide();
	afx_msg void OnMenu1Redimensionner();
	afx_msg void OnMenu2Ajouteruntexte();
	afx_msg void OnMenu2Ajouterunepoliceprdfinie();
	afx_msg void OnMenu2Ajouteruneimage();
	afx_msg void OnMenu2Supprimerunimagedefond();
	afx_msg void OnMenu2Ajouterunecouleurdefond();
	afx_msg void OnMenu2Ajouteruneimagette();
	afx_msg void OnMenu2Reculeduneposition();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Crea2K6View.cpp
inline CCrea2K6Doc* CCrea2K6View::GetDocument()
   { return (CCrea2K6Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREA2K6VIEW_H__23B34C24_88D3_4AC8_AE6C_B228C6A7AEE3__INCLUDED_)
