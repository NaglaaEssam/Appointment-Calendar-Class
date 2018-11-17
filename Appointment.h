//#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <iostream>
#include "time.h"
#include "DayAppointment.h"
#include "Calendar.h"
using namespace std;

class Appointment
{
    public:
        Appointment();
        Appointment(time ,time );
        bool operator == (Appointment );
        bool operator != (Appointment );
        bool operator <  (Appointment );
        bool operator >  (Appointment );
        bool operator <= (Appointment );
        bool operator >= (Appointment );
        friend istream& operator>>(istream& , Appointment& );
        friend ostream& operator<<(ostream& , Appointment );
    private:
        time start;
        time End;
};

