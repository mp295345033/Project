#include "stdafx.h"
#include "Recoder.h"
#include <thread>
#include "stuct.h"

static 	IUIAutomation *g_pAutomation = nullptr;
static IUIAutomationElement *uiElement = nullptr;

HHOOK Recoder::mHook = nullptr;
queue<POINT> Recoder::*queLeftbuttonPint = nullptr;

static Recoder * g_rec = nullptr;

Recoder::Recoder()
{
	CoInitialize(NULL);
	HRESULT hr = CoCreateInstance(__uuidof(CUIAutomation), NULL, CLSCTX_INPROC_SERVER,
	__uuidof(IUIAutomation), (void**)&g_pAutomation);
	
}

Recoder::~Recoder()
{
	CoUninitialize();
	UnhookWindowsHookEx(mHook);
}
void Recoder::recoderProc()
{
	POINT pt;
	memset(&pt, 0, sizeof(POINT));
	while (true)
	{
		if (!g_rec->que.isEmpty()){
			pt = g_rec->que.front();
			g_rec->que.pop();
			IUIAutomationElement *element = nullptr;
			//shared_ptr<IUIAutomationElement> element = nullptr;
			g_pAutomation->ElementFromPoint(pt,&element);
			BSTR bstr = nullptr;
			if (element == nullptr){
				break;
			}
			element->get_CurrentName(&bstr);
			MessageBox(NULL, bstr, NULL, NULL);
		}
		Sleep(1000);
	}
	
}

void Recoder::DoRecoder()
{
	thread hook(HookThread,this);
	thread recoderHook(recoderProc);
	hook.join();	
	recoderHook.join();
}


LRESULT CALLBACK Recoder::LowLevelMouseProc(_In_ int   nCode, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	MSLLHOOKSTRUCT *p = (MSLLHOOKSTRUCT *)lParam;
	
	switch (wParam)
	{
	case  WM_LBUTTONDOWN:
		printf("pt is%d\n", p->pt.x);
		RecoderMouse(p->pt);
		break;
	default:
		break;
	}
	return ::CallNextHookEx(mHook, nCode, wParam, lParam);
}


void Recoder::HookThread(void *pram)
{
	g_rec = (Recoder *)pram;
	mHook = ::SetWindowsHookEx(WH_MOUSE_LL, LowLevelMouseProc, ::GetModuleHandle(NULL), 0);
	MSG msg;
	while (::GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	
}

void Recoder::RecoderMouse(const POINT &pt)
{
	g_rec->que.Spasvopush(pt);
}

