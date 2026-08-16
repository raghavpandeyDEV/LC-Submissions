class Solution {
public: 

    bool isSafe(int r , int c , vector<string>&board ,int n){
        int saved_row=r;
        int saved_col=c;

        while(r>=0 && c>=0){
            if(board[r][c]=='Q')return false;
            r--;
            c--;
        }

        r=saved_row;
        c=saved_col;

        while(c>=0){
            if(board[r][c]=='Q')return false;
            c--;
        }

r=saved_row;
        c=saved_col;
        while(r<n && c>=0){
            if(board[r][c]=='Q')return false;
            r++;
            c--;
        }
        return true;
    }

    void solve(int col , vector<string>&board, vector<vector<string>>&ans ,int n){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++){
           if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
           }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        // n x n empty board
        vector<string> board(n, string(n, '.'));

        solve(0, board, ans, n);

        return ans;
    }
};