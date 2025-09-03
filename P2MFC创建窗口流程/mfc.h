#pragma once
#include<afxwin.h>
//应用程序类
class MyApp :public CWinApp {
public:
    //该处为MFC程序的入口地址
    virtual BOOL InitInstance();

private:

};

//框架类
class MyFrame :public CFrameWnd {
public:
    MyFrame();
private:

};