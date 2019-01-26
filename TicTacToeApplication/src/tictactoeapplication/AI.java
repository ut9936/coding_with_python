
package tictactoeapplication;

import java.util.ArrayList;
import java.util.Random;


class AI {
    Random r = new Random();
    private int count;
    public int pickSpot(TicTacToe game){
        ArrayList<Integer> choices = new ArrayList<>();
        for(int i = 0;i < 9;i++){
            if(game.board[i] == '-'){
                choices.add(i+1);
            }
        }
        int choice = choices.get(Math.abs(r.nextInt()%choices.size()));
        return choice;
    } 
    public int smartPickSpot(TicTacToe game){
        ArrayList<Integer> choices = new ArrayList<>();
        ArrayList<Integer> PlayersChoices = new ArrayList<>();
        count = 0;
        for(int i = 0;i < 9;i++){
            if(game.board[i] == '-'){
                choices.add(i+1);
            }
            else if(game.board[i] == game.userMarker){
                PlayersChoices.add(i+1);
                count++;
            }
        }
        if(count == 1){
            return firstPick(PlayersChoices);
        }
        if(count == 2){
            return secondPick(PlayersChoices,game);
        }
        else{
            return pickSpot(game);
        }
    }
    public int firstPick(ArrayList<Integer> user){
        //Corner
        int A = user.get(0);
        if(A == 5){
            return 1;
        }
        else{
            return 5;
        }
    }
    public int secondPick(ArrayList<Integer> user,TicTacToe game){
        int A = user.get(0);
        int R = pickSpot(game);
        if(A != 5){
            int B = user.get(1);
            if(A == 1 && B == 3){
                R = 2;
            }
            else if(A == 1 && B != 3){
                R = 4;
            }
        }
        else{
            int B = user.get(1);
            int C = Math.abs(10-B);
            R = C;
        }
        return R;
    }
}
