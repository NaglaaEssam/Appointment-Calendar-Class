#include <iostream>
#include "time.h"
#include "Appointment.h"
#include "DayAppointment.h"
#include "Calendar.h"
using namespace std;
Calendar(int n_o_d)
{
    numofday=n_o_d;
    day=new DayAppointment[numofday];
    for (int i=0; i<numofday; i++)
    {
        day[i];
    }
}
Calendar()
{
    numofday=0;
    day=new DayAppointment [numofday];
    for (int i=0; i<numofday; i++)
    {
        day[i];
    }
}
~Calendar()
{
    delete [] day;
}
istream& operator>>(istream& is, Calendar& c1)
{
    cout<<"Enter num of day :";
    is>>c1.numofday;
    c1.day=new DayAppointment [c1.numofday];
    for(int i=0; i<c1.numofday; i++)
    {
        is>>c1.day[i];
    }
    return is;
}
ostream& operator<<(ostream& os, Calendar c1 )
{
    os<<c1.numofday;
    c1.day=new DayAppointment [c1.numofday];
    for(int i=0; i<c1.numofday; i++)
    {
        os<<c1.day[i];
    }
    return os;
}
