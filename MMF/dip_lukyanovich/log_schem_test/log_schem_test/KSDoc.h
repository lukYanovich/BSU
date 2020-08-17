// KSDoc.h : interface of the CKSDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KSDOC_H__B9D7934A_1449_11D7_9C16_C41715B34A51__INCLUDED_)
#define AFX_KSDOC_H__B9D7934A_1449_11D7_9C16_C41715B34A51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define INT_SIZE 32

class CKSDoc : public CDocument
{
protected: // create from serialization only
	CKSDoc();
	DECLARE_DYNCREATE(CKSDoc);

	// Attributes
public:

	// Operations
public:

	// Overrides
		// ClassWizard generated virtual function overrides
		//{{AFX_VIRTUAL(CKSDoc)
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKSDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// Generated message map functions
protected:
	//{{AFX_MSG(CKSDoc)
	afx_msg void OnTestingRm();
	afx_msg void OnTexnologi();
	afx_msg void OnHandTest();
	afx_msg void OnTestFromFile();
	afx_msg void OnVermet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int ReadData();
	void SaveData();
};
UINT Mainpr(LPVOID pParam);
UINT FromFile(LPVOID pParam);
int Pow2(int);
void ReadElement(FILE*);
int Convertor();
void ClearArrays();

struct MPStruct {
	CUIntArray M;
	HWND hw;
	LPCSTR st;
};
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.


#endif // !defined(AFX_KSDOC_H__B9D7934A_1449_11D7_9C16_C41715B34A51__INCLUDED_)
