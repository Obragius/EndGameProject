#include <vector>
#include <stdlib.h>
#include "Hand.h"
using namespace std;
using namespace myCard;
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
                Card card1;
                int index = 0;
                for (string mySuit : card1.suits)
                {
                    for (string myName : card1.names)
                    {
                        Card card2(mySuit,myName);
                        this->cards[index] = card2;
                        index += 1;
                    }
                }
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
                vector<Card> newDeck;
                while (this->cards.size() > 0)
                {
                    int myInt = rand() % 1 + this->cards.size();
                    Card givenCard = this->cards.back();
                    this->cards.pop_back();
                    newDeck.emplace_back(givenCard);
                }
                this->cards = newDeck;
            }

    };
}