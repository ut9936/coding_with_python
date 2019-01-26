
package tictactoeapplication;

import java.util.Scanner;

public class TicTacToeApplication {

    public static void main(String[] args) {
        // Getting Input
        Scanner sc = new Scanner(System.in);
         boolean doYouWantToPlay = true;
         //Allows for continuous games
         while(doYouWantToPlay){
             //Setting up tokens
             System.out.println("Welcome to Tic Tac Toe ! You are about to go against "
                     + "the master of Tic Tac Toe. Are you ready? I hope so!\n But first"
                     + " you must pick what character you want to be and which character I will be\n \n "
                     + "Enter a single character that will represent you on the board");
             char playerToken = sc.next().charAt(0);
             System.out.println("Enter a single character that will represent your opponent on the board");
             char aiToken = sc.next().charAt(0);
             TicTacToe game = new TicTacToe(playerToken,aiToken);
             AI ai = new AI();
             //set up the game
             System.out.println("\nNow we can start the game, to play enter a number, and "
                     + "your token shall be put in it's place.\nNumbers representing different slots "
                     + "are shown below");
             TicTacToe.printIndexBoard();
             //Let's play
             while(game.gameOver().equals("notOver")){
                 if(game.currentMarker == game.userMarker){
                     System.out.println("It's your turn! Enter a spot for yout token");
                     int spot = sc.nextInt();
                     while(!game.playTurn(spot)){
                         System.out.println("Try again\n"+spot+" is already taken"
                                 + " or it is out of the range.");
                         spot = sc.nextInt();
                     }
                     System.out.println("You picked" + spot + "!");
                 }
                 else{
                     System.out.println("It's my turn");
                     int spot1 = ai.smartPickSpot(game);
                     game.playTurn(spot1);
                     System.out.println("I picked "+spot1+"!");
                 }
                 System.out.println();
                 game.printBoard();
                 System.out.println();
             }
             System.out.println("Do you wnat to play another game or"
                     + "you are tired of me. Enter Y to ontinue playing othewise enter any "
                     + "other character.");
             char Response = sc.next().charAt(0);
             doYouWantToPlay = (Response == 'Y');
             System.out.println();
             System.out.println();
         }
    }
    
}
