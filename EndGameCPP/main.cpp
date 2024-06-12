#include "BlackJackGame.h"
#include <iostream>

using namespace std;
using namespace myBlackJackGame;

int main ()
{
    cout << "Started" << endl;
    BlackJackGame thisGame;
    cout << "Hello and welcome to BlackJack" << endl;
    cout << "To play twist to recieve more cards or stick to stop" << endl;
    cout << "To guess twist, type [T]" << endl;
    cout << "To guess stick, type [S]" << endl;
    cout << "The deck is being shuffled \n\n" << endl;
    thisGame.startGame();
    cout << "Player One got " << thisGame.getPlayerHand(0).getLastAddedCard().getName() << " of " << thisGame.getPlayerHand(0).getLastAddedCard().getSuit() << endl;
    cout << "Player Two got " << thisGame.getPlayerHand(1).getLastAddedCard().getName() << " of " << thisGame.getPlayerHand(1).getLastAddedCard().getSuit() << endl;
    cout << endl << endl;

    for (int i = 0; i<thisGame.getNumberOfPlayers(); i++)
    {
        cout << "Player " << i+1 << " turn" << endl;
        thisGame.getPlayerHand(i).printHand();
        cout << "Your score is " << thisGame.getPlayerScore(i) << endl;
        if (thisGame.checkPlayerOver())
        {
            break;
        }
        string userInput;
        cout << "Twist or Stick" << endl;
        do
        {
            cin >> userInput;
            if (userInput == "t")
            {
                thisGame.addCardToPlayer(thisGame.getGameDeck().pickNextCard(),i);
                cout << endl << endl;
                cout << "You got " << thisGame.getPlayerHand(i).getLastAddedCard().getName() << " of " << thisGame.getPlayerHand(i).getLastAddedCard().getSuit() << endl;
                cout << "Your score is " << thisGame.getPlayerScore(i) << endl;
                if (thisGame.checkPlayerOver() || i == 1 && thisGame.checkPlayerTwoOver())
                {
                    break;
                }
                thisGame.getPlayerHand(i).printHand();
                cout << "Twist or Stick" << endl;
            }
        } while (userInput != "s");
    }
    cout << endl << endl;
    cout << "Player One score is " << thisGame.getPlayerHand(0).handCalculator() << endl;
    cout << "Player Two score is " << thisGame.getPlayerHand(1).handCalculator() << endl;
    switch (thisGame.playerWon())
    {
        case 0:
            cout << "Player One has Won" << endl;
            break;
        case 1:
            cout << "Player Two has won" << endl;
            break;
        case -1:
            cout << "Draw" << endl;
            break;
    }
    cout << "END" << endl;
    return 0;
}