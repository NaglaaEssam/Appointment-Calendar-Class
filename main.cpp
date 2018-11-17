#include <iostream>

using namespace std;
class time
{
private:
    int hour;
    int minute;
    string day_night;
public:
    time(int h,int m,string d_n){
     hour=h;
     minute=m;
     day_night=d_n;
    }
    time(){
    hour=0;
    minute=0;
    day_night=" ";
    }
    bool operator == (time t2){
        if((hour==t2.hour)&&(minute==t2.minute)&&(day_night[0]==t2.day_night[0])){
            return true;
        }
        else
            return false;
    }
    bool operator != (time t2){
        if((hour==t2.hour)&&(minute==t2.minute)&&(day_night[0]==t2.day_night[0])){
            return false;
        }
        else
            return true;
    }
    bool operator < (time t2){
        if(day_night[0]<t2.day_night[0]){return true;}
        else if((hour<t2.hour)||(hour==12)){return true;}
        else if((hour==t2.hour)&&(minute<t2.minute)){return true;}
        else
            return false;
    }
    bool operator > (time t2){
        if(day_night[0]>t2.day_night[0]){return true;}
        else if((hour>t2.hour)||(t2.hour==12)){return true;}
        else if((hour==t2.hour)&&(minute>t2.minute)){return true;}
        else
            return false;
    }
    friend istream& operator>>(istream& , time& );
    friend ostream& operator<<(ostream& , time );
};
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
class Appointment
{
private:
    time start;
    time End;
public:
    Appointment(time s,time e){
        start=s;
        End=e;
    }
    Appointment(){
        start;
        End;
    }
    bool operator == (Appointment A2){
        if((start==A2.start)&&(End==A2.End)){
            return true;
        }
        else
            return false;
    }
    bool operator != (Appointment A2){
        if((End<A2.start)&&(End!=A2.End)){
            return true;
        }
        else
            return false;
    }
    bool operator < (Appointment A2){
        if((start<A2.start)&&(End<A2.start)){
            return true;
        }
        else
            return false;
    }
    bool operator > (Appointment A2){
        if((start>A2.End)&&(End>A2.End)){
            return true;
        }
        else
            return false;
    }
    bool operator <= (Appointment A2){
        if(((start<A2.start)&&(End<A2.start))||((start==A2.start)&&(End==A2.End))){
            return true;
        }
        else
            return false;
    }
    bool operator >= (Appointment A2){
        if(((start>A2.End)&&(End>A2.End))||((start==A2.start)&&(End==A2.End))){
            return true;
        }
        else
            return false;
    }
    friend istream& operator>>(istream& , Appointment& );
    friend ostream& operator<<(ostream& , Appointment );

};
istream& operator>>(istream&in ,Appointment& A1 ){
    cout<<"Enter time to start"<<endl;
    in>>A1.start;
    cout<<"Enter time to end"<<endl;
    in>>A1.End;
    return in;
}
ostream& operator<<(ostream& os , Appointment A1 ){
    os<<A1.start<<" ";
    os<<A1.End<<endl;
return os;
}
class DayAppointments
{
private:
    Appointment* appointments;
    int numOfAppointments;
    string weekDay;
public:
    DayAppointments(int n_o_a,string w_d){
        numOfAppointments=n_o_a;
        weekDay=w_d;
        appointments=new Appointment [numOfAppointments];
        for (int i=0; i<numOfAppointments; i++){
            appointments[i];
		}
    }
     DayAppointments(){
         numOfAppointments=0;
        weekDay=" ";
        appointments=new Appointment [numOfAppointments];
        for (int i=0; i<numOfAppointments; i++){
            appointments[i];
		}
    }
        void operator = ( DayAppointments &d1){
        numOfAppointments=d1.numOfAppointments;
        for (int i=0; i<numOfAppointments; i++){
            appointments[i]=d1.appointments[i];
            cout<< appointments[i]<<endl;
		}

    }
     bool operator ==(DayAppointments d2){
        if((numOfAppointments==d2.numOfAppointments)&&(weekDay!=d2.weekDay)){
            return true;
        }
        else
            return false;
    }
     bool operator !=(DayAppointments d2){
        if((numOfAppointments!=d2.numOfAppointments)&&(weekDay!=d2.weekDay)){
            return true;

        }
        else
            return false;
     }
     int get(){
        return numOfAppointments;
     }

