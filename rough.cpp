#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

struct Date {
    int year, month, day;

    Date(int y, int m, int d) : year(y), month(m), day(d) {}
};

Date parseDate(const std::string& dateStr) {
    int year, month, day;
    char sep;  // To discard the ':' characters
    std::istringstream(dateStr) >> year >> sep >> month >> sep >> day;
    return Date(year, month, day);
}

// Helper function to calculate the difference in days
int daysBetween(const Date& date1, const Date& date2) {
    std::tm tm1 = {0, 0, 0, date1.day, date1.month - 1, date1.year - 1900};  // months are 0-based in std::tm
    std::tm tm2 = {0, 0, 0, date2.day, date2.month - 1, date2.year - 1900};  // years since 1900

    std::time_t time1 = std::mktime(&tm1);
    std::time_t time2 = std::mktime(&tm2);

    const int seconds_per_day = 60 * 60 * 24;

    // Return difference in days, positive if date1 > date2, negative if date1 < date2
    return static_cast<int>(std::difftime(time1, time2) / seconds_per_day);
}

int dateDifference(const std::string& date1, const std::string& date2) {
    Date d1 = parseDate(date1);
    Date d2 = parseDate(date2);

    return daysBetween(d2, d1);  // Switch d1 and d2 to get correct sign
}

// int main() {
//     std::string date1 = "2023:09:01";
//     std::string date2 = "2023:08:25";

//     int diff = dateDifference(date1, date2);
//     std::cout << "Difference in days: " << diff << std::endl;

//     return 0;
// }

class Event{
public:
    string event_name;
    string venue_name;
    string country;
    string date;
    string start_time;
    string end_time;
    Event(string event_name,string venue_name, string country, string date,string start_time,string end_time){
        this->event_name=event_name;
        this->venue_name=venue_name;
        this->country=country;
        this->date=date;
        this->start_time=start_time;
        this->end_time=end_time;
    }
    void display(){
        cout<<venue_name<<" "<<country<<" "<<date<<endl;
    }
};
class Congregation{
public:
    string name;
    string type;
    string start_date;
    string end_date;
    vector <Event> events;
    Congregation(string congregation_name,string congregation_type, string s_date, string e_date){
        name=congregation_name;
        type=congregation_type;
        start_date=s_date;
        end_date=e_date;
        events={};
    }
    void display(){
        cout<<name<<" "<<type<<" "<<start_date<<" "<<end_date<<endl;
    }
};
class Venue{
public:
    string venue_name;
    string state;
    string city;
    string postal;
    string country;
    string capacity;
    string location_address;
    vector <Congregation> cong;
    Venue(string vname,string sstate,string scity,string spostal,string scountry,string cap,string location_add){
        venue_name=vname;
        state=sstate;
        city=scity;
        postal=spostal;
        country=scountry;
        capacity=cap;
        cong={};
        location_address=location_add;
    }
    void display(){
        cout<<venue_name<<" "<<location_address<<":"<<city<<":"<<state<<":"<<postal<<":"<<country<<" "<<capacity<<endl;
    }
};


class Reservation{
public:
    string venue_name;
    string congregation_name;
    string country_name;
    string start_date;
    string end_date;
    string capacity;
    string location;
    Reservation(string vname,string cname,string con_name,string sdate,string edate,string cap,string l){
        venue_name=vname;
        congregation_name=cname;
        country_name=con_name;
        start_date=sdate;
        end_date=edate;
        capacity=cap;
        location=l;
    }
    void display(){
        cout<<venue_name<<" "<<location<<" "<<capacity<<endl;
    }
}; 
int date_comparator(int year1,int month1,int date1,int year2 ,int month2,int date2){
    if(year1<year2){
        return 1;
    }
    else if(year2<year1){
        return 2;
    }
    else{
        if(month1<month2){
            return 1;
        }
        else if(month2<month1){
            return 2;
        }
        else{
            if(date1<date2){
                return 1;
            }
            else if(date2<date1){
                return 2;
            }
            else{
                return 0;
            }
        }
    }
    return 0;
}

int leap_year_checker(int year){
    int val=year/1000;
    if(val*1000==year){
        if(year%400==0){
            return 1;
        }
        else{
            return -1;
        }
    }
    else{
        if(year%4==0){
            return 1;
        }
        else{
            return -1;
        }
    }
}


int date_verifier(string current_date){
    int start_year,start_month,start_date;
    int year,month,date;
    string temp="";
    temp+=current_date[0];
    temp+=current_date[1];
    temp+=current_date[2];
    temp+=current_date[3];
    start_year=stoi(temp);
    temp="";
    temp+=current_date[5];
    temp+=current_date[6];
    start_month=stoi(temp);
    temp="";
    temp+=current_date[8];
    temp+=current_date[9];
    start_date=stoi(temp);
    int dyear=2024;
    int dmonth=8;
    int ddate=30;
    date=start_date;
    // if(date_comparator())
    if(start_month==2){
        if(leap_year_checker(year)==1){
            if(date<=29 && date>=1){
                return 1;
            }
            else{
                return -1;
            }
        }
        else{
            if(date<=28 && date>=1){
                return 1;
            }
            else{
                return -1;
            }
        }
    }
    else if(start_month==1 || start_month==3 || start_month==5 || start_month==7 || start_month==8 || start_month==10 || start_month==12){
        if(date<=31 && date>=1){
            return 1;
        }
        else{
            return -1;
        }
    }
    else if(start_month==4 || start_month==6 || start_month==9 || start_month==11){
        if(date<=30 && date>=1){
            return 1;
        }
        else{
            return -1;
        }
    }
    return 0;
}

int start_end_verifier(string date1,string date2){
    // cout<<"start end verifier called"<<endl;
    int val=date_verifier(date1);
    if(val==-1){
        // cout<<"date1 is not correct"<<endl;
        return -1;
    }
    val=date_verifier(date2);
    if(val==-1){
        // cout<<"date2 is not correct"<<endl;
        return -1;
    }
    int start_year,start_month,start_date;
    int end_year,end_month,end_date;
    string temp="";
    temp+=date1[0];
    temp+=date1[1];
    temp+=date1[2];
    temp+=date1[3];
    start_year=stoi(temp);
    temp="";
    temp+=date1[5];
    temp+=date1[6];
    start_month=stoi(temp);
    temp="";
    temp+=date1[8];
    temp+=date1[9];
    start_date=stoi(temp);
    temp="";
    temp+=date2[0];
    temp+=date2[1];
    temp+=date2[2];
    temp+=date2[3];
    end_year=stoi(temp);
    temp="";
    temp+=date2[5];
    temp+=date2[6];
    end_month=stoi(temp);
    temp="";
    temp+=date2[8];
    temp+=date2[9];
    end_date=stoi(temp);
    val=date_comparator(start_year,start_month,start_date,end_year,end_month,end_date);
    if(val==2 || val==0){
        // cout<<"date cannot exists together"<<endl;
        return -1;
    }
    // else{
    //     return 1;
    // }
    int dyear=2024;
    int dmonth=8;
    int ddate=30;
    if(date_comparator(start_year,start_month,start_date,dyear,dmonth,ddate)==1){
        return -1;
    }
    return 1;
}

// int greater_time
vector <int> date_diff(string date1,string date2){
    int start_year,start_month,start_date;
    int end_year,end_month,end_date;
    string temp="";
    temp+=date1[0];
    temp+=date1[1];
    temp+=date1[2];
    temp+=date1[3];
    start_year=stoi(temp);
    temp="";
    temp+=date1[5];
    temp+=date1[6];
    start_month=stoi(temp);
    temp="";
    temp+=date1[8];
    temp+=date1[9];
    start_date=stoi(temp);
    temp="";
    temp+=date2[0];
    temp+=date2[1];
    temp+=date2[2];
    temp+=date2[3];
    end_year=stoi(temp);
    temp="";
    temp+=date2[5];
    temp+=date2[6];
    end_month=stoi(temp);
    temp="";
    temp+=date2[8];
    temp+=date2[9];
    end_date=stoi(temp);
    vector <int> v(3);
    v[0]=start_year-end_year;
    v[1]=start_month-end_month;
    v[2]=start_date-end_date;
    return v;
}

int dates_days_difference(string date1, string date2){
    int start_year,start_month,start_date;
    int end_year,end_month,end_date;
    string temp="";
    temp+=date1[0];
    temp+=date1[1];
    temp+=date1[2];
    temp+=date1[3];
    start_year=stoi(temp);
    temp="";
    temp+=date1[5];
    temp+=date1[6];
    start_month=stoi(temp);
    temp="";
    temp+=date1[8];
    temp+=date1[9];
    start_date=stoi(temp);
    temp="";
    temp+=date2[0];
    temp+=date2[1];
    temp+=date2[2];
    temp+=date2[3];
    end_year=stoi(temp);
    temp="";
    temp+=date2[5];
    temp+=date2[6];
    end_month=stoi(temp);
    temp="";
    temp+=date2[8];
    temp+=date2[9];
    end_date=stoi(temp);

}
int time_verifier(string time){
    string temp="";
    int hour,min;
    temp+=time[0];
    temp+=time[1];
    hour=stoi(temp);
    temp="";
    temp+=time[3];
    temp+=time[4];
    min=stoi(temp);
    if(hour){

    }
}

