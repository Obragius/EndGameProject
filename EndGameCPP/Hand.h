#include <iostream>
#include <vector>
#include "Card.h"
using namespace std;
using namespace myCard;

namespace myHand
{
    class Hand
    {
        private:
            vector<Card> playerHand;
            Card lastAddedCard;
        public:
            bool isEmpty()
            {
                return this->playerHand.empty();
            }

            Card getLastAddedCard()
            {
                return this->lastAddedCard;
            }

            void setLastAddedCard(Card lastAddedCard)
            {
                this->lastAddedCard = lastAddedCard;
            }

            void addCard(Card newCard)
            {
                this->playerHand.emplace_back(newCard);
                this->setLastAddedCard(newCard);
            }

            vector<Card> returnAllCards()
            {
                return this->playerHand;
            }

            Card removeCard()
            {
                Card givenCard = this->playerHand.back();
                this->playerHand.pop_back();
                return givenCard;
            }

            int handCalculator()
            {
                int score[] = {0,0};
                for (Card givenCard : this->playerHand)
                {
                    score[0] += givenCard.getValue();
                }
                for (Card givenCard : this->playerHand)
                {
                    score[1] += givenCard.getAltValue();
                }
                if (score[0] <= 21)
                {
                    return score[0];
                }
                else
                {
                    return score[1];
                }
            }

            void printHand()
            {
                cout << "Your hand consists of:" << endl;
                for (Card givenCard : this->playerHand )
                {
                    cout << "-- " << givenCard.getName() << " of " << givenCard.getSuit() << endl;
                }
            }
    };
}