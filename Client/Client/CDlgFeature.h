#pragma once


// CDlgFeature dialog

class CDlgFeature : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgFeature)

public:
	CDlgFeature(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgFeature();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton m_New;
	CButton m_View;
	CButton m_ChooseFile;
	afx_msg void OnBnClickedChoosefile();
	afx_msg void OnBnClickedNew();
	CEdit m_Content;
	CStatic m_Title_Content;
	CButton m_SendNote;
	afx_msg void OnBnClickedSendNote();
	afx_msg void OnBnClickedView();
	CComboBox m_ListNote;
};
