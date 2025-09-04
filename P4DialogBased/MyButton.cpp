// MyButton.cpp: 实现文件
//

#include "pch.h"
#include "P4DialogBased.h"
#include "MyButton.h"


// MyButton

IMPLEMENT_DYNAMIC(MyButton, CButton)

MyButton::MyButton()
{

}

MyButton::~MyButton()
{
}


BEGIN_MESSAGE_MAP(MyButton, CButton)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// MyButton 消息处理程序
void MyButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//设置随机移动距离
	int x = rand() % 400;
	int y = rand() % 400;
	//移动距离x轴，y轴，窗口宽，高,是否重绘（默认true)s
	this->MoveWindow(x, y, 100, 500);
	CButton::OnMouseMove(nFlags, point);
}

