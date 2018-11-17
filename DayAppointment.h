//#ifndef DAYAPPOINTMENT_H
#define DAYAPPOINTMENT_H
#include <iostream>
#include "time.h"
#include "Appointment.h"
#include "Calendar.h"
using namespace std;

class DayAppointment
{
    public:
        DayAppointment(int ,string );
        DayAppointment();
        void operator =( DayAppointment &);
        bool operator == (DayAppointment );
        bool operator != (DayAppointment );
        DayAppointment fun(int );
        friend istream& operator>>(istream& , DayAppointment& );
        friend ostream& operator<<(ostream& , DayAppointment );
        ~DayAppointment();
    private:
        Appointment * appointment;
        int numOfAppointment;
        string weekDay;
};
