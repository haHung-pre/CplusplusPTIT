#include<bits/stdc++.h>
using namespace std;
void playGuessNumber(){
    srand(time(0));
    int numberToGuess=rand()%100+1;
    int guess;
    int attempts=0;
    cout<<"Welcome to the Number Guessing Game!\n";
    cout<<"I'm thinking of a number between 1 and 100. Can you guess it?\n";
    
    do{
        cout<<"Enter your guess: ";
        cin>>guess;
        attempts++;
        if(guess<numberToGuess){
            cout<<"Your guess is too low.\n";
        }else if(guess>numberToGuess){
            cout<<"Your guess is too high.\n";
        }else{
            cout<<"Congratulations! You guessed it in "<<attempts<<" attempts.\n";
        }
    }while(guess!=numberToGuess);
}

// Tic-Tac-Toe Game
void displayBoard(const vector<vector<char>>&board){
    cout<<"  0 1 2\n";
    for(int i=0;i<3;++i){
        cout<<i<<" ";
        for(int j=0;j<3;++j){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool checkWin(const vector<vector<char>>&board,char player){
    for(int i=0;i<3;i++){
        if(board[i][0]==player&&board[i][1]==player&&board[i][2]==player)return true;
        if(board[0][i]==player&&board[1][i]==player&&board[2][i]==player)return true;
    }
    if(board[0][0]==player&&board[1][1]==player&&board[2][2]==player)return true;
    if(board[0][2]==player&&board[1][1]==player&&board[2][0]==player)return true;
    return false;
}

bool isBoardFull(const vector<vector<char>>&board){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==' ')return false;
        }
    }
    return true;
}

void playTicTacToe(){
    vector<vector<char>>board(3,vector<char>(3,' '));
    char currentPlayer='X';
    cout<<"Welcome to Tic-Tac-Toe!\n";
    
    while(true){
        displayBoard(board);
        int row,col;
        cout<<"It's "<<currentPlayer<<"'s turn. Enter row and column (0-2): ";
        cin>>row>>col;
        
        if(row<0||row>2||col<0||col>2||board[row][col]!=' '){
            cout<<"Invalid move. Try again.\n";
            continue;
        }

        board[row][col]=currentPlayer;
        
        if(checkWin(board,currentPlayer)){
            displayBoard(board);
            cout<<"Congratulations! Player "<<currentPlayer<<" wins!\n";
            break;
        }

        if(isBoardFull(board)){
            displayBoard(board);
            cout<<"It's a draw!\n";
            break;
        }
        
        currentPlayer=(currentPlayer=='X')?'O':'X';
    }
}

int main(){
    int choice;
    do{
        cout<<"\nMini Game Console\n";
        cout<<"1. Number Guessing\n";
        cout<<"2. Tic-Tac-Toe\n";
        cout<<"3. Exit\n";
        cout<<"Choose a game: ";
        cin>>choice;

        switch(choice){
            case 1:
                playGuessNumber();
                break;
            case 2:
                playTicTacToe();
                break;
            case 3:
                cout<<"Exiting the program.\n";
                break;
            default:
                cout<<"Invalid option. Please choose again.\n";
        }
    }while(choice!=3);

    return 0;
}

