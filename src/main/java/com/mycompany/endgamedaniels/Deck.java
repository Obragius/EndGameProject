/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.endgamedaniels;

import java.util.ArrayList;
import java.util.Random;

/**
 *
 * @author Shadow
 */
public class Deck {
    private ArrayList<Card> cards = new ArrayList<Card>();
    private String[] cardNames = {"Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King","Ace"};

    public Deck() 
    {
        String[] suits = {"Hearts","Diamonds","Spades","Clubs"};
        for (String suit: suits)
        {
            for (String card: this.cardNames)
            {
                this.cards.add(new Card(suit,card));
            }
        }
    }
    
    public void returnAllCards(ArrayList<Hand> playerHands)
    {
        for (int i = 1; i < playerHands.size(); i++)
        while (playerHands.get(i-1).isEmpty() == false)
        {
            this.cards.add(playerHands.get(i-1).removeCard());
        }
    }
    
    public Card pickNextCard()
    {
       return this.cards.remove(0);
    }
    
    public Card pickACard()
    {
        Random rand = new Random();
        int indexOfCard = rand.nextInt(this.cards.size());
        return this.cards.remove(indexOfCard);
    }
    
    public void shuffle()
    {
        ArrayList<Card> newDeck = new ArrayList();
        Random rand = new Random();
        while (this.cards.size() > 0)
        {
            int indexOfCard = rand.nextInt(this.cards.size());
            newDeck.add(this.cards.remove(indexOfCard));
        }
        this.cards = newDeck;
    }
    
}
