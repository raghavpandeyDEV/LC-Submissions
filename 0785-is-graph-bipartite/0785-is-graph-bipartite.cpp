class Solution {
public:

   bool dfs(int node,int newColor ,vector<int>&color ,vector<int>&vis,vector<vector<int>>& graph){
    vis[node]=1;
    color[node]=newColor;

    for(auto it : graph[node]){
        if(vis[it]==-1){
            if(dfs(it,!newColor,color,vis,graph)==false)return false;
        }
        else {
            if(color[it]==newColor)return false;
        }
      
   }
     return true;
   }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);
        vector<int>color(n,-1);

        

        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(dfs(i,1,color,vis,graph)==false)return false;
            }
        }
        return true;
    }
};