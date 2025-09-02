#include<Windows.h>  //�ײ�ʵ�ִ��ڵ�ͷ�ļ�


//6��������Ϣ �����ڹ��̣�

//CALLBACK �����˲����Ĵ���˳�򣬴��ҵ���������ջ�����Һ�������֮ǰ��ն�ջ
LRESULT CALLBACK winproc(
	_In_ HWND   hwnd, //��Ϣ�����Ĵ��ھ��
	_In_ UINT   uMsg, //������Ϣ����   WM_XXX��Ϣ��
	_In_ WPARAM wParam,//���̸�����Ϣ
	_In_ LPARAM lParam //��긽����Ϣ
)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);  //DestroyWindow������һ����Ϣ  WM_DESTROY
		break;
	case WM_DESTROY:     //�˳����̣���ȫ�ر�
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN: //����������
	{
		int xPos = LOWORD(lParam);
		int yPos = HIWORD(lParam);

		//Ҫ��ʾ������
		char buf[1024];
		wsprintf(buf, TEXT("x = %d,y = %d"), xPos, yPos);

		//������Ϣ����
		MessageBox(hwnd, buf, TEXT("����������"), MB_OK);

		break;
	}
	case WM_KEYDOWN:  //����
		MessageBox(hwnd, TEXT("���̰���"), TEXT("���̰���"), MB_OK);
		break;

	}



	//����ֵ��Ĭ�ϴ���ʽ
	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}



//������ں���
//WINAPI�� ����_stdcall�˲����Ĵ���˳�򣬴��ҵ���������ջ�����Һ�������֮ǰ��ն�ջ
int WINAPI WinMain(
	HINSTANCE hInstance,  //Ӧ�ó���ʵ�����
	HINSTANCE hPrevInstance, //��һ��Ӧ�ó���������win32�����£�����һ��ΪNULL������������
	LPSTR lpCmdLine,//char *arg[]
	int nShowCmd  //��ʾ���� ��󻯡���С��������
)
{
	//1����ƴ���
	//2��ע�ᴰ��
	//3����������
	//4����ʾ�͸���
	//5��ͨ��ѭ��ȡ��Ϣ
	//6��������Ϣ �����ڹ��̣�

	//1����ƴ���
	WNDCLASS wc;
	wc.cbClsExtra = 0; //��Ķ�����ڴ棬һ��Ϊ0
	wc.cbWndExtra = 0; //���ڵĶ����ڴ棬һ��Ϊ0
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //ѡ�񴰿ڱ����������ð�ɫ
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);//���ù������,��һ������ΪNULL������ʹ��ϵͳ�ṩ����
	wc.hIcon = LoadIcon(NULL, IDI_ERROR);//����ͼ�꣬��һ������ΪNULL������ʹ��ϵͳ�ṩ����
	wc.hInstance = hInstance;//Ӧ�ó���ʵ�����  ����WinMain�е��βμ���
	wc.lpfnWndProc = winproc;//�ص�����  ���ڹ���
	wc.lpszClassName = TEXT("WIN"); //ָ������������
	wc.lpszMenuName = NULL; //�˵�����
	wc.style = 0;//0����Ĭ�Ϸ��

	//2��ע�ᴰ��
	RegisterClass(&wc);

	//3����������
	/*
	lpClassName,  ����
	lpWindowName, ������
	dwStyle,   WS_OVERLAPPEDWINDOW ��Ϸ��
	x,        ��ʾ����
	y,                  Ĭ��ֵΪCW_USEDEFAULT
	nWidth,    ���
	nHeight,
	hWndParent, NULL  ������
	hMenu,      �˵�  NULL
	hInstance,  ʵ�����
	lpParam     ����ֵ  ��긽��ֵ
	*/
	HWND hwnd = CreateWindow(wc.lpszClassName, TEXT("�����Ǵ�����"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	//4����ʾ�͸���
	ShowWindow(hwnd, SW_NORMAL);
	UpdateWindow(hwnd);


	//5��ͨ��ѭ��ȡ��Ϣ
	/* ��Ϣ�а��������ݣ�
	HWND        hwnd;  �����ھ��
	UINT        message;������Ϣ����
	WPARAM      wParam; ������Ϣ  ������Ϣ
	LPARAM      lParam; ������Ϣ  �����Ϣ  ���Ҽ�
	DWORD       time;   ��Ϣ����ʱ��
	POINT       pt;     ������Ϣ  �����Ϣ  λ����Ϣ x y
	*/
	MSG  msg;  //������Ϣ

	while (1)
	{
		/*
		_Out_ LPMSG lpMsg,  ��Ϣ
		_In_opt_ HWND hWnd, ���񴰿ڣ���дNULL���������еĴ���
	   _In_ UINT wMsgFilterMin,  //��С�������˵���Ϣ��һ����0
		_In_ UINT wMsgFilterMax  //��0���������е���Ϣ

		*/
		if (GetMessage(&msg, NULL, 0, 0) == FALSE)
		{
			break;
		}

		//������Ϣ
		TranslateMessage(&msg);

		//��Ϊfalse
		//�ַ���Ϣ
		DispatchMessage(&msg);

	}



}
