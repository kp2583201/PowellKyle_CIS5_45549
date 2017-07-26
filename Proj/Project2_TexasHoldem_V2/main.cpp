/* 
 * File:   main.cpp
 * Author: Kyle Powell
 * Created on July 24, 2017, 12:45 PM
 * Purpose: Texas Hold'em 
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time Library
#include <string>    //String Library
#include <iomanip>   //Format Library
#include <fstream>   //File I/O Library
#include <cmath>     //Math Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
int NUMPERC=100;//converting number to percent & vice versa

//Function Prototypes
char hands(char);
void pair(int);
int high(int, int);
char suit(char);
char face(char);

//Execution begins here
int main(int argc, char** argv) {
    //Texas Hold'em Rules
    fstream inFile;
    string rules;
    int num=352;
    inFile.open("TexasHoldemRules.txt");
    for(int count=1;count<=num;count++){
        inFile>>rules;
        cout<<rules<<" ";
    }
    inFile.close();
    cout<<endl;
    
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    const int SIZE=52;
    string cards[SIZE]={"2S","3S","4S","5S","6S","7S","8S","9S",//deck of cards
                        "TS","JS","QS","KS","AS",
                        "2D","3D","4D","5D","6D","7D","8D","9D",
                        "TD","JD","QD","KD","AD",
                        "2C","3C","4C","5C","6C","7C","8C","9C",
                        "TC","JC","QC","KC","AC",
                        "2H","3H","4H","5H","6H","7H","8H","9H",
                        "TH","JH","QH","KH","AH"};
    const int DLT=9;
    int dltCard[DLT], j;
    char hCard1,hCard2,oHCard1,oHCard2;//cards dealt to hand player & opponent
    int coCard1,coCard2,coCard3,coCard4,coCard5;//community cards
    string betChce;//call or fold choice
    char choice;//
    bool replay=false;
    float bet, pot=0.0f, pMoney=500.0f, oMoney=500.0f;//bet related variables
    
//Loop
    cout<<"Welcome to the Table. This is a low stakes game, the average "
            "pot is about $50. "<<"\nThe buy-in is $"<<pMoney<<endl;
    do{
        if (replay=true){
            
        }else{
            cout<<"Press 1 if you would like to play."<<endl;
            cin>>choice;
        }
        switch(choice){
            case'1':{
    //Generate cards to be dealt
            for(int i=0;i<9;i++){
                dltCard[i]=rand()%52+1;
                cout<<dltCard[i]<<endl;
            }
            cout<<"Card with highest value = "<<endl;
                    high(dltCard[DLT],DLT);
    //Pre-Flop (Deal cards to players)
        //Opponent's Hole Cards
        j=dltCard[0];
        cards[j];
        j=dltCard[1];
        cards[j];
        oHCard1=rand()%52+1;//first card dealt to opponent
        oHCard2=rand()%52+1;//second card dealt to opponent
        if(face(oHCard1)==face(oHCard2)&&suit(oHCard1)==suit(oHCard2)){//prevents cards with same face and suit
            while(oHCard2==oHCard1){
                oHCard2=rand()%52+1;
            }
        }
        //Opponent's bet
        bet=rand()%25+1;
        oMoney-=bet;
        pot+=bet;
        cout<<"bet "<<bet<<endl;
        
        //Player's Hole Cards
        /*hCard1=rand()%52+1;//first card dealt to player
        hCard2=rand()%52+1;//second card dealt to player
        cout<<"Your Hand"<<endl;
        if(hCard1==oHCard1||hCard1==oHCard2){//prevents same cards being dealt
            while(hCard1==oHCard1||hCard1==oHCard2){
                hCard1=rand()%52+1;
            }
        }
        if(hCard2==oHCard1||hCard2==oHCard2||hCard1==hCard2){//prevents same cards being dealt
            while(hCard2==oHCard1||hCard2==oHCard2||hCard1==hCard2){
                hCard2=rand()%52+1;
            }
        }*/
        //Output Player's hole cards
        j=dltCard[2];
        cout<<"Card = "<<cards[j]<<endl;
        j=dltCard[3];
        cout<<"Card = "<<cards[j]<<endl<<endl;
        
        //Input data for bet
        cout<<"Your opponent placed an initial bet of $0 into the pot. "
                "Do you want to call or fold? (Enter \"call\" or \"fold\" "
                "to choose) "<<endl;
        cin>>betChce;
        if(betChce=="call"){
            cout<<"You called your opponent's bet of $"<<bet<<", the flop is being "
                    "dealt... "<<endl<<endl;
            pMoney-=bet;
            pot+=bet;
            
        }else{
            cout<<"You folded. Your opponent won the pot of $"<<pot;
            oMoney+=pot;
            replay=true;
            break;
        }
    
    //The Flop (Deal community cards)
            do{
                coCard1=rand()%52+1;//deals card
            }while(coCard1==hCard1||coCard1==oHCard1||coCard1==oHCard2||
                    coCard1==hCard2);//prevents the same card from being dealt
            do{
                coCard2=rand()%52+1;//deals card
            }while(coCard2==hCard1||coCard2==oHCard1||coCard2==oHCard2||
                    coCard2==hCard2||coCard2==coCard1);//prevents the same card from being dealt
            do{
                coCard3=rand()%52+1;//deals card
            }while(coCard3==hCard1||coCard3==oHCard1||coCard3==oHCard2||
                    coCard3==hCard2||coCard3==coCard2||coCard3==coCard1);//prevents the same card from being dealt
        //Output all visible cards, community cards and player hole cards
        cout<<"Community Cards = "<<face(coCard1)<<suit(coCard1)<<setw(3)<<
                face(coCard2)<<suit(coCard2)<<setw(3)<<face(coCard3)<<
                suit(coCard3)<<endl<<endl;
        cout<<"Your Hand"<<endl;
        cout<<"Card = "<<face(hCard1)<<suit(hCard1)<<endl;
        cout<<"Card = "<<face(hCard2)<<suit(hCard2)<<endl<<endl;
        //Opponent bet
        bet=rand()%25+1;
        oMoney-=bet;
        pot+=bet;
        cout<<"bet "<<bet<<endl;
        //Input data for bet
        cout<<"Your opponent made a bet of $"<<bet<<". Do you want to call or fold? "
                "(Enter \"call\" or \"fold\" to choose)"<<endl;
        cin>>betChce;
        if(betChce=="call"){
            cout<<"You called. The turn is being dealt... "<<endl<<endl;
            pMoney-=bet;
            pot+=bet;
        }else{
            cout<<"You folded. Your opponent won the pot of $"<<pot<<". ";
            oMoney+=pot;
            replay=true;
            break;
        }
    
    //The Turn (Deal Community Card)
        coCard4=rand()%52+1;//deals 4th community card
        if(coCard4==hCard1||coCard4==oHCard1||coCard4==oHCard2||coCard4==hCard2
                ||coCard4==coCard2||coCard4==coCard1||coCard4==coCard3){//prevents same card being dealt
            do{
                coCard4=rand()%52+1;
            }while(coCard4==hCard1||coCard4==oHCard1||coCard4==oHCard2||
                    coCard4==hCard2||coCard4==coCard2||coCard4==coCard1||
                    coCard4==coCard3);
        }
        //output all visible cards
        cout<<"Community Cards = "<<face(coCard1)<<suit(coCard1)<<setw(3)<<
                face(coCard2)<<suit(coCard2)<<setw(3)<<face(coCard3)<<
                suit(coCard3)<<setw(3)<<face(coCard4)<<suit(coCard4)<<endl;
        cout<<"Your Hand"<<endl;
        cout<<"Card = "<<face(hCard1)<<suit(hCard1)<<endl;
        cout<<"Card = "<<face(hCard2)<<suit(hCard2)<<endl<<endl;
        //Opponent bet
        bet=rand()%25+1;
        oMoney-=bet;
        pot+=bet;
        //Input Data for bet
        cout<<"Your opponent bet $"<<bet<<". Do you want to call or fold? "
                "(Enter \"call\" or \"fold\" to choose)"<<endl;
        cin>>betChce;
        if(betChce=="call"){
            cout<<"You called. The river is being dealt... "<<endl<<endl;
            pMoney-=bet;
            pot+=bet;
        }else{
            cout<<"You folded. Your opponent won the pot of $"<<pot<<".";
            oMoney+=pot;
            replay=true;
            break;
        }
        
    //The River (Deal Community Card)
        coCard5=rand()%52+1;//deals 5th community card
        if(coCard5==hCard1||coCard5==oHCard1||coCard5==oHCard2||coCard5==hCard2
                ||coCard5==coCard2||coCard5==coCard1||coCard5==coCard3||
                coCard5==coCard4){//prevents same card being dealt
            do{
                coCard5=rand()%52+1;
            }while(coCard5==hCard1||coCard5==oHCard1||coCard5==oHCard2||
                    coCard5==hCard2||coCard5==coCard2||coCard5==coCard1||
                    coCard5==coCard3||coCard5==coCard4);
        }
        //output all visible cards
        cout<<"Community Cards = "<<face(coCard1)<<suit(coCard1)<<setw(3)<<
                face(coCard2)<<suit(coCard2)<<setw(3)<<face(coCard3)<<
                suit(coCard3)<<setw(3)<<face(coCard4)<<suit(coCard4)<<
                setw(3)<<face(coCard5)<<suit(coCard5)<<endl;
        cout<<"Your Hand"<<endl;
        cout<<"Card = "<<face(hCard1)<<suit(hCard1)<<endl;
        cout<<"Card = "<<face(hCard2)<<suit(hCard2)<<endl<<endl;
        //Opponent bet
        bet=rand()%25+1;
        oMoney-=bet;
        pot+=bet;
        //Input Data for bet
        cout<<"Your opponent bet $"<<bet<<". Do you want to call or fold? "
                "(Enter \"call\" or \"fold\" to choose)"<<endl;
        cin>>betChce;
        if(betChce=="call"){
            cout<<"You called. Reveal your cards... "<<endl<<endl;
            pMoney-=bet;
            pot+=bet;
        }else{
            cout<<"You folded. Your opponent won the pot of $0. ";
            oMoney+=pot;
            replay=true;
            break;
        }
        //comparing hands, player and opponent
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
        
    //Hand Pair
        bool pair=false;
        bool pair2=false;
        if(face(oHCard1)==face(oHCard2)||face(oHCard1)==face(coCard1)||
                face(oHCard1)==face(coCard2)||face(oHCard1)==face(coCard2)||
                face(oHCard1)==face(coCard3)||face(oHCard1)==face(coCard4)||
                face(oHCard1)==face(coCard5))pair=true;
        else if(face(oHCard2)==face(oHCard1)||face(oHCard2)==face(coCard1)||
                face(oHCard2)==face(coCard2)||face(oHCard2)==face(coCard2)||
                face(oHCard2)==face(coCard3)||face(oHCard2)==face(coCard4)||
                face(oHCard2)==face(coCard5))pair2=true;
        if (pair==true||pair2==true)cout<<"You have a pair."<<endl;
        if (pair==true&&pair2==true)cout<<"You have a two pair."<<endl;
        if(pair==false&&pair2==false){
            
        }
           break;}
            default: cout<<"Thank you for playing."<<endl;
        }
    }while(choice=='1');
    //Exit stage right!
    return 0;
}

