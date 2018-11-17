#include <iostream>
#include "time.h"
#include "Appointment.h"
#include "DayAppointment.h"
#include "Calendar.h"
using namespace std;
DayAppointment(int n_o_a,string w_d)
{
    numOfAppointments=n_o_a;
    weekDay=w_d;
    appointments=new Appointment [numOfAppointments];
    for (int i=0; i<numOfAppointments; i++)
    {
        appointments[i];
    }
}
DayAppointment()
{
    numOfAppointments=0;
    weekDay=" ";
    appointments=new Appointment [numOfAppointments];
    for (int i=0; i<numOfAppointments; i++)
    {
        appointments[i];
    }
}
void DayAppointment :: operator = ( DayAppointment &d1)
{
    numOfAppointments=d1.numOfAppointment;
    for (int i=0; i<numOfAppointments; i++)
    {
        appointments[i]=d1.appointments[i];
        cout<< appointments[i]<<endl;
    }

}
bool DayAppointment :: operator ==(DayAppointment d2)
{
    if((numOfAppointments==d2.numOfAppointments)&&(weekDay!=d2.weekDay))
    {
        return true;
    }
    else
        return false;
}
bool DayAppointment :: operator !=(DayAppointment d2)
{
    if((numOfAppointments!=d2.numOfAppointments)&&(weekDay!=d2.weekDay))
    {
        return true;

    }
    else
        return false;
}

DayAppointment DayAppointment :: fun(int num)
{
    DayAppointment d1(numOfAppointments-1,weekDay);
    for(int i=0; i<numOfAppointments; i++)
    {
        if(i!=(num-1))
        {
            d1.appointments[i]=appointments[i];
        }
        else
        {
            d1.appointments[i]=appointments[i+1];
            i++;
        }
    }
    return d1;
}
~DayAppointment()
{
    delete [] appointments;
}
istream& operator>>(istream& is, DayAppointment& d1 )
{
    cout<<"Enter the day :";
    is>>d1.weekDay;
    cout<<"Enter num of appointments :";
    is>>d1.numOfAppointments;
    d1.appointments=new Appointment[d1.numOfAppointments];
    for(int i=0; i<d1.numOfAppointments; i++)
    {
        is>>d1.appointments[i];
        if(i==1)
        {
            while (d1.appointments[i]==d1.appointments[i-1])
            {
                cout<<"error please enter appointment again"<<endl;
                is>>d1.appointments[i];
            }
        }
    }
    return is;
}
ostream& operator<<(ostream& os, DayAppointment d1 )
{
    os<<d1.weekDay<<endl;
    os<<d1.numOfAppointments<<endl;
    for(int i=0; i<d1.numOfAppointments; i++)
    {
        os<<d1.appointments[i];
    }
    return os;
}
