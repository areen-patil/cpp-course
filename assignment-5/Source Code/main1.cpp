#include <bits/stdc++.h>
using namespace std;
enum diet_type{herbivore,carnivore};
enum size_type{small,medium,large};
enum bird_feed_type{grain,insect,fish};
enum aqua_feed_type{fishfood,livefish,plants};

class Zoo_species{
protected:
// public:
    string Species_name;
    int Species_count;
    char category_character;
public:
    Zoo_species(char category){
        // Species_count=count;
        // Species_name=speciiec_name;
        category_character=category;
    }
    void Set_name(string name){     //set the species name
        Species_name=name;
    }
    string Get_name(){      //return the species name
        return Species_name;
    }
    void Set_count(int count){       //set the species count
        Species_count=count;
    }
    void decrement_counter(int d_count){      //decrease the count of the particular species by count
        Species_count-=d_count;
    }
    void increment_coutner(int i_count){       //increase the count of the particular species by count
        Species_count+=i_count;
    }
    int Get_count(){       //return the count of the particular species
        return Species_count;
    }
    char get_category(){        //return the spesies type (M,R,B or Q)
        return category_character;
    }
    virtual void Set_diet_type(enum diet_type d){}  //all these are virtual functions which have been defined in their respective classes
    virtual void Set_feed_size(enum size_type d){} 
    virtual void Set_bird_feed(enum bird_feed_type d){}
    virtual void Set_aqua_feed(enum aqua_feed_type d){} 
    virtual void Print(){}
    virtual void Print_to_file(ofstream& file){}
    virtual string get_diet_type(){}
    virtual string get_feed_size(){}
    virtual string get_bird_feed(){}
    virtual string get_aqua_feed(){}
    virtual ~Zoo_species(){

    }
};

class Bird:public Zoo_species{
private:
    enum bird_feed_type Bird_feed;
public:
    Bird(char category_name):Zoo_species(category_name){

    }
    void Set_bird_feed(enum bird_feed_type d){
        Bird_feed=d;          //set the bird feed type
    }
    string get_bird_feed(){           //return the bird feed type
        if(Bird_feed==0){
            return "grain";
        }
        else if(Bird_feed==1){
            return "insect";
        }
        else if(Bird_feed==2){
            return "fish";
        }
    }
    void Print(){       //print the details of the bird species type
        if(Bird_feed==0){
            cout<<Species_name<<" "<<Species_count<<" "<<"grain"<<endl;
        }
        else if(Bird_feed==1){
            cout<<Species_name<<" "<<Species_count<<" "<<"insect"<<endl;

        }
        else if(Bird_feed==2){
            cout<<Species_name<<" "<<Species_count<<" "<<"fish"<<endl;
        }
    }
    void Print_to_file(ofstream& file){      //write the details to the file
        if(Bird_feed==0){
            file<<Species_name<<" "<<Species_count<<" "<<"grain"<<endl;
        }
        else if(Bird_feed==1){
            file<<Species_name<<" "<<Species_count<<" "<<"insect"<<endl;

        }
        else if(Bird_feed==2){
            file<<Species_name<<" "<<Species_count<<" "<<"fish"<<endl;
        }
    }

};

class Aquatic:public Zoo_species{
private:
enum aqua_feed_type Aqua_feed;
public:
    Aquatic(char category_name):Zoo_species(category_name){

    }
    void Set_aqua_feed(enum aqua_feed_type d){
        Aqua_feed=d;   //set the aqua feed type
    }
    string get_aqua_feed(){        //return the aqua feed type
        if(Aqua_feed==0){
            return "fishfood";
        }
        else if(Aqua_feed==1){
            return "livefish";
        }
        else if(Aqua_feed==2){
            return "plants";
        }
    }
    void Print(){ //print the details of the aquatic species type
        if(Aqua_feed==0){
            cout<<Species_name<<" "<<Species_count<<" "<<"fishfood"<<endl;
        }
        else if(Aqua_feed==1){
            cout<<Species_name<<" "<<Species_count<<" "<<"livefish"<<endl;
        }
        else if(Aqua_feed==2){
            cout<<Species_name<<" "<<Species_count<<" "<<"plants"<<endl;
        }
    }
    void Print_to_file(ofstream& file){   //write the details to the file
        if(Aqua_feed==0){
            file<<Species_name<<" "<<Species_count<<" "<<"fishfood"<<endl;
        }
        else if(Aqua_feed==1){
            file<<Species_name<<" "<<Species_count<<" "<<"livefish"<<endl;
        }
        else if(Aqua_feed==2){
            file<<Species_name<<" "<<Species_count<<" "<<"plants"<<endl;
        }
    }
};

