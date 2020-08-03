#include <DateTime/Clock.h>
#include <chrono>

namespace dt
{
    Clock::Clock()
	{
		_starttime = getTimeNow();
	}

	Time Clock::restart()
	{
		Time temp = getTimeNow() - _starttime;
		_starttime = getTimeNow();
		return temp;
	}

	Time Clock::getTimeNow()
	{
		Time temp = Time::nanoseconds(std::chrono::duration_cast<std::chrono::nanoseconds>
			(std::chrono::system_clock::now().time_since_epoch()).count());
		return temp;
	}

	Time Clock::getStartTime()
	{
		return _starttime;
	}

	Time Clock::getElapsedTime()
	{
		Time tmp = getTimeNow() - _starttime;
		return tmp;
	}
}
