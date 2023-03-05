#include "time.h"
#ifndef EVENT_H
#define EVENT_H

class Event
{
	char title[128];
	char organiser[128];
	Time start_time;
	Time end_time;

public:
	Event();
	Time getDur();
	void setTitle();
	void setOrganiser();
	bool evCross(const Event b);
	void inputEvenets();

	


};




#endif 

