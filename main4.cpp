#include <bits/stdc++.h>
using namespace std;
class Resevation {
public:
    string venue_name;
    string congregation_name;
    string program_name;
    string country_name;
    string program_type;
    string start_date;
    string end_date;
public:
    Resevation(string venue_name,string country_name,string congregation_name,string program_name,string program_type,string start_date,string end_date){
        this->venue_name=venue_name;
        this->congregation_name=congregation_name;
        this->program_name=program_name;
        this->country_name=country_name;
        this->program_type=program_type;
        this->start_date=start_date;
        this->end_date=end_date;
    }
};
class Congregation{
public:
    string congregation_name;
    string start_date;
    string end_date;
    string congregation_type;
    Congregation(string congregation_name1,string congregation_type1,string start_date1,string end_date1){
        congregation_name=congregation_name1;
        congregation_type=congregation_type1;
        start_date=start_date1;
        end_date=end_date1;
    }
    Congregation(string congregation_name){
        this->congregation_name=congregation_name;
    }
    void display(){
        cout<<congregation_name<<" "<<congregation_type<<" "<<start_date<<" "<<end_date<<endl;
    }
    virtual int allowed_types(string program_type_temp){}

};

class  Games:public Congregation{
public :    
    int allowed_types(string program_type_temp){
        vector <string> allowed_types_vector={"Ceremony","Track and field","Indoor games","Water sports"};
        for(int i=0;i<allowed_types_vector.size();i++){
            if(allowed_types_vector[i]==program_type_temp){
                return 1;
            }
        }
        return 0;
    } 
    Games(string congregation_name,string congregation_type,string start_date,string end_date):Congregation(congregation_name,congregation_type,start_date,end_date){

    }
};

class Concert:public Congregation{
public:
    int allowed_types(string program_type_temp){
        vector <string> allowed_types_vector={"Pre-concerts","Main Concert"};
        for(int i=0;i<allowed_types_vector.size();i++){
            if(allowed_types_vector[i]==program_type_temp){
                return 1;
            }
        }
        return 0;
    } 
    Concert(string congregation_name,string congregation_type,string start_date,string end_date):Congregation(congregation_name,congregation_type,start_date,end_date){}
};
class Conference:public Congregation{
public:    
    int allowed_types(string program_type_temp){
        vector <string> allowed_types_vector={"Workshop","Main Conference","Banquet"};
        for(int i=0;i<allowed_types_vector.size();i++){
            if(allowed_types_vector[i]==program_type_temp){
                return 1;
            }
        }
        return 0;
    } 
    Conference(string congregation_name,string congregation_type,string start_date,string end_date):Congregation(congregation_name,congregation_type,start_date,end_date){}

};
class Conventions:public Congregation{
public:
    int allowed_types(string program_type_temp){
        vector <string> allowed_types_vector={"Food Court","Exhibition","Workshop","Main Conference","Banquet"};
        for(int i=0;i<allowed_types_vector.size();i++){
            if(allowed_types_vector[i]==program_type_temp){
                return 1;
            }
        }
        return 0;
    } 
    Conventions(string congregation_name,string congregation_type,string start_date,string end_date):Congregation(congregation_name,congregation_type,start_date,end_date){}
};

class Program:public Congregation{
public:
    string program_name;
    string program_type;
    string start_date;
    string end_date;
    Program(string program_name,string program_type,string start_date,string end_date,string congregation_name):Congregation(congregation_name){
        this->program_name=program_name;
        this->program_type=program_type;
        this->start_date=start_date;
        this->end_date=end_date;
    }
};

