// Name:            Min Hein
// Class:           CECS 325-02
// Project Name:    Prog 2 - More War <vector>
// Due Date:        Feb / 13 / 2025

// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
class Card
{
    private:
        char rank;
        char suit;

    public:
        Card(char r, char s) : rank(r), suit(s) {}

        void displayCard()
        {
            if (rank == 'T')
            {
                cout << "10" << suit;
            }
            else
            {
                cout << rank << suit;
            }
        }

        int compareCard(Card other)
        {
            string order = "A23456789TJQK";
            int value1 = order.find(rank);
            int value2 = order.find(other.rank);

            if (value1 > value2) return 1;
            if (value2 > value1) return -1;

            return 0;
        }
};

class Deck
{
    private:
        vector<Card> cards;
    
    public:
        Deck()
        {
            char suits[] = {'C', 'D', 'H', 'S'};
            char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
            
            for (char suit: suits)
            {
                for (char rank: ranks)
                {
                    cards.push_back(Card(rank, suit));
                }
            }
        }

        Card deal()
        {
            if (isEmpty())
            {
                throw runtime_error("Error - Deck is empty");
            }
            Card dealtCard = cards.back();
            cards.pop_back();
            return dealtCard;
        }

        void displayDeck()
        {
            for (size_t i = 0; i < cards.size(); i++)
            {
                cards[i].displayCard();
                cout << " ";
                if ((i + 1) % 13 == 0)
                {
                    cout << endl;
                }
            }
            cout << endl;
        }


        void shuffle()
        {
            srand(time(0));
            for (size_t i = cards.size() -1; i > 0; i--)
            {
                int j = rand() % (i +1);
                swap(cards[i], cards[j]);
            }
        }

        bool isEmpty()
        {
            return cards.empty();
        }


};

int main() 
{
    string player1, player2;    // creates 2 string variable called player1 and player2
    Deck deck;                  // calls the deck class
    int numGames;               // the numbers of games the players wants to play

    //player names are inputed
    cout << "Enter the name of the first player: ";
    cin >> player1;
    cout << "Enter the name of the second player: ";
    cin >> player2;

    //number of games is imputed
    cout << "How many games will they play? ";
    cin >> numGames;
    
    //Displays the original deck
    cout << "\nOriginal Deck\n";
    deck.displayDeck();
    
    // Shuffle deck then display it
    deck.shuffle();
    
    cout << "\nShuffled Deck\n";
    deck.displayDeck();
    
    // initilize integers for the amount of wins that player1, and player2 have, as well as the amount of times they tied.
    int wins1 = 0, wins2 = 0, ties = 0;

    try
    {
        // looping "numGames" times, the game is played and values of cards are compared between player 1 and 2.
        for (int i = 0; i < numGames; i++) 
        {
            if (deck.isEmpty())
            {
                throw runtime_error("Deck is empty");
            }

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
            
            // checks which integer (1, -1) is outputed when compareing each of the player's card
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
    }
    catch (runtime_error &e)
    {
        cout << "\n" << e.what() << "\n";
    }
    // Outputs the final result of the 26 games played by player1 and player2
    cout << "\n------Final Stats-------\n";
    cout << "       " << player1 << " vs. " << player2 << "\n";
    cout << "Wins   " << wins1 << "          " << wins2 << "\n";
    cout << "Losses " << wins2 << "          " << wins1 << "\n";
    cout << "Ties   " << ties << "           " << ties << "\n";
    
    return 0;
}