#include "Deck.h"
using namespace std;
using namespace myDeck;

namespace myGame
{
    class Game
    {
        protected:
            bool gameOn;
            Deck gameDeck;
            vector<bool> lost;
            int numberOfPlayers;
            vector<Hand> playerHands;

        public:
            Game()
            {
                this->gameOn = true;
                Deck givenDeck = Deck();
                Deck pGivenDeck = givenDeck;
                this->gameDeck = pGivenDeck;
            }

            Deck& getGameDeck()
            {
                return this->gameDeck;
            }

            bool isGameOn()
            {
                return this->gameOn;
            }

            void setGameOn(bool game)
            {
                this->gameOn = game;
            }

            void setLost(int player)
            {
                this->lost[player] = true;
            }

            bool getLost(int playerNumber)
            {
                return this->lost[playerNumber];
            }

            Hand getPlayerHand(int playerNumber)
            {
                return this->playerHands[playerNumber];
            }

            int getNumberOfPlayers()
            {
                return this->numberOfPlayers;
            }

            void addCardToPlayer(Card cardToAdd, int playerNumber)
            {
                this->playerHands[playerNumber].addCard(cardToAdd);
            }

            void addPlayer()
            {
                this->lost.emplace_back(false);
                this->numberOfPlayers += 1;
                Hand givenHand;
                this->playerHands.emplace_back(givenHand);
            }

            void startGame()
            {

            }
            void finishGame()
            {

            }
    };
}