#include<Windows.h>  //底层实现窗口的头文件


//6、处理消息 （窗口过程）

//CALLBACK 代表了参数的传递顺序，从右到左依次入栈，并且函数返回之前清空堆栈
LRESULT CALLBACK winproc(
	_In_ HWND   hwnd, //消息所属的窗口句柄
	_In_ UINT   uMsg, //具体消息名称   WM_XXX消息名
	_In_ WPARAM wParam,//键盘附加消息
	_In_ LPARAM lParam //鼠标附加消息
)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);  //DestroyWindow发送另一个消息  WM_DESTROY
		break;
	case WM_DESTROY:     //退出进程，完全关闭
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN: //鼠标左键按下
	{
		int xPos = LOWORD(lParam);
		int yPos = HIWORD(lParam);

		//要显示的内容
		char buf[1024];
		wsprintf(buf, TEXT("x = %d,y = %d"), xPos, yPos);

		//弹出消息窗口
		MessageBox(hwnd, buf, TEXT("鼠标左键按下"), MB_OK);

		break;
	}
	case WM_KEYDOWN:  //键盘
		MessageBox(hwnd, TEXT("键盘按下"), TEXT("键盘按下"), MB_OK);
		break;

	}



	//返回值用默认处理方式
	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}


//****************************************************
//-----------------<程序入口函数>--------------------
//****************************************************

//WINAPI宏 代表_stdcall了参数的传递顺序，从右到左依次入栈，并且函数返回之前清空堆栈
int WINAPI WinMain(
	HINSTANCE hInstance,		// 应用程序实例句柄
	HINSTANCE hPrevInstance,	// 上一个应用程序句柄，在win32环境下，参数一般为NULL，不起作用了
	LPSTR lpCmdLine,			// char *arg[]
	int nShowCmd				// 显示命令 最大化、最小化、正常
)
{
	//1、设计窗口
	//2、注册窗口
	//3、创建窗口
	//4、显示和更新
	//5、通过循环取消息
	//6、处理消息 （窗口过程）

	//1、设计窗口
	WNDCLASS wc;
	wc.style = 0;												//0代表默认风格
	wc.lpfnWndProc = winproc;									//回调函数  窗口过程
	wc.cbClsExtra = 0;											//类的额外的内存，一般为0
	wc.cbWndExtra = 0;											//窗口的额外内存，一般为0
	wc.hInstance = hInstance;									//应用程序实例句柄  传入WinMain中的形参即可
	wc.hIcon = LoadIcon(NULL, IDI_ERROR);						//设置图标，第一个参数为NULL，代表使用系统提供类型
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					//设置光标类型,第一个参数为NULL，代表使用系统提供类型
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		//选择窗口背景，这里用白色
	wc.lpszMenuName = NULL;										//菜单名称
	wc.lpszClassName = TEXT("WIN");								//指定窗口类名称

	//2、注册窗口
	RegisterClass(&wc);

	//3、创建窗口
	/*
	lpClassName,  类名
	lpWindowName, 标题名
	dwStyle,   WS_OVERLAPPEDWINDOW 混合风格
	x,        显示坐标
	y,                  默认值为CW_USEDEFAULT
	nWidth,    宽高
	nHeight,
	hWndParent, NULL  父窗口
	hMenu,      菜单  NULL
	hInstance,  实例句柄
	lpParam     附加值  鼠标附加值
	*/
	HWND hwnd = CreateWindow(wc.lpszClassName, TEXT("这里是窗口名"), WS_POPUPWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	//4、显示和更新
	ShowWindow(hwnd, SW_NORMAL);
	UpdateWindow(hwnd);


	//5、通过循环取消息
	/* 消息中包含的内容：
	HWND        hwnd;  主窗口句柄
	UINT        message;具体消息名称
	WPARAM      wParam; 附加消息  键盘消息
	LPARAM      lParam; 附加消息  鼠标消息  左右键
	DWORD       time;   消息产生时间
	POINT       pt;     附加消息  鼠标消息  位置信息 x y
	*/
	MSG  msg;  //声明消息

	while (1)
	{
		/*
		_Out_ LPMSG lpMsg,  消息
		_In_opt_ HWND hWnd, 捕获窗口，填写NULL代表捕获所有的窗口
	   _In_ UINT wMsgFilterMin,  //最小和最大过滤的消息，一般填0
		_In_ UINT wMsgFilterMax  //填0代表捕获所有的消息

		*/
		if (GetMessage(&msg, NULL, 0, 0) == FALSE)
		{
			break;
		}

		//翻译消息
		TranslateMessage(&msg);

		//不为false
		//分发消息
		DispatchMessage(&msg);

	}



}
