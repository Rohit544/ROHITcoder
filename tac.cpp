#include<bits/stdc++.h>
using namespace std;

//to define the constant function 
#define computer 1
#define human 2

// define the size of the array 
#define side 3

// computer will move with O
// and human will move with X
#define computerMove 'O'
#define humanMove 'X'

//lets go through with a funcion 
void showBoard(char board[][side]){
    cout<<"\n\n";
      
    cout<<"  |   |  \n"<< board[0][0]<<board[0][1]<< board[0][2]<<endl;
    cout<<"--------------\n"<<endl;
    cout<<"  |   |   \n"<< board[1][0]<<board[1][1]<< board[1][2]<<endl;
    cout<<"--------------\n"<<endl;
    cout<<"  |   |   \n\n"<< board[2][0]<<board[2][1]<< board[2][2]<<endl;
   
    return;
}
    
    // now to show the instruction
    void showInstruction(){
        cout<<"\t\t\t  Tic-Tac-Toe\n\n"<<endl;
        cout<<"Choose a cell numbered from 1 to 9 as below and play\n\n"<<endl;
        
        cout<<" 1 | 2  | 3  \n"<<endl;
        cout<<"--------------\n"<<endl;
        cout<<" 4 | 5  | 6  \n"<<endl;
        cout<<"--------------\n"<<endl;
        cout<<" 7 | 8  | 9  \n\n"<<endl;
        
        cout<<"-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n"<<endl;

        return;
    }

    // a function to intialise the game
    void initialise(char board[][side],int moves[]){

        srand(time(NULL));
        // initially the board is empty
        for(int i=0;i<side;i++){
            for(int j=0;j<side;j++){
                board[i][j] = ' ';
            }
        }

        // to fill the board with moves
        for(int i =0;i<side*side;i++){
            moves[i] = i;
        }
        random_shuffle(moves,moves+side*side);
        return ;
    }

    //a function to declare the winner of the game 
    void declareWinner(int whoseTurn){
        if(whoseTurn == computer){
            cout<<"computer has won"<<endl;
        }
        else{
            cout<<"human has won "<<endl;
        }
       return; 
    }

        // the function for row crossed

    bool rowCrossed(char board[][side]){
        for(int i =0;i<side;i++){
            if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]!=' '){
                return(true);
            }
        }
        return(false);
    }

    // now the function of column crossed
    bool columnCrossed(char board[][side]){
        for(int i=0;i<side;i++){
            if(board[0][i]==board[i][1]&&board[i][1]==board[i][2]&&board[0][i]!=' '){
                return(true);
            }
        }

        return(false);
    }

    // now for the diagonals
    bool diagonalCrossed(char board[][side]){
            for(int i=0;i<side;i++){
                if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[0][0]!=' '){
                    return(true);
                }
                if(board[0][2]==board[1][1]&&board[1][1]==board[2][2]&&board[0][2]!=' '){
                    return(true);
                }
            }
        return(false);
    }

    // when the game will be over
    bool gameOver(char board[][side]){
        return(rowCrossed(board)||columnCrossed(board)||diagonalCrossed(board));
    }

    //now we want to play the game
     void play(int whoseTurn){
        char board[side][side];
        int moves[side*side];

        //calling the initialise function to show the board
        initialise(board,moves);
        //now to show the instruction
        showInstruction();
        
        int moveIndex = 0,x,y;

        while(gameOver(board) == false&&moveIndex != side*side){
            if(whoseTurn == computer){
                x = moves[moveIndex]/side;
                y = moves[moveIndex]%side;
                board[x][y] = computerMove;
                cout<<"computer has put a in cell "<<endl;
                showBoard(board);
                moveIndex++;
                whoseTurn = human;
            }
            else if(whoseTurn == human){
                x = moves[moveIndex];
                y = moves[moveIndex];
                board[x][y] = humanMove;
                cout<<"human has put a in cell "<<endl;
                showBoard(board);
                moveIndex++;
                whoseTurn = computer;
            }
        }

        //if the game will be drown
        if(gameOver(board) == false && moveIndex == side*side){
            cout<<"it is drow "<<endl;
        }
        else{
            if(whoseTurn == computer){
                whoseTurn = human;
            }else if(whoseTurn == human){
                whoseTurn = computer;
            }
            declareWinner(whoseTurn);
        }
        return;
     }

    int main(){

        // lets play with code
        play(computer);
        return 0;
    }