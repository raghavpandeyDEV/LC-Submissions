class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>>dis(m,vector<int>(n,1e9));

        priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> pq;
 
     int sr=entrance[0];
     int sc=entrance[1];
     pq.push({0,{sr,sc}});
     dis[sr][sc]=0;

     while(!pq.empty()){
        int d=pq.top().first;
        int r=pq.top().second.first;
        int c=pq.top().second.second;
       if(!(r == sr && c == sc) &&
   (r == 0 || r == m-1 || c == 0 || c == n-1))
    return d;

       pq.pop();

       vector<int>drow={1,0,-1,0};
       vector<int>dcol={0,1,0,-1};

       for(int i=0;i<4;i++){
        int nrow=r+drow[i];
        int ncol=c+dcol[i];
if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && maze[nrow][ncol]=='.' && dis[nrow][ncol]>d+1){
    pq.push({d+1,{nrow,ncol}});
    dis[nrow][ncol]=d+1;
}
       }
     }
    return -1;

    }
};