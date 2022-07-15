
// Client.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CClientApp:
// See Client.cpp for the implementation of this class
//

class CClientApp : public CWinApp
{
public:
	CClientApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
	
};

extern CClientApp theApp;

#include <list>
struct Note {
	CString* filePath, * content, * type;
};
struct User {
	CString* name, * password;
	std::list<Note> notes;
};

extern std::list<User> users;
extern std::list<Note> ltemp;