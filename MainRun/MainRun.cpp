// MainRun.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "MainRun.h"
#include "Recoder.h"


// ���ǵ���������һ��ʾ��
MAINRUN_API int nMainRun=0;

// ���ǵ���������һ��ʾ����
MAINRUN_API int fnMainRun(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� MainRun.h
//CMainRun::CMainRun()
//{
//	return;
//}


MAINRUN_API void  API_DoRecoder(void)
{
	shared_ptr<Recoder> rec = make_shared<Recoder>();
	rec->DoRecoder();
}