class Venue{
public:
    string venue_name;
    string country_name="";
    string venue_type;
    string capacity;
    string location;
    // string country="";
    string pincode="";
    string city_name="";
    string place_name="";
    string state="";
    vector <string> supported_program_types;
    Venue(string venue_name,string venue_type,string location,string capacity){
        // cout<<"venue constructor called"<<endl;
        // cout<<"the venue constructor called"<<endl;
        this->venue_name=venue_name;
        this->venue_type=venue_type;
        this->location=location;
        this->capacity=capacity;
        int ind=0;
        // if(cnter==4){
        while(location[ind]!=':'){
            place_name+=location[ind];
            ind++;
        }
        ind++;
        while(location[ind]!=':'){
            city_name+=location[ind];
            ind++;
        }
        ind++;
        while(location[ind]!=':'){
            state+=location[ind];
            ind++;
        }
        ind++;
        while(location[ind]!=':'){
            pincode+=location[ind];
            ind++;
        }
        ind++;
        while(ind<location.size()){
            country_name+=location[ind];
            ind++;
        }
        // cout<<"location: "<<location<<endl;
        // cout<<"place_name: "<<place_name;
        // cout<<"city_name: "<<city_name<<endl;
        // cout<<"state: "<<state<<endl;
        // cout<<"pincode: "<<pincode<<endl;
        // cout<<"country_name: "<<country_name<<endl;
        // }
        // else{
        //     // int ind=0;
        //     while(location[ind]!=':'){
        //         city_name+=location[ind];
        //         ind++;
        //     }
        //     ind++;
        //     while(location[ind]!=':'){
        //         state+=location[ind];
        //         ind++;
        //     }
        //     ind++;
        //     while(location[ind]!=':'){
        //         pincode+=location[ind];
        //         ind++;
        //     }
        //     ind++;
        //     while(ind<location.size()){
        //         country_name+=location[ind];
        //         ind++;
        //     }
        // }
        // cout<<"venue constructor ended"<<endl;
    }
    void display(){
        cout<<venue_name<<" "<<location<<" "<<venue_type<<" "<<capacity<<endl;
    }
};

class For_show_reserve{
public:
    int count=0;
    string program_name;
    string program_type;
    For_show_reserve(string program_name,string program_type){
        this->program_name=program_name;
        this->program_type=program_type;
    }

};



int date_compare(string date1,string date2) {
    // Extract year, month, and day from date1
    int year1 = std::stoi(date1.substr(0, 4));
    int month1 = std::stoi(date1.substr(5, 2));
    int day1 = std::stoi(date1.substr(8, 2));

    // Extract year, month, and day from date2
    int year2 = std::stoi(date2.substr(0, 4));
    int month2 = std::stoi(date2.substr(5, 2));
    int day2 = std::stoi(date2.substr(8, 2));

    // Compare years
    if (year1 > year2) {
        return 1;
    } else if (year1 < year2) {
        return 2;
    }

    // Compare months
    if (month1 > month2) {
        return 1;
    } else if (month1 < month2) {
        return 2;
    }

    // Compare days
    if (day1 > day2) {
        return 1;
    } else if (day1 < day2) {
        return 2;
    }

    // Dates are equal
    return 0;
}


int date_comparator(string congregation_start_date,string congregation_end_date,string program_start_date,string program_end_date){
    int a=date_compare(congregation_start_date,program_start_date);
    int b=date_compare(congregation_end_date,program_start_date);
    int c=date_compare(congregation_start_date,program_end_date);
    int d=date_compare(congregation_end_date,program_end_date);
    if(a==0 || a==2){
        if(d==1 || d==0){
            // cout<<"returning the value of 1"<<endl;
            return 1;
        }
        else{
            // cout<<"returning the value of -1"<<endl;
            return -1;
        }
    }
    else{
        // cout<<"returning the value of -1"<<endl;
        return -1;
    }
}

