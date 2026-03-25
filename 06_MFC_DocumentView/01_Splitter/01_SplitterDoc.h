
// 01_SplitterDoc.h : interface of the CMy01SplitterDoc class
//


#pragma once

#include <afxtempl.h>

class CMy01SplitterDoc : public CDocument
{
protected: // create from serialization only
	CMy01SplitterDoc() noexcept;
	DECLARE_DYNCREATE(CMy01SplitterDoc)

// Attributes
public:
	CArray<CPoint, CPoint&> m_points;
	CArray<TCHAR, TCHAR> m_str;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMy01SplitterDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
