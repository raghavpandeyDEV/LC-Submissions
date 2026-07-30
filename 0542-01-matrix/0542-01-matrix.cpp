class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n =mat[0].size();
       //BFS

       
       vector<vector<int>>ans(m,vector<int>(n,0));
       vector<vector<int>>vis(m,vector<int>(n,-1));
       queue<pair<pair<int,int>,int>>q; // {{r,c},d}

       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
                vis[i][j]=1;
                q.push({{i,j},0});
            }
        }
       }

       while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            ans[r][c]=d;

            q.pop();

            vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, 1, 0, -1};

            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && vis[nrow][ncol]==-1 && mat[nrow][ncol]==1){
    vis[nrow][ncol]=1;
    q.push({{nrow,ncol},d+1});
    
}
            }

        }
        return ans;
    }
};