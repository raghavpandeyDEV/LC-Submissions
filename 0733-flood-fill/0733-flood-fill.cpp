class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();

        int ini=image[sr][sc];
        vector<vector<int>>vis(m,vector<int>(n,-1));
        queue<pair<int,int>>q;

        q.push({sr,sc});
        vis[sr][sc]=1;
        image[sr][sc]=color;

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;

            q.pop();

            vector<int>drow={-1,0,1,0};
            vector<int>dcol={0,1,0,-1};

            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && vis[nrow][ncol]==-1 && image[nrow][ncol]==ini){
    vis[nrow][ncol]=1;
    q.push({nrow,ncol});
    image[nrow][ncol]=color;
}
            }
        }
     vector<vector<int>>ans;
  for(int i=0;i<m;i++){
    vector<int>row;
    for(int j=0;j<n;j++){
    row.push_back(image[i][j]);
    }
    ans.push_back(row);
  }
return ans;
    }
};