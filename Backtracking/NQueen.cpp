#include<iostream>
#include<vector>
using namespace std;
void printboard(vector<vector<int>> board, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j];
        }
    }
}
void nqueens(vector<vector<int>> board, int row){
    if(row == board.size()){
        printboard(board,row);
        return;
    }
}
int main(){
    vector<vector<char>> board;
    int n=4;
    for(int i=0;i<n;i++){
        vector<char> rows;
        for(int j=0;j<n;j++){
            rows.push_back(' ');
        }
        board.push_back(rows);
    }
    nqueens( board, 0);
    
}