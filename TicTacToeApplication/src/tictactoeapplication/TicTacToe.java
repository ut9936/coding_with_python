
package tictactoeapplication;

public class TicTacToe {
    protected char[] board;
    protected char userMarker;
    protected char aiMarker;
    protected char winner;
    protected char currentMarker;
    
    public TicTacToe(char PlayerToken,char AIToken){
        this.userMarker = PlayerToken;
        this.aiMarker = AIToken;
        this.winner = '-';
        this.board = setBoard();
        this.currentMarker = userMarker;
    }
    public static char[] setBoard(){
        char[] board = new char[9];
        for(int i = 0;i < board.length;i++){
            board[i] = '-';
        }
        return board;
    }
    public boolean playTurn(int spot){
        boolean isValid = (withinRange(spot) && !isSpotTaken(spot));
        if(isValid){
            board[spot-1] = currentMarker;
            currentMarker = ((currentMarker == userMarker) ? aiMarker : userMarker);
            System.out.println(this.currentMarker);
        }
        return isValid;
    }
    public boolean withinRange(int number){
        return number > 0 && number < board.length+1;
    }
    public boolean isSpotTaken(int spot){
        return (board[spot-1] != '-');
    }
    public void printBoard(){
        for(int i = 0;i < board.length;i++){
            if(i%3 == 0){
                System.out.println();
                System.out.println("--------------");
                // | X | X | X
                //--------------
            }
            System.out.print(" | "+board[i]);
        }
        System.out.print(" ");
    }
    public static void printIndexBoard(){
        for(int i = 0;i < 9;i++){
            if(i%3 == 0){
                System.out.println();
                System.out.println("--------------");
                // | X | X | X
                //--------------
            }
            System.out.print(" | "+(i+1));
        }
        System.out.println();
    }
    
    public boolean isThereAWinner(){
        boolean diagonalsAndMiddles = (rightD() || leftD() || middleRow() || secondCol()) && this.isSpotTaken(5);
        boolean topAndFirst = (topRow() || firstCol()) && this.isSpotTaken(1);
        boolean bottomAndThird = (bottomRow() || thirdCol()) && this.isSpotTaken(9);
        if(diagonalsAndMiddles){
            this.winner = board[4];
        }
        else if(topAndFirst){
            this.winner = board[0];
        }
        else if(bottomAndThird){
            this.winner = board[8];
        }
        return ((diagonalsAndMiddles || topAndFirst) || (bottomAndThird));
    }
    public boolean rightD(){
        return ((board[2] == board[4]) && (board[4] == board[6]));
    }
    public boolean leftD(){
        return ((board[0] == board[4]) && (board[4] == board[8]));
    }
    public boolean middleRow(){
        return ((board[3] == board[4]) && (board[4] == board[5]));
    }
    public boolean secondCol(){
        return ((board[1] == board[4]) && (board[4] == board[7]));
    }
    public boolean firstCol(){
        return ((board[3] == board[0]) && (board[0] == board[6]));
    }
    public boolean topRow(){
        return board[1] == board[0] && board[0] == board[2];
    }
    public boolean bottomRow(){
        return board[6] == board[8] && board[8] == board[7];
    }
    public boolean thirdCol(){
        return ((board[2] == board[8]) && (board[8] == board[5]));
    }
     
    public boolean isTheBoardFilled(){
        for(int i = 0;i < board.length;i++){
            if(board[i] == '-'){
                return false;
            }
        }
        return true;
    }
    public String gameOver(){
        boolean didSomeoneWin = isThereAWinner();
        if(didSomeoneWin){
            return "We have a winner. The winner is "+this.winner+"'s.";
        }
        else if(isTheBoardFilled()){
            return "Draw : The game over";
        }
        else{
            return "notOver";
        }
    }
}
