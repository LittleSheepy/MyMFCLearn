#include "mfc.h"
#pragma once
MyApp myApp;//ȫ��Ψһ��MyAPP���󣬴�����������ʵ��

BOOL MyApp::InitInstance() {
    /*
    1.������������
    2.��ʾ����
    3.���´���
    4.�����������ָ��
    */
    MyFrame* frame = new MyFrame;
    //��ʾ���ڣ��˴��õ�������ʾ
    frame->ShowWindow(SW_SHOWNORMAL);
    //���´���
    frame->UpdateWindow();
    //�����������ָ��
    m_pMainWnd = frame;
    return TRUE;
}

MyFrame::MyFrame() {
    //CWnd��ĳ�Ա����
    //CFrameWnd�̳���CWnd
    //������NULL��ʾ��Ĭ�����������⣬֮����Ĭ��ֵ
    Create(NULL, TEXT("MFC"));

}