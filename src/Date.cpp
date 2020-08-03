/*Copyright (c) 2020 TobiasHuber
This file is part of the DateTime library by TobiasHuber

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

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