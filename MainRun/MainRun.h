// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� MAINRUN_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// MAINRUN_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef MAINRUN_EXPORTS
#define MAINRUN_API __declspec(dllexport)
#else
#define MAINRUN_API __declspec(dllimport)
#endif

// �����Ǵ� MainRun.dll ������
class MAINRUN_API CMainRun {
public:
	CMainRun(void);
	// TODO:  �ڴ�������ķ�����
};

extern MAINRUN_API int nMainRun;

MAINRUN_API int fnMainRun(void);
