/* 
 * File:   main.cpp
 * Author: Kyle Powell
 * Created on July 15, 2017, 2:30 PM
 * Purpose:  Safest Driving Area
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
int getNAcc(int &,int &,int &,int &,int &);//Getting numb of accidents in city regions
void findLow(int &,int &,int &,int &,int &);//Finding city region with lowest accidents

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    int n,s,e,w,c;//regions in a city
    
    //Input data
    getNAcc(n,s,e,w,c);
    
    //Output the transformed data
    findLow(n,s,e,w,c);
    
    //Exit stage right!
    return 0;
}

int getNAcc(int &n, int &s, int &e, int &w, int &c){
    do{
    cout<<"Enter the number of accidents reported in the North region: ";
    cin>>n;
    if(n<0)cout<<"The number of accidents reported must be positive.";
    }while(n<0);
    do{
    cout<<"Enter the number of accidents reported in the South region: ";
    cin>>s;
    if(s<0)cout<<"The number of accidents reported must be positive.";
    }while(s<0);
    do{
    cout<<"Enter the number of accidents reported in the East region: ";
    cin>>e;
    if(e<0)cout<<"The number of accidents reported must be positive.";
    }while(e<0);
    do{
    cout<<"Enter the number of accidents reported in the West region: ";
    cin>>w;
    if(w<0)cout<<"The number of accidents reported must be positive.";
    }while(w<0);
    do{
    cout<<"Enter the number of accidents reported in the Central region: ";
    cin>>c;
    if(c<0)cout<<"The number of accidents reported must be positive.";
    }while(c<0);
    return n,s,e,w,c;
}

void findLow(int &n,int &s,int &e,int &w,int &c){
    if(n<s&&n<e&&n<w&&n<c){
        cout<<"The North region had the lowest number of reported accidents.";
    }else if(s<e&&s<w&&s<c&&s<n){
        cout<<"The South region had the lowest number of reported accidents.";
    }else if(e<w&&e<c&&e<n&&e<s){
        cout<<"The East region had the lowest number of reported accidents.";
    }else if(w<c&&w<n&&w<s&&w<e){
        cout<<"The West region had the lowest number of reported accidents.";
    }else if(c<n&&c<s&&c<e&&c<w){
        cout<<"The Central region had the lowest number of reported accidents.";
    }else cout<<"No regions had the lowest number of reported accidents.";
}
