// MainRun.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "MainRun.h"


// ���ǵ���������һ��ʾ��
MAINRUN_API int nMainRun=0;

// ���ǵ���������һ��ʾ����
MAINRUN_API int fnMainRun(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� MainRun.h
CMainRun::CMainRun()
{
	return;
}