class Mammal:public Zoo_species{
private:
    enum diet_type Diet_type;
public:
    Mammal(char category_name):Zoo_species(category_name){

    }
    void Set_diet_type(enum diet_type d){
        Diet_type=d;       //set the diet type
    }
    string get_diet_type(){  //return the diet type
        if(Diet_type==0){
            return "herbivore";
        }
        else{
            return "carnivore";
        }
    }
    void Print(){   //print the details of the mammal species type
        if(Diet_type==0){
            cout<<Species_name<<" "<<Species_count<<" "<<"herbivore"<<endl;
        }
        else{
            cout<<Species_name<<" "<<Species_count<<" "<<"carnivore"<<endl;
        }
    }
    void Print_to_file(ofstream& file){  //write the details to the file
        if(Diet_type==0){ 
            file<<Species_name<<" "<<Species_count<<" "<<"herbivore"<<endl;
        }
        else{
            file<<Species_name<<" "<<Species_count<<" "<<"carnivore"<<endl;
        }
    }
};

class Reptile:public Zoo_species{
private:
    enum size_type Feed_size;
public:
    Reptile(char category_name):Zoo_species(category_name){
        
    }
    void Set_feed_size(enum size_type d){
        Feed_size=d;        //set the feed size
    }
    string get_feed_size(){        //return the feed size
        if(Feed_size==0){
            return "small";
        }
        else if(Feed_size==1){
            return "medium";
        }
        else{
            return "large";
        }
    }
    void Print(){   //print the details of the reptiles species type
        if(Feed_size==0){
            cout<<Species_name<<" "<<Species_count<<" "<<"small"<<endl;
        }
        else if(Feed_size==1){
            cout<<Species_name<<" "<<Species_count<<" "<<"medium"<<endl;
        }
        else if(Feed_size==2){
            cout<<Species_name<<" "<<Species_count<<" "<<"large"<<endl;
        }
    }
    void Print_to_file(ofstream& file){  //write the details to the file
        if(Feed_size==0){
            file<<Species_name<<" "<<Species_count<<" "<<"small"<<endl;
        }
        else if(Feed_size==1){
            file<<Species_name<<" "<<Species_count<<" "<<"medium"<<endl;
        }
        else if(Feed_size==2){
            file<<Species_name<<" "<<Species_count<<" "<<"large"<<endl;
        }
    }
};

