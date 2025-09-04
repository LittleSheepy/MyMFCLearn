
// P3MFC程序View.h: CP3MFC程序View 类的接口
//

#pragma once


class CP3MFC程序View : public CView
{
protected: // 仅从序列化创建
	CP3MFC程序View() noexcept;
	DECLARE_DYNCREATE(CP3MFC程序View)

// 特性
public:
	CP3MFC程序Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CP3MFC程序View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
    CPoint m_myPoint;
    CString m_str;
private:
    bool m_isPress;
public:
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg void OnFileSave();
    afx_msg void OnTestDemo();
    afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnTestB();
private:
    bool m_isUpdate;
public:
    afx_msg void OnUpdateTestA(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // P3MFC程序View.cpp 中的调试版本
inline CP3MFC程序Doc* CP3MFC程序View::GetDocument() const
   { return reinterpret_cast<CP3MFC程序Doc*>(m_pDocument); }
#endif

