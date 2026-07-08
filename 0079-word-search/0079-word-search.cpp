class Solution {
public:
    bool found(int i , int j , vector<vector<char>>& board , int k, string&word ){
        int m=board.size();
        int n=board[0].size();

        if(k==word.size())return true;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]!=word[k])return false;

        char temp=board[i][j];
        board[i][j]='#';

        bool up=found(i-1,j,board,k+1,word);
        bool down=found(i+1,j,board,k+1,word);
        bool left=found(i,j-1,board,k+1,word);
        bool right=found(i,j+1,board,k+1,word);

        board[i][j]=temp;
        return up || down || left || right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(found(i,j,board,0,word))return true;
                }
            }
        }
        return false;
    }
};