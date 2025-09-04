
// P4DialogBasedDlg.h: 头文件
//

#pragma once
#include "MyButton.h"


// CP4DialogBasedDlg 对话框
class CP4DialogBasedDlg : public CDialogEx
{
// 构造
public:
	CP4DialogBasedDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_P4DIALOGBASED_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	MyButton m_button;
	CString m_str;
	CEdit m_Edit1;
	afx_msg void OnBnClickedButtonGengxin();
};