//ADD FUNCTION
void add(vector <Zoo_species*>&v,char category_character,string species_name,int count,string enum_string){
    if(category_character=='M'){
        for(int i=0;i<v.size();i++){
            string temp=v[i]->Get_name();
            // cout<<temp<<endl;
            if(v[i]->Get_name()==species_name && v[i]->get_diet_type()==enum_string){
                v[i]->increment_coutner(count);   //If the species_name and the diet_type aldready exists then just add the counter to the species_count
                return;
            }
            else if(v[i]->Get_name()==species_name && v[i]->get_diet_type()!=enum_string){
                // cout<<-1<<endl;
                cout<<"Error: ";
                cout<<"The species name exist but the type doesn't match"<<endl;
                return;
            }
        }
        if(enum_string=="herbivore"){
            Zoo_species* z=new Mammal(category_character);
            z->Set_diet_type(herbivore);     //set the diet type as herbivore
            z->Set_name(species_name);   //set the species_name as species_name
            z->Set_count(count);       //set the species_count count
            v.push_back(z);
        }
        else if(enum_string=="carnivore"){
            Zoo_species* z=new Mammal(category_character);
            z->Set_diet_type(carnivore);   //set the diet type as carnivore
            z->Set_name(species_name);   //set the species_name as species_name
            z->Set_count(count);         //set the species_count count
            v.push_back(z);
        }
    }
    else if(category_character=='B'){
        for(int i=0;i<v.size();i++){
            if(v[i]->Get_name()==species_name && v[i]->get_bird_feed()==enum_string){
                v[i]->increment_coutner(count);          //If the species with particular feed type aldready exists then add the count to the species
                return;
            }
            else if(v[i]->Get_name()==species_name && v[i]->get_bird_feed()!=enum_string){
                // cout<<-1<<endl;
                cout<<"Error: ";
                cout<<"The species name exists but the type doesn't match"<<endl;
                return;
            }
        }
        if(enum_string=="grain"){
            Zoo_species* z=new Bird(category_character);
            z->Set_bird_feed(grain);       //use the set method to set the bird feed type as grain
            z->Set_name(species_name);    //set the species_name as species_name
            z->Set_count(count);    //set the species_count count
            v.push_back(z);
        }
        else if(enum_string=="insect"){
            Zoo_species* z=new Bird(category_character);
            z->Set_bird_feed(insect);      //use the set method to set the bird feed type as insect
            z->Set_name(species_name);      //set the species_name as species_name
            z->Set_count(count);      //set the species_count count
            v.push_back(z);
        }
        else if(enum_string=="fish"){
            Zoo_species* z=new Bird(category_character);
            z->Set_bird_feed(fish);       //use the set method to set the bird feed type as fish
            z->Set_name(species_name);      //set the species_name as species_name
            z->Set_count(count);      //set the species_count count
            v.push_back(z);
        }
    }
    else if(category_character=='R'){
        for(int i=0;i<v.size();i++){
            if(v[i]->Get_name()==species_name && v[i]->get_feed_size()==enum_string){
                v[i]->increment_coutner(count);     //If the species with particular feed type aldready exists then add the count to the species
                return;
            }
            else if(v[i]->Get_name()==species_name && v[i]->get_feed_size()!=enum_string){
                // cout<<-1<<endl;
                cout<<"Error: ";
                cout<<"The species name exist but the type doesn't match"<<endl;
                return;
            }
        }
        if(enum_string=="small"){
            Zoo_species* z=new Reptile(category_character);
            z->Set_feed_size(small);       //set the feed type as small
            z->Set_name(species_name);       //set the species_name as species_name
            z->Set_count(count);        //set the species_count count
            v.push_back(z);
        }
        else if(enum_string=="medium"){
            Zoo_species* z=new Reptile(category_character);
            z->Set_feed_size(medium);  //set the feed type as medium
            z->Set_name(species_name);      //set the species_name as species_name
            z->Set_count(count);      //set the species_count count
            v.push_back(z);
        }
        else if(enum_string=="large"){
            Zoo_species* z=new Reptile(category_character);
            z->Set_feed_size(large);         //set the feed type as large
            z->Set_name(species_name);       //set the species_name as species_name
            z->Set_count(count);        //set the species_count count
            v.push_back(z);
        }
    }
    else if(category_character=='Q'){
        for(int i=0;i<v.size();i++){
            if(v[i]->Get_name()==species_name && v[i]->get_aqua_feed()==enum_string){
                v[i]->increment_coutner(count);     //If the species with particular feed type aldready exists then add the count to the species
                return;
            }
            else if(v[i]->Get_name()==species_name && v[i]->get_aqua_feed()!=enum_string){
                // cout<<-1<<endl;
                cout<<"Error: ";
                cout<<"The species name exist but the type doesn't match"<<endl;
                return;
            }
        }
        if(enum_string=="fishfood"){
            Zoo_species* z=new Aquatic(category_character);
            z->Set_aqua_feed(fishfood);     //set the aqua feed type as fishfood
            z->Set_name(species_name);   //set the species_name as species_name
            z->Set_count(count);      //set the species_count count
            v.push_back(z);
        }
        else if(enum_string=="livefish"){
            Zoo_species* z=new Aquatic(category_character);
            z->Set_aqua_feed(livefish);   //set the aqua feed type as livefish
            z->Set_name(species_name);   //set the species_name as species_name
            z->Set_count(count);      //set the species_count count
            v.push_back(z);
        }
        else if(enum_string=="plants"){
            Zoo_species* z=new Aquatic(category_character);
            z->Set_aqua_feed(plants);   //set the aqua feed type as plants
            z->Set_name(species_name);  //set the species_name as species_name
            z->Set_count(count);    //set the species_count count
            v.push_back(z);
        }
    }
    else{
        // cout<<-1<<endl;
        cout<<"Error: ";
        cout<<"The category does not exist"<<endl;
        return;
    }
    cout<<"Added Successfully"<<endl;
}

