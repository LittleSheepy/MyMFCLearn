#include "mfc.h"
#pragma once
MyApp myApp;//全局唯一的MyAPP对象，代表整个进程实例

BOOL MyApp::InitInstance() {
    /*
    1.创建框架类对象
    2.显示窗口
    3.更新窗口
    4.保存框架类对象指针
    */
    MyFrame* frame = new MyFrame;
    //显示窗口，此处用的正常显示
    frame->ShowWindow(SW_SHOWNORMAL);
    //更新窗口
    frame->UpdateWindow();
    //保存框架类对象指针
    m_pMainWnd = frame;
    return TRUE;
}

MyFrame::MyFrame() {
    //CWnd类的成员函数
    //CFrameWnd继承于CWnd
    //类名（NULL表示用默认名），标题，之后有默认值
    Create(NULL, TEXT("MFC"));

}