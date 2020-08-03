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

#include <DateTime/Timestamp.h>
#include <time.h>
#include <iomanip>
#include <sstream>

namespace dt
{
	std::string unix2stamp(Time time, char delimiter, short prec)
	{
		char buffer[28];
		time_t tt = time.asSeconds();

		std::string format = "%Y-%m-%d";
		format += delimiter;
		format += "%H:%M:%S";

		struct tm tmp;
		strftime(buffer, 28, format.c_str(), gmtime_r(&tt, &tmp));

		std::stringstream ss;
		ss << buffer;
		if(prec == TimestampPrecision::MILLISECONDS)
			ss << "." << std::setfill('0') << std::setw(3) << time.asMilliseconds()-(time.asSeconds()*1e3);
		else if(prec == TimestampPrecision::MICROSECONDS)
			ss << "." << std::setfill('0') << std::setw(6) << time.asMicroseconds()-(time.asSeconds()*1e6);
        else if(prec == TimestampPrecision::NANOSECONDS)
			ss << "." << std::setfill('0') << std::setw(9) << time.asNanoseconds()-(time.asSeconds()*1e9);

		return ss.str();
	}

	Time stamp2unix(const std::string& stamp, char delimiter, short prec)
	{
		struct std::tm tm;

		std::string format = "%Y-%m-%d";
		format += delimiter;
		format += "%H:%M:%S";

		std::istringstream ss(stamp);
		ss >> std::get_time(&tm, format.c_str());
		int64_t time = mktime(&tm) - timezone;

		int64_t nanos = time*1e9;

		try
		{
			int ppos = stamp.find_last_of('.');
			if(prec == TimestampPrecision::MILLISECONDS)
			{
				nanos += std::stoll(stamp.substr(ppos+1, 3))*1e6;
			}
			else if(prec == TimestampPrecision::MICROSECONDS)
			{
				nanos += std::stoll(stamp.substr(ppos+1, 6))*1e3;
			}
            else if(prec == TimestampPrecision::NANOSECONDS)
			{
				nanos += std::stoll(stamp.substr(ppos+1, 9));
			}
		}
		catch(std::exception &ex)
		{
			
		}

		return Time::microseconds(nanos);
	}
}