/* 
 * File:   main.cpp
 * Author: Kyle Powell
 * Created on July 17, 2017, 11:45 PM
 * Purpose: Texas Hold'em 
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cstdlib>   //Random number library
#include <ctime>     //Time library
#include <string>    //String Library
#include <iomanip>   //format library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes
char suit(char);
char face(char);

//Execution begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    char hCard1,hCard2,oHCard1,oHCard2;//cards dealt to hand player & opponent
    int coCard1,coCard2,coCard3,coCard4,coCard5;//community cards
    string bet;//call or fold choice
    
    //Map inputs to outputs or process the data
    
    //Pre-Flop (Deal cards to players)
        //Opponent's Hole Cards
        oHCard1=rand()%52+1;
        oHCard2=rand()%52+1;
        //cout<<face(oHCard2)<<suit(oHCard2)<<endl;//test
        if(face(oHCard1)==face(oHCard2)&&suit(oHCard1)==suit(oHCard2)){
            while(oHCard2==oHCard1){
                oHCard2=rand()%52+1;
            }
        }
        /*//Remove (only for test)
        cout<<"Your Opponent's Hand"<<endl;
        cout<<"Card = "<<face(oHCard1)<<suit(oHCard1)<<endl;
        cout<<"Card = "<<face(oHCard2)<<suit(oHCard2)<<endl;*/

        //Player's Hole Cards
        hCard1=rand()%52+1;
        hCard2=rand()%52+1;
        //cout<<face(hCard1)<<suit(hCard1)<<endl;//test
        //cout<<face(hCard2)<<suit(hCard2)<<endl;//test
        cout<<"Your Hand"<<endl;
        if(hCard1==oHCard1||hCard1==oHCard2){
            while(hCard1==oHCard1||hCard1==oHCard2){
                hCard1=rand()%52+1;
                //cout<<"DO W 1 "<<face(hCard1)<<suit(hCard1)<<endl;//test
            }
        }
        if(hCard2==oHCard1||hCard2==oHCard2||hCard1==hCard2){
            do{
                hCard2=rand()%52+1;
                //cout<<"DO W 2 "<<face(hCard2)<<suit(hCard2)<<endl;//test
            }while(hCard2==oHCard1||hCard2==oHCard2||hCard1==hCard2);
        }
        cout<<"Card = "<<face(hCard1)<<suit(hCard1)<<endl;
        cout<<"Card = "<<face(hCard2)<<suit(hCard2)<<endl<<endl;
        
        //Input data
        cout<<"Your opponent placed an initial bet of $0 into the pot. "
                "Do you want to call or fold? (Enter \"call\" or \"fold\" "
                "to choose) "<<endl;
        cin>>bet;
        if(bet=="call"){
            cout<<"You called your opponent's bet of $0, the flop is being "
                    "dealt... "<<endl<<endl;
        }else{
            cout<<"You folded. Your opponent won the pot of $0. ";
            return 0;
        }
    
    //The Flop (Deal community cards)
        //Community Cards
        cout<<"Community Cards"<<endl;
        coCard1=rand()%52+1;
        //cout<<"Com Card 1 = "<<face(coCard1)<<suit(coCard1)<<endl;//test
        if(coCard1==hCard1||coCard1==oHCard1||coCard1==oHCard2||
                coCard1==hCard2){
            do{
                coCard1=rand()%52+1;
                //cout<<"DO W 1 "<<face(coCard1)<<suit(coCard1)<<endl;//test
            }while(coCard1==hCard1||coCard1==oHCard1||coCard1==oHCard2||
                    coCard1==hCard2);
        }
        coCard2=rand()%52+1;
        //cout<<"Com Card 2 = "<<face(coCard2)<<suit(coCard2)<<endl;//test
        if(coCard2==hCard1||coCard2==oHCard1||coCard2==oHCard2||coCard2==hCard2
                ||coCard2==coCard1){
            do{
                coCard2=rand()%52+1;
                //cout<<"DO W 2 "<<face(coCard2)<<suit(coCard2)<<endl;//test
            }while(coCard2==hCard1||coCard2==oHCard1||coCard2==oHCard2||
                    coCard2==hCard2||coCard2==coCard1);
        }
        coCard3=rand()%52+1;
        //cout<<"Com Card 3 = "<<face(coCard3)<<suit(coCard3)<<endl;//test
        if(coCard3==hCard1||coCard3==oHCard1||coCard3==oHCard2||coCard3==hCard2
                ||coCard3==coCard2||coCard3==coCard1){
            do{
                coCard3=rand()%52+1;
                //cout<<"DO W 3 "<<face(coCard3)<<suit(coCard3)<<endl;//test
            }while(coCard3==hCard1||coCard3==oHCard1||coCard3==oHCard2||
                    coCard3==hCard2||coCard3==coCard2||coCard3==coCard1);
        }
        cout<<"Community Cards = "<<face(coCard1)<<suit(coCard1)<<setw(3)<<
                face(coCard2)<<suit(coCard2)<<setw(3)<<face(coCard3)<<
                suit(coCard3)<<endl;
        cout<<"Your Hand"<<endl;
        cout<<"Card = "<<face(hCard1)<<suit(hCard1)<<endl;
        cout<<"Card = "<<face(hCard2)<<suit(hCard2)<<endl<<endl;
        //Input data
        cout<<"Your opponent called. Do you want to call or fold? "
                "(Enter \"call\" or \"fold\" to choose)"<<endl;
        cin>>bet;
        if(bet=="call"){
            cout<<"You called. The turn is being dealt... "<<endl<<endl;
        }else{
            cout<<"You folded. Your opponent won the pot of $0. ";
            return 0;
        }
    
    //The Turn (Deal Community Card)
        coCard4=rand()%52+1;
        //cout<<"Com Card 4 = "<<face(coCard4)<<suit(coCard4)<<endl;//test
        if(coCard4==hCard1||coCard4==oHCard1||coCard4==oHCard2||coCard4==hCard2
                ||coCard4==coCard2||coCard4==coCard1||coCard4==coCard3){
            do{
                coCard4=rand()%52+1;
                //cout<<"DO W 4 "<<face(coCard4)<<suit(coCard4)<<endl;//test
            }while(coCard4==hCard1||coCard4==oHCard1||coCard4==oHCard2||
                    coCard4==hCard2||coCard4==coCard2||coCard4==coCard1||
                    coCard4==coCard3);
        }
        cout<<"Community Cards = "<<face(coCard1)<<suit(coCard1)<<setw(3)<<
                face(coCard2)<<suit(coCard2)<<setw(3)<<face(coCard3)<<
                suit(coCard3)<<setw(3)<<face(coCard4)<<suit(coCard4)<<endl;
        cout<<"Your Hand"<<endl;
        cout<<"Card = "<<face(hCard1)<<suit(hCard1)<<endl;
        cout<<"Card = "<<face(hCard2)<<suit(hCard2)<<endl<<endl;
        //Input Data
        cout<<"Your opponent called. Do you want to call or fold? "
                "(Enter \"call\" or \"fold\" to choose)"<<endl;
        cin>>bet;
        if(bet=="call"){
            cout<<"You called. The river is being dealt... "<<endl<<endl;
        }else{
            cout<<"You folded. Your opponent won the pot of $0. ";
            return 0;
        }
        
    //The River (Deal Community Card)
        coCard5=rand()%52+1;
        //cout<<"Com Card 5 = "<<face(coCard5)<<suit(coCard5)<<endl;//test
        if(coCard5==hCard1||coCard5==oHCard1||coCard5==oHCard2||coCard5==hCard2
                ||coCard5==coCard2||coCard5==coCard1||coCard5==coCard3||
                coCard5==coCard4){
            do{
                coCard5=rand()%52+1;
                //cout<<"DO W 5 "<<face(coCard5)<<suit(coCard5)<<endl;//test
            }while(coCard5==hCard1||coCard5==oHCard1||coCard5==oHCard2||
                    coCard5==hCard2||coCard5==coCard2||coCard5==coCard1||
                    coCard5==coCard3||coCard5==coCard4);
        }
        cout<<"Community Cards = "<<face(coCard1)<<suit(coCard1)<<setw(3)<<
                face(coCard2)<<suit(coCard2)<<setw(3)<<face(coCard3)<<
                suit(coCard3)<<setw(3)<<face(coCard4)<<suit(coCard4)<<
                setw(3)<<face(coCard5)<<suit(coCard5)<<endl;
        cout<<"Your Hand"<<endl;
        cout<<"Card = "<<face(hCard1)<<suit(hCard1)<<endl;
        cout<<"Card = "<<face(hCard2)<<suit(hCard2)<<endl<<endl;
        //Input Data
        cout<<"Your opponent called. Do you want to call or fold? "
                "(Enter \"call\" or \"fold\" to choose)"<<endl;
        cin>>bet;
        if(bet=="call"){
            cout<<"You called. Reveal your cards... "<<endl<<endl;
        }else{
            cout<<"You folded. Your opponent won the pot of $0. ";
            return 0;
        }
        cout<<"Community Cards = "<<face(coCard1)<<suit(coCard1)<<setw(3)<<
                face(coCard2)<<suit(coCard2)<<setw(3)<<face(coCard3)<<
                suit(coCard3)<<setw(3)<<face(coCard4)<<suit(coCard4)<<
                setw(3)<<face(coCard5)<<suit(coCard5)<<endl<<endl;
        cout<<"Your Opponent's Hand"<<endl;
        cout<<"Card = "<<face(oHCard1)<<suit(oHCard1)<<endl;
        cout<<"Card = "<<face(oHCard2)<<suit(oHCard2)<<endl<<endl;
        cout<<"Your Hand"<<endl;
        cout<<"Card = "<<face(hCard1)<<suit(hCard1)<<endl;
        cout<<"Card = "<<face(hCard2)<<suit(hCard2)<<endl<<endl;
        
    
    //Exit stage right!
    return 0;
}

char face(char card){
    switch(card%13){
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

char suit(char card){
    if(card<=13)return 'S';//S -> Spades
    if(card<=26)return 'D';//D -> Diamond
    if(card<=39)return 'C';//C -> Clubs
    return 'H';//H -> Hearts;
}


