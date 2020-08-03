#ifndef DT_CLOCK_H
#define DT_CLOCK_H

#include "Time.h"

namespace dt
{
    class Clock
	{
	private:
		Time _starttime;

	public:
		Clock();
		Time restart();
		static Time getTimeNow();
		Time getStartTime();
		Time getElapsedTime();
	};
}

#endif