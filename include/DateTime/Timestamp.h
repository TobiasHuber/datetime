#ifndef DT_TIMESTAMP_H
#define DT_TIMESTAMP_H

#include "Time.h"
#include <string>

namespace dt
{
    enum TimestampPrecision
    {
        SECONDS,
        MILLISECONDS,
        MICROSECONDS,
        NANOSECONDS
    };

	std::string unix2stamp(Time time, char delimiter = 'T', short prec = TimestampPrecision::SECONDS);
	Time stamp2unix(const std::string& stamp, char delimiter = 'T', short prec = TimestampPrecision::SECONDS);
}


#endif