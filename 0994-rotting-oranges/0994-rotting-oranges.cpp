class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        //{{r,c},t}

        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(m , vector<int>(n,-1)); 

        int fresh=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=1;
              }
              else if(grid[i][j]==1)fresh++;
            }
        }
        
        vector<int>drow={-1,0,1,0}; 
        vector<int>dcol={0,1,0,-1};

        int tm=0;
        int cnt=0;

        while(!q.empty()){
          int r=q.front().first.first;
          int c=q.front().first.second;
          int t=q.front().second;
          q.pop();

          tm=max(tm,t);

          for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && vis[nrow][ncol]==-1 && grid[nrow][ncol]==1){
    vis[nrow][ncol]=1;
    q.push({{nrow,ncol}, t+1});
    cnt++;
}
          }


        }
if(cnt!=fresh)return -1;
return tm;

    }
};