class Event_manamger{
public:
    vector <string> indoor_stadium={"Indoor games"};
    vector <string> swimming_pool={"Water sports"};
    vector <string> outdoor_stadium={"Track and field","Ceremony","Main Concert","Pre Concert","Food Court","Exhibition"};
    vector <string> Hotel={"Food Court","Exhibition","Workshop","Main Conference","Banquet"};
    vector <string> convention_center={"Pre-concert","Main Concert","Workshop","Main Conference","Banquet","Food Court","Exhibition"};
    vector <string> concert_hall={"Pre Concert","Main Concert"};
    vector <Resevation> reserves_list;
    vector <Congregation*> congregation_list;
    vector <Venue> venues_list;
    vector <Program> program_list;
    vector <string> games_types={"Ceremony","Track and field","Indoor games","Water sports"};
    vector <string> confernce_types={"Workshop","Main Conference","Banquet"};
    vector <string> conventions_types={"Food Court","Exhibition","Workshop","Main Conference","Banquet"};
    // vector <vector<strings>>         //STrat WorkginG Fomr HEre
    void add_Venue(string venue_name,string location,string venue_type,string capacity){
        Venue v(venue_name,venue_type,location,capacity);
        venues_list.push_back(v);
        cout<<0<<endl;
        return;
    }
    void delete_venue(string venue_name,string country_name){
        int venue_exists=0;
        int ind=0;
        for(int i=0;i<venues_list.size();i++){
            if(venues_list[i].country_name==country_name && venues_list[i].venue_name==venue_name){
                venue_exists=1;
                ind=i;
                break;
            }
        }
        if(venue_exists==0){
            cout<<-1<<endl;
            cout<<"Error"<<endl;
            // cout<<"Venue does not exists"<<endl;
            return;
        }
        venues_list.erase(venues_list.begin()+ind);
        cout<<0<<endl;
    }
    void show_Venues(string location,string type="NONE"){
        int cnter=0;
        for(int i=0;i<location.size();i++){
            if(location[i]==':'){
                cnter++;
            }
        }
        string state="";
        string country="";
        string pincode="";
        string city_name="";
        string place_name="";
        int ind=0;
        if(cnter==4){
            while(location[ind]!=':'){
                place_name+=location[ind];
                ind++;
            }
            ind++;
            while(location[ind]!=':'){
                city_name+=location[ind];
                ind++;
            }
            ind++;
            while(location[ind]!=':'){
                state+=location[ind];
                ind++;
            }
            ind++;
            while(location[ind]!=':'){
                pincode+=location[ind];
                ind++;
            }
            ind++;
            while(ind<location.size()){
                country+=location[ind];
                ind++;
            }
        }
        else{
            // int ind=0;
            while(location[ind]!=':'){
                city_name+=location[ind];
                ind++;
            }
            ind++;
            while(location[ind]!=':'){
                state+=location[ind];
                ind++;
            }
            ind++;
            while(location[ind]!=':'){
                pincode+=location[ind];
                ind++;
            }
            ind++;
            while(ind<location.size()){
                country+=location[ind];
                ind++;
            }
        }
        int count=0;

        for(int i=0;i<venues_list.size();i++){
            if(city_name=="" && place_name=="" && pincode=="" && state=="" && country!=""){
                if(venues_list[i].country_name==country){
                    if(type=="NONE"){
                        count++;
                    }
                    else{
                        if(venues_list[i].venue_type==type){
                            count++;
                        }
                    }
                    // venues_list[i].display();
                }
            }
            else if(city_name!="" && place_name!="" && pincode!="" && state!="" && country!=""){
                if(venues_list[i].city_name==city_name && venues_list[i].country_name==country && venues_list[i].pincode==pincode && venues_list[i].place_name==place_name){
                    if(type=="NONE"){
                        count++;
                    }
                    else{
                        if(venues_list[i].venue_type==type){
                            count++;
                        }
                    }
                }
            }
            else if(city_name!="" && place_name!="" && pincode=="" && state!="" && country!=""){
                if(venues_list[i].city_name==city_name && venues_list[i].country_name==country && venues_list[i].place_name==place_name){
                    if(type=="NONE"){
                        count++;
                    }
                    else{
                        if(venues_list[i].venue_type==type){
                            count++;
                        }
                    }
                }
            }
            else if(city_name=="" && place_name=="" && pincode!="" && country!=""){
                if(venues_list[i].country_name==country && venues_list[i].pincode==pincode){
                    if(type=="NONE"){
                        count++;
                    }
                    else{
                        if(venues_list[i].venue_type==type){
                            count++;
                        }
                    }
                }
            }
            else if(place_name=="" && city_name!="" && state!="" && pincode=="" && country!=""){
                if(venues_list[i].country_name==country && venues_list[i].city_name==city_name && venues_list[i].state==state){
                    if(type=="NONE"){
                        count++;
                    }
                    else{
                        if(venues_list[i].venue_type==type){
                            count++;
                        }
                    }
                }
            }
        }
        
        cout<<count<<endl;

        for(int i=0;i<venues_list.size();i++){
            if(city_name=="" && place_name=="" && pincode=="" && state=="" && country!=""){
                if(venues_list[i].country_name==country){
                    if(type=="NONE"){
                        // count++;
                        venues_list[i].display();
                    }
                    else{
                        if(venues_list[i].venue_type==type){
                            // count++;
                            venues_list[i].display();
                        }
                    }
                    // venues_list[i].display();
                }
            }
            else if(city_name!="" && place_name!="" && pincode!="" && state!="" && country!=""){
                if(venues_list[i].city_name==city_name && venues_list[i].country_name==country && venues_list[i].pincode==pincode && venues_list[i].place_name==place_name){
                    if(type=="NONE"){
                        // count++;
                        venues_list[i].display();
                    }
                    else{
                        if(venues_list[i].venue_type==type){
                            // count++;
                            venues_list[i].display();
                        }
                    }
                }
            }
            else if(city_name!="" && place_name!="" && pincode=="" && state!="" && country!=""){
                if(venues_list[i].city_name==city_name && venues_list[i].country_name==country && venues_list[i].place_name==place_name){
                    if(type=="NONE"){
                        // count++;
                        venues_list[i].display();
                    }
                    else{
                        if(venues_list[i].venue_type==type){
                            // count++;
                            venues_list[i].display();
                        }
                    }
                }
            }
            else if(city_name=="" && place_name=="" && pincode!="" && country!=""){
                if(venues_list[i].country_name==country && venues_list[i].pincode==pincode){
                    if(type=="NONE"){
                        // count++;
                        venues_list[i].display();
                    }
                    else{
                        if(venues_list[i].venue_type==type){
                            // count++;
                            venues_list[i].display();
                        }
                    }
                }
            }
            else if(place_name=="" && city_name!="" && state!="" && pincode=="" && country!=""){
                // cout<<"checking the correct is else"<<endl;
                if(venues_list[i].country_name==country && venues_list[i].state==state && venues_list[i].city_name==city_name){
                    if(type=="NONE"){
                        // count++;
                        venues_list[i].display();
                    }
                    else{
                        if(venues_list[i].venue_type==type){
                            // count++;
                            venues_list[i].display();
                        }
                    }
                }
            }
        }
                            
    }
    void add_program(string congregation_name,string program_type,string program_name,string start_date,string end_date){
        int congregation_exists=0;
        int possible=1;
        for(int i=0;i<congregation_list.size();i++){
            if(congregation_list[i]->congregation_name==congregation_name){
                congregation_exists=1;
                if(date_comparator(congregation_list[i]->start_date,congregation_list[i]->end_date,start_date,end_date)==-1){
                    possible=0;
                }
                break;
            }
        }
        if(congregation_exists==0){
            cout<<-1<<endl;
            cout<<"Error"<<endl;
            // cout<<"The congregation does not exist"<<endl;
            return;
        }
        if(possible==0){
            cout<<-1<<endl;
            cout<<"Error"<<endl;
            // cout<<"The dates given for the program do not match the dates for the congregation"<<endl;
            return;
        }
        int found_type=0;
        for(int i=0;i<congregation_list.size();i++){
            if(congregation_list[i]->congregation_name==congregation_name){
                if(congregation_list[i]->allowed_types(program_type)==1){
                    found_type=1;
                    break;
                }
            }
        }
        if(found_type==1){
            Program p(program_name,program_type,start_date,end_date,congregation_name);
            program_list.push_back(p);
            cout<<0<<endl;
            return;
        }
        else{
            cout<<-1<<endl;
            cout<<"Error"<<endl;
            // cout<<"the program is not allowed for this congragation type"<<endl;
            return;
        }
    }
    void delete_program(string congregation_name,string program_name){
        int congregation_exist=0;
        int ind1=0;
        for(int i=0;i<congregation_list.size();i++){
            if(congregation_list[i]->congregation_name==congregation_name){
                congregation_exist=1;
                ind1=i;
                break;
                // return;
            }
        }
        if(congregation_exist==0){
            cout<<"-1"<<endl;
            cout<<"Error"<<endl;
            // cout<<"the congregation does not exist"<<endl;
            return;
        }
        int program_exist=0;
        int ind2=0;
        for(int i=0;i<program_list.size();i++){
            if(program_list[i].congregation_name==congregation_name && program_list[i].program_name==program_name){
                program_exist=1;
                ind2=i;
                break;
            }
        }
        if(program_exist==0){
            cout<<"-1"<<endl;
            cout<<"Error"<<endl;
            // cout<<"Program does not exist"<<endl;
            return;
        }
        int reservation_exist=0;
        for(int i=0;i<reserves_list.size();i++){
            // cout<<reserves_list[i].program_name<<" "<<program_name<<endl;
            if(reserves_list[i].program_name==program_name){
                reservation_exist=1;
                break;
            }
        }
        if(reservation_exist==1){
            cout<<-1<<endl;
            cout<<"Error"<<endl;
            // cout<<"there still exist a reservation for this"<<endl;
            return;
        }
        program_list.erase(program_list.begin()+ind2);
        cout<<0<<endl;
        return;
    }
    void show_program(string congregation_name){
        int cnt=0;
        for(int i=0;i<program_list.size();i++){
            if(program_list[i].congregation_name==congregation_name){
                // cout<<program_list[i].program_type<<" "<<program_list[i].program_name<<" "<<program_list[i].start_date<<" "<<program_list[i].end_date<<endl;
                cnt++;
            }
        }
        cout<<cnt<<endl;
        for(int i=0;i<program_list.size();i++){
            if(program_list[i].congregation_name==congregation_name){
                cout<<program_list[i].program_type<<" "<<program_list[i].program_name<<" "<<program_list[i].start_date<<" "<<program_list[i].end_date<<endl;
            }
        }
        return;
    }
    void add_congregation(string congregation_name,string congregation_type,string start_date, string end_date){
        int found=0;
        for(int i=0;i<congregation_list.size();i++){
            if(congregation_list[i]->congregation_name==congregation_name && congregation_list[i]->congregation_type==congregation_type){
                found=1;
                break;
            }
        }
        if(found==1){
            cout<<"-1"<<endl;
            cout<<"Error"<<endl;
            // cout<<"the congregation aldready exists"<<endl;
            return;
        }
        // cout<<"checking done"<<endl;
        if(congregation_type=="Games"){
            Congregation* c=new Games(congregation_name,congregation_type,start_date,end_date);
            congregation_list.push_back(c);
            cout<<0<<endl;
            // cout<<"games congregation added"<<endl;
        }
        else if(congregation_type=="Conference"){
            Congregation* c=new Conference(congregation_name,congregation_type,start_date,end_date);
            congregation_list.push_back(c);
            cout<<0<<endl;
        }
        else if(congregation_type=="Convention"){
            Congregation* c=new Conventions(congregation_name,congregation_type,start_date,end_date);
            congregation_list.push_back(c);
            cout<<0<<endl;
        }
        else if(congregation_type=="Concert"){
            Congregation* c=new Concert(congregation_name,congregation_type,start_date,end_date);
            congregation_list.push_back(c);
            cout<<0<<endl;
            // cout<<"concert congregation added"<<endl;
        }
        return;
    }