     DayAppointments fun(int num){
         DayAppointments d1(numOfAppointments-1,weekDay);
         for(int i=0;i<numOfAppointments;i++){
             if(i!=(num-1)){
              d1.appointments[i]=appointments[i];
             }
            else{
               d1.appointments[i]=appointments[i+1];
                i++;
            }
         }
         return d1;
     }

     friend istream& operator>>(istream& , DayAppointments& );
     friend ostream& operator<<(ostream& , DayAppointments );
     ~DayAppointments(){
       delete [] appointments;
     }
};
istream& operator>>(istream& is , DayAppointments& d1 ){
     cout<<"Enter the day :";
     is>>d1.weekDay;
     cout<<"Enter num of appointments :";
     is>>d1.numOfAppointments;
     d1.appointments=new Appointment[d1.numOfAppointments];
     for(int i=0;i<d1.numOfAppointments;i++){
        is>>d1.appointments[i];
        if(i==1){
        while (d1.appointments[i]==d1.appointments[i-1]){
            cout<<"error please enter appointment again"<<endl;
            is>>d1.appointments[i];
        }
        }
     }
     return is;
}
ostream& operator<<(ostream& os , DayAppointments d1 ){
     os<<d1.weekDay<<endl;
     os<<d1.numOfAppointments<<endl;
     for(int i=0;i<d1.numOfAppointments;i++){
        os<<d1.appointments[i];
     }
     return os;
}
class Calendar
{
private:
    DayAppointments* day;
    int numofday;
public:
    Calendar(int n_o_d){
        numofday=n_o_d;
        day=new DayAppointments[numofday];
        for (int i=0; i<numofday; i++){
            day[i];
		}
    }
    Calendar(){
         numofday=0;
        day=new DayAppointments [numofday];
        for (int i=0; i<numofday; i++){
            day[i];
		}
    }
    friend istream& operator>>(istream& , Calendar& );
    friend ostream& operator<<(ostream& , Calendar );
    ~Calendar(){
       delete [] day;
    }
};
istream& operator>>(istream& is , Calendar& c1){
     cout<<"Enter num of day :";
     is>>c1.numofday;
     c1.day=new DayAppointments [c1.numofday];
    for(int i=0;i<c1.numofday;i++){
        is>>c1.day[i];
     }
     return is;
}
ostream& operator<<(ostream& os , Calendar c1 ){
     os<<c1.numofday;
     c1.day=new DayAppointments [c1.numofday];
    for(int i=0;i<c1.numofday;i++){
        os<<c1.day[i];
     }
     return os;
}
int main()
{
    DayAppointments d1;
    Calendar c1;
     int x;
     while(x!=0){
        cout<<"1-insert an appointment for a specific day "<<endl;
        cout<<"2-insert an appointment for multiple days "<<endl;
        cout<<"3-display his an appointment for specific day "<<endl;
        cout<<"4-display his an appointment foe multiple days"<<endl;
        cout<<"5-delete an appointment "<<endl;
        cout<<"6-make the appointments of a day equal to another day "<<endl;
        cout<<"7-check if two days have equal appointments "<<endl;
        cout<<"0-End "<<endl;
        cout<<"enter your number ";
        cin>>x;
        if(x==1){
           cin>>d1;
        }
        if(x==2){
            cin>>c1;
        }
        if(x==3){
            cout<<d1;
        }
        if(x==4){
            cout<<c1;
        }
        if(x==5)
        {
            int y;
            cout<<"enter number of appointment want to delete:";
            cin>>y;
            d1.fun(y);
        }
        if(x==6){
        int y=d1.get();
        string day;
        cout<<"which day want two copy it:";
        cin>>day;
         DayAppointments d2(y,day);
         d2=d1;
        }
        if(x==7){
            DayAppointments d2;
            if(d1==d2){
                return true;
            }
            else
                return false;
        }
     }
    return 0;
}
