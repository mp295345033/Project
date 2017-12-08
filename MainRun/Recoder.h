#pragma once

#include "combaseapi.h"
#include "JarkQueue.h"
#include "JarkQueue.cpp"
#include <UIAutomationClient.h>




class Recoder
{
public:

	Recoder();
	~Recoder();
public :
	void DoRecoder();
private:
	static LRESULT CALLBACK LowLevelMouseProc(_In_ int   nCode, _In_ WPARAM wParam, _In_ LPARAM lParam);

	static void HookThread(void *);
	static void RecoderMouse(const POINT &pt);
	static void recoderProc();

private: 
	static HHOOK mHook;
	JarkQueue<POINT> que;
};

