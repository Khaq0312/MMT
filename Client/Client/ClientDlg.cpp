
// ClientDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Client.h"
#include "ClientDlg.h"
#include "CDlgFeature.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CClientDlg dialog



CClientDlg::CClientDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLIENT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_USERNAME, m_Username);
	DDX_Control(pDX, IDC_PASSWORD, m_Password);
	DDX_Control(pDX, IDC_LOGIN, m_LogIn);
	DDX_Control(pDX, IDC_SIGNUP, m_SignUp);
	DDX_Control(pDX, IDC_STATIC_NAME, m_StaticName);
	DDX_Control(pDX, IDC_STATIC_PW, m_StaticPW);
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_WM_SYSCOMMAND()
	//ON_BN_CLICKED(IDC_LOGIN, &CClientDlg::OnBnClickedLogin)
	//ON_BN_CLICKED(IDC_SIGNUP, &CClientDlg::OnBnClickedSignup)
	ON_COMMAND_RANGE(IDC_LOGIN, IDM_MES, &CClientDlg::OnCommand)
	ON_MESSAGE(IDM_MES, &CClientDlg::OnUserDefinedMessage)
END_MESSAGE_MAP()


// CClientDlg message handlers

BOOL CClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CClientDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect rect;
	GetClientRect(&rect);

	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		/*CRect rect;
		GetClientRect(&rect);*/
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);

	}
	else
	{
		// Title
		CFont font;
		font.CreateFontW(120, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 0, 0, L"Arial");
		CFont* pFont = dc.SelectObject(&font);
		dc.SetTextColor(RGB(255, 62, 76));
		dc.SetBkMode(TRANSPARENT);
		dc.SetTextAlign(TA_CENTER);
		dc.TextOut(560, 100, L"E-NOTE");

		dc.SelectObject(pFont);
		font.DeleteObject();

		font.CreateFontW(25, 0, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, L"Arial");
		GetDlgItem(IDC_STATIC_NAME)->SetFont(&font);
		GetDlgItem(IDC_STATIC_PW)->SetFont(&font);
		font.DeleteObject();

		CDialogEx::OnPaint();
	}
}
// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CClientDlg::OnBnClicked()
{
	// TODO: Add your control notification handler code here
	CString text;
	m_Username.GetWindowTextW(text);
	// int len = m_Username.GetWindowTextLengthW();
	// 
	// send username to server
	//
	m_Password.GetWindowTextW(text);
	// int len = m_Password.GetWindowTextLengthW();
	// send password to server
	//
}

LRESULT CClientDlg::OnUserDefinedMessage(WPARAM wParam, LPARAM lParam) {
	char* mesID;
	// receive MES
	// 
	switch (MES::LOGIN_SUC) {
	case MES::LOGIN_SUC:
	{
		AfxMessageBox(_T("Log in successfully!"), MB_OK | MB_ICONINFORMATION);
		// Destroy windows
		/*m_Username.DestroyWindow();
		m_Password.DestroyWindow();
		m_LogIn.DestroyWindow();
		m_SignUp.DestroyWindow();
		m_StaticName.DestroyWindow();
		m_StaticPW.DestroyWindow();*/

		// Create new window
		CDlgFeature ft;
		ft.DoModal();
	}
	break;
	case MES::LOGIN_FAIL:
		AfxMessageBox(_T("Username or password is incorrect."), MB_OK | MB_ICONERROR);
		break;
	case MES::SIGNUP_SUC:
		AfxMessageBox(_T("Sign up successfully!"), MB_OK | MB_ICONINFORMATION);
		break;
	case MES::SIGNUP_FAIL:
		AfxMessageBox(_T("Username must has at least 5 characters: a-z, 0-9\nPassword must have at least 3 characters"), MB_OK | MB_ICONERROR);
		break;
	}
	return 0;
}

void CClientDlg::OnCommand(UINT nID) {
	switch (nID) {
	case IDC_LOGIN: case IDC_SIGNUP:
	{
		// *****send IDC_LOGIN/IDC_SIGNUP*****
		//
		OnBnClicked();
		SendMessage(IDM_MES, 0, 0);
	}
	break;
	}
}