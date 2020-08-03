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