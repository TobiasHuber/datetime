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

#include <DateTime/Time.h>

namespace dt
{
    Time::Time()
	{
		_time = 0;
	}

	Time::Time(const Time & time)
	{
		_time = time.asNanoseconds();
	}

	Time::Time(int64_t nanos)
	{
		_time = nanos;
	}

	Time Time::hours(double amount)
	{
		return Time::minutes(amount*60);
	}

	Time Time::minutes(double amount)
	{
		return Time::seconds(amount*60);
	}

	Time Time::seconds(int64_t amount)
	{
		return Time::milliseconds(amount*1000);
	}

	Time Time::milliseconds(int64_t amount)
	{
		return Time::microseconds(amount*1000);
	}

	Time Time::microseconds(int64_t amount)
	{
		return Time(amount*1000);
	}

	Time Time::nanoseconds(int64_t amount)
	{
		return Time(amount);
	}

	double Time::asDays() const
	{
		return asHours() / 24;
	}

	double Time::asHours() const
	{
		return asMinutes() / 60;
	}

	double Time::asMinutes() const
	{
		return static_cast<double>(asSeconds()) / 60;
	}

	int64_t Time::asSeconds() const
	{
		return asMilliseconds() / 1000;
	}

	int64_t Time::asMilliseconds() const
	{
		return asMicroseconds() / 1000;
	}

	int64_t Time::asMicroseconds() const
	{
		return _time / 1000;
	}

	int64_t Time::asNanoseconds() const
	{
		return _time;
	}

	Time &Time::operator=(const Time & time)
	{
		_time = time.asNanoseconds();
		return *this;
	}

	bool operator==(Time left, Time right)
	{
		return (left.asNanoseconds() == right.asNanoseconds());
	}

	bool operator!=(Time left, Time right)
	{
		return (left.asNanoseconds() != right.asNanoseconds());
	}

	bool operator>=(Time left, Time right)
	{
		return (left.asNanoseconds() >= right.asNanoseconds());
	}

	bool operator<=(Time left, Time right)
	{
		return (left.asNanoseconds() <= right.asNanoseconds());
	}

	bool operator>(Time left, Time right)
	{
		return (left.asNanoseconds() > right.asNanoseconds());
	}

	bool operator<(Time left, Time right)
	{
		return (left.asNanoseconds() < right.asNanoseconds());
	}

	Time & operator+=(Time & left, Time right)
	{
		return left = left + right;
	}

	Time & operator-=(Time & left, Time right)
	{
		return left = left - right;
	}

	Time & operator/=(Time & left, Time right)
	{
		return left = left / right;
	}

	Time & operator*=(Time & left, Time right)
	{
		return left = left * right;
	}

	Time operator/(Time left, Time right)
	{
		return Time(left.asNanoseconds() / right.asNanoseconds());
	}

	Time operator*(Time left, Time right)
	{
		return Time(left.asNanoseconds() * right.asNanoseconds());
	}

	Time operator+(Time left, Time right)
	{
		return Time(left.asNanoseconds() + right.asNanoseconds());
	}

	Time operator-(Time left, Time right)
	{
		return Time(left.asNanoseconds() - right.asNanoseconds());
	}
}