//THIS IS THE LOAD ADD FUNCTION THAT LOADS THE DATA FROM THE db.txt
void load_add(vector <Zoo_species*>&v,char category_character,string species_name,int count,string enum_string){
    if(category_character=='M'){
        for(int i=0;i<v.size();i++){
            string temp=v[i]->Get_name();
            // cout<<temp<<endl;
            if(v[i]->Get_name()==species_name && v[i]->get_diet_type()==enum_string){
                v[i]->increment_coutner(count);   //If the species_name and the diet_type aldready exists then just add the counter to the species_count
                return;
            }
            else if(v[i]->Get_name()==species_name && v[i]->get_diet_type()!=enum_string){
                // cout<<-1<<endl;
                cout<<"Error: ";
                cout<<"The species name exist but the type doesn't match"<<endl;
                return;
            }
        }
        if(enum_string=="herbivore"){
            Zoo_species* z=new Mammal(category_character);
            z->Set_diet_type(herbivore);     //set the diet type as herbivore
            z->Set_name(species_name);   //set the species_name as species_name
            z->Set_count(count);       //set the species_count count
            v.push_back(z);
        }
        else if(enum_string=="carnivore"){
            Zoo_species* z=new Mammal(category_character);
            z->Set_diet_type(carnivore);   //set the diet type as carnivore
            z->Set_name(species_name);   //set the species_name as species_name
            z->Set_count(count);         //set the species_count count
            v.push_back(z);
        }
    }
    else if(category_character=='B'){
        for(int i=0;i<v.size();i++){
            if(v[i]->Get_name()==species_name && v[i]->get_bird_feed()==enum_string){
                v[i]->increment_coutner(count);          //If the species with particular feed type aldready exists then add the count to the species
                return;
            }
            else if(v[i]->Get_name()==species_name && v[i]->get_bird_feed()!=enum_string){
                // cout<<-1<<endl;
                cout<<"Error: ";
                cout<<"The species name exists but the type doesn't match"<<endl;
                return;
            }
        }
        if(enum_string=="grain"){
            Zoo_species* z=new Bird(category_character);
            z->Set_bird_feed(grain);       //use the set method to set the bird feed type as grain
            z->Set_name(species_name);    //set the species_name as species_name
            z->Set_count(count);    //set the species_count count
            v.push_back(z);
        }
        else if(enum_string=="insect"){
            Zoo_species* z=new Bird(category_character);
            z->Set_bird_feed(insect);      //use the set method to set the bird feed type as insect
            z->Set_name(species_name);      //set the species_name as species_name
            z->Set_count(count);      //set the species_count count
            v.push_back(z);
        }
        else if(enum_string=="fish"){
            Zoo_species* z=new Bird(category_character);
            z->Set_bird_feed(fish);       //use the set method to set the bird feed type as fish
            z->Set_name(species_name);      //set the species_name as species_name
            z->Set_count(count);      //set the species_count count
            v.push_back(z);
        }
    }
    else if(category_character=='R'){
        for(int i=0;i<v.size();i++){
            if(v[i]->Get_name()==species_name && v[i]->get_feed_size()==enum_string){
                v[i]->increment_coutner(count);     //If the species with particular feed type aldready exists then add the count to the species
                return;
            }
            else if(v[i]->Get_name()==species_name && v[i]->get_feed_size()!=enum_string){
                // cout<<-1<<endl;
                cout<<"Error: ";
                cout<<"The species name exist but the type doesn't match"<<endl;
                return;
            }
        }
        if(enum_string=="small"){
            Zoo_species* z=new Reptile(category_character);
            z->Set_feed_size(small);       //set the feed type as small
            z->Set_name(species_name);       //set the species_name as species_name
            z->Set_count(count);        //set the species_count count
            v.push_back(z);
        }
        else if(enum_string=="medium"){
            Zoo_species* z=new Reptile(category_character);
            z->Set_feed_size(medium);  //set the feed type as medium
            z->Set_name(species_name);      //set the species_name as species_name
            z->Set_count(count);      //set the species_count count
            v.push_back(z);
        }
        else if(enum_string=="large"){
            Zoo_species* z=new Reptile(category_character);
            z->Set_feed_size(large);         //set the feed type as large
            z->Set_name(species_name);       //set the species_name as species_name
            z->Set_count(count);        //set the species_count count
            v.push_back(z);
        }
    }
    else if(category_character=='Q'){
        for(int i=0;i<v.size();i++){
            if(v[i]->Get_name()==species_name && v[i]->get_aqua_feed()==enum_string){
                v[i]->increment_coutner(count);     //If the species with particular feed type aldready exists then add the count to the species
                return;
            }
            else if(v[i]->Get_name()==species_name && v[i]->get_aqua_feed()!=enum_string){
                // cout<<-1<<endl;
                cout<<"Error: ";
                cout<<"The species name exist but the type doesn't match"<<endl;
                return;
            }
        }
        if(enum_string=="fishfood"){
            Zoo_species* z=new Aquatic(category_character);
            z->Set_aqua_feed(fishfood);     //set the aqua feed type as fishfood
            z->Set_name(species_name);   //set the species_name as species_name
            z->Set_count(count);      //set the species_count count
            v.push_back(z);
        }
        else if(enum_string=="livefish"){
            Zoo_species* z=new Aquatic(category_character);
            z->Set_aqua_feed(livefish);   //set the aqua feed type as livefish
            z->Set_name(species_name);   //set the species_name as species_name
            z->Set_count(count);      //set the species_count count
            v.push_back(z);
        }
        else if(enum_string=="plants"){
            Zoo_species* z=new Aquatic(category_character);
            z->Set_aqua_feed(plants);   //set the aqua feed type as plants
            z->Set_name(species_name);  //set the species_name as species_name
            z->Set_count(count);    //set the species_count count
            v.push_back(z);
        }
    }
    else{
        // cout<<-1<<endl;
        cout<<"Error: ";
        cout<<"The category does not exist"<<endl;
        return;
    }
    // cout<<"Added Successfully"<<endl;
}

