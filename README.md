# DateTime
A DateTime library for C++

## build & install
```
mkdir build
cd build
cmake ..
make install
```

## example
```cpp
#include <DateTime/DateTime.h>
#include <iostream>

int main()
{
    dt::Time time = dt::Clock::getTimeNow();

    std::cout << time.asMicroseconds() << std::endl;

    std::string timestamp = "2020-01-01T10:20:13.327";
    dt::Time timeFromTimestamp = dt::stamp2unix(timestamp, 'T', dt::TimestampPrecision::MILLISECONDS);

    if(time > timeFromTimestamp)
    {
        std::cout << dt::unix2stamp(time 'T', dt::TimestampPrecision::MILLISECONDS);
        std::cout << " > " << timestamp << std::endl;
    }

    dt::Date date = Date::fromTime(time);
    std::cout << date.month << std::endl;

    return 0;
}
```
