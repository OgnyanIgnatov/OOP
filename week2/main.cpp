#include "time.h"
#include <iostream>
#include "..\time.h"

Time::Time()
{
    Time::hours = 0;
    Time::minutes = 0;
    Time::seconds = 0;
}

void Time::SetHour(int newHour)
{
    if (newHour < 0 || newHour > 24)
    {
        std::cout << "Invalid hour";
    }
    else hours = newHour;
}

int Time::GetHour()
{
    return hours;
}

void Time::SetMinutes(int newMins)
{
    if()
}

Time Time::get_diff(const Time other_time) const
{
    
}


int main()
{
    
}


