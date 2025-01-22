#include <vector>
#include <stdlib.h>
#include "Hand.h"
#include <random>
using namespace std;
using namespace myCard;
using namespace myHand;

namespace myDeck
{
    class Deck
    {
        protected:
            vector<Card> cards;
        public:
            Deck()
            {
                Card card1;
                for (string mySuit : card1.suits)
                {
                    for (string myName : card1.names)
                    {
                        Card card2(mySuit,myName);
                        this->cards.push_back(card2);
                    }
                }
            }

            int getSize()
            {
                return cards.size();
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

                //From Chat GPT------
                // Create a random device to seed the random number generator
                random_device rd;

                // Use Mersenne Twister as the random number generator
                mt19937 gen(rd());
                //-------------------

                for (int i = 0; i < 4; i++)
                {
                    while (this->cards.size() > 0)
                    {
                        std::uniform_int_distribution<> distrib(0, this->cards.size()-1);
                        int myInt = distrib(gen);

                        Card givenCard = this->cards[myInt];
                        this->cards.erase(this->cards.begin() + myInt);
                        newDeck.push_back(givenCard);
                    }
                    this->cards = newDeck;
                }
            }

    };
}