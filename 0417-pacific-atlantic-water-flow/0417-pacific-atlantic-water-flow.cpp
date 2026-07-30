class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        // pacific ocean 
       queue<pair<int,int>>q;
       vector<vector<int>>vis1(m,vector<int>(n,-1));

     for(int i=0;i<n;i++){
        q.push({0,i});
        vis1[0][i]=1;

     }

     for(int i=0;i<m;i++){
        q.push({i,0});
        vis1[i][0]=1;
     }

     while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        int currHeight=heights[r][c];

        q.pop();

        vector<int>drow={0,1,0,-1};
        vector<int>dcol={1,0,-1,0};

        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && heights[nrow][ncol]>=currHeight && vis1[nrow][ncol]==-1){
    vis1[nrow][ncol]=1;
    q.push({nrow,ncol});
}
        }
     }

     //Atlantic ocean

            vector<vector<int>>vis2(m,vector<int>(n,-1));

     for(int i=0;i<n;i++){
        q.push({m-1,i});
        vis2[m-1][i]=1;

     }

     for(int i=0;i<m;i++){
        q.push({i,n-1});
        vis2[i][n-1]=1;
     }

     while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        int currHeight=heights[r][c];

        q.pop();

        vector<int>drow={0,1,0,-1};
        vector<int>dcol={1,0,-1,0};

        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && heights[nrow][ncol]>=currHeight && vis2[nrow][ncol]==-1){
    vis2[nrow][ncol]=1;
    q.push({nrow,ncol});
}
        }
     }
// combining 
vector<vector<int>>ans;

  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(vis1[i][j]==1 && vis2[i][j]==1)ans.push_back({i,j});
    }
  }
return ans;
    }
};