#ifndef DT_DATE_H
#define DT_DATE_H

#include "Time.h"

namespace dt
{
	class Date
	{
	public:	
		uint64_t year;
		uint64_t month;
		uint64_t day;
		uint64_t hour;
		uint64_t minute;
		uint64_t second;

		uint64_t year_day;
		uint64_t week_day;

		static Date fromTime(const Time time);
		Time toTime();
	};
}

#endif