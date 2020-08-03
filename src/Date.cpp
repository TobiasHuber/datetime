#include <DateTime/Date.h>
#include <time.h>

namespace dt
{
    Date Date::fromTime(const Time time)
	{
		Date tmp;

		time_t t = time.asSeconds();
		struct tm *tm = gmtime(&t);
		tmp.year = tm->tm_year + 1900;
		tmp.month = tm->tm_mon + 1;
		tmp.day = tm->tm_mday;
		tmp.hour = tm->tm_hour;
		tmp.minute = tm->tm_min;
		tmp.second = tm->tm_sec;

		tmp.year_day = tm->tm_yday + 1;
		tmp.week_day = tm->tm_wday + 1;

		return tmp;
	}
    
	Time Date::toTime()
	{
		time_t tim;
		tm* time_ptr;

		time(&tim);
		time_ptr = gmtime(&tim);

		time_ptr->tm_year = year - 1900;
		time_ptr->tm_mon = month - 1;
		time_ptr->tm_mday = day;
		time_ptr->tm_hour = hour;
		time_ptr->tm_min = minute;
		time_ptr->tm_sec = second;

		int64_t unixt = mktime(time_ptr) - timezone;

		return Time::seconds(unixt);
	}
}