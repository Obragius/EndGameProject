/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.endgamedaniels;

/**
 *
 * @author lolki
 */
public class BlackJackGame extends Game {
    
    public BlackJackGame()
    {
        super();
        for (int i = 0; i < 2; i++)
        {
            this.addPlayer();
        }
        this.getGameDeck().shuffle();
    }
    
    @Override
    public void startGame()
    {
        //Give player one and two cards
        this.addCardToPlayer(this.getGameDeck().pickNextCard(),0);
        this.addCardToPlayer(this.getGameDeck().pickNextCard(),1);
        
    }
    
    public int playerWon()
    {
        int playerOneValue = this.getPlayerHand(0).handCalculator();
        int playerTwoValue = this.getPlayerHand(1).handCalculator();
        if (this.getLost(0) == true || playerTwoValue > playerOneValue && playerTwoValue <= 21)
        {
            return 1;
        }
        else if (this.getLost(1) == true || playerOneValue > playerTwoValue && playerOneValue <= 21)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    
    @Override
    public void finishGame()
    {
        this.setGameOn(false);
    }
    
    public boolean checkPlayerTwoOver()
    {
        return this.getPlayerHand(1).handCalculator() > this.getPlayerHand(0).handCalculator();
    }
    
    
    
    public boolean checkPlayerOver()
    {
        for (int i = 0; i < this.getNumberOfPlayers(); i++)
        {
            Hand thisPlayerHand = this.getPlayerHand(i);
            int handValue = thisPlayerHand.handCalculator();
            if (handValue > 21)
            {
                this.setLost(i);
                this.setGameOn(false);
                return true;
            }
        }
        return false;
    }
    
    public int getPlayerScore(int player)
    {
        return this.getPlayerHand(player).handCalculator();
    }
    
}