vector <int> time_diff(int hour1,int min1,int hour2,int min2){
    vector <int> v(2);
    // if(hour)
    v[0]=hour1-hour2;
    v[1]=min1-min2;
    return v;
}
void add_Venue(vector <Venue>&venue_list,string vname,string location,string capacity){
    // cout<<"Eneter the add venue"<<endl;
    // cout<<"location: "<<location<<endl;
    // cout<<capacity<<endl;
    int found=0;
    int ind=0;
    string city="";
    string state="";
    string postal="";
    string country="";
    string location_address="";
    while(location[ind]!=':'){
        location_address+=location[ind];
        ind++;
    }
    ind++;
    while(location[ind]!=':'){
        city+=location[ind];
        ind++;
    }
    ind++;
    while(location[ind]!=':'){
        state+=location[ind];
        ind++;
    }
    ind++;
    while(location[ind]!=':'){
        postal+=location[ind];
        ind++;
    }
    ind++;
    while(ind<location.size() && location[ind]!=':'){
        country+=location[ind];
        ind++;
    }
    for(int i=0;i<venue_list.size();i++){
        if(venue_list[i].venue_name==vname && venue_list[i].country==country){
            found=1;
            break;
        }
    }
    if(found==1){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"venue aldready exists";
        return;
    }
    // cout<<"location_address: "<<location_address<<endl;
    // cout<<"city: "<<city<<endl;
    // cout<<"state: "<<state<<endl;
    // cout<<"postal: "<<postal<<endl;
    // cout<<"country: "<<country<<endl;
    Venue ven(vname,state,city,postal,country,capacity,location_address);
    // string vname,string sstate,string scity,string spostal,string scountry,string cap  --->actual arguments list of the venue constructor
    venue_list.push_back(ven);
    cout<<0<<endl;
    // return 0;
    return;
}
void show_Venues(vector <Venue> &venue_list,string location){
    // string location_address="";
    string city="";
    string state="";
    string postal="";
    string country="";
    int ind=0;
    // while(location[ind]!=':'){
    //     location_address+=location[ind];
    //     ind++;
    // }
    // ind++;
    ind++;
    while(location[ind]!=':'){
        city+=location[ind];
        ind++;
    }
    ind++;
    while(location[ind]!=':'){
        state+=location[ind];
        ind++;
    }
    ind++;
    while(location[ind]!=':'){
        postal+=location[ind];
        ind++;
    }
    ind++;
    while(ind<location.size() && location[ind]!='\"'){
        country+=location[ind];
        ind++;
    }
    // cout<<"location_address: "<<location_address<<endl;
    // cout<<"city: "<<city<<endl;
    // cout<<"state: "<<state<<endl;
    // cout<<"postal: "<<postal<<endl;
    // cout<<"country: "<<country<<endl;
    int cnt=0;

    if(city!="" && state!="" && postal=="" && country!=""){
        // cout<<"first condition satisfied"<<endl;
        for(int i=0;i<venue_list.size();i++){
            // cout<<venue_list[i].city<<" "<<city<<endl;
            // cout<<venue_list[i].state<<" "<<state<<endl;
            // cout<<venue_list[i].country<<" "<<country<<endl;
            if(venue_list[i].city==city && venue_list[i].state==state && venue_list[i].country==country){
                // arr[i].display();
                cnt++;
            }

        }
    }
    else if(city=="" && state=="" && postal!="" && country!=""){
        // cout<<"2 condition satisfied"<<endl;
        for(int i=0;i<venue_list.size();i++){
            if(venue_list[i].postal==postal && venue_list[i].country==country){
                // arr[i].display();
                cnt++;
            }
        }
    }
    else if(city!="" && state!="" && postal!="" && country!=""){
        // cout<<"3 condition satisfied"<<endl;
        for(int i=0;i<venue_list.size();i++){
            if(venue_list[i].city==city && venue_list[i].state==state && venue_list[i].postal==postal && venue_list[i].country==country){
                // arr[i].display();
                cnt++;
            }
        }
    }
    else if(city=="" && state=="" && postal=="" && country!=""){
        // cout<<"4 condition satisfied"<<endl;
        for(int i=0;i<venue_list.size();i++){
            if(venue_list[i].country==country){
                // arr[i].display();
                cnt++;
            }
        }
    }
    else{
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        return;
    }
    cout<<cnt<<endl;
    if(city!="" && state!="" && postal=="" && country!=""){
        for(int i=0;i<venue_list.size();i++){
            if(venue_list[i].city==city && venue_list[i].state==state && venue_list[i].country==country){
                venue_list[i].display();
            }

        }
    }
    else if(city=="" && state=="" && postal!="" && country!=""){
        for(int i=0;i<venue_list.size();i++){
            if(venue_list[i].postal==postal && venue_list[i].country==country){
                venue_list[i].display();
            }
        }
    }
    else if(city!="" && state!="" && postal!="" && country!=""){
        for(int i=0;i<venue_list.size();i++){
            if(venue_list[i].city==city && venue_list[i].state==state && venue_list[i].postal==postal && venue_list[i].country==country){
                venue_list[i].display();
            }
        }
    }
    else if(city=="" && state=="" && postal=="" && country!=""){
        for(int i=0;i<venue_list.size();i++){
            if(venue_list[i].country==country){
                venue_list[i].display();
            }
        }
    }
    return;
}

void delete_Venue(vector <Venue> &venue_list,vector <Reservation>&reserves,vector <Congregation> &cong,string vname,string country_name){
    // time_t now = time(nullptr);
    // tm* localTime = localtime(&now);
    // // string current_date="";
    // int current_year=(localTime->tm_year + 1900);
    // int current_month=(localTime->tm_mon + 1);
    // int current_date=localTime->tm_mday;
    int exists=0;
    for(int i=0;i<venue_list.size();i++){
        if(venue_list[i].venue_name==vname && venue_list[i].country==country_name){
            exists=1;
            break;
        }
    }
    if(exists==0){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        return;
    }
    int found=0;
    for(int i=0;i<reserves.size();i++){
        // cout<<reserves[i].venue_name<<" "<<vname<<endl;
        // cout<<reserves[i].country_name<<" "<<country_name<<endl;
        if(reserves[i].venue_name==vname && reserves[i].country_name==country_name){
            found=1;
            break;
        }
    }
    if(found==1){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"Reservation still exists with respect to the congregation"<<endl;
        return;
    }
    // for(int i=0;i<reserves.size();i++){
    //     if(reserves[i].venue_name==vname && reserves[i].country_name==country_name){
    //         int temp_start_year,temp_start__month,temp_start_date;
    //         int temp_end_year,temp_end__month,temp_end_date;
    //         string temp_string="";
    //         temp_string+=(reserves[i].start_date[0]+reserves[i].start_date[1]+reserves[i].start_date[2]+reserves[i].start_date[3]);
    //         temp_start_year=stoi(temp_string);
    //         temp_string="";
    //         temp_string=reserves[i].start_date[5]+reserves[i].start_date[6];
    //         temp_start__month=stoi(temp_string);
    //         temp_string="";
    //         temp_string=reserves[i].start_date[8]+reserves[i].start_date[9];
    //         temp_start_date=stoi(temp_string);
    //         //some random values here
    //         //hree
    //         ///wg\w
    //         //wgwreg/rg
    //         temp_string="";
    //         temp_string+=(reserves[i].end_date[0]+reserves[i].end_date[1]+reserves[i].end_date[2]+reserves[i].end_date[3]);
    //         temp_start_year=stoi(temp_string);
    //         temp_string="";
    //         temp_string=reserves[i].end_date[5]+reserves[i].end_date[6];
    //         temp_start__month=stoi(temp_string);
    //         temp_string="";
    //         temp_string=reserves[i].end_date[8]+reserves[i].end_date[9];
    //         temp_start_date=stoi(temp_string);
    //         int val=date_comparator(current_year,current_month,current_date,temp_start_year,temp_start__month,temp_start_date);
    //         int val1=date_comparator(current_year,current_month,current_date,temp_end_year,temp_end__month,temp_end_date);
    //         if(val==1 || val1==1){
    //             found=1;
    //             break;
    //         }
    //     }
    // }
    // if(found==1){
    //     cout<<-1<<endl;
    //     cout<<"Error"<<endl;
    //     cout<<"there is still some resevation for the congrefation"<<endl;
    //     return;
    // }
    int ind1=0;
    for(int i=0;i<venue_list.size();i++){
        if(venue_list[i].venue_name==vname){
            ind1=i;
            break;
        }
    }
    venue_list.erase(venue_list.begin()+ind1);
    int ind2=0;
    // for(int i=0;i<cong.size();i++){
    //     if(cong[i].c_venues==)
    // }
    cout<<0<<endl;
    return;
}


