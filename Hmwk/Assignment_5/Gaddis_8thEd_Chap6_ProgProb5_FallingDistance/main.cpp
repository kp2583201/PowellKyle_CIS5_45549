/* 
 * File:   main.cpp
 * Author: Kyle Powell
 * Created on July 15, 2017, 6:15 PM
 * Purpose:  Falling Distance
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cmath>     //Math Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
float falDist(float, float, float);

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float d, g=9.8f, t=1;
    
    //Output the transformed data
    while(t<10){
        cout<<"After "<<t<<" second(s) an object has fallen "<<falDist(g,t,d)
                <<" meters"<<endl;
        t++;}
    
    //Exit stage right!
    return 0;
}

float falDist(float g, float t, float d){
    d=.5f*g*pow(t,2);
    return d;
}
