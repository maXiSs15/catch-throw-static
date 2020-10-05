#pragma once
#include <iostream>

using namespace std;

class Clock
{
	int hour;
	int minute;
	int second;

public:
//	Clock() { hour = 0; minute = 0; second = 0; }
	Clock(int h=0, int m=0, int s=0) { setHour(h); setMinute(m); setSecond(s); }
	Clock(Clock & time) :
		hour(time.getHour()), minute(time.getMinute()), second(time.getSecond()) {}
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);
	int getHour() { return hour; }
	int getMinute() { return minute; }
	int getSecond() { return second; }
	Clock operator +=(int s);

	friend ostream& operator <<(ostream &, Clock);
	friend istream& operator >>(istream&, Clock &);
};
