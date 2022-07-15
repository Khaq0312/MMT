
// ClientDlg.h : header file
//

#pragma once
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

// CClientDlg dialog
class CClientDlg : public CDialogEx
{
// Construction
public:
	CClientDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnCommand(UINT nID);
	afx_msg LRESULT OnUserDefinedMessage(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
	
public:
	CEdit m_Username;
	CEdit m_Password;
	CButton m_LogIn;
	CButton m_SignUp;
	CStatic m_StaticName;
	CStatic m_StaticPW;
	void CClientDlg::OnBnClicked();
};

enum MES {
	LOGIN_SUC = 1,
	LOGIN_FAIL,
	SIGNUP_SUC,
	SIGNUP_FAIL,
};