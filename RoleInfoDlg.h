// RoleInfoDlg.h : header file
//

#if !defined(AFX_ROLEINFODLG_H__104CE194_18F5_48F2_9DEF_E10E65404E58__INCLUDED_)
#define AFX_ROLEINFODLG_H__104CE194_18F5_48F2_9DEF_E10E65404E58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRoleInfoDlg dialog

class CRoleInfoDlg : public CDialog
{
// Construction
public:
	CRoleInfoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRoleInfoDlg)
	enum { IDD = IDD_ROLEINFO_DIALOG };
	int		m_maxblood;
	long	m_ex;
	float	m_exper;
	int		m_maxmagic;
	int		m_nowblood;
	long	m_nowex;
	int		m_nowmagic;
	CString	m_selector;
	CString	m_server;
	float	m_stamina;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoleInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRoleInfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnGet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROLEINFODLG_H__104CE194_18F5_48F2_9DEF_E10E65404E58__INCLUDED_)
