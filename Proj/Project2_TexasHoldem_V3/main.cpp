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
#include <vector>    //Vector Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
int NUMPERC=100;//converting number to percent & vice versa

//Function Prototypes
char suit(char);
char face(char);
char hands(char);

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
    int cards[SIZE]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
                     21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,
                     38,39,40,41,42,43,44,45,46,47,48,49,50,51,52};//deck of cards
    char face[14]={'A',2,3,4,5,6,7,8,9,'T','J','Q','K','A'};//card's face used for comparison
    char suit[4]={'S','C','D','H'};//card's suit used for comparison
    int card[SIZE];
    string bet;//call or fold choice
    char choice;//
    
//Loop
    cout<<"Welcome to the Table."<<endl;
    do{
        cout<<"Press 1 if you would like to play."<<endl;
        cin>>choice;
        switch(choice){
            case'1':{
    //Output cards
        for(int i=0;i<SIZE;i++){
            cout<<cards[i]<<" ";
        }cout<<endl;
    //Shuffle Cards
        for(int i=0;i<7;i++){
            for(int j=0;j<51;j++){
                int l=rand()%SIZE, temp;
                temp=cards[j];
                cards[j]=cards[l];
                cards[l]=temp;
            }
        }
        //output cards
            for(int i=0;i<51;i++){
                cout<<cards[i]<<" ";
            }cout<<endl;
    
    //Pre-Flop (Deal cards to players)
        //Opponent's Hole Cards
        
        
        //Player's Hole Cards
        
        
        //Output Player's hole cards
        
        
        //Input data for bet
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
            
        
        //Output all visible cards, community cards and player hole cards
        
        
        //Input data for bet
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
        
        
        //Output all visible cards
        
        
        //Input Data for bet
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
        
        
        //Output all visible cards
        
        
        //Input Data for bet
        cout<<"Your opponent called. Do you want to call or fold? "
                "(Enter \"call\" or \"fold\" to choose)"<<endl;
        cin>>bet;
        if(bet=="call"){
            cout<<"You called. Reveal your cards... "<<endl<<endl;
        }else{
            cout<<"You folded. Your opponent won the pot of $0. ";
            return 0;
        }
        //comparing hands, player and opponent
        vector<int> count(14);
        for(int i=0; i<4; i++){//how many cards make a hand
            for(int j=0; j<14; j++){//comparing each card to face
                if(card[j]==card[i]); //count++;
            }
            
        }
        
        
           break;}
            default: cout<<"Thank you for playing."<<endl;
        }
    }while(choice=='1');
    //Exit stage right!
    return 0;
}

/*void hands(){
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


