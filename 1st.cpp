#include <iostream>
using namespace std;


struct Time
{
    int hour;
    int minute;
    int second;
    Time get_diff(Time end_time)
    {
        Time diff;
        diff.hour = end_time.hour - hour;
        diff.minute = end_time.minute - minute;
        diff.second = end_time.second - second;
        return diff;
    }
};

struct Event
{
    char title[128];
    char organiser[128];
    Time start_time;
    Time end_time;
    /*Time get_duration()
    {
        Time durr;
        durr.hour = start_time.hour - end_time.hour;
        return durr;
    }
    */
};



int main()
{
    int i = 0;
    int n;
    cin >> n;
    int h = 0, m = 0, s = 0;
    while (i < n)
    {
       // Event ev;
        // cin >> ev.title >> ev.organiser;
        Time start_time;
        cin >> start_time.hour >> start_time.minute >> start_time.second;
        Time end_time;
        cin >> end_time.hour >> end_time.minute >> end_time.second;
        Time durr = start_time.get_diff(end_time);
        h += durr.hour;
        m += durr.minute;
        s += durr.second;
        i++;
    }
    while (m >= 60 || s >= 60)
    {
        if (m >= 60)
        {
            h++;
            m -= 60;
        }
        if (s >= 60)
        {
            m++;
            s -= 60;
        }

    }
    cout << h << ',' << m << ',' << s;

    
    
}
