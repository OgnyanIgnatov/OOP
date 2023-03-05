#ifndef TIME_H
#define TIME_H

class Time
{
	int hours;
	int minutes;
	int seconds;

public:
	Time();
	Time get_diff(const Time other_time) const;
	void setHours(int hours);
	int getHours();
	void setMinutes(int mintuets);
	int getMinutes();
	void setSeconds(int seconds);
	int getSeconds();
};




#endif 
