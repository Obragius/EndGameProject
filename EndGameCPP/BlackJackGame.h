#include "Game.h"
using namespace myGame;
using namespace std;

namespace myBlackJackGame
{
    class BlackJackGame: public Game
    {
        public:
            BlackJackGame()
                : Game()
                {
                    for (int i = 0; i < 2 ; i++)
                    {
                        this->addPlayer();
                    }
                    this->getGameDeck().shuffle();
                }

            void startGame()
            {
                this->addCardToPlayer(this->getGameDeck().pickNextCard(),0);
                this->addCardToPlayer(this->getGameDeck().pickNextCard(),1);
            }

            int playerWon()
            {
                int playerOneValue = this->getPlayerHand(0).handCalculator();
                int playerTwoValue = this->getPlayerHand(1).handCalculator();

                if (this->getLost(0) == true || playerTwoValue > playerOneValue && playerTwoValue <= 21)
                {
                    return 1;
                } else if (this->getLost(1) == true || playerOneValue > playerTwoValue && playerOneValue <= 21)
                {
                    return 0;
                } else
                {
                    return -1;
                }
            }

            void finishGame()
            {
                this->setGameOn(false);
            }

            bool checkPlayerTwoOver()
            {
                return this->getPlayerHand(1).handCalculator() > this->getPlayerHand(0).handCalculator();
            }

            bool checkPlayerOver()
            {
                for (int i = 0; i < this->getNumberOfPlayers() ; i++)
                {
                    Hand thisPlayerHand = this->getPlayerHand(i);
                    int handValue = thisPlayerHand.handCalculator();
                    if (handValue > 21)
                    {
                        this->setLost(i);
                        this->setGameOn(false);
                        return true;
                    }
                }
                return false;
            }

            int getPlayerScore(int player)
            {
                return this->getPlayerHand(player).handCalculator();
            }
    };
}