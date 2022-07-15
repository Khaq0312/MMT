// CDlgFeature.cpp : implementation file
//

#include "pch.h"
#include "Client.h"
#include "CDlgFeature.h"
#include "afxdialogex.h"
using namespace std;

// CDlgFeature dialog

IMPLEMENT_DYNAMIC(CDlgFeature, CDialogEx)

CDlgFeature::CDlgFeature(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CDlgFeature::~CDlgFeature()
{
}

void CDlgFeature::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NEW, m_New);
	DDX_Control(pDX, IDC_VIEW, m_View);
	DDX_Control(pDX, IDC_CHOOSEFILE, m_ChooseFile);
	DDX_Control(pDX, IDC_CONTENT, m_Content);
	DDX_Control(pDX, IDC_TITLE_CONTENT, m_Title_Content);
	DDX_Control(pDX, IDC_SEND_NOTE, m_SendNote);
	DDX_Control(pDX, IDC_LIST_NOTE, m_ListNote);
}


BEGIN_MESSAGE_MAP(CDlgFeature, CDialogEx)
	ON_BN_CLICKED(IDC_CHOOSEFILE, &CDlgFeature::OnBnClickedChoosefile)
	ON_BN_CLICKED(IDC_NEW, &CDlgFeature::OnBnClickedNew)
	ON_BN_CLICKED(IDC_SEND_NOTE, &CDlgFeature::OnBnClickedSendNote)
	ON_BN_CLICKED(IDC_VIEW, &CDlgFeature::OnBnClickedView)
END_MESSAGE_MAP()


// CDlgFeature message handlers



void CDlgFeature::OnBnClickedChoosefile()
{
	// *****send IDC_CHOOSEFILE*****
	//

	LPCTSTR lpszFilter = _T("All Files(*.*)|*.*|")
		_T("Text(*.txt)|*.txt|")
		_T("Image (*.jpg;*.jpeg;*.png)|*.jpg;*.jpeg;*.png||");
	CFileDialog fileDlg(TRUE, 0, 0,
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, lpszFilter);

	// Display the file dialog. When user clicks OK, fileDlg.DoModal() 
	// returns IDOK.
	if (fileDlg.DoModal() == IDOK)
	{
		CString pathName = fileDlg.GetPathName();
		// *****send pathName to server*****
		//

		CString fileName = fileDlg.GetFileTitle();

		wchar_t* ext = PathFindExtensionW(pathName);
		char* type = new char[6];
		char src[][6] = { "Text","Image","File" };
		if (!wcscmp(ext, L".txt"))
			type = src[0];
		else if (!wcscmp(ext, L".png") || !wcscmp(ext, L".jpg") || !wcscmp(ext, L".jpeg"))
			type = src[1];
		else
			type = src[2];
		// *****send type*****
		//

		// Show edit content
		m_Title_Content.ShowWindow(SW_NORMAL);
		m_Content.ShowWindow(SW_NORMAL);
		m_SendNote.ShowWindow(SW_NORMAL);
	}
}

void CDlgFeature::OnBnClickedNew()
{
	// TODO: Add your control notification handler code here
	m_ChooseFile.ShowWindow(SW_NORMAL);
}


void CDlgFeature::OnBnClickedSendNote()
{
	// TODO: Add your control notification handler code here
	CString text;
	m_Content.GetWindowTextW(text);
	// int len = m_Content.GetWindowTextLengthW();
	// 
	// *****send Content to server*****
	//
}

void CDlgFeature::OnBnClickedView()
{
	// *****send IDC_VIEW to server*****
	//
	list<Note> ltemp;
	list<Note>::iterator it;
	// *****recv list*****
	//
	m_ChooseFile.DestroyWindow();
	m_Title_Content.DestroyWindow();
	m_Content.DestroyWindow();
	m_SendNote.DestroyWindow();

	if (!m_ListNote.ShowWindow(SW_SHOWNORMAL)) {
		for (it = ltemp.begin(); it != ltemp.end(); it++) {
			m_ListNote.AddString(*it->content);
		}
		//
		CString str;
		for (int i = 0; i < 20; i++)
		{
			str.Format(_T("item string %d"), i);
			m_ListNote.AddString(str);
		}
		//
		int nIndex = m_ListNote.GetCurSel();
		// *****send Content selected to server*****
		//

	}
}