void add_Event(vector <Venue> &venue_list,vector <Reservation>&reserves,string congregation_name,string vname,string country,string sdate,string start_time, string end_time,string ename){
    int found=0;
    int ind=0;
    // cout<<start_time<<endl;
    for(int i=0;i<reserves.size();i++){
        if(reserves[i].congregation_name==congregation_name && reserves[i].venue_name==vname && reserves[i].country_name==country){
            found=1;
            // ind=i;
            break;
        }
    }
    if(found==0){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"Event cannot be added as there are no reservations for this venue"<<endl;
        return;
    }
    for(int i=0;i<venue_list.size();i++){
        if(venue_list[i].venue_name==vname && venue_list[i].country==country){
            ind=i;
            break;
        }
    }

    int ind1=0;
    for(int i=0;i<venue_list[ind].cong.size();i++){
        if(venue_list[ind].cong[i].name==congregation_name){
            ind1=i;
            break;
        }
    }
    int dd1=dateDifference(venue_list[ind].cong[ind1].start_date,sdate);
    // cout<<"FIRST CHECKPOINT"<<endl;
    if(dd1<0){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"as the dates do match"<<endl;
        return;
    }
    int dd2=dateDifference(venue_list[ind].cong[ind1].end_date,sdate);
    // cout<<"printing the value of temp "<<start_time<<endl;
    if(dd2>0){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"as the dates do match"<<endl;
        return;
    }
    string temp="";
    temp+=start_time[0];
    temp+=start_time[1];
    int start_hour=stoi(temp);
    temp="";
    temp+=start_time[3];
    temp+=start_time[4];
    int start_min=stoi(temp);
    temp="";
    temp+=end_time[0];
    temp+=end_time[1];
    int end_hour=stoi(temp);
    temp="";
    temp+=end_time[3];
    temp+=end_time[4];
    int end_min=stoi(temp);
    // cout<<"FIRST CHECKPOINT CLEARED"<<endl;
    vector <int> tdiff=time_diff(start_hour,start_min,end_hour,end_min);
    int possible=1;
    if(tdiff[0]==0){
        if(tdiff[1]>=0){
            possible=0;
        }
        else if(tdiff[1]<0){
            tdiff[1]=tdiff[1]*-1;
            if(tdiff[1]<30){
                possible=0;
            }
        }
    }
    else if(tdiff[0]>0){
        possible=0;
    }
    else if(tdiff[0]<0){
        if(start_min==45 && end_min==0){
            possible=0;
        }
    }
    // else if(end_hour==0){

    // }
    if(start_min%15!=0 || end_min%15!=0){
        possible=0;
    }
    if(start_min>59 || start_min<0 || end_min>59 || end_min<0){
        possible=0;
    }
    if(possible==0){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"problem with time format"<<endl;
        return;
    }
    for(int i=0;i<venue_list[ind].cong[ind1].events.size();i++){
        string temp1="";
        // vector <int> v=date_diff(venue_list[ind].cong[ind1].events[i].date,sdate);
        temp1+=venue_list[ind].cong[ind1].events[i].start_time[0];
        temp1+=venue_list[ind].cong[ind1].events[i].start_time[1];
        int temp_hour=stoi(temp1);
        temp1="";
        temp1+=venue_list[ind].cong[ind1].events[i].start_time[3];
        temp1+=venue_list[ind].cong[ind1].events[i].start_time[4];
        int temp_min=stoi(temp1);
        temp1="";
        temp1+=venue_list[ind].cong[ind1].events[i].end_time[0];
        temp1+=venue_list[ind].cong[ind1].events[i].end_time[1];
        int temp_end_hour=stoi(temp1);
        temp1="";
        temp1+=venue_list[ind].cong[ind1].events[i].end_time[3];
        temp1+=venue_list[ind].cong[ind1].events[i].end_time[4];
        int temp_end_min=stoi(temp1);
        // if(v[0]==0 && v[1])
        // cout<<venue_list[ind].cong[ind1].events[i].date<<" "<<sdate<<endl;
        int diff = dateDifference(venue_list[ind].cong[ind1].events[i].date,sdate);
        // cout<<"the value of diff is: "<<diff<<endl;
        if(diff==-1){
            if(temp_hour==0 && temp_min<15 && end_hour==23 && end_min==45){
                possible=0;
                break;
            }
            else if(temp_hour==0 && temp_min==15 && end_hour==24 && end_min==0){
                possible=0;
                break;
            }
        }
        else if(diff==1){
            if(temp_end_hour==23 && temp_end_min==45 && start_hour==0 && start_min<15){
                possible=0;
                break;
            }
            else if(temp_end_hour==23 && temp_end_min>30 && start_hour==0 && start_min==0){
                possible=0;
                break;
            }
        }
        else if(diff==0){
            
            if(venue_list[ind].cong[ind1].events[i].date==sdate){
                // cout<<"SECOND CHECKPOINT CLEATRED"<<endl;
                // cout<<"SECOND CHECKPOINT CLEARED"<<endl;
                vector <int> start_time_diff=time_diff(temp_hour,temp_min,start_hour,start_min);
                vector <int> end_time_diff=time_diff(end_hour,end_min,temp_end_hour,temp_end_min);
                vector <int> start_end_time_diff=time_diff(temp_end_hour,temp_end_min,start_hour,start_min);
                vector <int> end_start_time_diff=time_diff(temp_hour,temp_min,end_hour,end_min);
                vector <int> end_start_time_diff2=time_diff(end_hour,end_min,temp_hour,temp_min);
                // if(venue_list[ind].cong[ind1].events[i].){
                // }
                // vector <int> v1=date_diff(venue_list[ind].cong[ind1].events[i].date,sdate);
                // if(v1[0]==0 && v1[1]==0 && v1[2]==-1){

                // }
                // else if(v1[0]==0 && v1[1]==0 && v1[2]==1){

                // }
                // else if(v1[0]==0 && v1[1]==1 && v1[2]==){

                // }
                // else if(v1[0]==0 && v1[1]==-1 &&  ){

                // }
                if(start_time_diff[0]<0 ||  (start_time_diff[0]==0 &&  start_time_diff[1]<0)){
                    // cout<<"CHECKER1"<<endl;
                    // cout<<"CHECKER1"<<endl;
                    // cout<<"CHECKER1"<<endl;
                    // cout<<"CHECKER1"<<endl;
                    if(start_end_time_diff[0]>0 || (start_end_time_diff[0]==0 &&  start_end_time_diff[1]>0)){
                        // cout<<"ABCD"<<endl;
                        possible=0;
                        break;
                    }
                }
                if(start_end_time_diff[0]<0 || (start_end_time_diff[0]==0 && start_end_time_diff[1]<0) || start_hour==0){
                    // cout<<"CHECKER2"<<endl;
                    // cout<<"CHECKER2"<<endl;
                    // cout<<"CHECKER2"<<endl;
                    // cout<<"CHECKER2"<<endl;
                    // cout<<"hour:min of the end of the events: "<<temp_end_hour<<" "<<temp_end_min<<endl;
                    // cout<<"hour:min of the starting event to be added: "<<start_hour<<" "<<start_min<<endl;
                    
                    if(start_end_time_diff[0]==0 && venue_list[ind].cong[ind1].events[i].date==sdate){
                        int ins=start_end_time_diff[1]*-1;
                        if(ins<30){
                            possible=0;
                            // cout<<"6789"<<endl;
                            break;
                        }
                    }
                    else if(start_end_time_diff[0]==-1){
                        // int num;
                        // num=temp_end_min%60;
                        // vector <int> v=date_diff(venue_list[ind].cong[ind1].events[i].date,sdate);
                        if(temp_end_min==45 && start_min<15){
                            possible=0;
                            // cout<<"98765"<<endl;
                            break;
                        }
                        else if(temp_end_min==30 && (start_min>30 && start_min<=0)){
                            possible=0;
                            // cout<<"321"<<endl;
                            break;
                        }
                    }
                    // else if(temp_end_hour==23 && start_hour==0 && venue_list[ind].cong[ind1].events[i].date!=sdate){
                    //     vector <int> v=date_diff(venue_list[ind].cong[ind1].events[i].date,sdate);

                    //     if(temp_end_min==45 && start_min<15 && v[0]==0 && v[1]==0 && v[2]==-1){
                    //         possible=0;
                    //         cout<<"4321"<<endl;
                    //         break;
                    //     }
                    //     else if(temp_end_min==30 && (start_min>30 && start_min<59) && v[0]==0 && v[1]==0 && v[2]==0){
                    //         possible=0;
                    //         cout<<"123456"<<endl;
                    //         break;
                    //     }
                    // }
                }
                if(end_start_time_diff2[0]<0 || (end_start_time_diff2[0]==0 && end_start_time_diff2[1]<0)){   
                    // cout<<"CHECKER3"<<endl;
                    // cout<<"CHECKER3"<<endl;
                    // cout<<"CHECKER3"<<endl;
                    // cout<<"CHECKER3"<<endl;
                    if(end_start_time_diff2[0]==0){
                        int ins=end_start_time_diff2[1]*-1;
                        if(ins<30){
                            possible=0;
                            // cout<<"123"<<endl;
                            break;
                        }
                    }
                    if(end_min==45 && end_start_time_diff2[0]==-1){
                        if(temp_min<15){
                            possible=0;
                            // cout<<"1234"<<endl;
                            break;
                        }
                    }
                }
                if(end_time_diff[0]<0 || (end_time_diff[0]==0 && end_time_diff[1]<0)){
                    // cout<<"CHECKER4"<<endl;
                    // cout<<"CHECKER4"<<endl;
                    // cout<<"CHECKER4"<<endl;
                    // cout<<"CHECKER4"<<endl;
                    if(venue_list[ind].cong[ind1].events[i].date==sdate && (end_start_time_diff[0]<0 || (end_start_time_diff[0]==0 && end_start_time_diff[1]<0))){
                        possible=0;
                        // cout<<"printing the dates"<<endl;
                        // cout<<"printing the date that aldready exists: "<<venue_list[ind].cong[ind1].events[i].date<<endl;
                        // cout<<"printing the date to be added: "<<sdate<<endl;
                        // cout<<"-------------------------------------------------"<<endl;
                        // cout<<temp_hour<<" "<<temp_min<<" "<<start_hour<<" "<<start_min<<endl;
                        // cout<<end_hour<<" "<<end_min<<" "<<temp_end_hour<<" "<<temp_end_min<<endl;
                        // cout<<temp_end_hour<<" "<<temp_end_min<<" "<<start_hour<<" "<<start_min;
                        // cout<<"timing of the event to be added: "<<start_hour<<" "<<start_min<<" "<<end_hour<<" "<<end_min<<endl;
                        // cout<<"the timing of the events that aldready exists: "<<temp_hour<<" "<<temp_min<<" "<<temp_end_hour<<" "<<temp_end_min<<endl;
                        // cout<<end_hour<<" "<<end_min<<" "<<temp_end_hour<<" "<<temp_end_min<<endl;
                        // cout<<temp_hour<<" "<<temp_min<<" "<<end_hour<<" "<<end_min<<endl;
                        // cout<<"12345"<<endl;
                        break;
                    }
                }
            }
        }
    }
    // if(start_hour>end_hour){
    //     possible=2;
    //     // Event ev();
    // }
    if(possible==0){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"some of the dates are time interval are overlapping"<<endl;
        return;
    }
    // venue_list[ind].cong[ind1].events
    int year,month,date;
    // cout<<"THIRD CHECKPOINT"<<endl;
    string s="";
    s+=sdate[0];
    s+=sdate[1];
    s+=sdate[2];
    s+=sdate[3];
    year=stoi(s);
    s="";
    s+=sdate[5];
    s+=sdate[6];
    month=stoi(s);
    s="";
    s+=sdate[8];
    s+=sdate[9];
    date=stoi(s);
    // cout<<"THIRD CHECKPOINT CLEARED"<<endl;
    // if(leap_year_checker(year)==1)
    if(month==2){
        if(leap_year_checker(year)==1){
            if(date>28 || date<1){
                possible=0;
            }
        }
        else{
            if(date>27 || date<1){
                possible=0;
            }
        }
    }
    else{
        if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
            if(date>31 || date<1){
                possible=0;
            }
        }
        else{
            if(date>30 || date<1){
                possible=0;
            }
        }
    }
    int ind3=venue_list[ind].cong[ind1].events.size();
    for(int i=0;i<venue_list[ind].cong[ind1].events.size();i++){
        string temp_string_date=venue_list[ind].cong[ind1].events[i].date;
        int temp_year,temp_month,temp_date;
        // cout<<"FOURTH CHECKPOINT"<<endl;
        string t="";
        t+=temp_string_date[0];
        t+=temp_string_date[1];
        t+=temp_string_date[2];
        t+=temp_string_date[3];
        temp_year=stoi(t);
        t="";
        t+=temp_string_date[5];
        t+=temp_string_date[6];
        temp_month=stoi(t);
        t="";
        t+=temp_string_date[8];
        t+=temp_string_date[9];
        temp_date=stoi(t);
        // cout<<"FOURTH CHECKPOINT CLEARED"<<endl;
        int val=date_comparator(temp_year,temp_month,temp_date,year,month,date);
        // if(start_hour==00){

        // }
        if(val==1){
            continue;
        }
        if(val==2){
            ind3=i;
            break;    
        }
        else if(val==0){
            // val==0;
            // cout<<"FIFTH CHECKPOINT"<<endl;
            string temp1="";
            temp1+=venue_list[ind].cong[ind1].events[i].start_time[0];
            temp1+=venue_list[ind].cong[ind1].events[i].start_time[1];
            int temp_hour=stoi(temp1);
            temp1="";
            temp1+=venue_list[ind].cong[ind1].events[i].start_time[3];
            temp1+=venue_list[ind].cong[ind1].events[i].start_time[4];
            int temp_min=stoi(temp1);
            temp1="";
            temp1+=venue_list[ind].cong[ind1].events[i].end_time[0];
            temp1+=venue_list[ind].cong[ind1].events[i].end_time[1];
            int temp_end_hour=stoi(temp1);
            temp1="";
            temp1+=venue_list[ind].cong[ind1].events[i].end_time[3];
            temp1+=venue_list[ind].cong[ind1].events[i].end_time[4];
            int temp_end_min=stoi(temp1);
            // cout<<"FIFTH CHECKPOINT CLEARED"<<endl;
            vector <int>diff=time_diff(temp_end_hour,temp_end_min,start_hour,start_min);
            if(diff[0]<0 || (diff[0]==0 && diff[1]<0)){
                continue;
            }   
            else{
                ind3=i;
                break;
            }
        }
    }

    //adding part begin done here
    //------------------------------------------
    if(ind3==venue_list[ind].cong[ind1].events.size()){
        if(possible==1){
            Event ev1(ename,vname,country,sdate,start_time,end_time);
            venue_list[ind].cong[ind1].events.push_back(ev1);
            // cout<<"event added"<<endl;
            // Event ev2(ename,);
        }
        // else if(possible==2){
        //     Event ev1(ename,vname,country,sdate,start_time,"23:59");
        //     Event ev2(ename,vname,country,sdate,"00:00",end_time);
        //     venue_list[ind].cong[ind1].events.push_back(ev1);
        //     venue_list[ind].cong[ind1].events.push_back(ev2);
        // }
    }
    else{
        if(possible==1){
            Event ev1(ename,vname,country,sdate,start_time,end_time);
            // cout<<"Event added"<<endl;
            venue_list[ind].cong[ind1].events.insert(venue_list[ind].cong[ind1].events.begin()+ind3,ev1);
        }
        // else if(possible==2){
        //     Event ev1(ename,vname,country,sdate,start_time,"23:59");
        //     Event ev2(ename,vname,country,sdate,"00:00",end_time);
        //     venue_list[ind].cong[ind1].events.insert(venue_list[ind].cong[ind1].events.begin()+ind3,ev1);
        //     venue_list[ind].cong[ind1].events.insert(venue_list[ind].cong[ind1].events.begin()+ind3+1,ev2);

        // }
    }
    cout<<0<<endl;
    return;
}

