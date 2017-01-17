/******************************************************************************
* Projet : IHM - Création de cartes en tout genre 
* Auteurs : Anthony et Benoît Maréchal
* Dernière modification : 19 / 01 / 2006
* 
* Fichier :Crea2K6Doc.h
*
******************************************************************************/


#if !defined(AFX_CREA2K6DOC_H__F889EFCA_0B22_44E5_BA27_26EFE487297A__INCLUDED_)
#define AFX_CREA2K6DOC_H__F889EFCA_0B22_44E5_BA27_26EFE487297A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/* Mes inclusions */
#include <afxtempl.h>
#include "Entite.h"
#include "Img.h"	// Added by ClassView

class CCrea2K6Doc : public CDocument
{
protected: // create from serialization only
	CCrea2K6Doc();
	DECLARE_DYNCREATE(CCrea2K6Doc)

/* Attributs */
public:
CTypedPtrList<CObList,CEntite *> m_EntiteList ; // liste d'entite
CList<CPoint,const CPoint&> m_ImgPosList; // position
CSize m_Format;

/* Méthodes */
public:

// Récupère la  position de la tete
POSITION GetListHeadPosition() const {
	return m_EntiteList.GetHeadPosition();
}

// Récupère l'entite suivante
CEntite * GetNext(POSITION& aPos) {
	return m_EntiteList.GetNext(aPos);
}

// Récupère la position de la queue
POSITION GetListTailPosition() const {
	return m_EntiteList.GetTailPosition();
}

// Récupère l'entité précédente
CEntite * GetPrev(POSITION& aPos) const {
	return m_EntiteList.GetPrev(aPos);
}

// Ajout d'une entité en queue
void AddEntite(CEntite* pEnt) {
	m_EntiteList.AddTail(pEnt);	// ajout en queue
	
	SetModifiedFlag();
}



// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCrea2K6Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL m_begin;
	CPoint m_Origine;
	CRect m_RectVue;
	void OpenDoc(CString fichier);
	void SendToBack(CEntite *pEntite);
	void DeleteEntite(CEntite * pEntite);
	virtual ~CCrea2K6Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
public:
	void Back1(CEntite* pEnt);
	CString m_imgFondString;
	COLORREF m_couleurFond;
	TCHAR m_RepAppli[MAX_PATH];
	CImg* m_imgFond;
	CStringList m_ImgList;
	//{{AFX_MSG(CCrea2K6Doc)
	afx_msg void OnFormatCartedevisite();
	afx_msg void OnFormatCartedevoeux();
	afx_msg void OnFormatCartepostale();
	afx_msg void OnFormatInvitation();
	afx_msg void OnUpdateFormatCartedevisite(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFormatCartedevoeux(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFormatCartepostale(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFormatInvitation(CCmdUI* pCmdUI);
	afx_msg void OnMenu2Reculeduneposition();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREA2K6DOC_H__F889EFCA_0B22_44E5_BA27_26EFE487297A__INCLUDED_)
