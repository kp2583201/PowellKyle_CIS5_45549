/* 
 * File:   main.cpp
 * Author: Kyle Powell
 * Created on July 15, 2017, 8:13 PM
 * Purpose: Star Search
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Format Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
void getJDat(float &,float &,float &,float &,float &);
void calcScr(float &,float &,float &,float &,float &);
int findLow(float &,float &,float &,float &,float &);
int fndHigh(float &,float &,float &,float &,float &);

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float j1,j2,j3,j4,j5;
    
    //Input data
    cout<<"This program determines the score of performers in a talent "
            "competition."<<endl;
    getJDat(j1,j2,j3,j4,j5);
    
    //Map inputs to outputs or process the data
    
    //Output the transformed data
    cout<<"This performer's average score was ";
    calcScr(j1,j2,j3,j4,j5);
    
    //Exit stage right!
    return 0;
}

void getJDat(float &j1,float &j2,float &j3,float &j4,float &j5){
    do{
    cout<<"Enter the first judge's score for the performer."<<endl;
    cin>>j1;
    if(j1<0||j1>10)cout<<"The score must be between 0-10, try again..."<<endl;
    }while(j1<0||j1>10);
    do{
    cout<<"Enter the second judge's score for the performer."<<endl;
    cin>>j2;
    if(j2<0||j2>10)cout<<"The score must be between 1-10, try again..."<<endl;
    }while(j2<0||j2>10);
    do{
    cout<<"Enter the third judge's score for the performer."<<endl;
    cin>>j3;
    if(j3<0||j3>10)cout<<"The score must be between 1-10, try again..."<<endl;
    }while(j3<0||j3>10);
    do{
    cout<<"Enter the fourth judge's score for the performer."<<endl;
    cin>>j4;
    if(j4<0||j4>10)cout<<"The score must be between 1-10, try again..."<<endl;
    }while(j4<0||j4>10);
    do{
    cout<<"Enter the fifth judge's score for the performer."<<endl;
    cin>>j5;
    if(j5<0||j5>10)cout<<"The score must be between 0-10, try again..."<<endl;
    }while(j5<0||j5>10);
}

void calcScr(float &j1,float &j2,float &j3,float &j4,float &j5){
    findLow(j1,j2,j3,j4,j5);
    fndHigh(j1,j2,j3,j4,j5);
    cout<<j1<<" "<<j2<<" "<<j3<<" "<<j4<<" "<<j5<<endl;
    float avrg=(j1+j2+j3+j4+j5)/3;
    cout<<avrg<<endl;
}

int findLow(float &j1,float &j2,float &j3,float &j4,float &j5){
    if(j1<j2&&j1<j3&&j1<j4&&j1<j5){
        j1=0;return j1;}
    if(j2<j3&&j2<j4&&j2<j5&&j2<j1){
        j2=0;return j2;}
    if(j3<j4&&j3<j5&&j3<j1&&j3<j4){
        j3=0;return j3;}
    if(j4<j5&&j4<j1&&j4<j2&&j4<j3){
        j4=0;return j4;}
    if(j5<j1&&j5<j2&&j5<j3&&j5<j4){
        j5=0;return j5;}
    cout<<j1<<j2<<j3<<j4<<j5<<endl;
}

int fndHigh(float &j1,float &j2,float &j3,float &j4,float &j5){
    if(j1>j2&&j1>j3&&j1>j4&&j1>j5){
        j1=0;return j1;}
    if(j2>j3&&j2>j4&&j2>j5&&j2>j1){
        j2=0;return j2;}
    if(j3>j4&&j3>j5&&j3>j1&&j3>j4){
        j3=0;return j3;}
    if(j4>j5&&j4>j1&&j4>j2&&j4>j3){
        j4=0;return j4;}
    if(j5>j1&&j5>j2&&j5>j3&&j5>j4){
        j5=0;return j5;}
    cout<<j1<<j2<<j3<<j4<<j5<<endl;
}
