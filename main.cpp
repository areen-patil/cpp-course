// #include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include <cstdio>
using namespace std;

struct Date {     //created a struct for dates in order to calculate the difference between the dates
    int year, month, day;

    Date(int y, int m, int d) : year(y), month(m), day(d) {}
};

Date parseDate(const std::string& dateStr) {  //this func takes the date in the form of string as input and returns the object of the type Date
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


class Event{  //the class of event and its attributes
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
    void display(){   //member functions to display the attributes of the class events  
        cout<<venue_name<<" "<<country<<" "<<date<<endl;
    }
};
class Congregation{
public:
    string name;   //attributes of the class Congregation
    string type;
    string start_date;
    string end_date;
    vector <Event> events;
    Congregation(string congregation_name,string congregation_type, string s_date, string e_date){
        name=congregation_name;
        type=congregation_type;
        start_date=s_date;
        end_date=e_date;
        events={};  //intialising an empty vector of events to add events corresponding to the events later on
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
    vector <Congregation> cong;  //contains a vector of congregations , the congregations are added to this once they are reseved for the particular venue
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
    void display(){  //member funtion to display the attributes of the venue in case of the command showVenues
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
    if(year1<year2){  //this function compares between two dates and returns 1 if the first date is smaller and retruns 2 if the second date is smaller
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
        else{  //if both the year and months are the same then check on the basis of the dates
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

int leap_year_checker(int year){  //checks if the given year is a leap year
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


int date_verifier(string current_date){ //verifies is the given date is valid
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
    if(start_month==2){  //check for the month of february depending in whether it is a leap year or not
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
        if(date<=31 && date>=1){     //checking for the months with 31 days
            return 1;
        }
        else{
            return -1;
        }
    }
    else if(start_month==4 || start_month==6 || start_month==9 || start_month==11){
        if(date<=30 && date>=1){      //checking for the months with 30 days
            return 1;
        }
        else{
            return -1;
        }
    }
    return 0;
}

int start_end_verifier(string date1,string date2){  //verifies is the start and the end dates for a congregation or event are valid
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
        return -1;    //if the dates is of the past then it is invalid
    }
    return 1;
}

vector <int> date_diff(string date1,string date2){  //calculates teh diff between the dates
    int start_year,start_month,start_date; //the diff between this func and the DateDifference funciton is that this funciton return the diff between the year and the year, months and the dates in the form of a vector 
    int end_year,end_month,end_date;//whereas the latter one returns the actual diff in the dates in terms of the days 
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


vector <int> time_diff(int hour1,int min1,int hour2,int min2){  //returns a vector with two elements conssiting of the diff between the hours and the minutes respectively
    vector <int> v(2);
    v[0]=hour1-hour2;
    v[1]=min1-min2;
    return v;    //return the vector with differences of the hour and the min
}
void add_Venue(vector <Venue>&venue_list,string vname,string location,string capacity){
    int found=0;
    int ind=0;
    string city="";    //separate out the city ,state,postal code and the country from the locations string 
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
    //uptill here the code consists of just extracting the strings from the location string
    for(int i=0;i<venue_list.size();i++){ //check if the venue aldready exists
        if(venue_list[i].venue_name==vname && venue_list[i].country==country){
            found=1;
            break;
        }
    }
    if(found==1){
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
        // cout<<"venue aldready exists";
        return;
    }
    Venue ven(vname,state,city,postal,country,capacity,location_address);
    venue_list.push_back(ven);  //add the venue to the venue_list
    cout<<0<<endl;
    return;
}
void show_Venues(vector <Venue> &venue_list,string location){
    string city="";  //variables to store the string names
    string state="";
    string postal="";
    string country="";
    int ind=0;
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
    // extracting the names from the location string 
    int cnt=0;

    //the following if-else conditions basically consider the diff forms in which the date can be given
    if(city!="" && state!="" && postal=="" && country!=""){
        for(int i=0;i<venue_list.size();i++){
            if(venue_list[i].city==city && venue_list[i].state==state && venue_list[i].country==country){
                cnt++;
            }

        }
    }
    else if(city=="" && state=="" && postal!="" && country!=""){
        for(int i=0;i<venue_list.size();i++){
            if(venue_list[i].postal==postal && venue_list[i].country==country){
                cnt++;
            }
        }
    }
    else if(city!="" && state!="" && postal!="" && country!=""){
        for(int i=0;i<venue_list.size();i++){
            if(venue_list[i].city==city && venue_list[i].state==state && venue_list[i].postal==postal && venue_list[i].country==country){
                cnt++;
            }
        }
    }
    else if(city=="" && state=="" && postal=="" && country!=""){
        for(int i=0;i<venue_list.size();i++){
            if(venue_list[i].country==country){
                cnt++;
            }
        }
    }
    else{
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
        return;
    }
    //the above if else was used for counting the number of venues that lie in the given region/area specified
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
    //the above if-else are used for printing the counted venues
    return;
}

void delete_Venue(vector <Venue> &venue_list,vector <Reservation>&reserves,vector <Congregation> &cong,string vname,string country_name){
    int exists=0;
    for(int i=0;i<venue_list.size();i++){  //check whether the venue to be deleted actually exists or not
        if(venue_list[i].venue_name==vname && venue_list[i].country==country_name){
            exists=1;
            break;
        }
    }
    if(exists==0){
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
        //cout<<"venue does not exists"<<endl;
        return;
    }
    int found=0;
    for(int i=0;i<reserves.size();i++){ //before deleting check if their still exists a reservation for the venue if yes then do not delete and print an error message
        if(reserves[i].venue_name==vname && reserves[i].country_name==country_name){
            found=1;
            break;
        }
    }
    if(found==1){
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
        // cout<<"Reservation still exists with respect to the congregation"<<endl;
        return;
    }
    int ind1=0;
    for(int i=0;i<venue_list.size();i++){
        if(venue_list[i].venue_name==vname){
            ind1=i;
            break;
        }
    }
    venue_list.erase(venue_list.begin()+ind1);
    int ind2=0;
    cout<<0<<endl;
    return;
}


void add_Event(vector <Venue> &venue_list,vector <Reservation>&reserves,string congregation_name,string vname,string country,string sdate,string start_time, string end_time,string ename){
    int found=0;
    int ind=0;
    for(int i=0;i<reserves.size();i++){ //check if their exists a reservation for the venue and the congregation only then add the event
        if(reserves[i].congregation_name==congregation_name && reserves[i].venue_name==vname && reserves[i].country_name==country){
            found=1;
            break;
        }
    }
    if(found==0){
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
        // cout<<"the event cannot be added without reservation for the venue and the congregation"<<endl;
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
    if(dd1<0){
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
        return;
    }
    int dd2=dateDifference(venue_list[ind].cong[ind1].end_date,sdate);
    if(dd2>0){
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
        return;
    }
    //the above two if statements check if the date of the event to be added lies between the reseved dated for the congregation or not , if no the print an error message
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
    vector <int> tdiff=time_diff(start_hour,start_min,end_hour,end_min);
    int possible=1;
    if(tdiff[0]==0){  //checking is the time is valid
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
    if(start_min%15!=0 || end_min%15!=0){  //checking if the dates are multiples of 15
        possible=0;
    }
    if(start_min>59 || start_min<0 || end_min>59 || end_min<0){
        possible=0;
    }
    if(possible==0){
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
        // cout<<"problem with time format"<<endl;
        return;
    }
    for(int i=0;i<venue_list[ind].cong[ind1].events.size();i++){
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
        int diff = dateDifference(venue_list[ind].cong[ind1].events[i].date,sdate);
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
                vector <int> start_time_diff=time_diff(temp_hour,temp_min,start_hour,start_min);
                vector <int> end_time_diff=time_diff(end_hour,end_min,temp_end_hour,temp_end_min);
                vector <int> start_end_time_diff=time_diff(temp_end_hour,temp_end_min,start_hour,start_min);
                vector <int> end_start_time_diff=time_diff(temp_hour,temp_min,end_hour,end_min);
                vector <int> end_start_time_diff2=time_diff(end_hour,end_min,temp_hour,temp_min);
                if(start_time_diff[0]<0 ||  (start_time_diff[0]==0 &&  start_time_diff[1]<0)){
                    if(start_end_time_diff[0]>0 || (start_end_time_diff[0]==0 &&  start_end_time_diff[1]>0)){
                        possible=0;
                        break;
                    }
                }
                if(start_end_time_diff[0]<0 || (start_end_time_diff[0]==0 && start_end_time_diff[1]<0) || start_hour==0){
                    if(start_end_time_diff[0]==0 && venue_list[ind].cong[ind1].events[i].date==sdate){
                        int ins=start_end_time_diff[1]*-1;
                        if(ins<30){
                            possible=0;
                            break;
                        }
                    }
                    else if(start_end_time_diff[0]==-1){
                        if(temp_end_min==45 && start_min<15){
                            possible=0;
                            break;
                        }
                        else if(temp_end_min==30 && (start_min>30 && start_min<=0)){
                            possible=0;
                            break;
                        }
                    }
                }
                if(end_start_time_diff2[0]<0 || (end_start_time_diff2[0]==0 && end_start_time_diff2[1]<0)){   
                    if(end_start_time_diff2[0]==0){
                        int ins=end_start_time_diff2[1]*-1;
                        if(ins<30){
                            possible=0;
                            break;
                        }
                    }
                    if(end_min==45 && end_start_time_diff2[0]==-1){
                        if(temp_min<15){
                            possible=0;
                            break;
                        }
                    }
                }
                if(end_time_diff[0]<0 || (end_time_diff[0]==0 && end_time_diff[1]<0)){
                    if(venue_list[ind].cong[ind1].events[i].date==sdate && (end_start_time_diff[0]<0 || (end_start_time_diff[0]==0 && end_start_time_diff[1]<0))){
                        possible=0;
                        break;
                    }
                }
            }
        }
    }
    if(possible==0){
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
        // cout<<"some of the dates are time interval are overlapping"<<endl;
        return;
    }
    int year,month,date;
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
        int val=date_comparator(temp_year,temp_month,temp_date,year,month,date);
        if(val==1){
            continue;
        }
        if(val==2){
            ind3=i;
            break;    
        }
        else if(val==0){
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
    //ind3 is the index where the event has to be added as per the dates and the time
    if(ind3==venue_list[ind].cong[ind1].events.size()){
        if(possible==1){
            Event ev1(ename,vname,country,sdate,start_time,end_time);
            venue_list[ind].cong[ind1].events.push_back(ev1);
        }
    }
    else{
        if(possible==1){
            Event ev1(ename,vname,country,sdate,start_time,end_time);
            // cout<<"Event added"<<endl;
            venue_list[ind].cong[ind1].events.insert(venue_list[ind].cong[ind1].events.begin()+ind3,ev1);
        }
    }
    cout<<0<<endl;
    return;
}

void delete_Event(vector <Venue> &venue_list,string congregation_name,string vname, string country,string date,string from_time, string ename){
    int found_venue=0;
    int found_congregation=0;
    int ind=0;
    int ind1=0;
    for(int i=0;i<venue_list.size();i++){  //check if the venue exists or not
        if(venue_list[i].venue_name==vname && venue_list[i].country==country){
            found_venue=1;
            ind=i;
            break;
        }
    }
    if(found_venue==0){
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
        // cout<<"Venue not found"<<endl;
        return;
    }
    for(int i=0;i<venue_list[ind].cong.size();i++){ //check if the congregation exists or not
        if(venue_list[ind].cong[i].name==congregation_name){
            found_congregation=1;
            ind1=i;
            break;
        }
    }
    if(found_congregation==0){
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
        // cout<<"Congregation not found"<<endl;
        return;
    }
    int found_event=0;
    int ind2=0;
    for(int i=0;i<venue_list[ind].cong[ind1].events.size();i++){ //check if the event exists or not
        if(venue_list[ind].cong[ind1].events[i].event_name==ename && venue_list[ind].cong[ind1].events[i].start_time==from_time && venue_list[ind].cong[ind1].events[i].date==date){
            ind2=i;
            found_event=1;
            break;
        }
    }
    if(found_event==0){
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
        // cout<<"Event not found"<<endl;
        return;
    }
    venue_list[ind].cong[ind1].events.erase(venue_list[ind].cong[ind1].events.begin()+ind2);  //delete the events from its index in the vector
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
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
        // cout<<"venue does not exists"<<endl;
        return;
    }
    for(int i=0;i<venue_list[ind].cong.size();i++){   //count the number of events in the particular venue on the specific date
        for(int j=0;j<venue_list[ind].cong[i].events.size();j++){
            if(venue_list[ind].cong[i].events[j].date==date){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<venue_list[ind].cong.size();i++){  //print those events
        for(int j=0;j<venue_list[ind].cong[i].events.size();j++){
            if(venue_list[ind].cong[i].events[j].date==date){
                cout<<venue_list[ind].cong[i].events[j].event_name<<" "<<venue_list[ind].cong[i].events[j].start_time<<" "<<venue_list[ind].cong[i].events[j].end_time<<endl;
            }
        }
    }
    return;
}


string next_date(string current_date){ // funciton takes in the date in the string format and then return the next date
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
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
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
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
        // cout<<"reservation not found"<<endl;
        return;
    }
    string start_date_congregation="";
    string end_date_congregation="";
    int ind1=0;
    for(int i=0;i<venue_list[ind].cong.size();i++){
        if(venue_list[ind].cong[i].name==congregation_name){
            ind1=i;
            break;
        }
    }
    start_date_congregation=venue_list[ind].cong[ind1].start_date;
    end_date_congregation=venue_list[ind].cong[ind1].end_date;

    int final_counter=0;
    final_counter=venue_list[ind].cong[ind1].events.size();
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
    string current_date=start_date_congregation;
    while(true){  //store the dates that lie in the reservaiton for the congragation
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
        if(date_comparator(temp_year,temp_month,temp_date,end_year,end_month,end_date)==1 || date_comparator(temp_year,temp_month,temp_date,end_year,end_month,end_date)==0){
            dates.push_back(current_date);
        }
        else{
            break;
        }
        current_date=next_date(current_date);
    }

    cout<<final_counter<<endl;

    for(int i=0;i<dates.size();i++){     
        int temp_cnt=0;
        cout<<dates[i]<<" ";
        for(int j=0;j<venue_list[ind].cong[ind1].events.size();j++){  //count the number of events on this date
            if(venue_list[ind].cong[ind1].events[j].date==dates[i]){
                temp_cnt++;
            }
        }
        cout<<temp_cnt<<endl;
        for(int j=0;j<venue_list[ind].cong[ind1].events.size();j++){  //print those events
            if(venue_list[ind].cong[ind1].events[j].date==dates[i]){
                cout<<venue_list[ind].cong[ind1].events[j].event_name<<" "<<venue_list[ind].cong[ind1].events[j].start_time<<" "<<venue_list[ind].cong[ind1].events[j].end_time<<endl;
            }
        }
    }
    return;
}

void add_Congregation(vector <Congregation>&congregation_list,string congregation_name,string congregation_type,string start_date,string end_date){
    int found=0;
    for(int i=0;i<congregation_list.size();i++){ //check if the congragation aldready exists
        if(congregation_list[i].name==congregation_name && congregation_list[i].type==congregation_type){
            found=1;
            break;
        }
    }
    if(found==1){
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
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
    for(int i=0;i<congregation_list.size();i++){  //check if the congregation exists
        // cout<<congregation_list[i].name<<" :: "<<congregation_name<<endl;
        if(congregation_list[i].name==congregation_name){
            found=1;
            ind3=i;
            break;
        }
    }
    if(found==0){
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
        // cout<<"Congregaator not found"<<endl;
        return;
    }
    congregation_list.erase(congregation_list.begin()+ind3);  //delte teh congragation and also remove reservation that was presetn for that congragation
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
    cout<<congregation_list.size()<<endl; //print the number of congregations
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
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
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
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
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
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
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
    for(int i=0;i<reserves.size();i++){  //check if the reservation is not collliding with any other resevation for on the same venue on the same date
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
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
        // cout<<"The date are coliding with a aldready existing congregation"<<endl;
        return;
    }
    Reservation res(vname,congregation_name,country,congregation_list[ind].start_date,congregation_list[ind].end_date,capa,l); 
    reserves.push_back(res); //add the reservation
    int ind1=0;
    for(int i=0;i<venue_list.size();i++){
        if(venue_list[i].venue_name==vname){
            ind1=i;
            break;
        }
    }
    for(int i=0;i<congregation_list.size();i++){ //also add the congregation to the corresponding venue because the resevation is made and now event can be added to it
        if(congregation_list[i].name==congregation_name){
            venue_list[ind1].cong.push_back(congregation_list[i]);
        }
    } 
    cout<<0<<endl;
    return;
}

void free_Venue(vector <Venue> &venue_list,vector <Reservation>&reserves,string congregation_name,string vname,string country){
    int found=0;
    int ind=0;
    for(int i=0;i<reserves.size();i++){
        if(reserves[i].congregation_name==congregation_name && reserves[i].venue_name==vname && reserves[i].country_name==country){
            found=1;
            ind=i;
            break;
        }
    }
    if(found==0){
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
        // cout<<"venue not found"<<endl;
        return;
    }
    reserves.erase(reserves.begin()+ind);  //delete the reservation
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
    venue_list[ind1].cong.erase(venue_list[ind1].cong.begin()+ind2); //also remove the congregation from the venue's list of congregation as it is no longer reserved for it
    cout<<0<<endl;
    return;
}

void show_reserve(vector <Congregation>& congregation_list,vector <Reservation> &reserves,string congregation_name){
    int cnt=0;
    int found=0;
    for(int i=0;i<congregation_list.size();i++){
        if(congregation_list[i].name==congregation_name){
            found=1;
            break;
        }
    }
    if(found==0){
        cout<<"-1\nError"<<endl;
        // cout<<"Error"<<endl;
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
        for(int  i=0;i<reserves.size();i++){  //print the reservations
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
        stringstream ss(line);
        // line=remove_white_spaces(line);
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
        ss >> command;
        // while(line[ind]==' ' || line[ind]=='\t' || line[ind]=='\n'){
        //     ind++;
        // }
        // while(ind<line.size() && line[ind]!=' '){
        //     command+=line[ind];
        //     ind++;
        // }
        if(command=="" || command==" "){
            cout<<-1<<endl;
            cout<<"error"<<endl;
            continue;
        }
        else if(command=="End"){
            // cout<<"exiting"<<endl;
            break;
        }
        else if(command=="addCongregation"){
            // if(ind>=line.size()){
            //     cout<<"Please provide other info to add the congregation"<<endl;
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     continue;
            // }
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     cout<<"dfbfdb"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind< line.size() && line[ind]!='\"'){
            //     congregation_name+=line[ind];
            //     ind++;
            // // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Please close the name with a doubel qoutes and enter the command in the correct format"<<endl;
            //     cout<<"Error"<<endl;
            //     continue;
            // }
            // // cout<<"congregation_name: "<<congregation_name<<endl;
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Please enclose in double qoutes"<<endl;
            //     cout<<"Error"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     congregation_type+=line[ind];
            //     ind++;
            // }
            // if(ind>=line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Please enclose in double qoutes"<<endl;
            //     cout<<"Error"<<endl;
            //     continue;
            // // }
            getline(ss, congregation_name, '"');
            getline(ss, congregation_name, '"');
			getline(ss, congregation_type, '"');
            getline(ss, congregation_type, '"');
			getline(ss, start_date, '"');
            getline(ss, start_date, '"');
			getline(ss, end_date, '"');
            getline(ss, end_date, '"');
			// int 
            // getline(ss, congregation_name, '"');
			// getline(ss, type, '"');
            //             getline(ss, congregation_type, '"');
			// getline(ss, st_dt, '"');
            //             getline(ss, start_date, '"');
			// getline(ss, end_dt, '"');
            //             getline(ss, end_date, '"');
            // cout<<"congregation_type: "<<congregation_type<<endl;
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     // cout<<"please enclose the date in double qoutes"<<endl;
            //     cout<<"Error"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     start_date+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     // cout<<"Please enclose in double qoutes"<<endl;
            //     cout<<"Error"<<endl;
            //     continue;
            // }
            // // cout<<"start_date: "<<start_date<<endl;
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     // cout<<"please enclose the date in double qoutes"<<endl;
            //     cout<<"Error"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     end_date+=line[ind];
            //     ind++;
            // }
            // if(ind>=line.size()){
            //     cout<<-1<<endl;
            //     // cout<<"please enclose the date in double qoutes"<<endl;
            //     cout<<"Error"<<endl;
            //     continue;
            // }
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
            int val=start_end_verifier(start_date,end_date);
            if(val==-1){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                continue;
            }
            add_Congregation(congregation_list,congregation_name,congregation_type,start_date,end_date);
        }
        else if(command=="deleteCongregation"){
            // if(ind>=line.size()){
            //     // cout<<"Please provide other info to add the congregation"<<endl;
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     continue;
            // }
            // ind++;
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     congregation_name+=line[ind];
            //     ind++;
            // }

            // cout<<line<<endl;
            getline(ss, congregation_name, '"');
            getline(ss, congregation_name, '"');
            delete_Congregation(congregation_list,reserves,congregation_name);
        }
        else if(command=="showCongregations"){
            // cout<<line<<endl;
            show_Congregation(congregation_list);   
        }
        else if(command=="addVenue"){
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please start the venue name with a double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     vname+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please enter the correct format for the input"<<endl;
            //     continue;
            // }
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please the location string with a double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     location+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please close the double qoutes and enter the cpapcity"<<endl;
            //     continue;
            // }
            // ind++;
            // ind++;
            // while(ind<line.size() && line[ind]!='\0'){
            //     capacity+=line[ind];
            //     ind++;
            // }
            getline(ss, vname, '"');
            getline(ss, vname, '"');
            getline(ss, location, '"');
            getline(ss, location, '"');
            // getline(ss, capacity, '"');
            // getline(ss, capacity, '"');
            ss>>capacity;
            add_Venue(venue_list,vname,location,capacity);
        }
        else if(command=="deleteVenue"){
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please enter venue name and country name"<<endl;
            //     continue;
            // }
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please enclose the venue name in double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     vname+=line[ind];
            //     ind++;
            // }
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please enclose the venue name in double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     country+=line[ind];
            //     ind++;
            // }
            getline(ss, vname, '"');
            getline(ss, vname, '"');
            getline(ss, country, '"');
            getline(ss, country, '"');
            delete_Venue(venue_list,reserves,congregation_list,vname,country);
        }
        else if(command=="showVenues"){
            // if(ind>=line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please give the location string also"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size()){
            //     location+=line[ind];
            //     ind++;
            // }
            getline(ss, location, '"');
            getline(ss, location, '"');
            show_Venues(venue_list,location);
        }
        else if(command=="reserveVenue"){
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please start with the double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     vname+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"close the name with double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please enclose the country name in double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     country+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"close the name with double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please enclose the congregation name in double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size()  && line[ind]!='\"'){
            //     congregation_name+=line[ind];
            //     ind++;
            // }
            getline(ss, vname, '"');
            getline(ss, vname, '"');
            getline(ss, country, '"');
            getline(ss, country, '"');
            getline(ss, congregation_name, '"');
            getline(ss, congregation_name, '"');
            reserve_Venue(reserves,congregation_list,venue_list,vname,country,congregation_name);
        }
        else if(command=="freeVenue"){
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please start with the double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     vname+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"close the name with double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please enclose the country name in double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     country+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"close the name with double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please enclose the congregation name in double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size()  && line[ind]!='\"'){
            //     congregation_name+=line[ind];
            //     ind++;
            // }
            getline(ss, vname, '"');
            getline(ss, vname, '"');
            getline(ss, country, '"');
            getline(ss, country, '"');
            getline(ss, congregation_name, '"');
            getline(ss, congregation_name, '"');
            free_Venue(venue_list,reserves,congregation_name,vname,country);
        }
        else if(command=="showReserved"){
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please start with the double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     congregation_name+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"close the name with double qoutes"<<endl;
            //     continue;
            // }
            getline(ss, congregation_name, '"');
            getline(ss, congregation_name, '"');
            show_reserve(congregation_list,reserves,congregation_name);
        }
        else if(command=="addEvent"){
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please start with the double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     congregation_name+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"close the name with double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please enclose the country name in double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     vname+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"close the name with double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please enclose the congregation name in double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size()  && line[ind]!='\"'){
            //     country+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"close the name with double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // ind++;
            // ind++;
            // for(int i=0;i<10;i++){
            //     sdate+=line[ind];
            //     ind++;
            // }
            // ind++;
            // ind++;
            // ind++;
            // for(int i=0;i<5;i++){
            //     start_time+=line[ind];
            //     ind++;
            // }
            // ind++;
            // ind++;
            // ind++;
            // for(int i=0;i<5;i++){
            //     end_time+=line[ind];
            //     ind++;
            // }
            // ind++;
            // ind++;
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please give event name"<<endl;
            //     continue;
            // }
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please enclose the event name in double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     ename+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Close the event name with double qoutes"<<endl;
            //     continue;
            // }
            getline(ss, congregation_name, '"');
            getline(ss, congregation_name, '"');
            getline(ss, vname, '"');
            getline(ss, vname, '"');
            getline(ss, country, '"');
            getline(ss, country, '"');
            getline(ss, sdate, '"');
            getline(ss, sdate, '"');
            getline(ss, start_time, '"');
            getline(ss, start_time, '"');
            getline(ss, end_time, '"');
            getline(ss, end_time, '"');
            getline(ss, ename, '"');
            getline(ss, ename, '"');
            add_Event(venue_list,reserves,congregation_name,vname,country,sdate,start_time,end_time,ename);        }
            int val=date_verifier(sdate);
            if(val==-1){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                continue;
            }
        else if(command=="deleteEvent"){
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please start with the double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     congregation_name+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"close the name with double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please enclose the venue name in double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     vname+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"close the name with double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please enclose the congregation name in double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size()  && line[ind]!='\"'){
            //     country+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"close the name with double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // ind++;
            // ind++;
            // for(int i=0;i<10;i++){
            //     sdate+=line[ind];
            //     ind++;
            // }
            // ind++;
            // ind++;
            // ind++;
            // for(int i=0;i<5;i++){
            //     start_time+=line[ind];
            //     ind++;
            // }
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"start the end time with double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     ename+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please close the event name with double qoutes"<<endl;
            //     continue;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please close the event name with double qoutes"<<endl;
            //     continue;
            // }
            getline(ss, congregation_name, '"');
            getline(ss, congregation_name, '"');
            getline(ss, vname, '"');
            getline(ss, vname, '"');
            getline(ss, country, '"');
            getline(ss, country, '"');
            getline(ss, sdate, '"');
            getline(ss, sdate, '"');
            getline(ss, start_time, '"');
            getline(ss, start_time, '"');
            getline(ss, ename, '"');
            getline(ss, ename, '"');
            delete_Event(venue_list,congregation_name,vname,country,sdate,start_time,ename);
        }
        else if(command=="showEvents"){
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please start with the double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     vname+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"close the name with double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please enclose the country name in double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     country+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"close the name with double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"enclose the date string in doubel qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     sdate+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please close the date in double qoutes"<<endl;
            //     continue;
            // }
            getline(ss, vname, '"');
            getline(ss, vname, '"');
            getline(ss, country, '"');
            getline(ss, country, '"');
            getline(ss, sdate, '"');
            getline(ss, sdate, '"');
            show_Events(venue_list,vname,country,sdate);
        }
        else if(command=="showCalendar"){
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please start with the double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     congregation_name+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"close the name with double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please enclose the country name in double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     vname+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"close the name with double qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // ind++;
            // if(line[ind]!='\"'){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"enclose the date string in doubel qoutes"<<endl;
            //     continue;
            // }
            // ind++;
            // while(ind<line.size() && line[ind]!='\"'){
            //     country+=line[ind];
            //     ind++;
            // }
            // if(ind==line.size()){
            //     cout<<-1<<endl;
            //     cout<<"Error"<<endl;
            //     // cout<<"Please close the date in double qoutes"<<endl;
            //     continue;
            // }
            getline(ss, congregation_name, '"');
            getline(ss, congregation_name, '"');
            getline(ss, vname, '"');
            getline(ss, vname, '"');
            getline(ss, country, '"');
            getline(ss, country, '"');
            show_Calendar(reserves,venue_list,congregation_name,vname,country);
        }
        else{
            cout<<-1<<endl;
            cout<<"Error"<<endl;
            cout<<"Unkown command"<<endl;
        }
    }
}