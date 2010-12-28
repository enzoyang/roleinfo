// RoleInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RoleInfo.h"
#include "RoleInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRoleInfoDlg dialog

CRoleInfoDlg::CRoleInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRoleInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRoleInfoDlg)
	m_maxblood = 0;
	m_ex = 0;
	m_exper = 0.0f;
	m_maxmagic = 0;
	m_nowblood = 0;
	m_nowex = 0;
	m_nowmagic = 0;
	m_server = _T("");
	m_stamina = 0.0f;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRoleInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRoleInfoDlg)
	DDX_Text(pDX, IDC_EDT_BLOOD, m_maxblood);
	DDX_Text(pDX, IDC_EDT_EX, m_ex);
	DDX_Text(pDX, IDC_EDT_EXPER, m_exper);
	DDX_Text(pDX, IDC_EDT_MAGIC, m_maxmagic);
	DDX_Text(pDX, IDC_EDT_NOW_BLOOD, m_nowblood);
	DDX_Text(pDX, IDC_EDT_NOW_EX, m_nowex);
	DDX_Text(pDX, IDC_EDT_NOW_MAGIC, m_nowmagic);
	DDX_Text(pDX, IDC_EDT_SERVER, m_server);
	DDX_Text(pDX, IDC_EDT_STAMINA, m_stamina);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRoleInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CRoleInfoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRoleInfoDlg message handlers

BOOL CRoleInfoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRoleInfoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRoleInfoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRoleInfoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRoleInfoDlg::OnBtnGet() 
{
	if (AfxMessageBox(_T("请确定已经进入游戏,并且已经可以控制角色.是否继续?"),MB_YESNO) != IDYES)
		return;

	HWND hwnd = ::FindWindow(NULL,_T("YB_OnlineClient"));
	if(!hwnd)
	{
		AfxMessageBox(_T("没有找到正在运行的热血江湖进程."));
		return;
	}
	else
	{
		DWORD processId;
		::GetWindowThreadProcessId(hwnd,&processId);
		HANDLE handle = ::OpenProcess(PROCESS_ALL_ACCESS,FALSE,processId);
		int roleBase = 0x290F808;

		//获取角色名
		char str[13]; //热血江湖最多允许14个字符,即7个汉字
		::ReadProcessMemory(handle,(LPCVOID)(roleBase+0x70D0),(LPVOID)str,14,NULL);
		//str.Format(_T("%d"),GetLastError());
		this->SetWindowText(str);
		
		//获取当前血量和最大血量
		
		int max_blood,blood;
		::ReadProcessMemory(handle,(LPCVOID)(roleBase),(LPVOID)&blood,4,NULL);//当前血量
		::ReadProcessMemory(handle,(LPCVOID)(roleBase+0x0C),(LPVOID)&max_blood,4,NULL);//最大血量
		this->m_maxblood = max_blood;
		this->m_nowblood = blood;

		//获取当前魔法和最大魔法
		int max_magic,magic;
		::ReadProcessMemory(handle,(LPCVOID)(roleBase+0x4),(LPVOID)&magic,4,NULL);//当前魔法
		::ReadProcessMemory(handle,(LPCVOID)(roleBase+0x10),(LPVOID)&max_magic,4,NULL);//最大血量
		this->m_maxmagic = max_magic;
		this->m_nowmagic = magic;
		
		//获取当前经验和最大经验
		long max_ex,ex;
		::ReadProcessMemory(handle,(LPCVOID)(roleBase+0x18),(LPVOID)&ex,4,NULL);//当前经验
		::ReadProcessMemory(handle,(LPCVOID)(roleBase+0x20),(LPVOID)&max_ex,4,NULL);//最大经验
		this->m_ex= max_ex;
		this->m_nowex = ex;
		this->m_exper = (float)ex / max_ex * 100;
		
		//获取持久力,计算百分比
		int stamina,max_stamina = 1000;
		::ReadProcessMemory(handle,(LPCVOID)(roleBase+0x8),(LPVOID)&stamina,4,NULL);//当前持久力
		this->m_stamina = (float)stamina / max_stamina *100;

		//获取服务器和线路
		char server[7];
		DWORD len;
		::ReadProcessMemory(handle,(LPCVOID)(roleBase+0x2ec0),(LPVOID)&server,8,&len);//服务器
		this->m_server = server;

		UpdateData(FALSE);//将变量值更新到控件
	}

}
