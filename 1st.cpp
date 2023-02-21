#include <iostream>
using namespace std;


struct Time
{
    int hour;
    int minute;
    int second;
    Time get_diff(Time end_time)
    {
        end_time.hour - hour;
        end_time.minute - minute;
        end_time.second - second;
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
    Time start_time;
    cin >> start_time.hour;
    cin >> start_time.minute;
    cin >> start_time.second;
    Time end_time;
    cin >> end_time.hour;
    cin >> end_time.minute;
    cin >> end_time.second;
    Time durr= start_time.get_diff()
}

