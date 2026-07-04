class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>>vis(m,vector<int>(n,-1));

        int sr=entrance[0];
        int sc=entrance[1];

        vis[sr][sc]=1;
        queue<pair<pair<int,int>,int>>q;  //{{r,c},d};
      q.push({{sr,sc},0});
      
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;


            q.pop();

           if ((r != sr || c != sc) &&
                (r == 0 || r == m - 1 || c == 0 || c == n - 1))
                return d;
        

        vector<int>drow={1,0,-1,0};
        vector<int>dcol={0,-1,0,1};

        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];

    if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && maze[nrow][ncol]=='.' && vis[nrow][ncol]==-1){
        q.push({{nrow,ncol},d+1});
        vis[nrow][ncol]=1;
    }
        }
        }
        return -1;
    }
};