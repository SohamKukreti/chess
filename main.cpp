#include <iostream>
using namespace std;
#define WHITE_SQUARE 0xDB
#define BLACK_SQUARE 0xFF

class ChessBoard{
    public:
        ChessBoard(){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    board[i][j] = '0';
                }
            }
        };
        void printBoard(){
            cout << "   A   B   C   D   E   F   G   H" << endl;
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
    private:
        char board[8][8];
};

int main(){
    ChessBoard board;
    board.printBoard();
    return 0;
}