void delete_Event(vector <Venue> &venue_list,string congregation_name,string vname, string country,string date,string from_time, string ename){
    // cout<<"INSIDE THE DELETE EVENT FUNCTION NOW"<<endl;
    int found_venue=0;
    int found_congregation=0;
    int ind=0;
    int ind1=0;
    for(int i=0;i<venue_list.size();i++){
        // cout<<venue_list[i].venue_name<<" "<<vname<<endl;
        // cout<<venue_list[i].country<<" "<<country<<endl;
        if(venue_list[i].venue_name==vname && venue_list[i].country==country){
            found_venue=1;
            ind=i;
            break;
        }
    }
    if(found_venue==0){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"Venue not found"<<endl;
        return;
    }
    for(int i=0;i<venue_list[ind].cong.size();i++){
        // cout<<venue_list[ind].cong[i].name<<" :: "<<congregation_name<<endl;
        if(venue_list[ind].cong[i].name==congregation_name){
            found_congregation=1;
            ind1=i;
            break;
        }
    }
    if(found_congregation==0){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"Congregation not found"<<endl;
        return;
    }
    int found_event=0;
    int ind2=0;
    for(int i=0;i<venue_list[ind].cong[ind1].events.size();i++){
        if(venue_list[ind].cong[ind1].events[i].event_name==ename && venue_list[ind].cong[ind1].events[i].start_time==from_time && venue_list[ind].cong[ind1].events[i].date==date){
            ind2=i;
            found_event=1;
            break;
        }
    }
    if(found_event==0){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"Event not found"<<endl;
        return;
    }
    venue_list[ind].cong[ind1].events.erase(venue_list[ind].cong[ind1].events.begin()+ind2);
    cout<<0<<endl;
    return;
}

