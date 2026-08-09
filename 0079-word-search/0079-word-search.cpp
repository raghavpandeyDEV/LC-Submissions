class Solution {
public:
    bool solve(int i , int j , vector<vector<char>>& board , int idx ,string&word ){
        int m=board.size();
        int n=board[0].size();
        if(idx==word.size())return true;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]!=word[idx])return false;

        char ch=board[i][j];
        board[i][j]='#';

        bool up = solve(i-1,j,board,idx+1,word);
        bool down= solve(i+1,j,board,idx+1,word);
        bool left = solve(i,j-1,board,idx+1,word);
        bool right= solve(i,j+1,board,idx+1,word);

        board[i][j]=ch;
        return (up || down || left || right);

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
       
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,board,0,word)==true)return true;
                }
            }
        }
     return false;
    }
};