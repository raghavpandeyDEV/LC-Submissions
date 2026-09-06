class Solution {
public:

    void bfs( int r , int c , vector<vector<int>>&vis,vector<vector<char>>& grid){
       //{r,c}
       int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>>q;
        vis[r][c]=1;
        q.push({r,c});

        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=drow[i]+row;
                int ncol=dcol[i]+col;
if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && vis[nrow][ncol]==-1 && grid[nrow][ncol]=='1'){
    q.push({nrow,ncol});
    vis[nrow][ncol]=1;
}
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>vis(m , vector<int>(n,-1));
        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    if(vis[i][j]==-1){
                    bfs(i,j,vis,grid);
                    cnt++;
                }
                }
            }
        }
        return cnt;
    }
};