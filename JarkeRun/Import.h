#pragma once

#include "MainRun.h"



#ifdef JACK_EXPORTS
#define JACK_API __declspec(dllexport)
#else
#define JACK_API __declspec(dllimport)
#endif


#pragma comment (lib,"MainRun.lib")


JACK_API void API_DoRecoder();