    void delete_congregation(string congregation_name){
        int found=0;
        int ind=0;
        int check=1;
        for(int i=0;i<congregation_list.size();i++){
            if(congregation_list[i]->congregation_name==congregation_name){
                found=1;
                ind=i;
                break;
            }
        }
        if(found==0){
            cout<<-1<<endl;
            cout<<"Error"<<endl;
            // cout<<"No such congregaiton exist"<<endl;
        }
        delete congregation_list[ind];
        congregation_list.erase(congregation_list.begin()+ind);
        cout<<0<<endl;
        return;
    }

    void show_congregation(){
        cout<<congregation_list.size()<<endl;
        for(int i=0;i<congregation_list.size();i++){
            congregation_list[i]->display();
        }
    }

    void reserve_venue(string congregation_name,string venue_name,string country_name,string progran_name){
        // cout<<"eneterd the reserve venue function"<<endl;
        int venue_exists=0;
        string venue_type;
        for(int i=0;i<venues_list.size();i++){
            if(venues_list[i].venue_name==venue_name && venues_list[i].country_name==country_name){
                venue_exists=1;
                venue_type=venues_list[i].venue_type;
                break;
            }
        }
        if(venue_exists==0){
            cout<<-1<<endl;
            cout<<"Error"<<endl;
            // cout<<"venue does not exist"<<endl;
            return;
        }
        int congregation_exists=0;
        for(int i=0;i<congregation_list.size();i++){
            if(congregation_list[i]->congregation_name==congregation_name){
                congregation_exists=1;
                break;
            }
        }
        if(congregation_exists==0){
            cout<<-1<<endl;
            cout<<"Error"<<endl;
            // cout<<"congregation does not exists"<<endl;
            return;
        }
        // cout<<"initial error checking done"<<endl;
        int program_exist=0;
        int indd=0;
        string p;
        string start_date;
        string end_date;
        for(int i=0;i<program_list.size();i++){
            if(program_list[i].program_name==progran_name){
                p=program_list[i].program_type;
                program_exist=1;
                break;
            }
        }
        if(program_exist==0){
            cout<<-1<<endl;
            cout<<"Error"<<endl;
            // cout<<"the program does not exists"<<endl;
            return;
        }
        for(int i=0;i<program_list.size();i++){
            if(program_list[i].program_name==progran_name){
                p=program_list[i].program_type;
                start_date=program_list[i].start_date;
                end_date=program_list[i].end_date;
                break;
            }
        }
        int program_type_allowed=0;
        if(venue_type=="Indoor Stadium"){
            for(int i=0;i<indoor_stadium.size();i++){
                if(indoor_stadium[i]==p){
                    program_type_allowed=1;
                    break;
                }
            }
        }
        else if(venue_type=="Outdoor Stadium"){
            for(int i=0;i<outdoor_stadium.size();i++){
                if(outdoor_stadium[i]==p){
                    program_type_allowed=1;
                    break;
                }
            }
        }
        else if(venue_type=="Hotel"){
            for(int i=0;i<Hotel.size();i++){
                if(Hotel[i]==p){
                    program_type_allowed=1;
                    break;
                }
            }
        }
        else if(venue_type=="Swimming Pool"){
            for(int i=0;i<swimming_pool.size();i++){
                if(swimming_pool[i]==p){
                    program_type_allowed=1;
                    break;
                }
            }
        }
        else if(venue_type=="Convention Center"){
            for(int i=0;i<convention_center.size();i++){
                if(convention_center[i]==p){
                    program_type_allowed=1;
                    break;
                }
            }
        }
        else if(venue_type=="Concert Hall"){
            for(int i=0;i<concert_hall.size();i++){
                if(concert_hall[i]==p){
                    program_type_allowed=1;
                    break;
                }
            }
        }
        if(program_type_allowed==0){
            cout<<-1<<endl;
            cout<<"Error"<<endl;
            // cout<<"this program is not allowed"<<endl;
            return;
        }
        int dates_collide=0;
        for(int i=0;i<reserves_list.size();i++){
            if(reserves_list[i].venue_name==venue_name){
                int a=date_compare(reserves_list[i].start_date,start_date);
                int b=date_compare(reserves_list[i].end_date,end_date);
                int c=date_compare(reserves_list[i].start_date,end_date);
                int d=date_compare(reserves_list[i].end_date,start_date);
                if(a==2 && d==1){
                    dates_collide=1;
                    break;
                }
                else if(c==2 && b==1){
                    dates_collide=1;
                    break;
                }
                else if(a==1 && c==2){
                    dates_collide=1;
                    break;
                }
            }
        }
        if(dates_collide==0){
            Resevation r(venue_name,country_name,congregation_name,progran_name,p,start_date,end_date);
            reserves_list.push_back(r);
            cout<<0<<endl;
            return;
        }
        else{
            cout<<-1<<endl;
            cout<<"Error"<<endl;
            // cout<<"the dates collide with each other"<<endl;
            return;
        }
    }

