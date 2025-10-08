// Name:            Min Hein
// Class:           CECS 325-02
// Project Name:    Prog 1 - One Card War
// Due Date:        Feb / 13 / 2025

// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#ifndef DECK_H
#define DECK_H

#include "card.h"

class Deck                  // .h files are basically constructing skeletons and setting up variables for the .cpp files
{
private:                    // variables unaccessable to the player
    
    Card cards[52];         //set an array of 52 cards
    int top;                //set a variable for the top card

public:                     // variables accessable to the player
    
    Deck();                 //constructor class
    Card deal();            // will be used to deal a card to the player(s): should show as ('Rank''Suit', eg AC -> ace of clubs)
    void displayDeck();     // should display the deck
    void shuffle();         // should shuffle the deck
};

#endif