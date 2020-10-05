#include "Clock.h"

void Clock::setHour(int h)
{
	try
	{
		if (h > 23)
			throw "Invalid time - more than 24 hours.";
		if (h < 0)
			throw "Invalid time - negative number of hours.";
		hour = h;
	}
	catch (const char *str)
	{
		cout << "/n Exception message: " << str << endl;
		hour = 0;
	}
}

void Clock::setMinute(int m)
{
	try
	{
		if (m > 59)
			throw "Invalid time - more than 60 minutes.";
		if (m < 0)
			throw "Invalid time - negative number of minutes.";
		minute = m;
	}
	catch (const char *str)
	{
		cout << "\n Exception message: " << str << endl;
		minute = 0;
	}
}

void Clock::setSecond(int s)
{
	try
	{
		if (s > 59)
			throw "Invalid time - more than 60 seconds.";
		if (s < 0)
			throw "Invalid time - negative number of seconds.";
		second = s;
	}
	catch (const char *str)
	{
		cout << "\n Exception message: " << str << endl;
		second = 0;
	}
}

Clock Clock::operator+=(int s)
{
	second += s;
	if (second > 59)
	{
		second -= 60;
		minute++;
	}
	if (minute > 59)
	{
		minute -= 60;
		hour++;
	}
	if (hour > 23)
		hour=0;
	return *this;
}

ostream & operator<<(ostream & pr, Clock x)
{
	if (x.hour > 9)
		pr << x.hour << ":";
	else pr << "0" << x.hour << ":";
	if (x.minute > 9)
		pr << x.minute << ":";
	else
		pr << "0" << x.minute << ":";
	if (x.second > 9)
		pr << x.second;
	else
		pr << "0" << x.second;
	return pr;
}

istream & operator>>(istream & in, Clock &zman)
{
	int h, m, s;
	char x;
	in >> h >> x >> m >> x >> s;
	try
	{
		if (h > 23)
			throw "Invalid time - more than 24 hours.";
		if (h < 0)
			throw "Invalid time - negative number of hours.";
		if (m > 59)
			throw "Invalid time - more than 60 minutes.";
		if (m < 0)
			throw "Invalid time - negative number of minutes.";
		if (s > 59)
			throw "Invalid time - more than 60 seconds.";
		if (s < 0)
			throw "Invalid time - negative number of seconds.";
		if (x != ':')
			throw "Wrong time format.";
		zman.setHour(h);
		zman.setMinute(m);
		zman.setSecond(s);
	}
	catch (const char* str)
	{
		cout << "\n" << "Exception message: " << str << endl;
		zman.setHour(0);
		zman.setMinute(0);
		zman.setSecond(0);
	}

	return in;
}