//SHOW FUNCTION
void show(vector <Zoo_species*>&v,char category_character){
    if(category_character!='A' && category_character!='B' && category_character!='R' && category_character!='Q' && category_character!='M'){
        // cout<<-1<<endl;
        cout<<"Error: ";
        cout<<"The cateogry doestn match with anyone"<<endl;
        return;
    }
    if(category_character=='A'){
        // cout<<"identified that it show A"<<endl;
        int total_species=0;
        // for(int i=0;i<v.size();i++){     //Count the total number of species present in the zoo 
        //     // cout<<"iterating in the loop"<<endl;

        //     total_species+=v[i]->Get_count();
        //     // cout<<a<<endl;
        // }
        total_species=v.size();
        // cout<<"show A"<<endl;
        cout<<"total species "<<total_species<<endl;
        int mammal_count=0;
        int reptile_count=0;
        int bird_count=0;
        int aquatic_count=0;
        for(int i=0;i<v.size();i++){        //count the species number fro each type of the species type
            if(v[i]->get_category()=='M'){
                mammal_count++;
            }
            else if(v[i]->get_category()=='R'){
                reptile_count++;
            }
            else if(v[i]->get_category()=='B'){
                bird_count++;
            }
            else if(v[i]->get_category()=='Q'){
                aquatic_count++;
            }
        }
        cout<<"mammal "<<mammal_count<<endl;     //print all the mammals
        for(int i=0;i<v.size();i++){
            if(v[i]->get_category()=='M'){
                v[i]->Print();
            }
        }
        cout<<"reptile "<<reptile_count<<endl;  //print all the reptiles
        for(int i=0;i<v.size();i++){
            if(v[i]->get_category()=='R'){
                v[i]->Print();
            }
        }
        cout<<"bird "<<bird_count<<endl;   //print all the birds
        for(int i=0;i<v.size();i++){
            if(v[i]->get_category()=='B'){
                v[i]->Print();
            }
        }
        cout<<"aquatic "<<aquatic_count<<endl;  //print all the aquatic type species
        for(int i=0;i<v.size();i++){
            if(v[i]->get_category()=='Q'){
                v[i]->Print();
            }
        }
        return;
    }
    int category_count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]->get_category()==category_character){    //count of the given species type
            category_count++;
        }
    }
    cout<<"show "<<category_character<<endl;
    if(category_character=='M'){     //depending upon which species type it is print the count
        cout<<"mammal "<<category_count<<endl;
    }
    else if(category_character=='B'){
        cout<<"bird "<<category_count<<endl;
    }
    else if(category_character=='R'){
        cout<<"reptile "<<category_count<<endl;
    }
    else if(category_character=='Q'){
        cout<<"aquatic "<<category_count<<endl;
    }
    for(int i=0;i<v.size();i++){       //then print the details of that species type
        if(v[i]->get_category()==category_character){
            v[i]->Print();
        }
    }
    return;
}


