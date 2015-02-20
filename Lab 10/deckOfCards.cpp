                                                             
   // deckOfCards.cpp                                                              
#include <iostream>                                                             
#include <iomanip>                                                              
#include <cstdlib>                                                              
#include <ctime>                                                                
using namespace std;                                                            

int topCard = 1; 
                                                          
                                                                              
                                                                                
// DeckOfCards class definition                                                 
class DeckOfCards                                                               
{                                                                               
public:                                                                         
    DeckOfCards(); // constructor initializes deck                              
    void shuffle(); // shuffles cards in deck                                   
    void deal(); // deals cards in deck                                                 
    void newTopCard();                                                     
private:                                                                        
    int deck[ 4 ][ 13 ]; // represents deck of cards                         
} // end class DeckOfCards                                                     
                                                                                
                                                                                
// DeckOfCards default constructor initializes deck                             
DeckOfCards::DeckOfCards()                                                      
{     
   //topCard = 1;  
   // loop through rows of deck                                                 
   for ( int row = 0; row <= 3; row++ )                                         
   {                                                                            
      // loop through columns of deck for current row                           
      for ( int column = 0; column <= 12; column++ )                            
      {                                                                         
         deck[ row ][ column ] = 0; // initialize slot of deck to 0             
      } // end inner for                                                        
   } // end outer for                                                           
                                                                                
   srand( time( 0 ) ); // seed random number generator                          
} // end DeckOfCards default constructor                                        
                                                                                
// shuffle cards in deck                                                        
void DeckOfCards::shuffle()                                                     
{                                                                               
   int row; // represents suit value of card                                    
   int column; // represents face value of card                                 
                                                                                
   // for each of the 52 cards, choose a slot of the deck randomly              
   for ( int card = 1; card <= 52; card++ )        
{                                                                            
                                                                                
      do // choose a new random location until unoccupied slot is found         
      {                                                                         
         row = rand() % 4; // randomly select the row (0 to 3)                  
         column = rand() % 13; // randomly select the column (0 to 12)          
      } while( deck[ row ][ column ] != 0 ); // end do...while                  
                                                                                
      // place card number in chosen slot of deck                               
      deck[ row ][ column ] = card;                                             
   } // end for                                                                 
} // end function shuffle                                                       
                                                                                
// deal cards in deck                                                           
void DeckOfCards::deal()                                                        
{                                                                               
   // initialize suit array                                                     
   static const char *suit[ 4 ] =                                               
      { "Hearts", "Diamonds", "Clubs", "Spades" };                              
                                                                                
   // initialize face array                          
     static const char *face[ 13 ] =                                              
      { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",                
      "Eight", "Nine", "Ten", "Jack", "Queen", "King" };                        
                                                                                
   // for each of the 52 cards                                                  
   for ( int card = 1; card <= 52; card++ )                                     
   {                                                                            
      // loop through rows of deck                                              
      for ( int row = 0; row <= 3; row++ )                                      
      {                                                                         
         // loop through columns of deck for current row                        
         for ( int column = 0; column <= 12; column++ )                         
         {                                                                      
            // if slot contains current card, display card                      
            if ( deck[ row ][ column ] == card )                                
            {                                                                   
               cout << setw( 5 ) << right << face[ column ]                     
                  << " of " << setw( 8 ) << left << suit[ row ]                 
                  << ( card % 2 == 0 ? '\n' : '\t' );                           
            } // end if                                                         
         } // end innermost for                                                 
      } // end inner for                                                        
   } // end outer for                                                           
} // end function deal   

void DeckOfCards::newTopCard()                                                  
{                                                                               
                                                                                
int temp = deck[0][0];          
    for ( int row = 0; row <= 3; row++ )                                            
{                                                                               
        // loop through columns of deck for current row                         
        for ( int column = 0; column <= 12; column++ )                          
        {                                                                       
                if(column != 12)                                                
                {                                                               
                        deck[row][column] = deck[row][column+1];                
                }                                                               
                else if(row==3 && column==12)                                   
                {                                                               
                        deck[row][column] = temp;                               
                }                                                               
                else                                                            
                {                                                               
                deck[row][column] = deck[row+1][0];                             
                }                                                               
        }                                                                       
                                                                                
 }                                                                               
}       

class Card                                                                      
{                                                                               
public:                                                                         
        Card();                                                                 
        Card(const char*, const char*);    
        void dealNextCard(); // deals next card in deck          
        void displayCard();                                   
}                                                                              
                                                                                
Card::Card(const char *s, const char *v)                                                        
{                                                                               
                                                                                
        static const char *suit[ 4 ] =                                          
      { "Hearts", "Diamonds", "Clubs", "Spades" };                              
                                                                                
                                                                                
    static const char *face[ 13 ] =                                             
      { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",                
      "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
                                                                               
        cout << setw( 5 ) << right << s << " of " << setw( 8 ) << left << 
v << endl;                                                                
                                                                                
} 
  void Card::dealNextCard()                                     
{        
    const char *s;
    const char *v;                                                                        
    static const char *suit[ 4 ] =                                          
      { "Hearts", "Diamonds", "Clubs", "Spades" };                              
                                                                                
                                                                                
    static const char *face[ 13 ] =                                             
      { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",                
      "Eight", "Nine", "Ten", "Jack", "Queen", "King" };                                                                     
        for ( int row = 0; row <= 3; row++ )                                    
        {                                                                       
                // loop through columns of deck for current row                 
                for ( int column = 0; column <= 12; column++ )                  
                {                                                               
                        // if slot contains current card, display card          
                        if ( deck[ row ][ column ] == topCard)                  
                        {       
				s = suit[row];
				v = face[column];                                                
                                DeckOfCards::newTopCard();                                                          
                                return Card::Card(s,v);                  
                        } // end if                                             
                } // end innermost for                                          
        } // end outer for                                                      
}                                                                               

void displayCard(){
};
 
class Hand{
public:
	void evaluate();
}

void Hand::evaluate(){
}

int main() {                                                                      
    DeckOfCards mydeck;                                                         
    mydeck.shuffle();                                                           
    for(int i = 5; i < 5; i++)                                                  
        {                                                                       
                mydeck.dealNextCard();    
		        topCard++;                               
        }                                                                       
    return 0;                                                                   
}                                                                               
                         