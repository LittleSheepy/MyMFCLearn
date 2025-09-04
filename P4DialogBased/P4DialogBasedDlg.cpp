
// P4DialogBasedDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "P4DialogBased.h"
#include "P4DialogBasedDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CP4DialogBasedDlg 对话框



CP4DialogBasedDlg::CP4DialogBasedDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_P4DIALOGBASED_DIALOG, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CP4DialogBasedDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_button);
	DDX_Text(pDX, IDC_EDIT1, m_str);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
}

BEGIN_MESSAGE_MAP(CP4DialogBasedDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_GengXin, &CP4DialogBasedDlg::OnBnClickedButtonGengxin)
END_MESSAGE_MAP()


// CP4DialogBasedDlg 消息处理程序

BOOL CP4DialogBasedDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_button.SetWindowTextW(TEXT("会移动的按钮"));
	//CBitmap bitmap;
	//bitmap.LoadBitmapW(IDB_BITMAP1);
	////获取位图大小
	//BITMAP bmp;//存储位图数据
	//bitmap.GetBitmap(&bmp);
	//m_button.SetBitmap(bitmap);//为按钮设置位图
	//m_button.MoveWindow(20, 20, bmp.bmWidth, bmp.bmHeight);

	//资源来源（为程序外部时NULL），路径（绝对或相对），图片类型,长，宽（为0则图片原本长宽），载入设置
	//获取本窗口句柄AfxGetInstanceHandle()
	//m_button.SetBitmap((HBITMAP)(LoadImage(AfxGetInstanceHandle(), TEXT("res\\1.bmp"), IMAGE_BITMAP, 100, 500, LR_LOADFROMFILE | LR_CREATEDIBSECTION)));
	//m_button.MoveWindow(20, 20, 100, 500);

	m_str = TEXT("123");
	//把所有编辑区对应变量中存储的内容更新到编辑区，默认为TRUE
	UpdateData(FALSE);
	//UpdateData(TRUE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CP4DialogBasedDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CP4DialogBasedDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CP4DialogBasedDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CP4DialogBasedDlg::OnBnClickedButtonGengxin()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	MessageBox(m_str);
}