//DELETE FUNCTION
void del(vector <Zoo_species*>&v,char category_character,string species_name,int count_dec){
    if(category_character!='B' && category_character!='R' && category_character!='Q' && category_character!='M'){
        // cout<<-1<<endl;
        cout<<"Error: ";
        cout<<"The cateogry doesnt match with anyone"<<endl;
        return;
    }
    int ind=0;
    int species_name_found=0;
    for(int i=0;i<v.size();i++){
        if(v[i]->Get_name()==species_name){
            species_name_found=1;
            ind=i;
            break;
        }
    }
    if(species_name_found==0){
        // cout<<-1<<endl;
        cout<<"Error: ";
        cout<<"The species with this name does not exists"<<endl;
        return;
    }
    if(v[ind]->Get_count()<count_dec){
        // cout<<-1<<endl;
        cout<<"Error: ";
        cout<<"The element to be removed is less"<<endl;
        return;
    }
    v[ind]->decrement_counter(count_dec);        //decrement the count of the particular species
    if(v[ind]->Get_count()==0){   //If after decrementing the counter for the particular species type the count becomes 0 then delete the particular species count
        v.erase(v.begin()+ind);
    }
    cout<<"Deleted Successfully"<<endl;
    return;
}
int main(){
    vector <Zoo_species*> v;
    int conter=0;
    ifstream file("db.txt");
    if (!file) {
        std::cerr << "File could not be opened!" << std::endl;       //print the error if the file could not be opened
    } else {                            //open the file db.txt and take in all the data and store it
        // cout<<"opened the file"<<endl;
        std::string line;
        string string_total;
        string string_species;
        file>>string_total;
        if(string_total=="total"){
            file>>string_species;
            int total_count;
            file>>total_count;
            string mammal_string;
            file>>mammal_string;
            int mammal_count;
            file>>mammal_count;
            for(int i=0;i<mammal_count;i++){
                string species_name;
                file>>species_name;
                int count_species;
                file>>count_species;
                string species_category;
                file>>species_category;
                load_add(v,'M',species_name,count_species,species_category);
            }
            // cout<<"mammal count done"<<endl;
            string reptile_string;
            file>>reptile_string;
            int reptile_count;
            file>>reptile_count;
            for(int i=0;i<reptile_count;i++){
                string species_name;
                file>>species_name;
                int count_species;
                file>>count_species;
                string species_category;
                file>>species_category;
                load_add(v,'R',species_name,count_species,species_category);
            }
            // cout<<"reptile adding  done"<<endl;
            string bird_string;
            file>>bird_string;
            int bird_count;
            file>>bird_count;
            for(int i=0;i<bird_count;i++){
                string species_name;
                file>>species_name;
                int count_species;
                file>>count_species;
                string species_category;
                file>>species_category;
                load_add(v,'B',species_name,count_species,species_category);
            }
            // cout<<"bird adding done"<<endl;
            string aquatic_string;
            file>>aquatic_string;
            int aquatic_count;
            file>>aquatic_count;
            for(int i=0;i<aquatic_count;i++){
                string species_name;
                file>>species_name;
                int count_species;
                file>>count_species;
                string species_category;
                file>>species_category;
                load_add(v,'Q',species_name,count_species,species_category);
            }
            // cout<<"aquatic animals added"<<endl;
        }
    }
    // cout<<"loaded the data"<<endl;
    file.close();         //after the data is loaded from the db.txt then close the file

    while(true){
        string command;
        cin>>command;
        string species_name;
        if(command=="add"){    //If the add function is ecncountered then call the add function 
            char category_character;
            int count;
            cin>>category_character;
            string enum_string;
            cin>>species_name;
            cin>>count;
            cin>>enum_string;
            // cout<<"add "<<species_name<<" "<<count<<" "<<category_character<<" "<<enum_string<<endl;
            add(v,category_character,species_name,count,enum_string);
        }
        else if(command=="show"){  //If the show function is ecncountered then call the show function
            char categorical_character;
            cin>>categorical_character;
            // cout<<"show "<<categorical_character<<endl;
            show(v,categorical_character);
        }
        else if(command=="delete"){    //If the del function is ecncountered then call the del function
            char categorical_character;
            cin>>categorical_character;
            cin>>species_name;
            int count;
            cin>>count;
            // cout<<"delete "<<species_name<<" "<<count<<" "<<categorical_character<<endl;
            del(v,categorical_character,species_name,count);
        }
        else{
            // cout<<"going to open the file now"<<endl;
            ofstream file("db.txt");           //If the exit command is encountered then store the data to the db.txt  , overwriting the old data 
            if (!file) {
                    cout << "File could not be opened!" << endl;
            } 
            else {
                // cout<<"going to write into the file"<<endl;
                int total_species=0;       //same as show A store the data in the db.txt      
                // for(int i=0;i<v.size();i++){
                //     total_species+=v[i]->Get_count();
                // } 
                total_species=v.size();
                file<<"total species "<<total_species<<endl;
                int mammal_count=0;
                int reptile_count=0;
                int bird_count=0;
                int aquatic_count=0;
                for(int i=0;i<v.size();i++){
                    if(v[i]->get_category()=='M'){
                        mammal_count++;
                    }
                    else if(v[i]->get_category()=='R'){
                        reptile_count++;
                    }
                    else if(v[i]->get_category()=='B'){
                        bird_count++;
                    }
                    else if(v[i]->get_category()=='Q'){
                        aquatic_count++;
                    }
                }
                file<<"mammal "<<mammal_count<<endl;
                for(int i=0;i<v.size();i++){
                    if(v[i]->get_category()=='M'){
                        v[i]->Print_to_file(file);
                        // string s=v[i]->spe
                    }
                }
                file<<"reptile "<<reptile_count<<endl;
                for(int i=0;i<v.size();i++){
                    if(v[i]->get_category()=='R'){
                        v[i]->Print_to_file(file);
                    }
                }
                file<<"bird "<<bird_count<<endl;
                for(int i=0;i<v.size();i++){
                    if(v[i]->get_category()=='B'){
                        v[i]->Print_to_file(file);
                    }
                }
                file<<"aquatic "<<aquatic_count<<endl;
                for(int i=0;i<v.size();i++){
                    if(v[i]->get_category()=='Q'){
                        v[i]->Print_to_file(file);
                    }
                }
            }
            file.close();   //close the file after storing the data to db.txt
            break;    //terminate the program
            cout<<"Ending the program"<<endl;
        }
    }
}