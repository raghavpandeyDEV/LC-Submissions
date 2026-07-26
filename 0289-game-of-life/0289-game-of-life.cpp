class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int>drow={1,0,-1,0 , 1 ,1, -1,-1};
        vector<int>dcol={0,-1,0,1 , -1,1,-1,1};

        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int live = 0;
                for(int ind=0;ind<8;ind++){
                    int nrow=i+drow[ind];
                    int ncol=j+dcol[ind];
if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && abs(board[nrow][ncol])==1)live++;
                }
                if(board[i][j]==1){
                    if(live<2 || live>3)board[i][j]=-1;
                }
                else{
                    if(live==3)board[i][j]=5;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==-1)board[i][j]=0;
                if(board[i][j]==5)board[i][j]=1;
            }
        }
    }  
};