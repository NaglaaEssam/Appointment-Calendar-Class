//#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;

class time
{
    public:
        time(int ,int ,string );
        time();
        bool operator == (time );
        bool operator != (time );
        bool operator <  (time );
        bool operator >  (time );
        friend istream& operator>>(istream& , time& );
        friend ostream& operator<<(ostream& , time );
    private:
        int hour;
        int minute;
        string day_night;
};
