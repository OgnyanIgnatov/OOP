#include "time.h"
#include "event.h"
#include <iostream>

Time::Time()
{
    Time::hours = 0;
    Time::minutes = 0;
    Time::seconds = 0;
}

void Time::setHours(int newHour)
{
    if (newHour < 0 || newHour > 23)
    {
        std::cout << "Invalid hour";
    }
    else hours = newHour;
}

int Time::getHours()
{
    return hours;
}

void Time::setMinutes(int newMins)
{
    if (newMins < 0 || newMins > 59)
    {
        std::cout << "Invalid minutes";
    }
    else minutes = newMins;
}

int Time::getMinutes()
{
    return minutes;
}

void Time::setSeconds(int newSeconds)
{
    if (newSeconds < 0 || newSeconds > 59)
    {
        std::cout << "Invalid seconds";
    }
    else seconds = newSeconds;
}

int Time::getSeconds()
{
    return seconds;
}


Time Time::get_diff(const Time other_time) const
{
    Time a;

    a.hours = other_time.hours - hours;
    a.minutes = other_time.minutes - minutes;
    a.seconds = other_time.seconds - seconds;

    return a;
}



Event::Event()
{
    this->title[127] = { '\0' };
    this->organiser[127] = { '\0' };
    Time strat_time;
    Time end_time;
}

Time Event::getDur()
{
    return start_time.get_diff(end_time);
}

void Event::setTitle()
{
    for (int i = 0; i != 128; ++i)
    {
        std::cin >> title[i];
        if (title[i] == '\n')
        {
            title[i] = '\0';
            break;
        }
    }
}

void Event::setOrganiser()
{
    for (int i = 0; i != 128; ++i)
    {
        std::cin >> organiser[i];
        if (organiser[i] == '\n')
        {
            organiser[i] = '\0';
            break;
        }
    }
}

bool Event::evCross(const Event b)
{
    Time a = b.start_time;
    Time c = b.end_time;
    if ((start_time.getHours() >= a.getHours() && start_time.getHours() <= c.getHours()) || (end_time.getHours() >= a.getHours() && end_time.getHours() <= c.getHours()))
    {
        return 0;
    }
    if (start_time.getHours() == a.getHours() && start_time.getHours() == c.getHours())
    {
        if (end_time.getMinutes() >= a.getMinutes() && end_time.getMinutes() <= c.getMinutes())
        {
            return 0;
        }
    }
    return 1;
}

void Event::inputEvenets()
{
    int h1, m1, s1;
    int h2, m2, s2;
    
        std::cin >> h1;
        start_time.setHours(h1);
        std::cin >> m1;
        start_time.setMinutes(m1);
        std::cin >> s1;
        start_time.setSeconds(s1);


        std::cin >> h2;
        end_time.setHours(h2);
        std::cin >> m2;
        end_time.setMinutes(m2);
        std::cin >> s2;
        end_time.setSeconds(s2);
    

}


int main()
{
    Event* arr = new Event[3];
    int arr1[3], h = 1;
    for (int i = 0; i < 3; i++)
    {
        arr[i].inputEvenets();
    }
    arr1[0] = 1;
    for (int i = 1; i < 3; i++)
    {
        if (arr[i - 1].evCross(arr[i]))
        {
            arr1[h] = i + 1;
            h++;
        }
        else arr1[h] = 0;
    }
    std::cout << "ID of events you could visit: ";
    for (int i = 0; i < 3; i++) 
    {
        if (arr1[i] != 0)
        {
            std::cout << arr1[i] << ", ";
        }
    }
    delete[] arr;
    
    
}
