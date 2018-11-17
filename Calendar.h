
#ifndef CALENDAR_H
#define CALENDAR_H
#include <iostream>
#include "time.h"
#include "Appointment.h"
#include "DayAppointment.h"
using namespace std;

class Calendar
{
    public:
        Calendar(int n_o_d);
        Calendar();
        friend istream& operator>>(istream& , Calendar& );
        friend ostream& operator<<(ostream& , Calendar );
        ~Calendar();

    private:
        DayAppointment * day;
        int numofday;
};

#endif // CALENDAR_H
