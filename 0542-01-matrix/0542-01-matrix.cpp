class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // bfs -> queue -> {{r,c},d+1}

        int m=mat.size();
        int n=mat[0].size();
            queue<pair<pair<int,int>,int>>q;


         vector<vector<int>>ans(m, vector<int>(n));
         vector<vector<int>>vis(m, vector<int>(n,-1));

         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
         }

         vector<int>drow={-1,0,1,0};
         vector<int>dcol={0,1,0,-1};

         while(!q.empty()){
            int r=q.front().first.first;
            int c= q.front().first.second;
            int d=q.front().second;

            

            q.pop();

            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && vis[nrow][ncol]==-1 && mat[nrow][ncol]==1){
    q.push({{nrow,ncol},d+1});
    vis[nrow][ncol]=1;
    ans[nrow][ncol]=d+1;
}
            }
         }


return ans;

    }
};