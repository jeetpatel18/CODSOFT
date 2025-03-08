#include <iostream>
#include <vector>
using namespace std;

void displayBoard(const vector<vector<char>>& board) 
{
    cout<<" 0 1 2"<<endl;
    for (int i=0;i<3;++i)
    {
        cout<<i<<" ";
        for(int j=0;j<3;++j) 
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool checkWin(const vector<vector<char>>& board,char player) 
{
    for (int i=0;i<3;++i) 
    {
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player) 
        {
            return true;
        }
    }
    for(int j=0;j<3;++j) 
    {
        if(board[0][j]==player && board[1][j]==player && board[2][j]==player) 
        {
            return true;
        }
    }
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player) 
    {
        return true;
    }
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player) 
    {
        return true;
    }
    return false;
}
bool checkDraw(const vector<vector<char>>& board)
{
    for(int i=0;i<3;++i) 
    {
        for(int j=0;j<3;++j) 
        {
            if(board[i][j]==' ') 
            {
                return false; 
            }
        }
    }
    return true; 
}
int main() 
{
    char player1='X';
    char player2='O';
    char currentPlayer=player1;
    bool gameWon=false;
    bool gameDraw=false;
    bool playAgain=true;

    while(playAgain) 
    {
        vector<vector<char>>board(3,vector<char>(3, ' ')); 
        gameWon=false;
        gameDraw=false;
        currentPlayer=player1;

        while (!gameWon && !gameDraw) 
        {
            displayBoard(board);

            int row,col;
            cout<<"Player"<<currentPlayer<<",enter your move (row col):";
            cin>>row>>col;

            if(row>=0&& row<3 && col>=0 && col<3 && board[row][col]==' ') 
            {
                board[row][col]=currentPlayer;

                if(checkWin(board,currentPlayer))
                {
                    gameWon=true;
                } 
                else if(checkDraw(board)) 
                {
                    gameDraw=true;
                } 
                else 
                {
                    currentPlayer=(currentPlayer==player1)?player2:player1;
                }
            } 
            else 
            {
                cout<<"Invalid move. Try again."<<endl;
            }
        }
        displayBoard(board);
        if(gameWon) 
        {
            cout<<"Player"<<currentPlayer<<"wins!"<<endl;
        } 
        else 
        {
            cout<<"It's a draw!"<<endl;
        }
        char playAgainChoice;
        cout<<"Play again? (y/n): ";
        cin>>playAgainChoice;
        playAgain=(playAgainChoice=='y'||playAgainChoice=='Y');
    }
    cout<<"Thanks for playing!"<<endl;
    return 0;
}