    void free_venue(string venue_name,string country,string congregation_name,string program_name){
        int found=0;
        int ind=0;
        vector <int> indexes;
        for(int i=0;i<reserves_list.size();i++){
            if(reserves_list[i].venue_name==venue_name && reserves_list[i].country_name==country && reserves_list[i].congregation_name==congregation_name && reserves_list[i].program_name==program_name){
                found=1;
                indexes.push_back(i);
                break;
            }
        }
        if(found==0){
            cout<<-1<<endl;
            cout<<"Error"<<endl;
            return;
        }
        for(int i=indexes.size()-1;i>=0;i--){
            reserves_list.erase(reserves_list.begin()+i);
        }
        cout<<0<<endl;
    }

    void show_reserved(string congregation_name){
        int found=0;
        for(int i=0;i<congregation_list.size();i++){
            if(congregation_list[i]->congregation_name==congregation_name){
                found=1;
            }
        }
        if(found==0){
            cout<<"-1"<<endl;
            cout<<"Error"<<endl;
            // cout<<"the congregation id d founded"<<endl;
            // return -1;
            return;
        }
        vector <For_show_reserve> v;
        for (int i=0;i<program_list.size();i++){
            int found=0;
            int index;
            for(int j=0;j<v.size();j++){
                if(program_list[i].program_name==v[j].program_name && program_list[i].program_type==v[j].program_type){
                    found=1;
                    index=j;
                    break;
                }
            }
            if(found==0){
                For_show_reserve sv(program_list[i].program_name,program_list[i].program_type);
                v.push_back(sv);
            }

        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<reserves_list.size();j++){
                if(v[i].program_name==reserves_list[j].program_name && v[i].program_type==reserves_list[j].program_type){
                    v[i].count++;
                }
            }
        }
        
