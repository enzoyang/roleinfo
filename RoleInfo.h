// RoleInfo.h : main header file for the ROLEINFO application
//

#if !defined(AFX_ROLEINFO_H__C64B343A_198D_4850_8A46_F79F5F74B58F__INCLUDED_)
#define AFX_ROLEINFO_H__C64B343A_198D_4850_8A46_F79F5F74B58F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRoleInfoApp:
// See RoleInfo.cpp for the implementation of this class
//

class CRoleInfoApp : public CWinApp
{
public:
	CRoleInfoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoleInfoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRoleInfoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROLEINFO_H__C64B343A_198D_4850_8A46_F79F5F74B58F__INCLUDED_)
