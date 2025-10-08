// Name:            Min Hein
// Class:           CECS 325-02
// Project Name:    Prog 1 - One Card War
// Due Date:        Feb / 13 / 2025

// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include "deck.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

Deck::Deck() 
{
    // Creates an array of characters with variable name: suit and ranks, undefined limit
    // (limit can be added by putting a # into [], eg. suits[4] will make it so that the array will only have 4 elements)
    char suits[] = {'C', 'D', 'H', 'S'};
    char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

    // set the initial index
    int index = 0;

    // looping through the suits (so 4 times)
    for (char suit : suits) 
    {
        // looping through the ranks (so 13 times)
        for (char rank : ranks) 
        {
            // store the card of rank, suit at current index
            cards[index] = Card(rank, suit);
            // increase index by 1
            index++;
        }
    }
    // top card is set to 0
    top = 0;
}

Card Deck::deal() 
{
    // returns the card at the top, then increase value of top by 1
    return cards[top++];
}

void Deck::displayDeck() 
{
    // loops (initial; condition; method of increment)
    for (int i = top; i < 52; i++) 
    {
        // display the card at the index i, from the array of cards
        cards[i].displayCard();

        // creates spacing
        cout << " ";

        // creates a new line after every 13 cards been display
        if ((i - top + 1) % 13 == 0)
        {
            cout << endl;
        }
    }
    // creates a new line to reduce visual clutter
    cout << endl;
    
}

void Deck::shuffle() 
{
    // randomize using time(0) as the seed
    srand(time(0));

    // goes from the last card to the first card
    for (int i = 51; i > 0; i--) 
    {
        // j is a random number within the range of 0 to i
        int j = rand() % (i + 1);

        // swap the card at index i from the array of cards with card at index j from array of cards.
        swap(cards[i], cards[j]);
    }

    top = 0;
}
