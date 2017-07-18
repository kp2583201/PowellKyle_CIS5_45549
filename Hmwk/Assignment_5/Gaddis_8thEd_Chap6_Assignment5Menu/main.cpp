/* 
 * File:   main.cpp
 * Author: Kyle Powell
 * Created on July 17, 2017, 10:40 PM
 * Purpose:  Menu for Assignment 5
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Format Library
#include <cmath>     //Math Library
#include <string.h>
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const int CNVPERC=100;//Conversion to Percentage

//Function Prototypes
float markup(float, float, float,float);//function for markup

float getS1(float);//ne region sales
float getS2(float);//se region sales
float getS3(float);//nw region sales
float getS4(float);//sw region sales
void fndHigh(float &, float &, float &, float &);//finding region with highest sales

int getNAcc(int &,int &,int &,int &,int &);//Getting numb of accidents in city regions
void findLow(int &,int &,int &,int &,int &);//Finding city region with lowest accidents
float falDist(float, float, float);//function calculating distance fallen

bool isLpYr(int); 
char getCent(int); 
char getYear(int); 
char getMnth(string,int); 
char getDay(string); 
void getDate(string &,string &,short &); 
string result(char); 

float fValue1(float,float,int);
float fValue2(float,float,int);
float fValue3(float,float,int);
float fValue4(float,float,int);

void getJDat(float &,float &,float &,float &,float &);//Judge scores
void calcScr(float &,float &,float &,float &,float &);//calculates overall score
int findLow(float &,float &,float &,float &,float &);//finds lowest score
int fndHigh(float &,float &,float &,float &,float &);//finds highest score

//Execution begins here
int main(int argc, char** argv) {
    
    //Declare Variables
    char choice;
    
    //Loop on Menu
    do{
        
        //Input Data
        cout<<"Choose a Program from the List:"<<endl;
        cout<<"Type 1 For Problem 1, Markup."<<endl;
        cout<<"Type 2 For Problem 3, Winning Division."<<endl;
        cout<<"Type 3 For Problem 4, Safest Driving Area."<<endl;
        cout<<"Type 4 For Problem 5, Falling Distance."<<endl;
        cout<<"Type 5 For Problem 7, Day of Week."<<endl;
        cout<<"Type 6 For Problem 10, Future Value."<<endl;
        cout<<"Type 7 For Problem 12, Star Search."<<endl;
        cout<<"Type Any Other Number to Exit."<<endl;
        cin>>choice;
        cout<<endl;

        //Switch Statement for Menu
        switch(choice){
            case '1':{
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
                cout<<"The item's retail price is: $"
                        <<markup(cost,perc,cInc,tCost)<<endl;
                cout<<endl<<endl;
                break;
            }case'2':{
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
                cout<<"Which division had the highest gross sales for the "
                        "quarter?"<<endl;
                fndHigh(ne,se,nw,sw);
                cout<<endl<<endl;
                break;
            }case'3':{
                //Declare variables
                int n,s,e,w,c;//regions in a city

                //Input data
                getNAcc(n,s,e,w,c);

                //Output the transformed data
                findLow(n,s,e,w,c);
                cout<<endl<<endl;
                break;
            }case'4':{
                //Declare variables
                float d, g=9.8f, t=1;

                //Output the transformed data
                while(t<10){
                    cout<<noshowpoint<<"After "<<t<<" second(s) an object has fallen "
                            <<falDist(g,t,d)<<" meters"<<endl;
                    t++;}
                cout<<endl<<endl;
                break;
            }case'5':{
                //Declare variables 
                string sMonth;//Month as a string 
                string sDay;  //Day as a string 
                short  nYear; //Year as an integer 

                //Input data 
                getDate(sMonth,sDay,nYear); 

                //Map inputs to outputs or process the data 
                char day=(getDay(sDay) +  
                          getMnth(sMonth,nYear) +  
                          getYear(nYear) +  
                          getCent(nYear))%7; 

                //Output the results, i.e. which day of the week 
                cout<<endl<<"Day of the week = "<<result(day)<<endl; 
                cout<<endl<<endl;
                break;
            }case'6':{
               //Declare variables
                float pv,//Present Value in $
                        i;//Interest Rate percent/compounding period
                int n;//Number of compounding periods (yrs)

                //Input data - Prompt for input
                cout<<"This is a Savings Account Program"<<endl;
                cout<<"Input Present Value in Dollars, "<<endl;
                cout<<"Interest Rate in percent/year, "<<endl;
                cout<<"Number of Compounding Periods in years."<<endl;
                cin>>pv>>i>>n;

                //Map the inputs
                i/CNVPERC;//Convert percentage interest to fraction

                //Output the inputs
                cout<<fixed<<setprecision(2)<<showpoint;
                cout<<endl;
                cout<<"The Present Value =  $"<<setw(8)<<pv<<endl;
                cout<<"The Interest Rate =   "<<setw(8)<<i<<"%"<<endl;
                cout<<"The Number of Years = "<<setw(5)<<n<<endl;

                //Output the transformed data
                cout<<"Savings Function 1 -> Power      = $"<<fValue1(pv,i,n)
                        <<endl;
                cout<<"Savings Function 2 -> Exp - Log  = $"<<fValue2(pv,i,n)
                        <<endl;
                cout<<"Savings Function 3 -> for - loop = $"<<fValue3(pv,i,n)
                        <<endl;
                cout<<"Savings Function 4 -> Recursion  = $"<<fValue4(pv,i,n)
                        <<endl;
                cout<<endl<<endl;
                break;
            }case'7':{
                //Declare variables
                float j1,j2,j3,j4,j5;

                //Input data
                cout<<"This program determines the score of performers in a "
                        "talent competition."<<endl;
                getJDat(j1,j2,j3,j4,j5);

                //Output the transformed data
                cout<<"This performer's average score was ";
                calcScr(j1,j2,j3,j4,j5);
                cout<<endl<<endl;
                break;
            }
        }
    }while(choice>='1'&&choice<='7');    
    
    //Exit stage right!
    return 0;
}

float markup(float cost, float perc, float cInc, float tCost){
    perc/=100;
    cInc=cost*perc;
    tCost=cost+cInc;
    return tCost;
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
    if(ne>se&&ne>nw&&ne>sw){
        cout<<"The Northeast division had the highest gross sales for the "
            "quarter, with $"<<ne<<"."<<endl;
    }else if(se>ne&&se>nw&&se>sw){
        cout<<"The Southeast division had the highest gross sales for the "
                "quarter, with $"<<se<<"."<<endl;
    }else if(nw>ne&&nw>se&&nw>sw){
        cout<<"The Northwest division had the highest gross sales for the "
                "quarter, with $"<<nw<<"."<<endl;
    }else if(sw>ne&&sw>se&&sw>nw){
        cout<<"The Southwest division had the highest gross sales for the "
                "quarter, with $"<<sw<<"."<<endl;
    }else {
        cout<<"No division had the highest gross sales for the quarter."<<endl;
    }
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


float falDist(float g, float t, float d){
    d=.5f*g*pow(t,2);
    return d;
}


string result(char day){ 
     string msg; 
     switch(day){ 
         case 0:msg="Sunday";break; 
         case 1:msg="Monday";break; 
         case 2:msg="Tuesday";break; 
         case 3:msg="Wednesday";break; 
         case 4:msg="Thursday";break; 
         case 5:msg="Friday";break; 
         default:msg="Saturday"; 
     } 
     return msg; 
 } 
 
 void getDate(string &sMonth,string &sDay,short &nYear){ 
     cout<<"This program takes in a date and returns "; 
     cout<<"the day of the week"<<endl; 
     cout<<"Input date in the following format July 4, 2008"<<endl; 
     cin>>sMonth>>sDay>>nYear; 
 } 

 char getDay(string sDay){ 
     char len=0; 
     while(sDay[++len]==','); 
     if(len==2)return (sDay[0]-48); 
     return (sDay[0]-48)*10+(sDay[1]-48); 
 } 
 
   char getMnth(string month,int year){ 
     if(month=="January"){ 
         if(isLpYr(year))return 6; 
         return 0; 
     }else if(month=="February"){ 
         if(isLpYr(year))return 2; 
         return 3; 
     }else if(month=="March"||month=="November"){ 
         return 3; 
     }else if(month=="April"||month=="July"){ 
         return 6; 
     }else if(month=="May"){ 
         return 1; 
     }else if(month=="June"){ 
         return 4; 
     }else if(month=="August"){ 
         return 2; 
     }else if(month=="September"||month=="December"){ 
         return 5; 
     }else return 0; 
 } 
 
 char getYear(int year){ 
     year%=100; 
     return year+year/4; 
 } 
 
 char getCent(int year){ 
     char cent=year/100; 
     char remndr=cent%4; 
     return 2*(3-remndr); 
 } 
 
 bool isLpYr(int year){ 
     return ((year%400==0)||((year%4==0)&&!(year%100==0))); 
 } 

 
 //                     Future Value
//Inputs:
//   pVal ->    Present Value $
//   intRate -> Interest Rate as a fraction
//   nPds ->    Number of Compounding Periods (Yrs)
//Output:
//   Future Value -> Units of $
float fValue1(float pVal, float intRate, int nPds){
    return pVal*pow((1+intRate),nPds);
}

float fValue2(float pVal, float intRate, int nPds){
    return pVal*exp(nPds*log(1+intRate));
}

float fValue3(float pVal, float intRate, int nPds){
    float fv=pVal;
    for(int i=1; i<=nPds; i++){
        fv*=(1+intRate);
    }
    return fv;
}

float fValue4(float pVal, float intRate, int nPds){
    if(nPds<=0) return pVal;
    return fValue4 (pVal, intRate, nPds-1)*(1+intRate);
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

 