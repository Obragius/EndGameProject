#include <vector>
#include <stdlib.h>
#include "Hand.h"
using namespace std;
using namespace myHand;

namespace myDeck
{
    class Deck
    {
        private:
            vector<Card> cards;
        public:
            Deck()
            {
                Card card1 = Card();
                for (string mySuit : card1.suits)
                {
                    for (string myName : card1.names)
                    {
                        Card card2 = Card(mySuit,myName);
                        this->cards.emplace_back(card2);
                    }
                }
            }

            vector<Card> getCards()
            {
                return this->cards;
            }

            void returnAllCards(vector<Hand> playerHands)
            {
                for (int i = 0; i < 2; i++)
                {
                    while (playerHands[i].isEmpty() == false)
                    {
                        this->cards.emplace_back(playerHands[i].removeCard());
                    }
                } 
            }

            Card pickNextCard()
            {
                Card givenCard = this->cards.back();
                this->cards.pop_back();
                return givenCard;
            }

            Card pickACard()
            {
                int myInt = rand() % 1 + this->cards.size();
                Card givenCard = this->cards.at(myInt);
                this->cards.erase(cards.begin()+myInt);
                return givenCard;
            }

            void shuffle()
            {
                cout << "Shuffle" <<endl;
                vector<Card> newDeck;
                while (this->cards.size() > 0)
                {
                    int myInt = rand() % this->cards.size();
                    Card givenCard = this->cards[myInt];
                    Card lastCard = this->cards.back();
                    this->cards[myInt] = lastCard;
                    this->cards.pop_back();
                    newDeck.emplace_back(givenCard);
                }
                this->cards = newDeck;
                cout << this->getCards().back().getName() << endl;
            }

    };
}