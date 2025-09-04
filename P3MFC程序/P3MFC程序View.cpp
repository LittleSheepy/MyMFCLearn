
// P3MFC程序View.cpp: CP3MFC程序View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "P3MFC程序.h"
#endif

#include "P3MFC程序Doc.h"
#include "P3MFC程序View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CP3MFC程序View

IMPLEMENT_DYNCREATE(CP3MFC程序View, CView)

BEGIN_MESSAGE_MAP(CP3MFC程序View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    ON_WM_MOUSEMOVE()
    ON_WM_CREATE()
    ON_WM_CHAR()
    ON_WM_TIMER()
    //ON_COMMAND(ID_FILE_SAVE, &CP3MFC程序View::OnFileSave)
    //ON_COMMAND(ID_TEST_DEMO, &CP3MFC程序View::OnTestDemo)
    ON_WM_RBUTTONDOWN()
    ON_COMMAND(ID_TEST_B, &CP3MFC程序View::OnTestB)
    ON_UPDATE_COMMAND_UI(ID_TEST_A, &CP3MFC程序View::OnUpdateTestA)
END_MESSAGE_MAP()

// CP3MFC程序View 构造/析构

CP3MFC程序View::CP3MFC程序View() noexcept
{
	// TODO: 在此处添加构造代码
    m_isUpdate = false;

}

CP3MFC程序View::~CP3MFC程序View()
{
}

BOOL CP3MFC程序View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CP3MFC程序View 绘图

void CP3MFC程序View::OnDraw(CDC* pDC)
{
	CP3MFC程序Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
    //pDC->TextOutW(100, 100, TEXT("你好MFC"));
    
    //笔的样式、线宽（设备单位）、颜色
    //此处选择的为虚线-------
    //注意：虚线和点等样式，宽度必须不超过1。（具体请查看MFC手册）
    CPen pen(PS_DASH, 1, RGB(255, 0, 0));
    CPen* oldPen = pDC->SelectObject(&pen);//此处赋予笔刷新的格式，同时将返回的旧格式存储在oldPen里面
    pDC->MoveTo(10, 10);
    pDC->LineTo(120, 10);

    pDC->SelectObject(oldPen);
    pDC->Rectangle(50, 50, 300, 300);//绘制正方形：左上正方形坐标，左下正方形坐标。
    pDC->Ellipse(50, 50, 300, 300);//绘制圆形：左上正方形坐标，左下正方形坐标，绘出内切圆。

    // 使用画刷
    CBrush brush(RGB(255, 0, 0));
    pDC->SelectObject(&brush);
    pDC->Ellipse(400, 50, 600, 300);

    CBitmap bitmap;
    bitmap.LoadBitmapW(IDB_BITMAP1);
    CBrush brush2(&bitmap);
    pDC->SelectObject(&brush2);
    pDC->Ellipse(700, 100, 800, 200);

    CFont cfont;
    //字体大小（0.1*Size）、字体、绘图对象(有默认参数)。
    cfont.CreatePointFont(200, TEXT("楷体"));
    pDC->SelectObject(&cfont);
    pDC->TextOutW(730, 220, TEXT("七海"));
}


// CP3MFC程序View 打印

BOOL CP3MFC程序View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CP3MFC程序View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CP3MFC程序View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CP3MFC程序View 诊断

#ifdef _DEBUG
void CP3MFC程序View::AssertValid() const
{
	CView::AssertValid();
}

void CP3MFC程序View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CP3MFC程序Doc* CP3MFC程序View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CP3MFC程序Doc)));
	return (CP3MFC程序Doc*)m_pDocument;
}
#endif //_DEBUG


// CP3MFC程序View 消息处理程序


void CP3MFC程序View::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    //MessageBox(_T("视图-左键点击"));
    SetCaretPos(point);
    m_myPoint = point;//保存当前坐标
    m_isPress = true;
    m_str.Empty();
    CView::OnLButtonDown(nFlags, point);
}


void CP3MFC程序View::OnLButtonUp(UINT nFlags, CPoint point)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    // 画直线
    //CClientDC dc(this);
    //dc.MoveTo(m_myPoint);
    //dc.LineTo(point);
    m_isPress = false;
    CView::OnLButtonUp(nFlags, point);
}

void CP3MFC程序View::OnMouseMove(UINT nFlags, CPoint point)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    if (m_isPress == true) {
        CClientDC dc(this);
        dc.MoveTo(m_myPoint);
        dc.LineTo(point);
        m_myPoint = point;
    }
    CView::OnMouseMove(nFlags, point);
}



int CP3MFC程序View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CView::OnCreate(lpCreateStruct) == -1)
        return -1;

    //获取字体信息
    CClientDC dc(this);
    TEXTMETRIC tm;//字体信息结构体
    //一般只用得上字体高度和平均宽度
    dc.GetTextMetrics(&tm);
    //由于该类继承于Cwnd，可以直接用
    CreateSolidCaret(tm.tmAveCharWidth / 8, tm.tmHeight);//创建插入符号的宽度与高度(一般这样设置)
    ShowCaret();

    //无符号整型ID，时间间隔（毫秒），回调函数(为空代表使用系统默认处理函数)
    SetTimer(1, 200, NULL);
    return 0;
}


