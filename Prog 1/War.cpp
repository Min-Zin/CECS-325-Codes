// Name:            Min Hein
// Class:           CECS 325-02
// Project Name:    Prog 1 - One Card War
// Due Date:        Feb / 13 / 2025

// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include "deck.h"
#include "card.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
{
    string player1, player2;    // creates 2 string variable called player1 and player2
    Deck deck;                  // calls the deck class
    
    //player names are inputed
    cout << "Enter the name of the first player: ";
    cin >> player1;
    cout << "Enter the name of the second player: ";
    cin >> player2;
    
    //Displays the original deck
    cout << "\nOriginal Deck\n";
    deck.displayDeck();
    
    // Shuffle deck then display it
    deck.shuffle();
    
    cout << "\nShuffled Deck\n";
    deck.displayDeck();
    
    // initilize integers for the amount of wins that player1, and player2 have, as well as the amount of times they tied.
    int wins1 = 0, wins2 = 0, ties = 0;

    // looping 26 times, the game is played and values of cards are compared between player 1 and 2.
    for (int i = 0; i < 26; i++) {
        Card card1 = deck.deal();
        Card card2 = deck.deal();
        
        // Displays the current number of game play
        cout << "\nGame " << (i + 1) << "\n--------\n";
        
        // Displays player1's card
        cout << player1 << "=> ";
        card1.displayCard();
        cout << endl;
        
        // Displays player2's card 
        cout << player2 << "=> ";
        card2.displayCard();
        cout << endl;
        
        // checks which integer (1, -1, 0) is outputed when compareing each of the player's card
        int result = card1.compareCard(card2);
        
        // if the result is 1, player1 wins and player1's win count is increased by 1.
        if (result == 1) 
        {
            cout << player1 << "=> Winner\n";
            wins1++;
        } 
        
        // elif result is -1, player 2 wins and player2's win count is increased by 1
        else if (result == -1) 
        {
            cout << player2 << "=> Winner\n";
            wins2++;
        } 
        
        // last option, ties
        else 
        {
            cout << "Tie game\n";
            ties++;
        }
    }
    
    // Outputs the final result of the 26 games played by player1 and player2
    cout << "\n------Final Stats-------\n";
    cout << "       " << player1 << " vs. " << player2 << "\n";
    cout << "Wins   " << wins1 << "          " << wins2 << "\n";
    cout << "Losses " << wins2 << "          " << wins1 << "\n";
    cout << "Ties   " << ties << "           " << ties << "\n";
    
    return 0;
}