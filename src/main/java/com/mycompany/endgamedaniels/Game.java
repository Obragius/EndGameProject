/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.endgamedaniels;

import java.util.ArrayList;

/**
 *
 * @author lolki
 */
public abstract class Game {
    private boolean gameOn;
    private Deck gameDeck;
    private ArrayList<Boolean> lost = new ArrayList<Boolean>();
    private int numberOfPlayers;
    private ArrayList<Hand> playerHands = new ArrayList<Hand>();

    public Game() {
        this.gameOn = true;
        this.gameDeck = new Deck();
    }
    
    public Deck getGameDeck() 
    {
        return gameDeck;
    }

    public boolean isGameOn() 
    {
        return gameOn;
    }
    
    
    public void setGameOn(boolean game)
    {
        this.gameOn = game;
    }
    
    public void setLost(int player)
    {
        this.lost.set(player,true);
    }
    
    public boolean getLost(int player)
    {
        return this.lost.get(player);
    }
    
    public Hand getPlayerHand(int playerNumber)
    {
        return this.playerHands.get(playerNumber);
    }

    public int getNumberOfPlayers() {
        return this.numberOfPlayers;
    }
    
    public void addCardToPlayer(Card cardToAdd, int playerNumber)
    {
        this.playerHands.get(playerNumber).addCard(cardToAdd);
    }

    public void addPlayer()
    {
        this.lost.add(false);
        this.numberOfPlayers += 1;
        this.playerHands.add(new Hand());
    }
    
    public abstract void startGame();
    
    public abstract void finishGame();
    
    
}
