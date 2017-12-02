// MainRun.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "MainRun.h"


// 这是导出变量的一个示例
MAINRUN_API int nMainRun=0;

// 这是导出函数的一个示例。
MAINRUN_API int fnMainRun(void)
{
	return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 MainRun.h
CMainRun::CMainRun()
{
	return;
}
