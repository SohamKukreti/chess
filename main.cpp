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

        void executeMove(string move);

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
        string turn;
        vector <char> whiteCapturedPieces;
        vector <char> blackCapturedPieces;
        Game(){
            ChessBoard board;
            turn = "white";
        }
        ChessBoard board;

        pair<int,int> getCoordinates(string move){
            int row = move[1] - '1';
            int col = move[0] - 'a';
            cout << row << " " << col << endl;
            return make_pair(row,col);
        }

        bool isValidMove(string move){
            if(move.length() != 4){
                return false;
            }
            pair<int,int> start = getCoordinates(move.substr(0,2));
            pair<int,int> end = getCoordinates(move.substr(2,2));
            if(start.first < 0 || start.first > 7 || start.second < 0 || start.second > 7){
                return false;
            }
            if(end.first < 0 || end.first > 7 || end.second < 0 || end.second > 7){
                return false;
            }
            if(board.board[start.first][start.second] == ' '){
                return false;
            }
            char piece = board.board[start.first][start.second];

            if(piece == 'P' and turn == "white"){
                if(start.first == 1){
                    if(end.first == 3 && start.second == end.second){
                        return true;
                    }
                }
                if(end.first == start.first + 1 && start.second == end.second){
                    if(board.board[end.first][end.second] != ' '){
                        return false;
                    }
                    return true;
                }
                if(board.board[end.first][end.second] != ' '){
                    if(abs(start.second - end.second) == 1 && end.first == start.first + 1){
                        return true;
                    }
                }
            }

            if(piece == 'p' && turn == "black"){
                if(start.first == 6){
                    if(end.first == 4 && start.second == end.second){
                        return true;
                    }
                }
                if(end.first == start.first - 1 && start.second == end.second){
                    if(board.board[end.first][end.second] != ' '){
                        return false;
                    }
                    return true;
                }
                if(board.board[end.first][end.second] != ' '){
                    if(abs(start.second - end.second) == 1 && end.first == start.first - 1){
                        return true;
                    }
                }
            }

            if(piece == 'R' && turn == "white" || piece == 'r' && turn == "black"){
                if(start.first == end.first || start.second == end.second){
                    return true;
                }
            }

            if(piece == 'N' && turn == "white" || piece == 'n' && turn == "black"){
                if((abs(start.first - end.first) == 2 && abs(start.second - end.second) == 1) || (abs(start.first - end.first) == 1 && abs(start.second - end.second) == 2)){
                    return true;
                }
            }

            if(piece == 'B' && turn == "white" || piece == 'b' && turn == "black"){
                if(abs(start.first - end.first) == abs(start.second - end.second)){
                    return true;
                }
            }

            if(piece == 'Q' && turn == "white" || piece == 'q' && turn == "black"){
                if(start.first == end.first || start.second == end.second){
                    return true;
                }
                if(abs(start.first - end.first) == abs(start.second - end.second)){
                    return true;
                }
            }

            if(piece == 'K' && turn == "white" || piece == 'k' && turn == "black"){
                if(abs(start.first - end.first) <= 1 && abs(start.second - end.second) <= 1){
                    return true;
                }
            }

            return false;

        }

        void makeMove(string move){
            if(isValidMove(move)){
                executeMove(move);
                if(turn == "white"){
                    turn = "black";
                }
                else{
                    turn = "white";
                }
            }
            else{
                cout << "Invalid move" << endl;
            }
        }

        void executeMove(string move){
            pair <int,int> start = getCoordinates(move.substr(0,2));
            pair <int,int> end = getCoordinates(move.substr(2,2));
            cout << "Start: " << start.first << " " << start.second << endl;
            cout << "End: " << end.first << " " << end.second << endl;
            if(board.board[end.first][end.second] != ' '){
                if(turn == "white"){
                    cout << "White captured " << board.board[end.first][end.second] << endl;
                    whiteCapturedPieces.push_back(board.board[end.first][end.second]);
                }
                else{
                    cout << "Black captured " << board.board[end.first][end.second] << endl;
                    blackCapturedPieces.push_back(board.board[end.first][end.second]);
                }
                
            }
            board.board[end.first][end.second] = board.board[start.first][start.second];
            board.board[start.first][start.second] = ' '; 
            if(board.board[end.first][end.second] == 'P' && end.first == 7){
                board.board[end.first][end.second] = 'Q';
            }
            if(board.board[end.first][end.second] == 'p' && end.first == 0){
                board.board[end.first][end.second] = 'q';
            }
            cout << "Move executed" << endl;
        }
};

int main(){
    Game game;
    cout << endl << "Move format: original position to new position (e.g. a2a4)" << endl << endl;
    cout << "Enter 'exit' to exit the game" << endl << endl;
    cout << "Uppercase letters represent white pieces and lowercase letters represent black pieces" << endl << endl;
    while(true){
        game.board.printBoard();
        cout << "Turn: " << game.turn << endl;
        if(game.whiteCapturedPieces.size() > 0){
            cout << "White captured pieces: ";
            for(int i = 0;i<game.whiteCapturedPieces.size();i++){
                cout << game.whiteCapturedPieces[i] << " ";
            }
        }
        if(game.blackCapturedPieces.size() > 0){
            cout << "Black captured pieces: ";
            for(int i = 0;i<game.blackCapturedPieces.size();i++){
                cout << game.blackCapturedPieces[i] << " ";
            }
        }
        cout << endl;
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