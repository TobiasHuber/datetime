#ifndef DT_TIME_H
#define DT_TIME_H

#include <cstdint>

namespace dt
{
    class Time
	{
	private:
		int64_t _time;

	public:
		Time();
		Time(const Time& time);
		Time(int64_t nanos);

		static Time hours(double amount);
		static Time minutes(double amount);
		static Time seconds(int64_t amount);
		static Time milliseconds(int64_t amount);
		static Time microseconds(int64_t amount);
		static Time nanoseconds(int64_t amount);

		double asDays() const;
		double asHours() const;
		double asMinutes() const;
		int64_t asSeconds() const;
		int64_t asMilliseconds() const;
		int64_t asMicroseconds() const;
		int64_t asNanoseconds() const;

		Time &operator =(const Time &time);
	};

	bool operator ==(Time left, Time right);
	bool operator !=(Time left, Time right);
	bool operator >=(Time left, Time right);
	bool operator <=(Time left, Time right);
	bool operator >(Time left, Time right);
	bool operator <(Time left, Time right);
	Time& operator +=(Time &left, Time right);
	Time& operator -=(Time &left, Time right);
	Time& operator /=(Time &left, Time right);
	Time& operator *=(Time &left, Time right);
	Time operator /(Time left, Time right);
	Time operator *(Time left, Time right);
	Time operator +(Time left, Time right);
	Time operator -(Time left, Time right);
}

#endif