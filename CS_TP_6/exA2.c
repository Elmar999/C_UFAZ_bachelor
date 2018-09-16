#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* prototypes */
void shuffle( int wDeck[][ 13 ] );
void deal( const int wDeck[][ 13 ], const char *wFace[], 
           const char *wSuit[] );
int main()
{  
   const char *suit[ 4 ] = { "Hearts", "Diamonds", "Clubs", "Spades" };/* initialize suit array */
   const char *face[ 13 ] = { "Ace", "Deuce", "Three", "Four", 
        "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Jack", "Queen", "King" }; /* initialize face array */
   
   int deck[ 4 ][ 13 ] = { 0 };/* initialize deck array */
   srand( time( 0 ) ); /* seed random-number generator */
   shuffle( deck );
   deal( deck, face, suit );
   return 0; /* indicates successful termination */
} /* end main */

/* shuffle cards in deck */
void shuffle( int wDeck[][ 13 ] )
{  int row;    /* row number */
   int column; /* column number */
   int card;   /* counter */
   /* for each of the 52 cards, choose slot of deck randomly */
   for ( card = 1; card <= 52; card++ ) {
      /* choose new random location until unoccupied slot found */
      do {
         row = rand() % 4;
         column = rand() % 13;
      } while( wDeck[ row ][ column ] != 0 ); /* end do...while */ /* We are searching the empty place in deck to define the place of the card. We use do while because we also should define the position of the first card and using while loop we will never define its position */
      /* place card number in chosen slot of deck */
      wDeck[ row ][ column ] = card;
   } /* end for */
} /* end function shuffle */
/* deal cards in deck */
void deal( const int wDeck[][ 13 ], const char *wFace[],
           const char *wSuit[] )
{  int card;   /* card counter */
   int row;    /* row counter */
   int column; /* column counter */
   /* deal each of the 52 cards */
   for ( card = 1; card <= 52; card++ ) {
      /* loop through rows of wDeck */
      for ( row = 0; row <= 3; row++ ) {
         /* loop through columns of wDeck for current row */
         for ( column = 0; column <= 12; column++ ) {
            /* if slot contains current card, display card */
            if ( wDeck[ row ][ column ] == card ) /* Here we check if our card's position is defined in this place or not. If it's we print our card so all cards will be in their own places */{
               printf( "%5s of %-8s%c", wFace[ column ], wSuit[ row ],
                  card % 2 == 0 ? '\n' : '\t' );/* Here we check if number of card odd or even to print them in beautiful way :) */
            } /* end if */
         } /* end for */
      } /* end for */
   } /* end for */
} /* end function deal */