        cout<<v.size()<<endl;

        for(int j=0;j<v.size();j++){
            cout<<v[j].program_name<<" "<<v[j].program_type<<" ";  //required print statements do not delete
            cout<<v[j].count<<endl;
            for(int i=0;i<reserves_list.size();i++){
                // if(reserves_list[i].congregation_name==congregation_name){
                // }
                if(reserves_list[i].program_name==v[j].program_name && reserves_list[i].program_type==v[j].program_type){
                    // reserves_list[i].display();
                    string venue_name=reserves_list[i].venue_name;
                    for(int k=0;k<venues_list.size();k++){
                        if(venues_list[k].venue_name==venue_name){
                            cout<<venues_list[k].venue_name<<" "<<venues_list[k].location<<" "<<venues_list[k].venue_type<<" "<<venues_list[k].capacity<<endl;
                        }
                    }
                }
            }
        }
    }
    ~Event_manamger(){
        for(int i=0;i<congregation_list.size();i++){
            delete congregation_list[i];
        }
    }
};

int main(int argc, char *argv[]){
    istream* input_stream;
    ifstream file;
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
    string line;
    Event_manamger manager;
    while(getline(cin,line)){
        stringstream ss(line);
        string command;
        ss>>command;
        if(command=="End"){
            // cout<<"Exiting the loop"<<endl;
            break;
        }
        else if(command=="addCongregation"){
            string congregation_name;
            string congregation_type;
            string start_date;
            string end_date;
            getline(ss,congregation_name,'"');
            getline(ss,congregation_name,'"');
            getline(ss,congregation_type,'"');
            getline(ss,congregation_type,'"');
            getline(ss,start_date,'"');
            getline(ss,start_date,'"');
            getline(ss,end_date,'"');
            getline(ss,end_date,'"');
            int val=date_compare(start_date,end_date);
            if(val==1){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                // cout<<"incorrect date"<<endl;
                continue;
            }
            manager.add_congregation(congregation_name,congregation_type,start_date,end_date);
        }
        else if(command=="deleteCongregation"){
            string congregation_name;
            getline(ss,congregation_name,'"');
            getline(ss,congregation_name,'"');
            manager.delete_congregation(congregation_name);
        }
        else if(command=="showCongregations"){
            manager.show_congregation();
        }
        else if(command=="addProgram"){
            string congregation_name;
            string start_date;
            string end_date;
            string program_type;
            string program_name;
            getline(ss,congregation_name,'"');
            getline(ss,congregation_name,'"');
            getline(ss,program_type,'"');
            getline(ss,program_type,'"');
            getline(ss,program_name,'"');
            getline(ss,program_name,'"');
            getline(ss,start_date,'"');
            getline(ss,start_date,'"');
            getline(ss,end_date,'"');
            getline(ss,end_date,'"');
            int val=date_compare(start_date,end_date);
            if(val==1){
                cout<<-1<<endl;
                cout<<"Error"<<endl;
                cout<<"the date does not match"<<endl;
                continue;
            }
            manager.add_program(congregation_name,program_type,program_name,start_date,end_date);
        }
        else if(command=="deleteProgram"){
            string congregation_name;
            string program_name;
            getline(ss,congregation_name,'"');
            getline(ss,congregation_name,'"');
            getline(ss,program_name,'"');
            getline(ss,program_name,'"');
            manager.delete_program(congregation_name,program_name);
        }
        else if(command=="showPrograms"){
            string congregation_name;
            getline(ss,congregation_name,'"');
            getline(ss,congregation_name,'"');
            manager.show_program(congregation_name);
        }
        else if(command=="addVenue"){
            string venue_name;
            string location;
            string venue_type;
            string capacity;
            getline(ss,venue_name,'"');
            getline(ss,venue_name,'"');
            getline(ss,location,'"');
            getline(ss,location,'"');
            getline(ss,venue_type,'"');
            getline(ss,venue_type,'"');
            ss>>capacity;
            ss>>capacity;
            manager.add_Venue(venue_name,location,venue_type,capacity);
        }
        else if(command=="deleteVenue"){
            string venue_name;
            string country_name;
            getline(ss,venue_name,'"');
            getline(ss,venue_name,'"');
            getline(ss,country_name,'"');
            getline(ss,country_name,'"');
            manager.delete_venue(venue_name,country_name);
        }
        else if(command=="showVenues"){
            string location;
            string b;
            getline(ss,location,'"');
            getline(ss,location,'"');
            if (std::getline(ss, b, '"') && std::getline(ss, b, '"')) {
            } else {
                b = "";
            }
            getline(ss,b,'"');
            getline(ss,b,'"');
            if(b!=""){
                // cout<<"WITH VENUE TYPE SHOW VENEUS CALLED"<<endl;
                manager.show_Venues(location,b);
            }
            else{
                // cout<<"WIHTOUT VENUE TYPE SHOW VENUES CALLED"<<endl;
                manager.show_Venues(location);
            }
        }
        else if(command=="reserveVenue"){
            string venue_name;
            string country_name;
            string congregation_name;
            string program_name;
            getline(ss,venue_name,'"');
            getline(ss,venue_name,'"');
            getline(ss,country_name,'"');
            getline(ss,country_name,'"');
            getline(ss,congregation_name,'"');
            getline(ss,congregation_name,'"');
            getline(ss,program_name,'"');
            getline(ss,program_name,'"');
            manager.reserve_venue(congregation_name,venue_name,country_name,program_name);
        }
        else if(command=="freeVenue"){
            string venue_name;
            string country_name;
            string congregation_name;
            string program_name;
            getline(ss,venue_name,'"');
            getline(ss,venue_name,'"');
            getline(ss,country_name,'"');
            getline(ss,country_name,'"');
            getline(ss,congregation_name,'"');
            getline(ss,congregation_name,'"');
            getline(ss,program_name,'"');
            getline(ss,program_name,'"');
            manager.free_venue(venue_name,country_name,congregation_name,program_name);
        }
        else if(command=="showReserved"){
            string congregation_name;
            getline(ss,congregation_name,'"');
            getline(ss,congregation_name,'"');
            manager.show_reserved(congregation_name);
        }
    }
}