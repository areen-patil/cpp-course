#include <bits/stdc++.h>
using namespace std;
// class Base {
//     private : int i ;
//     protected : int j ;
//     public : int k ;
//     int hello;
// } ;
// class Der : public Base {
//     private : int i ;
//     protected : int y ;
//     public : int z ;
//     int hello;
// };
// class Vehicle {
//   private :
//       int _mass;
//       int mass_speed;
//   public :
//       Vehicle ( int mass, int some ) {
//             _mass = mass;
//             mass_speed=some;
//       }
//       void display(){
//         cout<< _mass<<endl;
//         cout<<mass_speed<<endl;
//       }
// } ;
// class LandVehicle : public Vehicle {
//   private :
//       int _speed;
//   public :
//       LandVehicle ( int mass, int speed ) :
//  	Vehicle (mass,speed){
//         // _speed=speed;
//     }
//     void display(){
//         Vehicle :: display();
//         cout<< _speed<<endl;
//     }
// } ;

// int main( ) {
//     Base bobj; Der dobj;
//     LandVehicle lv(23,32);
//     lv.display();
//     // cout << sizeof ( bobj ) <<" "<< sizeof ( dobj );
// }

// class Sample {
//   protected : int i ;
//   public :
//       Sample ( int j ) {
//             i = j;
//       }
//       Sample () = default; /* default 
//           constructor is re-instated */
//       Sample (const Sample& s) = 
// 	delete; /* default copy constructor
// 		is explicitly deleted */
//       Sample& operator=(const Sample& s) = 
// 	delete; /* default assignment 
// 	    operator is explicitly deleted */
// } ;
// class Sample1 {
//   protected : int i ;
//   public :
//       Sample1 ( int j ) {i = j;}
//       Sample1 (const Sample1& s) : i {s.i} {}
// } ;
// class NewSample : public Sample1 {
//   private : int m;
//   public :
//       NewSample(int k): Sample1 (k) { m = 2 * i; }
//       NewSample(const NewSample& n) :
// 	Sample1{n}, /* copy base */
// 	m{n.m} /* copy data member */ {}
//     void display(){
//         cout<<"m: "<<m<<endl;
//         cout<<"i: "<<i<<endl;
//     }
// } ;
// int main () {
//      NewSample ns1{2}; NewSample ns2{ns1};
//     //  cout<<ns2.m<<endl;
//     ns2.display();
// }

#include <iostream>
using namespace std ; 
class Shape { // abstract class
    public :
        virtual void draw( ) = 0; /* pure
		virtual function */
};

class Circle : public Shape {
    public :
        void draw( ) {
             cout << "Circle" <<endl;
        }
};

class Rectangle : public Shape {
    public :
        void draw( ) {
            cout << "Rectangle" <<endl;
        }
};

int main( ) {
    Circle c1, c2, c3, c4, c5; 
    Rectangle r1, r2, r3, r4, r5 ; 
    Shape *p[10]={&c1,&r4,&c4,&c3,&r5,&r2,&r1,&c2,&c5,&r3};
    for(int i=0;i<=9;i++)
	p[i]-> draw(); /* order is 
		preserved */
}
