/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */
package com;

import java.util.Scanner;

/**
 *
 * @author Shadow
 */
public class EndGameDaniels {

    public static void main(String[] args) {
        BlackJackGame thisGame = new BlackJackGame();
        Scanner myScanner = new Scanner(System.in);
        System.out.println("Hello and welcome to blackjack");
        System.out.println("To play twist to recieve more cards or stick to stop");
        System.out.println("To guess twist, type [T]");
        System.out.println("To guess stick, type [S]");
        System.out.println("The deck is being shuffled\n\n");
        thisGame.startGame();
        System.out.println("Player One got " + thisGame.getPlayerHand(0).getLastAddedCard().getName() + " of " + thisGame.getPlayerHand(0).getLastAddedCard().getSuit());
        System.out.println("Player Two got " + thisGame.getPlayerHand(1).getLastAddedCard().getName() + " of " + thisGame.getPlayerHand(1).getLastAddedCard().getSuit());
        System.out.println("\n\n");

        for (int i = 0; i < thisGame.getNumberOfPlayers(); i++) {
            System.out.println(String.format("Player %d turn",i+1));
            thisGame.getPlayerHand(i).printHand();
            System.out.println(String.format("Your score is %d",thisGame.getPlayerScore(i)));
            if (thisGame.checkPlayerOver()) 
            {
                break;
            }
            String userInput;
            System.out.println("Twist or Stick?");
            do {
                userInput = myScanner.nextLine().toLowerCase();
                if (userInput.equals("t")) {
                    thisGame.addCardToPlayer(thisGame.getGameDeck().pickNextCard(), i);
                    System.out.println("\n\n");
                    System.out.println("You got " + thisGame.getPlayerHand(i).getLastAddedCard().getName() + " of " + thisGame.getPlayerHand(i).getLastAddedCard().getSuit());
                    System.out.println(String.format("Your score is %d",thisGame.getPlayerScore(i)));
                    if (thisGame.checkPlayerOver() || i == 1 && thisGame.checkPlayerTwoOver()) 
                    {
                        break;
                    }
                    thisGame.getPlayerHand(i).printHand();
                    System.out.println("Twist or Stick?");
                }
            } while (userInput.equals("s") == false);
        }
        System.out.println("\n\n");
        System.out.println(String.format("Player One score is %d",thisGame.getPlayerHand(0).handCalculator()));
        System.out.println(String.format("Player Two score is %d",thisGame.getPlayerHand(1).handCalculator()));
        switch (thisGame.playerWon()) {
            case 0:
                System.out.println("Player One has Won");
                break;
            case 1:
                System.out.println("Player Two has Won");
                break;
            case -1:
                System.out.println("Draw");
                break;
        }
        System.out.println("END");
    }
}