void show_Events(vector <Venue> &venue_list,string venue_name,string country,string date){
    int cnt=0;
    int found=0;
    int ind=0;
    for(int i=0;i<venue_list.size();i++){
        if(venue_list[i].venue_name==venue_name && venue_list[i].country==country){
            found=1;
            ind=i;
            break;
        }
    }
    if(found==0){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"venue does not exists"<<endl;
        return;
    }
    for(int i=0;i<venue_list[ind].cong.size();i++){
        for(int j=0;j<venue_list[ind].cong[i].events.size();j++){
            if(venue_list[ind].cong[i].events[j].date==date){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<venue_list[ind].cong.size();i++){
        for(int j=0;j<venue_list[ind].cong[i].events.size();j++){
            if(venue_list[ind].cong[i].events[j].date==date){
                cout<<venue_list[ind].cong[i].events[j].event_name<<" "<<venue_list[ind].cong[i].events[j].start_time<<" "<<venue_list[ind].cong[i].events[j].end_time<<endl;
            }
        }
    }
    return;
}


string next_date(string current_date){
    int start_year,start_month,start_date;
    int year,month,date;
    string temp="";
    temp+=current_date[0];
    temp+=current_date[1];
    temp+=current_date[2];
    temp+=current_date[3];
    start_year=stoi(temp);
    temp="";
    temp+=current_date[5];
    temp+=current_date[6];
    start_month=stoi(temp);
    temp="";
    temp+=current_date[8];
    temp+=current_date[9];
    start_date=stoi(temp);
    string s;
    year=start_year;
    month=start_month;
    date=start_date;
    if(start_month==12){
        if(start_date==31){
            year+=1;
            month=0;
            date=1;
        }
        else{
            date+=1;
        }
    }
    else if((start_month==1 || start_month==3 || start_month==5 || start_month==7 || start_month==8 || start_month==10)){
        if(start_date==31){
            date=1;
            month+=1;
        }
        else if(start_date!=31){
            date+=1;
        }
    }
    else if(start_month==4 || start_month==6 || start_month==9 || start_month==11){
        if(start_date==30){
            date=1;
            month+=1;
        }
        else{
            date+=1;
        }

    }
    else if(start_month==2){
        int val=leap_year_checker(start_year);
        if(val==1){
            if(start_date==28){
                date=1;
                month+=1;
            }
            else{
                date+=1;
            }
        }
        else if(val==-1){
            if(start_date==27){
                date=1;
                month+=1;
            }
            else{
                date+=1;
            }
        }
    }
    ostringstream oss;

    // Add the year
    oss << year << "-";

    // Add the month with leading zero if necessary
    if (month < 10) {
        oss << "0";
    }
    oss << month << "-";

    // Add the date with leading zero if necessary
    if (date < 10) {
        oss << "0";
    }
    oss << date;

    // Convert the stringstream to string
    s = oss.str();
    return s;
}

void show_Calendar(vector <Reservation>&reserves,vector <Venue>&venue_list,string congregation_name,string venue_name,string country){
    int found=0;
    int ind=0;
    for(int i=0;i<venue_list.size();i++){
        if(venue_list[i].venue_name==venue_name){
            found=1;
            ind=i;
            break;
        }
    }
    if(found==0){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"venue not found"<<endl;
        return;
    }
    int reservation_exists=0;
    for(int i=0;i<reserves.size();i++){
        if(reserves[i].venue_name==venue_name && reserves[i].congregation_name==congregation_name){
            reservation_exists=1;
            break;
        }
    }
    if(reservation_exists==0){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"reservation not found"<<endl;
        return;
    }
    string start_date_congregation="";
    string end_date_congregation="";
    int ind1=0;
    for(int i=0;i<venue_list[ind].cong.size();i++){
        // if(venue_list[ind].venue_name==venue_name && venue_list[ind].cong)
        if(venue_list[ind].cong[i].name==congregation_name){
            ind1=i;
            break;
        }
    }
    start_date_congregation=venue_list[ind].cong[ind1].start_date;
    end_date_congregation=venue_list[ind].cong[ind1].end_date;

    int final_counter=0;
    final_counter=venue_list[ind].cong[ind1].events.size();
    // for(int i=0;i<venue_list[ind].cong.size();i++){
    //     // cout<<venue_list[ind].cong[i].name<<endl;
    //     // cout<<"Now going to print the corresponding events"<<endl;
    //     vector <string> dates;
    //     for(int j=0;j<venue_list[ind].cong[i].events.size();j++){
    //         int present=0;
    //         for(int k=0;k<dates.size();k++){
    //             if(dates[k]==venue_list[ind].cong[i].events[j].date){
    //                 present=1;
    //                 break;
    //             }
    //         }
    //         if(present==0){
    //             dates.push_back(venue_list[ind].cong[i].events[j].date);
    //         }
    //     }
        // cout<<"printing the dates: "<<endl;
        // for(int i=0;i<dates.size();i++){
        //     cout<<dates[i]<<" ";
        // }
    vector <string> dates;
    int start_year,start_month,start_date;
    int end_year,end_month,end_date;
    string temp="";
    temp+=start_date_congregation[0];
    temp+=start_date_congregation[1];
    temp+=start_date_congregation[2];
    temp+=start_date_congregation[3];
    start_year=stoi(temp);
    temp="";
    temp+=start_date_congregation[5];
    temp+=start_date_congregation[6];
    start_month=stoi(temp);
    temp="";
    temp+=start_date_congregation[8];
    temp+=start_date_congregation[9];
    start_date=stoi(temp);
    temp="";
    temp+=end_date_congregation[0];
    temp+=end_date_congregation[1];
    temp+=end_date_congregation[2];
    temp+=end_date_congregation[3];
    end_year=stoi(temp);
    temp="";
    temp+=end_date_congregation[5];
    temp+=end_date_congregation[6];
    end_month=stoi(temp);
    temp="";
    temp+=end_date_congregation[8];
    temp+=end_date_congregation[9];
    end_date=stoi(temp);
    // string ndate;
    string current_date=start_date_congregation;
    while(true){
        int temp_year,temp_month,temp_date;
        string st="";
        st+=current_date[0];
        st+=current_date[1];
        st+=current_date[2];
        st+=current_date[3];
        temp_year=stoi(st);
        st="";
        st+=current_date[5];
        st+=current_date[6];
        temp_month=stoi(st);
        st="";
        st+=current_date[8];
        st+=current_date[9];
        temp_date=stoi(st);
        // cout<<temp_year<<" "<<temp_month<<" "<<temp_date<<" "<<end_year<<" "<<end_month<<" "<<end_date<<endl;
        if(date_comparator(temp_year,temp_month,temp_date,end_year,end_month,end_date)==1 || date_comparator(temp_year,temp_month,temp_date,end_year,end_month,end_date)==0){
            dates.push_back(current_date);
        }
        else{
            break;
        }
        current_date=next_date(current_date);
        // cout<<"received from the funciton: "<<current_date<<endl;
    }

    // for(int m=0;m<dates.size();m++){
    //     // cout<<dates[m]<<" ";
    //     int count=0;
    //     for(int n=0;n<venue_list[ind].cong[i].events.size();n++){
    //         if(venue_list[ind].cong[i].events[n].date==dates[m]){
    //             count++;
    //         }
    //     }
    //     final_counter+=count;
    //     // cout<<count<<endl;
    //     // if(count==0){
    //     //     cout<<"NULL"<<endl;
    //     // }
    //     // else{
    //     //     for(int n=0;n<venue_list[ind].cong[i].events.size();n++){
    //     //         if(venue_list[ind].cong[i].events[n].date==dates[m]){
    //     //             cout<<venue_list[ind].cong[i].events[n].event_name<<" "<<venue_list[ind].cong[i].events[n].start_time<<" "<<venue_list[ind].cong[i].events[n].end_time<<endl;
    //     //         }
    //     //     }   
    //     // }
    // }
    // }




    cout<<final_counter<<endl;

    for(int i=0;i<dates.size();i++){
        int temp_cnt=0;
        cout<<dates[i]<<" ";
        for(int j=0;j<venue_list[ind].cong[ind1].events.size();j++){
            if(venue_list[ind].cong[ind1].events[j].date==dates[i]){
                temp_cnt++;
            }
        }
        cout<<temp_cnt<<endl;
        for(int j=0;j<venue_list[ind].cong[ind1].events.size();j++){
            if(venue_list[ind].cong[ind1].events[j].date==dates[i]){
                cout<<venue_list[ind].cong[ind1].events[j].event_name<<" "<<venue_list[ind].cong[ind1].events[j].start_time<<" "<<venue_list[ind].cong[ind1].events[j].end_time<<endl;
            }
        }
    }
    return;
}

void add_Congregation(vector <Congregation>&congregation_list,string congregation_name,string congregation_type,string start_date,string end_date){
    int found=0;
    for(int i=0;i<congregation_list.size();i++){
        if(congregation_list[i].name==congregation_name && congregation_list[i].type==congregation_type){
            found=1;
            break;
        }
    }
    if(found==1){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"congregation aldready exists"<<endl;
        return;
    }
    Congregation cong(congregation_name,congregation_type,start_date,end_date); 
    congregation_list.push_back(cong);
    cout<<0<<endl;
    return;
}
void delete_Congregation(vector <Congregation>&congregation_list,vector <Reservation>&reserves,string congregation_name){
    int found=0;
    int ind3=0;
    for(int i=0;i<congregation_list.size();i++){
        // cout<<congregation_list[i].name<<" :: "<<congregation_name<<endl;
        if(congregation_list[i].name==congregation_name){
            found=1;
            ind3=i;
            break;
        }
    }
    if(found==0){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"Congregaator not found"<<endl;
        return;
    }
    congregation_list.erase(congregation_list.begin()+ind3);
    vector <int> indices;
    for(int i=reserves.size()-1;i>=0;i--){
        if(reserves[i].congregation_name==congregation_name){
            indices.push_back(i);
        }
    }
    for(int i=0;i<indices.size();i++){
        reserves.erase(reserves.begin()+indices[i]);
    }
    cout<<0<<endl;
    return;
}

void show_Congregation(vector <Congregation>&congregation_list){
    cout<<congregation_list.size()<<endl;
    for(int i=0;i<congregation_list.size();i++){
        congregation_list[i].display();
    }
    return;
}

void reserve_Venue(vector <Reservation>&reserves,vector <Congregation>&congregation_list,vector <Venue>&venue_list,string vname,string country,string congregation_name){
    int found=0;
    for(int i=0;i<reserves.size();i++){
        if(reserves[i].congregation_name==congregation_name && reserves[i].venue_name==vname && reserves[i].country_name==country){
            found=1;
            break;
        }
    }
    if(found==1){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"Aldready reserved"<<endl;
        return;
    }
    int venue_exist=0;
    string capa;
    string l="";
    for(int i=0;i<venue_list.size();i++){
        if(venue_list[i].venue_name==vname && venue_list[i].country==country){
            capa=venue_list[i].capacity;
            l+=venue_list[i].location_address+":"+venue_list[i].city+":"+venue_list[i].state+":"+venue_list[i].postal+":"+venue_list[i].country;
            venue_exist=1;
            break;
        }
    }
    if(venue_exist==0){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"venue doesnt exist"<<endl;
        return;
    }
    int congregation_exist=0;
    for(int i=0;i<congregation_list.size();i++){
        if(congregation_list[i].name==congregation_name){
            congregation_exist=1;
            break;
        }
    }
    if(congregation_exist==0){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"congregation doesnt exist"<<endl;
        return;
    }
    int ind=0;
    for(int i=0;i<congregation_list.size();i++){
        if(congregation_list[i].name==congregation_name){
            ind=i;
            break;
        }
    }
    string ayear="";
    string amonth="";
    string adate="";
    string end_ayear="";
    string end_amonth="";
    string end_adate="";
    ayear += congregation_list[ind].start_date[0];
    ayear += congregation_list[ind].start_date[1];
    ayear += congregation_list[ind].start_date[2];
    ayear += congregation_list[ind].start_date[3];
    amonth += congregation_list[ind].start_date[5];
    amonth += congregation_list[ind].start_date[6];
    adate += congregation_list[ind].start_date[8];
    adate += congregation_list[ind].start_date[9];
    end_ayear += congregation_list[ind].end_date[0];
    end_ayear += congregation_list[ind].end_date[1];
    end_ayear += congregation_list[ind].end_date[2];
    end_ayear += congregation_list[ind].end_date[3];
    end_amonth += congregation_list[ind].end_date[5];
    end_amonth += congregation_list[ind].end_date[6];
    end_adate += congregation_list[ind].end_date[8];
    end_adate += congregation_list[ind].end_date[9];

    int year=stoi(ayear);
    int month=stoi(amonth);
    int date=stoi(adate);
    int end_year=stoi(end_ayear);
    int end_month=stoi(end_amonth);
    int end_date=stoi(end_adate);
    int possible=1;
    string temp_year="";
    string temp_month="";
    string temp_date="";
    int int_year;
    int int_month;
    int int_date;
    string temp_end_year="";
    string temp_end_month="";
    string temp_end_date="";
    int int_end_year;
    int int_end_month;
    int int_end_date;
    for(int i=0;i<reserves.size();i++){
        if(reserves[i].venue_name==vname && reserves[i].country_name==country){
            temp_year="";
            temp_month="";
            temp_date="";
            temp_end_year="";
            temp_end_month="";
            temp_end_date="";
            temp_year+=reserves[i].start_date[0];
            temp_year+=reserves[i].start_date[1];
            temp_year+=reserves[i].start_date[2];
            temp_year+=reserves[i].start_date[3];
            temp_month+=reserves[i].start_date[5];
            temp_month+=reserves[i].start_date[6];
            temp_date+=reserves[i].start_date[8];
            temp_date+=reserves[i].start_date[9];
            temp_end_year+=reserves[i].end_date[0];
            temp_end_year+=reserves[i].end_date[1];
            temp_end_year+=reserves[i].end_date[2];
            temp_end_year+=reserves[i].end_date[3];
            temp_end_month+=reserves[i].end_date[5];
            temp_end_month+=reserves[i].end_date[6];
            temp_end_date+=reserves[i].end_date[8];
            temp_end_date+=reserves[i].end_date[9];
            int_year=stoi(temp_year);
            int_month=stoi(temp_month);
            int_date=stoi(temp_date);
            int_end_year=stoi(temp_end_year);
            int_end_month=stoi(temp_end_month);
            int_end_date=stoi(temp_end_date);
            // cout<<"start date: "<<reserves[i].start_date<<endl;
            // cout<<"end date: "<<reserves[i].end_date<<endl;
            // cout<<"start date: "<<year<<" "<<month<<" "<<date<<endl;
            // cout<<"end date: "<<end_year<<" "<<end_month<<" "<<end_date<<endl;
            // cout<<"printing the start date of reservation: "<<int_year<<" "<<int_month<<" "<<int_date<<endl;
            // cout<<"printing the end date of the reservation:  "<<int_end_year<<" "<<int_end_month<<" "<<int_end_date<<endl;
            // cout<<"printing the start date to be reseved: "<<year<<" "<<month<<" "<<date<<endl;
            // cout<<"printing the end date to be reserved: "<<end_year<<" "<<end_month<<" "<<end_date<<endl;
            int a=date_comparator(year,month,date,int_year,int_month,int_date);
            int b=date_comparator(end_year,end_month,end_date,int_end_year,int_end_month,int_end_date);
            int c=date_comparator(end_year,end_month,end_date,int_year,int_month,int_date);
            int d=date_comparator(year,month,date,int_end_year,int_end_month,int_end_date);
            if(a==2 && d==1){
                possible=0;
                break;
            }
            if(c==2 && b==1){
                possible=0;
                break;
            }
            if(a==2 && b==1){
                possible=0;
                break;
            }
            if(a==1 && b==1){
                possible=0;
                break;
            }
            // if(a==1 && b==1 && c==2){
            //     cout<<"got it"<<endl;
            //     possible=0;
            //     break;
            // }
            // else if(a==2 && b==2 && c==1){
            //     cout<<"got it 2"<<endl;
            //     possible=0;
            //     break;
            // }
        }
    }
    if(possible==0){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"The date are coliding with a aldready existing congregation"<<endl;
        return;
    }
    Reservation res(vname,congregation_name,country,congregation_list[ind].start_date,congregation_list[ind].end_date,capa,l); 
    reserves.push_back(res);
    int ind1=0;
    // Congregation c(congregation_name,congre);
    for(int i=0;i<venue_list.size();i++){
        if(venue_list[i].venue_name==vname){
            ind1=i;
            break;
        }
    }
    for(int i=0;i<congregation_list.size();i++){
        if(congregation_list[i].name==congregation_name){
            // Congregation c(congregation_name,);
            venue_list[ind1].cong.push_back(congregation_list[i]);
        }
    } 
    // venue_list.push_back();
    // vens.push_back();
    cout<<0<<endl;
    return;
}

void free_Venue(vector <Venue> &venue_list,vector <Reservation>&reserves,string congregation_name,string vname,string country){
    int found=0;
    int ind=0;
    for(int i=0;i<reserves.size();i++){
        // cout<<reserves[i].congregation_name<<" :: "<<congregation_name<<endl;
        // cout<<reserves[i].venue_name<<" :: "<<vname<<endl;
        // cout<<reserves[i].country_name<<" :: "<<country<<endl;
        if(reserves[i].congregation_name==congregation_name && reserves[i].venue_name==vname && reserves[i].country_name==country){
            found=1;
            ind=i;
            break;
        }
    }
    if(found==0){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"venue not found"<<endl;
        return;
    }
    reserves.erase(reserves.begin()+ind);
    int ind1=0;
    for(int i=0;i<venue_list.size();i++){
        if(venue_list[i].venue_name==vname && venue_list[i].country==country){
            ind1=i;
            break;
        }
    }
    int ind2=0;
    for(int i=0;i<venue_list[ind1].cong.size();i++){
        if(venue_list[ind1].cong[i].name==congregation_name){
            ind2=i;
            break;
        }
    }
    venue_list[ind1].cong.erase(venue_list[ind1].cong.begin()+ind2);
    cout<<0<<endl;
    return;
}

void show_reserve(vector <Congregation>& congregation_list,vector <Reservation> &reserves,string congregation_name){
    int cnt=0;
    // cout<<"Printing the total number of reservations present"<<reserves.size()<<endl;
    // for(int i=0;i<reserves.size();i++){
    //     reserves[i].display();
    // }
    // cout<<"the above was printed just for the purpose of cheking"<<endl;
    int found=0;
    for(int i=0;i<congregation_list.size();i++){
        if(congregation_list[i].name==congregation_name){
            found=1;
            break;
        }
    }
    if(found==0){
        cout<<-1<<endl;
        cout<<"Error"<<endl;
        // cout<<"congregation does not exists"<<endl;
        return;
    }
    for(int i=0;i<reserves.size();i++){
        if(reserves[i].congregation_name==congregation_name){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    if(cnt>0){
        for(int  i=0;i<reserves.size();i++){
            if(reserves[i].congregation_name==congregation_name){
                reserves[i].display();
            }
        }
    }
    return;
}

string remove_white_spaces(string line){
    string nline="";  //creating an empty string that will be the final string after removing the unwanted white spaces
    int i=0;
    int sizes=line.size();
    while(i<sizes){  
        while(i< sizes && line[i]==' '){
            i++;
        }
        while(i<sizes && line[i]!=' '){
            nline=nline+line[i];
            i++;
        }
        nline=nline+' ';
    }

    int j=nline.size()-1;  //removing the extra white spaces present at the end
    while(nline[j]==' '){
        j--;
    }
    nline=nline+'\0';  //adding the new line character to terminate the string
    return nline;
}



int main(int argc, char *argv[]){
    istream* input_stream;
    ifstream file;
    // Check if a file name is provided as a command line argument
    Venue*hvenue=NULL;
    if (argc > 1) {    //if the file name is given through the command line then take the inout through the flie
        file.open(argv[1]);
        if (!file.is_open()) {
            // perror("Error opening file");
            cout<<"The file "<<argv[1]<<" could not be opened"<<endl;
            return 1;
        }
        input_stream=&file;     //if file is successfully opened then use file to take the input
    }
    else{
        input_stream=&cin;   //if no file provided then take the input through stdin
    }
    vector <Reservation> reserves;
    vector <Venue> venue_list;
    vector <Venue> vens;
    vector <Congregation> congregation_list;
    string line;
    while(true){
        getline(*input_stream,line);
        line=remove_white_spaces(line);
        string command="";
        string congregation_name="";
        string congregation_type="";
        string location="";
        string city="";
        string country="";
        string state="";
        string postalcode="";
        string start_date="";
        string end_date="";
        string vname="";
        string ename="";
        string sdate="";
        string syear="";
        string smonth="";
        string sday="";
        string capacity="";
        int day,year,month;
        string time="";
        string shour="";
        string sminutes="";
        string start_time="";
        string end_time="";
        int hour,minutes;
        int ind=0;
        while(ind<line.size() && line[ind]!=' '){
            command+=line[ind];
            ind++;
        }
        // cout<<"command: "<<command<<endl;
        // return 0;
        // cout<<line<<endl;
        if(command=="" || command==" "){
            cout<<-1<<endl;
            cout<<"error"<<endl;
            continue;
        }
        else if(command=="End"){
            // cout<<"exiting"<<endl;
            // cout<<line<<endl;
            break;
        }
        else if(command=="addCongregation"){
            if(ind>=line.size()){
                // cout<<"Please provide other info to add the congregation"<<endl;
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                continue;
            }
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                continue;
            }
            ind++;
            while(ind< line.size() && line[ind]!='\"'){
                congregation_name+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                // cout<<"Please close the name with a doubel qoutes and enter the command in the correct format"<<endl;
                cout<<"Error"<<endl;
                continue;
            }
            // cout<<"congregation_name: "<<congregation_name<<endl;
            ind++;
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                // cout<<"Please enclose in double qoutes"<<endl;
                cout<<"Error"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                congregation_type+=line[ind];
                ind++;
            }
            // cout<<"checker"<<endl;
            // cout<<line[ind]<<endl;
            if(ind>=line.size()){
                cout<<-1<<endl;
                // cout<<"Please enclose in double qoutes"<<endl;
                cout<<"Error"<<endl;
                continue;
            }
            // cout<<"congregation_type: "<<congregation_type<<endl;
            ind++;
            // cout<<line[ind]<<endl;
            ind++;
            // cout<<line[ind]<<endl;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                // cout<<"please enclose the date in double qoutes"<<endl;
                cout<<"Error"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                start_date+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                // cout<<"Please enclose in double qoutes"<<endl;
                cout<<"Error"<<endl;
                continue;
            }
            // cout<<"start_date: "<<start_date<<endl;
            ind++;
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                // cout<<"please enclose the date in double qoutes"<<endl;
                cout<<"Error"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                end_date+=line[ind];
                ind++;
            }
            if(ind>=line.size()){
                cout<<-1<<endl;
                // cout<<"please enclose the date in double qoutes"<<endl;
                cout<<"Error"<<endl;
                continue;
            }
            int found=0;
            for(int i=0;i<congregation_list.size();i++){
                if(congregation_list[i].name==congregation_name){
                    found=1;
                }
            }
            if(found==1){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"congragation aldready exists"<<endl;
                continue;
            }
            // cout<<"WHILE ADDING CONGREGATION CHECKIGN THE VALUE OF THE END_DATE THAT WE ARE SONDING TO THE FUNCITON"<<endl;
            // cout<<"CHECKER: "<<end_date<<endl;
            // cout<<line<<endl;
            int val=start_end_verifier(start_date,end_date);
            if(val==-1){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                continue;
            }
            add_Congregation(congregation_list,congregation_name,congregation_type,start_date,end_date);
            // cout<<endl<<endl<<endl;
            // vector <Congregation>&congregation_list,congregation_name, congregation_type,start_date,end_date
        }
        else if(command=="deleteCongregation"){
            if(ind>=line.size()){
                // cout<<"Please provide other info to add the congregation"<<endl;
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                continue;
            }
            ind++;
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                congregation_name+=line[ind];
                ind++;
            }
            // cout<<line<<endl;
            delete_Congregation(congregation_list,reserves,congregation_name);
            // vector <Congregation>&arr,vector <Reservation>&reserves,congregation_name
        }
        else if(command=="showCongregations"){
            // cout<<line<<endl;
            show_Congregation(congregation_list);   
        }
        else if(command=="addVenue"){
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please start the venue name with a double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                vname+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please enter the correct format for the input"<<endl;
                continue;
            }
            ind++;
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please the location string with a double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                location+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please close the double qoutes and enter the cpapcity"<<endl;
                continue;
            }
            ind++;
            ind++;
            while(ind<line.size() && line[ind]!='\0'){
                capacity+=line[ind];
                ind++;
            }
            // cout<<line<<endl;
            add_Venue(venue_list,vname,location,capacity);
            // cout<<endl<<endl<<endl;
        }
        else if(command=="deleteVenue"){
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please enter venue name and country name"<<endl;
                continue;
            }
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please enclose the venue name in double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                vname+=line[ind];
                ind++;
            }
            ind++;
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please enclose the venue name in double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                country+=line[ind];
                ind++;
            }
            // vector <Venue> &venue_list,vector <Reservation>&reserves,vector <Congregation> &cong,string vname,string country_name
            // cout<<line<<endl<<endl<<endl<<endl;
            // cout<<line<<endl;
            delete_Venue(venue_list,reserves,congregation_list,vname,country);
            // cout<<endl<<endl<<endl;
        }
        else if(command=="showVenues"){
            if(ind>=line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please give the location string also"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size()){
                location+=line[ind];
                ind++;
            }
            // cout<<line<<endl<<endl<<endl<<endl;
            // cout<<line<<endl;
            show_Venues(venue_list,location);
            // cout<<endl<<endl<<endl;
        }
        else if(command=="reserveVenue"){
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please start with the double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                vname+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"close the name with double qoutes"<<endl;
                continue;
            }
            ind++;
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please enclose the country name in double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                country+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"close the name with double qoutes"<<endl;
                continue;
            }
            ind++;
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please enclose the congregation name in double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size()  && line[ind]!='\"'){
                congregation_name+=line[ind];
                ind++;
            }
            // cout<<line<<endl<<endl<<endl<<endl;
            // cout<<line<<endl;
            reserve_Venue(reserves,congregation_list,venue_list,vname,country,congregation_name);
            // cout<<endl<<endl<<endl;
            // vector <Reservation>&reserves,vector <Congregation>&arr,vector <Venue>&cong,string vname,string country,string congregation_name
        }
        else if(command=="freeVenue"){
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please start with the double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                vname+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"close the name with double qoutes"<<endl;
                continue;
            }
            ind++;
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please enclose the country name in double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                country+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"close the name with double qoutes"<<endl;
                continue;
            }
            ind++;
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please enclose the congregation name in double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size()  && line[ind]!='\"'){
                congregation_name+=line[ind];
                ind++;
            }
            // cout<<line<<endl<<endl<<endl<<endl;
            // cout<<line<<endl;
            free_Venue(venue_list,reserves,congregation_name,vname,country);
            // cout<<endl<<endl<<endl;
            // vector <Venue> &venue_list,vector <Reservation>&reserves,string congregation_name,string vname,string country
        }
        else if(command=="showReserved"){
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please start with the double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                congregation_name+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"close the name with double qoutes"<<endl;
                continue;
            }
            // cout<<line<<endl<<endl<<endl<<endl;
            // cout<<line<<endl;
            show_reserve(congregation_list,reserves,congregation_name);
            // cout<<endl<<endl<<endl;
        }
        else if(command=="addEvent"){
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please start with the double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                congregation_name+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"close the name with double qoutes"<<endl;
                continue;
            }
            // cout<<"congregation name: "<<congregation_name<<endl;
            ind++;
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please enclose the country name in double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                vname+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"close the name with double qoutes"<<endl;
                continue;
            }
            // cout<<"vname: "<<vname<<endl;
            ind++;
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please enclose the congregation name in double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size()  && line[ind]!='\"'){
                country+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"close the name with double qoutes"<<endl;
                continue;
            }
            // cout<<"coutnry: "<<country<<endl;
            ind++;
            ind++;
            ind++;
            for(int i=0;i<10;i++){
                sdate+=line[ind];
                ind++;
            }
            // cout<<"date: "<<sdate<<endl;
            ind++;
            ind++;
            ind++;
            for(int i=0;i<5;i++){
                start_time+=line[ind];
                ind++;
            }
            // cout<<"start time: "<<start_time<<endl;
            ind++;
            ind++;
            ind++;
            for(int i=0;i<5;i++){
                end_time+=line[ind];
                ind++;
            }
            // cout<<"end time: "<<end_time<<endl;
            ind++;
            ind++;
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please give event name"<<endl;
                continue;
            }
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please enclose the event name in double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                ename+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Close the event name with double qoutes"<<endl;
                continue;
            }
            // cout<<"event name: "<<ename<<endl;
            // cout<<"congregation_name"<<congregation_name<<endl;
            // cout<<"venue_name"<<vname<<endl;
            // cout<<"country: "<<country<<endl;
            // cout<<"date: "<<sdate<<endl;
            // cout<<"start time: "<<start_time<<endl;
            // cout<<"end time: "<<end_time<<endl;
            // cout<<"event name: "<<ename<<endl;
            // cout<<line<<endl<<endl<<endl<<endl;
            // cout<<line<<endl;
            int val=date_verifier(sdate);
            if(val==-1){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                continue;
            }
            add_Event(venue_list,reserves,congregation_name,vname,country,sdate,start_time,end_time,ename);
            // cout<<endl<<endl<<endl;
            // vector <Venue> &venue_list,vector <Reservation>&reserves,string congregation_name,string vname,string country,string sdate,string start_time, string end_time,string ename
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     cout<<"Please enclose the congregation name in double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size()  && line[ind]!='\"'){
            //     country+=line[ind];
            //     ind++;
            // }
        }
        else if(command=="deleteEvent"){
            // cout<<"NOW IN THE DELETE EVENT INPUT TAKER"<<endl;
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please start with the double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                congregation_name+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"close the name with double qoutes"<<endl;
                continue;
            }
            // cout<<"CONGREGATION NAME: "<<congregation_name<<endl;
            ind++;
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please enclose the venue name in double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                vname+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"close the name with double qoutes"<<endl;
                continue;
            }
            // cout<<"VENUE NAME: "<<vname<<endl;
            ind++;
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please enclose the congregation name in double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size()  && line[ind]!='\"'){
                country+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"close the name with double qoutes"<<endl;
                continue;
            }
            // cout<<"COUTNRY NAME: "<<country<<endl;
            ind++;
            ind++;
            ind++;
            for(int i=0;i<10;i++){
                sdate+=line[ind];
                ind++;
            }
            // cout<<"SDATE: "<<sdate<<endl;
            ind++;
            ind++;
            ind++;
            for(int i=0;i<5;i++){
                start_time+=line[ind];
                ind++;
            }
            // cout<<"START_TIME: "<<start_time<<endl;
            ind++;
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"start the end time with double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                ename+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please close the event name with double qoutes"<<endl;
                continue;
            }
            // cout<<"EVENT NAME: "<<ename<<endl;
            // ind++;
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     cout<<"start the event name with double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     ename+=line[ind];
            //     ind++;
            // }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please close the event name with double qoutes"<<endl;
                continue;
            }
            // cout<<ename<<endl;
            // cout<<"EVENT NAME: "<<ename<<endl;
            // cout<<line<<endl<<endl<<endl<<endl;
            // cout<<line<<endl;
            delete_Event(venue_list,congregation_name,vname,country,sdate,start_time,ename);
            // vector <Venue> &venue_list,string congregation_name,string vname, string country,string date,string from_time, string ename
            // cout<<endl<<endl<<endl;
            // cout<<"DELETE EVENT FUNCTION"<<endl;
            // vector <Venue> &venue_list,string congregation_name,string vname, string country,string date,string from_time, string ename
        }
        else if(command=="showEvents"){
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please start with the double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                vname+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"close the name with double qoutes"<<endl;
                continue;
            }
            ind++;
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please enclose the country name in double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                country+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"close the name with double qoutes"<<endl;
                continue;
            }
            ind++;
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"enclose the date string in doubel qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                sdate+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please close the date in double qoutes"<<endl;
                continue;
            }
            // delete_Event();
            // cout<<line<<endl<<endl<<endl<<endl;
            // cout<<line<<endl;
            show_Events(venue_list,vname,country,sdate);
            // cout<<endl<<endl<<endl;
            // vector <Venue> &venue_list,string venue_name,string country,string date
        }
        else if(command=="showCalendar"){
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please start with the double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                congregation_name+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"close the name with double qoutes"<<endl;
                continue;
            }
            ind++;
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please enclose the country name in double qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                vname+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"close the name with double qoutes"<<endl;
                continue;
            }
            ind++;
            ind++;
            if(line[ind]!='\"'){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"enclose the date string in doubel qoutes"<<endl;
                continue;
            }
            ind++;
            while(ind<line.size() && line[ind]!='\"'){
                country+=line[ind];
                ind++;
            }
            if(ind==line.size()){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"Please close the date in double qoutes"<<endl;
                continue;
            }
            // cout<<line<<endl<<endl<<endl<<endl;
            // cout<<line<<endl;
            show_Calendar(reserves,venue_list,congregation_name,vname,country);
            // cout<<endl<<endl<<endl;
            // vector <Reservation>&reserves,vector <Venue>venue_list,string congregation_name,string venue_name,string country
        }
        else{
            cout<<-1<<endl;
            cout<<"Error"<<endl;
            // cout<<"Unkown command"<<endl;
        }
    }
}