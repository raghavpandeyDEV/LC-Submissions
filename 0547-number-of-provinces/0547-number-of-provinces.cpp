class Solution {
public:
    void bfs(int node , vector<vector<int>>&adj ,vector<int>&vis){
        queue<int>q;
        q.push(node);

        while(!q.empty()){
          int node=q.front();
          q.pop();

          for(auto it : adj[node]){
            if(vis[it]==-1){
                q.push(it);
                vis[it]=1;
            }
          }
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
         // make an adj list
         int n=isConnected.size();

         vector<vector<int>>adj(n);

         for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
            if(isConnected[i][j]==1){
                adj[i].push_back(j);        
            }
           }
         }

         vector<int>vis(n,-1);
         int cnt=0;

         for(int i=0;i<n;i++){
            if(vis[i]==-1){
                bfs(i,adj,vis);
                cnt++;
            }
         }
         return cnt;
    }
};