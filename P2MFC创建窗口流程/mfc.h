#pragma once
#include<afxwin.h>
//Ӧ�ó�����
class MyApp :public CWinApp {
public:
    //�ô�ΪMFC�������ڵ�ַ
    virtual BOOL InitInstance();

private:

};

//�����
class MyFrame :public CFrameWnd {
public:
    MyFrame();
private:

};