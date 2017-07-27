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
char shwsuit(int [],int);
char shwface(int [],int);
void preFlop(int [],int,float &,float &,float &,float &);
void dealBet(int [],int,float &,float &,float &,float &);

//Execution begins here
int main(int argc, char** argv) {
    //Texas Hold'em Rules
    fstream inFile;
    string rules;
    int num=373;
    inFile.open("TexasHoldemRules.dat");
    for(int count=1;count<=num;count++){
        inFile>>rules;
        cout<<rules<<" ";
        if (count==7||count==27||count==37||count==56||count==66||count==86
                ||count==101||count==123||count==138||count==162||count==177
                ||count==233||count==241||count==256||count==266||count==282
                ||count==294||count==310||count==319||count==328||count==341)
            cout<<endl<<endl;
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
    
    /* Remove??
    const int F=13;
    const int S=4;
    char face[F]={2,3,4,5,6,7,8,9,'T','J','Q','K','A'};//card's face used for comparison
    char suit[S]={'S','C','D','H'};//card's suit used for comparison*/
    
    bool replay=false;
    char choice;//Menu choice
    float bet, pot=0.0f, pMoney=500.0f, oMoney=500.0f;//bet related variables
    
//Loop
    cout<<"\n\nWelcome to the Table. This is a low stakes game, so the average "
            "pot is usually less than $100. "<<"\nThe buy-in is $"<<pMoney<<"."<<endl;
    do{
        if (replay==true){
            
        }else{
            cout<<"Press 1 if you would like to play."<<endl;
            cin>>choice;
        }
        switch(choice){
            case'1':{
                //Output money
                cout<<"\nYour money = $"<<pMoney<<endl;
                cout<<"opps money = $"<<oMoney<<endl;
                cout<<"pot money  = $"<<pot<<endl;
    //Output cards; for test
        cout<<"\nThe cards before shuffling: ";
        int cntr=0;
        do{
            cout<<cards[cntr]<<" ";
            cntr++;
        }while(cntr<SIZE);
        cout<<endl;
    //Shuffle Cards
        for(int i=0;i<7;i++){
            for(int j=0;j<52;j++){
                int l=rand()%SIZE, temp;
                temp=cards[j];
                cards[j]=cards[l];
                cards[l]=temp;
            }
        }
        //Output cards again; for test
            cout<<"The cards after shuffling:  ";
            int countr=0;
            while(countr<SIZE){
                cout<<cards[countr]<<" ";
                countr++;
            }
            cout<<"\n*********************************************************"
                    "*********************************************************"
                    "********************************************************"<<endl<<endl;
/*    
    //Pre-Flop (Deal cards to players)
            preFlop(cards,SIZE,oMoney,pot,pMoney,bet);
            if(replay==true)break;
            //Output money
                cout<<"Your money = $"<<pMoney<<endl;
                cout<<"opps money = $"<<oMoney<<endl;
                cout<<"pot money  = $"<<pot<<endl;
            cout<<"The flop is being dealt..."<<endl<<endl;
    
    //The Flop 
            dealBet(cards,SIZE,oMoney,pot,pMoney,bet);
            if(replay==true)break;
            //Output money
                cout<<"Your money = $"<<pMoney<<endl;
                cout<<"opps money = $"<<oMoney<<endl;
                cout<<"pot money  = $"<<pot<<endl;
            cout<<"The turn is being dealt... "<<endl<<endl;
    
    //The Turn
        dealBet(cards,SIZE,oMoney,pot,pMoney,bet);  
        //Output money
                cout<<"Your money = $"<<pMoney<<endl;
                cout<<"opps money = $"<<oMoney<<endl;
                cout<<"pot money  = $"<<pot<<endl;
        cout<<"The river is being dealt... "<<endl<<endl;
        
    //The River 
        dealBet(cards,SIZE,oMoney,pot,pMoney,bet);
        //Output money
                cout<<"Your money = $"<<pMoney<<endl;
                cout<<"opps money = $"<<oMoney<<endl;
                cout<<"pot money  = $"<<pot<<endl;
        cout<<"Reveal your cards... "<<endl<<endl;
*/        
        //Variables for hand determination
            bool pair=false;//pair, 2 cards with same face value
            bool twoPair=false;//two pair, 2 different cards with pairs
            bool thrKind=false;//three of a kind, 3 cards with same face value
            bool strght=false;//straight, 5 cards with face values incrementing by 1 (not in same suit)
            bool flush=false;//flush, 5 cards with the same suit
            bool flHouse=false;//full house, three of a kind + a pair
            bool fourKnd=false;//four of a kind, 4 cards with same face value
            bool strFlsh=false;//straight flush, a straight with the same suit
            bool royFlsh=false;//royal flush, 10-Ace straight flush
            
        //Finding pairs in the opponent's hand
            const int COL=2;
            int count[13][COL]={};//counter array
            if (shwface(cards,0)==shwface(cards,2))count[0][1]+=1;//finds pair in opponent's hole cards
            for (int i=4;i<9;i++){//finds pairs with opp hole cards in com 
                if (shwface(cards,0)==shwface(cards,i))count[0][1]+=1;
            }cout<<"Number of pairs for the opponent's first card: "
                    <<count[0][1]<<endl;
            for (int i=4;i<9;i++){//finds pairs with opp hole cards in com 
                if (shwface(cards,2)==shwface(cards,i))count[1][1]+=1;
            }cout<<"Number of pairs for the opponent's second card: "
                    <<count[1][1]<<endl;
            for(int i=4;i<9;i++){//finds pairs in com cards
                for(int j=i+1;j<9;j++){
                    if (shwface(cards,i)==shwface(cards,j))count[2][1]+=1;
                }
            }cout<<"Number of pairs in the community cards: "<<count[2][1]
                    <<endl<<endl;
        //Finding cards w/ same suit
            if (shwsuit(cards,0)==shwsuit(cards,2))count[0][2]+=1;//finds same suit in opponent's hole cards
            for (int i=4;i<9;i++){//finds same suit with opp hole cards in com 
                if (shwsuit(cards,0)==shwsuit(cards,i))count[0][2]+=1;
            }cout<<"Number of cards with same suit for the opponent's first "
                    <<"card: "<<count[0][2]<<endl;
            for (int i=4;i<9;i++){//finds same suit with opp hole cards in com 
                if (shwsuit(cards,2)==shwsuit(cards,i))count[1][2]+=1;
            }cout<<"Number of cards with same suit for the opponent's second "
                    "card: "<<count[1][2]<<endl;
            for(int i=4;i<9;i++){//finds same suit in com cards
                for(int j=i+1;j<9;j++){
                    if (shwsuit(cards,i)==shwsuit(cards,j))count[2][2]+=1;
                }
            }cout<<"Number of cards with same suit in the community cards: "
                    <<count[2][2]<<endl;
            //Determine hand
                for(int i=1;i<=2;i++){
                    for(int j=0;j<=2;j++){
                        if(count[j][i]==1)pair=true;
                        else if(count[j][i]&&count[j+1][i]==1)twoPair=true;
                        else if(count[j][i]==2)thrKind=true;
                        else if(count[j][i]==2&&count[j+1][i]==1)flHouse=true;
                        else if(count[j][i]==3)fourKnd=true;
                    }
                }
            
        //Finding pairs in the player's hand
            if (shwface(cards,1)==shwface(cards,3))count[3][1]+=1;
            for (int i=4;i<9;i++){
                if (shwface(cards,1)==shwface(cards,i))count[3][1]+=1;
            }cout<<"Number of pairs for the first card: "<<count[3][1]<<endl;
            for (int i=4;i<9;i++){
                if (shwface(cards,3)==shwface(cards,i))count[4][1]+=1;
            }cout<<"Number of pairs for the second card: "<<count[4][1]<<endl;
            for(int i=4;i<9;i++){
                for(int j=i+1;j<9;j++){
                    if (shwface(cards,i)==shwface(cards,j))count[5][1]+=1;
                }
            }cout<<"Number of pairs for the community cards: "<<count[5][1]<<endl;
            //Determine hand
                for(int i=1;i<=2;i++){
                    for(int j=3;j<=5;j++){
                        if(count[j][i]==1)pair=true;
                        else if(count[j][i]&&count[j+1][i]==1)twoPair=true;
                        else if(count[j][i]==2)thrKind=true;
                        else if(count[j][i]==2&&count[j+1][i]==1)flHouse=true;
                        else if(count[j][i]==3)fourKnd=true;
                    }
                }
            
        //Compare hands
            
            
        cout<<"Player hand: "<<shwface(cards,1)<<shwsuit(cards,1)<<"  "<<shwface(cards,3)
                    <<shwsuit(cards,3)<<" Opponent hand: "<<shwface(cards,0)
                    <<shwsuit(cards,0)<<" "<<shwface(cards,2)<<shwsuit(cards,2)
                    <<" Community Cards: "<<shwface(cards,4)<<shwsuit(cards,4)<<" "
                    <<shwface(cards,5)<<shwsuit(cards,5)<<" "<<shwface(cards,6)
                    <<shwsuit(cards,6)<<" "<<shwface(cards,7)<<shwsuit(cards,7)<<" "
                    <<shwface(cards,8)<<shwsuit(cards,8)<<endl;
            break;}
            default:{
                cout<<endl<<"Thank you for playing."<<endl;
                if(pMoney>500){
                    cout<<"You are walking away with $"<<pMoney<<"!"
                            <<"\nCongratulations!"<<endl;
                }else if(pMoney<500){
                    cout<<"You are walking away with $"<<pMoney<<"."
                            <<"\nBetter Luck Next Time!"<<endl;
                }else{ 
                    cout<<"You are walking away with $"<<pMoney
                            <<"!\nGood Job!"<<endl;
                }
            }
        }
    }while(choice=='1');
    //Exit stage right!
    return 0;
}

void dealBet(int cards[],int size,float &oMoney,float &pot,float &pMoney,float &bet){
    string betChce;//call or fold, bet choice
    //Deal community cards
        cards[4],cards[5],cards[6],cards[7],cards[8];
    
        //Output all visible cards, community cards and player hole cards
            
        //Opponent's bet
            bet=rand()%15+1;
            oMoney-=bet;
            pot+=bet;
            cout<<"bet "<<bet<<endl<<endl;

        //Input data for bet
            cout<<"Your opponent made a bet of $"<<bet<<". Do you want to call "
                    "or fold? (Enter \"call\" or \"fold\" to choose)"<<endl;
            cin>>betChce;
            if(betChce=="call"){
                cout<<"You called. The turn is being dealt... "<<endl<<endl;
                pMoney-=bet;
                pot+=bet;
            }else{
                cout<<"You folded. Your opponent won the pot of $"<<pot<<". ";
                oMoney+=pot;
                bool replay=true;
            }
    
}

void preFlop(int cards[],int size,float &oMoney,float &pot,float &pMoney,float &bet){
    string betChce;//call or fold, bet choice
        //Opponent's Hole Cards
            cards[0];
            cards[2];
            
        //Opponent's bet
            bet=rand()%25+1;
            oMoney-=bet;
            pot+=bet;
            cout<<"bet "<<bet<<endl;

        //Output Player's hole cards
            cout<<"These are the cards in your hand: "<<shwface(cards,1)
                    <<shwsuit(cards,1)<<"  "<<shwface(cards,3)
                    <<shwsuit(cards,3)<<endl<<endl;
        
        //Input data for bet
            cout<<"Your opponent placed an initial bet of "<<bet<<" into the pot. "
                    "Do you want to call or fold? (Enter \"call\" or \"fold\" "
                    "to choose) "<<endl;
            cin>>betChce;
            if(betChce=="call"){
                cout<<"You called your opponent's bet of $"<<bet<<"."<<endl<<endl;
                pMoney-=bet;
                pot+=bet;

            }else{
                cout<<"You folded. Your opponent won the pot of $"<<pot;
                oMoney+=pot;
                bool replay=true;
            }
        
}

char shwface(int cards[], int i){
    switch(cards[i]%13){
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

char shwsuit(int cards[], int i){
    if(cards[i]<=13)return 'S';//S -> Spades
    if(cards[i]<=26)return 'D';//D -> Diamond
    if(cards[i]<=39)return 'C';//C -> Clubs
    return 'H';//H -> Hearts;
}


