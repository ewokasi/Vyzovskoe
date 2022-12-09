#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <mmsystem.h>
#include "TIMER.h"



#ifndef TIMER_H
#define TIMER_H
class TIMER
{
public:
	TIMER() : isPaused(false)
	{		}
	~TIMER() {}
	double GetTime();
protected:
	double startTime;
	bool isPaused;
	double pauseTime;
};
#endif	//TIMER_H
