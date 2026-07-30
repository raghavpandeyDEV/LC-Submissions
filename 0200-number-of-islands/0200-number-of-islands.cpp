class Solution {
public:
    void bfs(vector<vector<int>>&vis ,vector<vector<char>>& grid,queue<pair<int,int>>&q){
           int m=grid.size();
           int n=grid[0].size();

        while(!q.empty()){

            int i=q.front().first;
            int j=q.front().second;
            q.pop();

        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};
        
        for(int idx=0;idx<4;idx++){
            int nrow=i+drow[idx];
            int ncol=j+dcol[idx];
    if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && vis[nrow][ncol]==-1 && grid[nrow][ncol]=='1'){
        vis[nrow][ncol]=1;
        q.push({nrow,ncol});
    }
        }

    }
    }
    int numIslands(vector<vector<char>>& grid) {
        
 int m=grid.size();
         int n=grid[0].size();
         vector<vector<int>>vis(m , vector<int>(n,-1));
         int cnt=0;
          
         queue<pair<int,int>>q;

         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vis[i][j]==-1){
                    q.push({i,j});
                    vis[i][j]=1;
                    bfs(vis,grid,q);
                    cnt++;
                }
            }
         }
         return cnt;
    }
};