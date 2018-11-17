#include <iostream>
#include "time.h"
#include "Appointment.h"
#include "DayAppointments.h"
#include "Calendar.h"
using namespace std;
time(int h,int m,string d_n)
{
    hour=h;
    minute=m;
    day_night=d_n;
}
time()
{
    hour=0;
    minute=0;
    day_night=" ";
}
bool time :: operator == (time t2)
{
    if((hour==t2.hour)&&(minute==t2.minute)&&(day_night[0]==t2.day_night[0]))
    {
        return true;
    }
    else
        return false;
}
bool time :: operator != (time t2)
{
    if((hour==t2.hour)&&(minute==t2.minute)&&(day_night[0]==t2.day_night[0]))
    {
        return false;
    }
    else
        return true;
}
bool time :: operator < (time t2)
{
    if(day_night[0]<t2.day_night[0])
    {
        return true;
    }
    else if((hour<t2.hour)||(hour==12))
    {
        return true;
    }
    else if((hour==t2.hour)&&(minute<t2.minute))
    {
        return true;
    }
    else
        return false;
}
bool time :: operator > (time t2)
{
    if(day_night[0]>t2.day_night[0])
    {
        return true;
    }
    else if((hour>t2.hour)||(t2.hour==12))
    {
        return true;
    }
    else if((hour==t2.hour)&&(minute>t2.minute))
    {
        return true;
    }
    else
        return false;
}
istream& operator>>(istream& in , time& t1 ){
    cout<<"Enter number of hour :";
    in>>t1.hour;
    cout<<"Enter number of minute :";
    in>>t1.minute;
    cout<<"Enter day night :";
    in>>t1.day_night;
    return in;
}
ostream& operator<<(ostream& os , time t1 ){
    os<<t1.hour<<":"<<t1.minute<<" "<<t1.day_night;
    return os;
}
