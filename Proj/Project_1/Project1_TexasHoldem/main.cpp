/* 
 * File:   main.cpp
 * Author: Kyle Powell
 * Created on July 17, 2017, 11:45 PM
 * Purpose: Five Card Stud
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cstdlib>   //Random number library
#include <ctime>     //Time library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
char suit1(char);
char face1(char);
char suit2(char);
char face2(char);

//Execution begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    char hCard1,hCard2,oHCard1,oHCard2;//cards dealt to hand player & opponent
    
    //Initialize variables
    hCard1=rand()%52+1;
    hCard2=rand()%52+1;
    oHCard1=rand()%52+1;
    oHCard2=rand()%52+1;
    //hCard5=rand()%52+1;
    
    
    //Input data
    
    //Map inputs to outputs or process the data
    
    //Community Cards
    
    //Opponent's Hole Cards
    
    //Player's Hole Cards
    cout<<"Your Hand"<<endl;
    cout<<"Card = "<<face1(hCard1)<<suit1(hCard1)<<endl;
    cout<<"Card = "<<face2(hCard2)<<suit2(hCard2)<<endl;
    
    //Exit stage right!
    return 0;
}

char face1(char hCard1){
    switch(hCard1%13){
        case 1:return 'A';
        case 2:return '2';
        case 3:return '3';
        case 4:return '4';
        case 5:return '5';
        case 6:return '6';
        case 7:return '7';
        case 8:return '8';
        case 9:return '9';
        case 10:return 'T';
        case 11:return 'J';
        case 12:return 'Q';
        default:return 'K';
    }
}

char suit1(char hCard1){
    if(hCard1<=13)return 'S';//S -> Spades
    if(hCard1<=26)return 'D';//D -> Diamond
    if(hCard1<=39)return 'C';//C -> Clubs
    return 'H';//H -> Hearts;
}

char face2(char hCard2){
    switch(hCard2%13){
        case 1:return 'A';
        case 2:return '2';
        case 3:return '3';
        case 4:return '4';
        case 5:return '5';
        case 6:return '6';
        case 7:return '7';
        case 8:return '8';
        case 9:return '9';
        case 10:return 'T';
        case 11:return 'J';
        case 12:return 'Q';
        default:return 'K';
    }
}

char suit2(char hCard2){
    if(hCard2<=13)return 'S';//S -> Spades
    if(hCard2<=26)return 'D';//D -> Diamond
    if(hCard2<=39)return 'C';//C -> Clubs
    return 'H';//H -> Hearts;
}
