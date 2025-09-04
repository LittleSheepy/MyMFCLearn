
// MainFrm.cpp: CMainFrame 类的实现
//

#include "pch.h"
#include "framework.h"
#include "P3MFC程序.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
    ON_WM_LBUTTONDOWN()
    //ON_COMMAND(ID_FILE_SAVE, &CMainFrame::OnFileSave)
    ON_COMMAND(ID_TEST_DEMO, &CMainFrame::OnTestDemo)
    ON_UPDATE_COMMAND_UI(ID_TEST_A, &CMainFrame::OnUpdateTestA)
    ON_COMMAND(ID_TEST_B, &CMainFrame::OnTestB)
    ON_COMMAND(ID_TEST_EXEC, &CMainFrame::OnTestExec)
    ON_COMMAND(ID_TEST_SHOW, &CMainFrame::OnTestShow)
    ON_COMMAND(ID_TEST_MY_DLG, &CMainFrame::OnTestMyDlg)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame() noexcept
{
	// TODO: 在此添加成员初始化代码
    m_bAutoMenuEnable = FALSE;          // 避免它内部自动更新。与构造函数总设置。
    m_isUpdate = false;
    dlg.Create(IDD_DIALOG2);
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;

    if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
        !m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
    {
        TRACE0("未能创建工具栏\n");
        return -1;      // 未能创建
    }

    if (!m_wndStatusBar.Create(this))
    {
        TRACE0("未能创建状态栏\n");
        return -1;      // 未能创建
    }
    m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));

    // TODO: 如果不需要可停靠工具栏，则删除这三行
    m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
    EnableDocking(CBRS_ALIGN_ANY);
    DockControlBar(&m_wndToolBar);

    //获取菜单
    CMenu* menu = GetMenu();
    //获取子菜单
    CMenu* fileMenu = menu->GetSubMenu(0);//GetMenu属于CWnd，从0开始指代每一个菜单子菜单。此处获取第一栏
    //标志“新建”
    //参数，怎么确定的参数(位置、ID等)|标志该项目
    //此处通过位置确定
    fileMenu->CheckMenuItem(0, MF_BYPOSITION | MF_CHECKED);
    //标志“打开”
    //参数，怎么确定的参数(位置、ID)|标志该项目
    //此处通过ID确定
    fileMenu->CheckMenuItem(ID_FILE_OPEN, MF_BYCOMMAND | MF_CHECKED);
    //设置默认项，一个菜单项只有一个默认项
    //默认项“保存”
    //参数，怎么确定的参数(TRUE:位置,FALSE:ID)
    //此处通过位置确定
    fileMenu->SetDefaultItem(2, TRUE);

    //设置禁用项
    //首先需要将CFrameWnd::m_bAutoMenuEnable设置false
    //禁用“另存为”
    //参数，怎么确定的参数(位置、ID)|禁用该项目
    fileMenu->EnableMenuItem(3, MF_BYPOSITION | MF_DISABLED);
    //禁用“打印”，分隔符要占位
    fileMenu->EnableMenuItem(6, MF_BYPOSITION | MF_GRAYED);


    SetMenu(NULL);      // 移除菜单栏
    CMenu menu2;
    //加载菜单
    menu2.LoadMenuW(IDR_MENU1);//输入菜单ID
    SetMenu(&menu2);
    //Detach()：将对象从Windows菜单CMenu中分离，并返回句柄。
    //使得该对象不会随着该函数结束后一同被消除
    menu2.Detach();
    return 0;
}


BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
    MessageBox(_T("框架-鼠标左键点击！"));
    CFrameWnd::OnLButtonDown(nFlags, point);
}


void CMainFrame::OnFileSave()
{
    AfxMessageBox(TEXT("Frame"));
}


void CMainFrame::OnTestDemo()
{
    AfxMessageBox(TEXT("Frame Demo"));
}


void CMainFrame::OnUpdateTestA(CCmdUI* pCmdUI)
{
    if (true == m_isUpdate) {
        pCmdUI->Enable(TRUE);
    }
    else {
        pCmdUI->Enable(FALSE);
    }

}


void CMainFrame::OnTestB()
{
    m_isUpdate = !m_isUpdate;
}


void CMainFrame::OnTestExec()
{
    // TODO: 在此添加命令处理程序代码
    // 创建对象
    //无参构造
    //有参构造：对话框的ID（UINT）/名称（LPCTSTR)，父对象（CWnd*)默认为NULL
    CDialog dialog(IDD_DIALOG1);
    dialog.DoModal();//以模态运行
}

void CMainFrame::OnTestShow()
{
    // TODO: 在此添加命令处理程序代码
    dlg.ShowWindow(TRUE);
}


void CMainFrame::OnTestMyDlg()
{
    // TODO: 在此添加命令处理程序代码
    MyDialog dlg;
    dlg.DoModal();
}
