// Name:            Min Hein
// Class:           CECS 325-02
// Project Name:    Prog 1 - One Card War
// Due Date:        Feb / 13 / 2025

// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#ifndef CARD_H
#define CARD_H

using namespace std;

class Card 
{
private:                            // private variables, unaccessable to the player

    char rank;                      // rank, will be a character
    char suit;                      // suit, will be a string

public:                             // public variables, accessable to the player
    
    Card();                         // Card constructor
    Card(char r, char s);           // Card constructor that will be used to set up the rank: r, suits: s
    void displayCard();             // will display the card, ex: AC (ace of clubs)
    int compareCard(Card);          // will compare the integer value of the cards
};

#endif
