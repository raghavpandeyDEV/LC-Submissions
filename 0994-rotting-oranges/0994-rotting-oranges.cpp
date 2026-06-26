class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cntFresh=0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int,int>,int>>q;   // {{r,c},t}

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                if(grid[i][j]==1){
                    cntFresh++;
                }
            }
        }

         int drow[4]={-1,0,1,0};
          int dcol[4]={0,1,0,-1};
        int tm=0;
        int cnt=0;

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(t,tm);
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=drow[i]+r;
                int ncol=dcol[i]+c;
     if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
        vis[nrow][ncol]=1;
        q.push({{nrow,ncol},t+1});
        cnt++;
     }

            }
        }
      if(cntFresh!=cnt) return -1;
      return tm;

    }
};