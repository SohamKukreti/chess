#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ChessBoard{
    public:
        ChessBoard(){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    board[i][j] = ' ';
                }
            }
            board[0][0] = 'R';
            board[0][1] = 'N';
            board[0][2] = 'B';
            board[0][3] = 'Q';
            board[0][4] = 'K';
            board[0][5] = 'B';
            board[0][6] = 'N';
            board[0][7] = 'R';
            for(int i = 0; i < 8; i++){
                board[1][i] = 'P';
            }
            board[7][0] = 'r';
            board[7][1] = 'n';
            board[7][2] = 'b';
            board[7][3] = 'q';
            board[7][4] = 'k';
            board[7][5] = 'b';
            board[7][6] = 'n';
            board[7][7] = 'r';
            for(int i = 0; i < 8; i++){
                board[6][i] = 'p';
            }
        };
        void printBoard(){
            cout << "   a   b   c   d   e   f   g   h" << endl;
            cout << " ---------------------------------" << endl;
            for(int row = 0; row < 8; row++){
                for(int col = 0; col < 8; col++){
                    cout << " | ";
                    cout << board[row][col];
                }
                cout << " |";
                cout << " " << row + 1;
                cout << endl;
                cout << " ---------------------------------" << endl;
            }
        }
        char board[8][8];
};

class Game{
    public:
        Game(){
            ChessBoard board;
        }
        ChessBoard board;

        pair<int,int> getCoordinates(string move){
            int row = move[1] - '1';
            int col = move[0] - 'a';
            cout << row << " " << col << endl;
            return make_pair(row,col);
        }

        void makeMove(string move){
            pair <int,int> start = getCoordinates(move.substr(0,2));
            pair <int,int> end = getCoordinates(move.substr(2,2));
            cout << "Start: " << start.first << " " << start.second << endl;
            cout << "End: " << end.first << " " << end.second << endl;
            board.board[end.first][end.second] = board.board[start.first][start.second];
            board.board[start.first][start.second] = ' ';
            }
};

int main(){
    Game game;
    while(true){
        game.board.printBoard();
        cout << "Enter a move: ";
        string move;
        cin >> move;
        if(move != "exit"){
            game.makeMove(move);
        }
        if(move == "exit"){
            break;
        }
    }
    return 0;
}