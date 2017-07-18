/* 
 * File:   main.cpp
 * Author: Kyle Powell
 * Created on July 13, 2017, 4:15 PM
 * Purpose:  Winning Division
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
float getS1(float);
float getS2(float);
float getS3(float);
float getS4(float);
void fndHigh(float &, float &, float &, float &);

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float ne, se, nw, sw;
    
    //Input data
    cout<<"Northeast division"<<endl;
    ne=getS1(ne);
    cout<<"You entered $"<<ne<<" for the Northeast division's "
            "quarterly sales figure. "<<endl<<endl;
    cout<<"Northwest division"<<endl;
    se=getS2(se);
    cout<<"You entered $"<<se<<" for the Northwest division's "
            "quarterly sales figure."<<endl<<endl;
    cout<<"Southeast division"<<endl;
    nw=getS3(nw);
    cout<<"You entered $"<<nw<<" for the Southeast division's "
            "quarterly sales figure."<<endl<<endl;
    cout<<"Southwest division"<<endl;
    sw=getS4(sw);
    cout<<"You entered $"<<sw<<" for the Southwest division's "
            "quarterly sales figure."<<endl<<endl;
    
    //Output the transformed data
    cout<<"Which division had the highest gross sales for the quarter?"<<endl;
    fndHigh(ne,se,nw,sw);
    
    //Exit stage right!
    return 0;
}

float getS1(float ne){
    do{
    cout<<"Enter the Northeast division's quarterly sales figure: $";
    cin>>ne;
    return ne;
    if(ne<0)cout<<"Sales must be greater than $0.00, try again..."<<endl;
    }while(ne<0);
}

float getS2(float se){
    do{
    cout<<"Enter the Southeast division's quarterly sales figure: $";
    cin>>se;
    return se;
    if(se<0)cout<<"Sales must be greater than $0.00, try again..."<<endl;
    }while(se<0);
}

float getS3(float nw){
    do{
    cout<<"Enter the Northwest division's quarterly sales figure: $";
    cin>>nw;
    return nw;
    if(nw<0)cout<<"Sales must be greater than $0.00, try again..."<<endl;
    }while(nw<0);
}

float getS4(float sw){
    do{
    cout<<"Enter the Southwest division's quarterly sales figure: $";
    cin>>sw;
    return sw;
    if(sw<0)cout<<"Sales must be greater than $0.00, try again..."<<endl;
    }while(sw<0);
}

void fndHigh(float &ne, float &se, float &nw, float &sw){
    cout<<ne<<" "<<se<<" "<<nw<<" "<<sw<<endl;
    if(ne>se||ne>nw||ne>sw){
        cout<<"The Northeast division had the highest gross sales for the "
            "quarter, with $"<<ne<<"."<<endl;
    }else if(se>ne||se>nw||se>sw){
        cout<<"The Southeast division had the highest gross sales for the "
                "quarter, with $"<<se<<"."<<endl;
    }else if(nw>ne||nw>se||nw>sw){
        cout<<"The Northwest division had the highest gross sales for the "
                "quarter, with $"<<nw<<"."<<endl;
    }else if(sw>ne||sw>se||sw>nw){
        cout<<"The Southwest division had the highest gross sales for the "
                "quarter, with $"<<sw<<"."<<endl;
    }else {
        cout<<"No division had the highest gross sales for the quarter."<<endl;
    }
}
