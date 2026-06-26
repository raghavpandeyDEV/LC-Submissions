class Solution {
public:
    void bfs(int r , int c , vector<vector<int>>&vis , vector<vector<char>>& grid){
         int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>>q;
        q.push({r,c});

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;

            q.pop();

            vector<int>drow={1,0,-1,0};
            vector<int>dcol={0,-1,0,1};

    for(int i=0;i<4;i++){
        int nrow=r+drow[i];
        int ncol=c+dcol[i];

 if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol]=='1' && vis[nrow][ncol]==-1){
  q.push({nrow,ncol});
  vis[nrow][ncol]=1;
 }
    }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,-1));
       int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]=='1' && vis[i][j]==-1 ){
                bfs(i,j,vis,grid);
                cnt++;
               }
            }
        }
        return cnt;
    }
};