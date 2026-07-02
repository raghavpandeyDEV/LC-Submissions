class Solution {
public: 
     bool isSafe(int row , int col ,  vector<string>&board , int n){
        int saved_row=row;
        int saved_col=col;

        while(row>=0 && col>=0){
            if(board[row][col]=='Q')return false;
            row--;
            col--;
        }
        row=saved_row;
        col=saved_col;

        while(col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }
        col=saved_col;

        while(row<n && col>=0){
             if(board[row][col]=='Q')return false;
             row++;
             col--;
        }
        return true;

    }

    void solve(int col , vector<string>&board ,int&count, int n){
      if(col==n){
        count++;
        return ;
      }
      for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,board,count,n);
            board[row][col]='.';
        }
      }

    }

    int totalNQueens(int n) {
        int cnt=0;
        vector<string> board(n, string(n, '.'));
        int count = 0;

        solve(0, board, count, n);

        return count;
    }
};