// Name:            Min Hein
// Class:           CECS 325-02
// Project Name:    Prog 1 - One Card War
// Due Date:        Feb / 13 / 2025

// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include "card.h"
#include <iostream>
#include <string>

using namespace std;

Card::Card(char r, char s) : rank(r), suit(s) {}    // Card constructor takes 2 parameters r and s, set private variables rank to r, and suit to s.

Card::Card() : rank('A'), suit('C') {}              // initilize that card to be AC

void Card::displayCard() 
{

    if (rank == 'T' && suit == 'C')                 // sets it so that T will dispaly a 10 instead
    {
        cout << "10" << suit;
    }
    else                                            // other card will be displayed as is
    {
        cout << rank << suit;
    }
    
}

int Card::compareCard(Card other) 
{
    string order = "A23456789TJQK";                 // sets the ranking order in vriable order. (A lowest, K highest, 10 is represented as 'T')
    int value1 = order.find(rank);                  // using order as a kind of list, it finds the "rank" that matches the index in "order" and stores the index as a integer
    int value2 = order.find(other.rank);
    
    if (value1 > value2) return 1;                  // using the index value, it checks which is higher.
    if (value1 < value2) return -1;                 // if first value is higher, compereCard() should output a 1,
    return 0;                                       // if second value is higher, compareCard() should output a -1
}                                                   // 0 is returned if the values are the same. (also cuz compareCard() should return a integer)
                                                    