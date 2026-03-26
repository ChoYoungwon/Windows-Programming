
// 02_MDITestDoc.h : interface of the CMy02MDITestDoc class
//


#pragma once
#include <afxtempl.h>


class CMy02MDITestDoc : public CDocument
{
protected: // create from serialization only
	CMy02MDITestDoc() noexcept;
	DECLARE_DYNCREATE(CMy02MDITestDoc)

// Attributes
public:
	CArray<TCHAR, TCHAR> m_str;		// 글자 저장
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
	virtual ~CMy02MDITestDoc();
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
