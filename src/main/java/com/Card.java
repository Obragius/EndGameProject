/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com;


/**
 *
 * @author Shadow
 */
public class Card {
    private String suit;
    private String name;

    public Card(String suit, String name) {
        this.suit = suit;
        this.name = name;
    }

    public String getSuit() {
        return suit;
    }

    public void setSuit(String suit) {
        this.suit = suit;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    
    
    
    public int getValue()
    {
       String[] names = {"Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King","Ace"};
       int loopCount = 0;
       for (String name: names)
       {
           if (name.equals(this.name))
           {
               break;
           }
           loopCount += 1;
       }
       if (loopCount < 9)
       {
           return (loopCount + 2);
       }
       else if (loopCount > 8 && loopCount < 12)
       {
           return 10;
       }
       else
       {
            return 11;
       }
    }
    
    public int getAltValue()
    {
        if (this.name.equals("Ace"))
        {
            return 1;
        }
        else
        {
            return this.getValue();
        }
    }
}