void CP3MFC程序View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    CClientDC dc(this);
    CSize size;
    if (nChar == VK_RETURN) {//如果输入的是换行 
        dc.GetTextExtent(m_str);
        size = dc.GetTextExtent(m_str);//获取字符串大小
        m_myPoint.y = m_myPoint.y + size.cy;
        m_str.Empty();
        SetCaretPos(m_myPoint);
        return;
    }
    else if (nChar == VK_BACK) {
        COLORREF color = dc.GetBkColor();//获取背景颜色
        COLORREF oldColor = dc.SetTextColor(color);//用背景色作为字体颜色，并称存储之前颜色
        dc.TextOutW(m_myPoint.x, m_myPoint.y, m_str);//覆盖之前的文字
        m_str = m_str.Left(m_str.GetLength() - 1);//去掉后一个字符
        dc.SetTextColor(oldColor);//恢复原本颜色
    }
    else {
        m_str = m_str + (TCHAR)nChar;
    }
    size = dc.GetTextExtent(m_str);//获取字符串大小
    int x = m_myPoint.x + size.cx;
    int y = m_myPoint.y;
    SetCaretPos(CPoint(x, y));
    dc.TextOutW(m_myPoint.x, m_myPoint.y, m_str);
    CView::OnChar(nChar, nRepCnt, nFlags);
}

//void CP3MFC程序View::OnTimer(UINT_PTR nIDEvent)
//{
//    static int i = 0;
//    i++;
//    CString str;
//    str.Format(TEXT("%d"), i);
//    MessageBox(str);
//    CView::OnTimer(nIDEvent);
//}
void CP3MFC程序View::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    static int w = 0;
    w = w + 5;
    CString str = TEXT("一个人被他人所信赖，不是因为他能做到什么，而是因为他做到了什么，才被他人所信赖。");
    //获取字符串宽度
    CClientDC dc(this);
    CSize size = dc.GetTextExtent(str);
    //设置字体
    CFont cfont;
    cfont.CreatePointFont(200, TEXT("楷体"));
    dc.SelectObject(&cfont);

    //起点坐标
    int x = 30;
    int y = 30;
    if (w == 5) {
        dc.TextOutW(x, y, str);
    }
    else if (w > size.cx) {
        w = 0;//比字符串宽则重新开始
    }

    //长方形左上角坐标，右下角坐标
    CRect rect(x, y, x + w, y + size.cy);

    dc.SetTextColor(RGB(255, w % 255, 0));
    //文本内容，绘出区域，方式（左对齐）
    dc.DrawText(str, &rect, DT_LEFT);
    CView::OnTimer(nIDEvent);
}

void CP3MFC程序View::OnFileSave()
{
    // TODO: 在此添加命令处理程序代码
    AfxMessageBox(TEXT("View"));
}


void CP3MFC程序View::OnTestDemo()
{
    // TODO: 在此添加命令处理程序代码
    AfxMessageBox(TEXT("View Demo"));
}


void CP3MFC程序View::OnRButtonDown(UINT nFlags, CPoint point)//鼠标标志以及点击的坐标
{	
    //由于菜单是属于框架的，因而要单独为view创建一个
    CMenu menu;
    //载入需要的菜单
    menu.LoadMenuW(IDR_MENU1);
    CMenu* subMenu = menu.GetSubMenu(0);
    if (true == m_isUpdate) {
        subMenu->EnableMenuItem(subMenu->GetMenuItemID(0), TRUE);
    }
    else {
        subMenu->EnableMenuItem(subMenu->GetMenuItemID(0), FALSE);
    }
    //将客户区域坐标转换为屏幕坐标（左上角原点）。因为弹窗坐标是以屏幕为单位
    ClientToScreen(&point);
    //标志位(设置鼠标在弹出菜单的位置，通过屏幕位置标志与鼠标键标志组合)，
    //坐标x，坐标 y，属于哪一个窗口，对齐方式(TRUE，则菜单按从右到左的阅读顺序右对齐;FALSE，则菜单为从左到右的阅读顺序左对齐)
    //此处为鼠标在左侧，右键点击,去点击坐标，当前窗口，默认值FALSE
    subMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
    CView::OnRButtonDown(nFlags, point);
}


void CP3MFC程序View::OnUpdateTestA(CCmdUI* pCmdUI)
{
    if (true == m_isUpdate) {
        pCmdUI->Enable(TRUE);
    }
    else {
        pCmdUI->Enable(FALSE);
    }

}

void CP3MFC程序View::OnTestB()
{
    m_isUpdate = !m_isUpdate;
}

