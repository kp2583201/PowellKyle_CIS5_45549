/* 
 * File:   main.cpp
 * Author: Kyle Powell
 * Created on July 13, 2017, 3:33 PM
 * Purpose:  Markup
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Format Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
float markup(float, float, float,float);

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float perc, cInc, tCost, cost;
    
    //Input data
    cout<<"Enter an item's wholesale cost: $";
    cin>>cost;
    cout<<"Enter the item's markup percentage: ";
    cin>>perc;
    
    //Map inputs to outputs or process the data
    
    //Output the transformed data
    cout<<setprecision(2)<<fixed<<showpoint<<endl;
    cout<<"The item's retail price is: $"<<markup(cost,perc,cInc,tCost)<<endl;
    
    //Exit stage right!
    return 0;
}

float markup(float cost, float perc, float cInc, float tCost){
    perc/=100;
    cInc=cost*perc;
    tCost=cost+cInc;
    return tCost;
    
}