/*char hands(){
    char card1,card2;
    card1;//high card
    if (card1==card2);//pair
    else if (card1==card2&&card3==card4);//two pair
    else if(card1==card2&&card2==card3);//three of kind
    else if(card2==card1+=1&&card3==card2+=1&&card4==card3+=1&&card5==card4+=1);//straight
    else if(face(card1)==face(card2)&&face(card2)==face(card3)&&
            face(card3)==face(card4)&&face(card4)==face(card5));//flush
    else if(card1==card2&&card2==card3&&card4==card5);//full house
    else if(card1==card2&&card2==card3&&card3==card4);//four of kind
    else if (card2==card1+=1&&card3==card2+=1&&card4==card3+=1&&card5==card4+=1
            &&face(card1)==face(card2)&&face(card2)==face(card3)&&
            face(card3)==face(card4)&&face(card4)==face(card5));//staight flush
    else;//royal flush
}*/
void pair(){
    
}


int high(int dltCard[DLT], int DLT){
    int c;
    int highest=dltCard[0];
    for(c=1;c<DLT;c++){
        if(dltCard[c]>highest)highest=dltCard[c];
    return highest;
    }
}


char face(char card){
    switch(card%13){
        case 1:return '2';
        case 2:return '3';
        case 3:return '4';
        case 4:return '5';
        case 5:return '6';
        case 6:return '7';
        case 7:return '8';
        case 8:return '9';
        case 9:return 'T';
        case 10:return 'J';
        case 11:return 'Q';
        case 12:return 'K';
        default:return 'A';
    }
}

char suit(char card){
    if(card<=13)return 'S';//S -> Spades
    if(card<=26)return 'D';//D -> Diamond
    if(card<=39)return 'C';//C -> Clubs
    return 'H';//H -> Hearts;
}


