#include<iostream>
using namespace std;

int board[20][20];
int n;

bool issafe(int row, int col){
    for(int i=0; i<row; i++){
        if(board[i][col] == 1)
            return false;
    }
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 1)
            return false;
    }
    for(int i=row, j=col; i >= 0 && j < n; i--, j++){
        if(board[i][j] == 1)
            return false;
    }
    return true;
}
bool nqueen(int row){
    if(row == n)
        return true;
    for(int col=0; col<n; col++){
        if(issafe(row, col)){
            board[row][col] = 1;
            if(nqueen(row + 1))
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}
int main(){
    cout<<"enter number of queens: ";
    cin>>n;

    if(nqueen(0)){
        cout<<"solution:\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"no solution exists";
    }
    return 0;
}