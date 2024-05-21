/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com;

import java.util.ArrayList;

/**
 *
 * @author lolki
 */
public class Hand {
    private ArrayList<Card> playerHand = new ArrayList<Card>();
    private Card lastAddedCard;
    
    public boolean isEmpty()
    {
        return this.playerHand.isEmpty();
    }

    public Card getLastAddedCard() 
    {
        return lastAddedCard;
    }

    public void setLastAddedCard(Card lastAddedCard) 
    {
        this.lastAddedCard = lastAddedCard;
    }
    
    
    
    public void addCard(Card newCard)
    {
        this.playerHand.add(newCard);
        this.setLastAddedCard(newCard);
    }
    
    public ArrayList<Card> returnAllCards()
    {
        return this.playerHand;
    }
    
    public Card removeCard()
    {
        return this.playerHand.remove(0);
    }
    
    
    
    public int handCalculator()
    {
        int[] score = {0,0};
        for (Card givenCard: this.playerHand)
        {
            score[0] += givenCard.getValue();
        }
        for (Card givenCard: this.playerHand)
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
    
    public void printHand()
    {
        System.out.println("Your hand consists of:");
        for (Card givenCard: this.playerHand)
        {
            System.out.println("-- "+givenCard.getName()+" of "+givenCard.getSuit());
        }
    }
    
}
